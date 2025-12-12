#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include "board.h"
#include "moves.h"
#include "checkmate.h"
#include "render.h"
#include "menu.h"
#include "save.h"
#include "highscores.h"
#include "settings.h"
#include "ending.h"

int main()
{
    // Load settings & highscores
    loadSettings("settings.cfg");
    loadHighscores("highscores.dat");

    // Initialize SFML window
    const int winSize = 800;
    sf::RenderWindow window(sf::VideoMode(winSize, winSize), "SFML Chess");
    window.setFramerateLimit(60);

    loadTextures();

    // Main menu loop
    while (window.isOpen())
    {
        MenuResult mr = mainMenu(window);
        if (mr == MENU_EXIT)
        {
            saveHighscores("highscores.dat");
            saveSettings("settings.cfg");
            break;
        }
        else if (mr == MENU_SETTINGS)
        {
            sf::Font font;
            font.loadFromFile("C:/Windows/Fonts/arial.ttf");

            sf::Text title("Settings", font, 36);
            title.setPosition(300, 50);
            title.setFillColor(sf::Color::Black);

            sf::Text toggleSound("Toggle Sound (click)", font, 28);
            toggleSound.setPosition(250, 150);
            toggleSound.setFillColor(sf::Color::Black);

            sf::Text toggleTheme("Toggle Theme (click)", font, 28);
            toggleTheme.setPosition(250, 220);
            toggleTheme.setFillColor(sf::Color::Black);

            while (window.isOpen())
            {
                sf::Event e;
                while (window.pollEvent(e))
                {
                    if (e.type == sf::Event::Closed)
                    {
                        window.close();
                        break;
                    }
                    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
                        goto settings_done;

                    if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
                    {
                        int mx = e.mouseButton.x, my = e.mouseButton.y;
                        if (toggleSound.getGlobalBounds().contains(mx, my)) soundOn = 1 - soundOn;
                        if (toggleTheme.getGlobalBounds().contains(mx, my)) theme = 1 - theme;
                        saveSettings("settings.cfg");
                    }
                }
                window.clear(sf::Color(119, 149, 86));
                window.draw(title);
                window.draw(toggleSound);
                window.draw(toggleTheme);
                window.display();
            }
        settings_done:
            continue;
        }
        else if (mr == MENU_HIGHSCORES)
        {
            sf::Font font;
            font.loadFromFile("C:/Windows/Fonts/arial.ttf");

            sf::Text t("Highscores", font, 36);
            t.setPosition(300, 50);
            t.setFillColor(sf::Color::Black);

            sf::Text s1(("White wins: " + std::to_string(whiteWins)), font, 24);
            s1.setPosition(300, 140);
            s1.setFillColor(sf::Color::Black);

            sf::Text s2(("Black wins: " + std::to_string(blackWins)), font, 24);
            s2.setPosition(300, 180);
            s2.setFillColor(sf::Color::Black);

            while (window.isOpen())
            {
                sf::Event e;
                while (window.pollEvent(e))
                {
                    if (e.type == sf::Event::Closed)
                    {
                        window.close();
                        break;
                    }
                    if (e.type == sf::Event::KeyPressed) goto hs_done;
                }
                window.clear(sf::Color(119, 149, 86));
                window.draw(t);
                window.draw(s1);
                window.draw(s2);
                window.display();
            }
        hs_done:
            continue;
        }
        else if (mr == MENU_LOAD)
        {
            if (!loadGameFromFile("savegame.txt"))
                initializeBoard();
        }
        else if (mr == MENU_START)
        {
            initializeBoard();
            turn = 'w'; 
        }

        // ====================
        //        GAME LOOP
        // ====================
        bool inGame = true;
        int selR = -1, selC = -1;

        while (window.isOpen() && inGame)
        {
            sf::Event e;
            while (window.pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                {
                    saveHighscores("highscores.dat");
                    saveSettings("settings.cfg");
                    window.close();
                    break;
                }

                if (e.type == sf::Event::KeyPressed)
                {
                    if (e.key.code == sf::Keyboard::Escape)
                    {
                        inGame = false;
                        break;
                    }
                    else if (e.key.code == sf::Keyboard::P)
                    {
                        MenuResult pm = pauseMenu(window);
                        if (pm == MENU_EXIT)
                        {
                            inGame = false;
                            break;
                        }
                        else if (pm == MENU_LOAD)
                        {
                            saveGameToFile("savegame.txt");
                        }
                    }
                    else if (e.key.code == sf::Keyboard::S)
                        saveGameToFile("savegame.txt");
                }

                if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
                {
                    std::pair<int, int> cell = windowToBoard(window, sf::Mouse::getPosition(window));
                    int r = cell.first, c = cell.second;

                    if (selR == -1)
                    {
                        // Select piece
                        if (board[r][c] != ' ' && ((turn == 'w' && isWhitePiece(board[r][c])) || (turn == 'b' && isBlackPiece(board[r][c]))))
                        {
                            selR = r; selC = c;
                        }
                    }
                    else
                    {
                        // Attempt move
                        if (isMoveValid(selR, selC, r, c))
                        {
                            char savedDest = board[r][c];
                            char savedSrc = board[selR][selC];
                            board[r][c] = savedSrc;
                            board[selR][selC] = ' ';

                            if (isKingInCheck(turn))
                            {
                                board[selR][selC] = savedSrc;
                                board[r][c] = savedDest;
                                selR = -1; selC = -1;
                                continue;
                            }

                           
                            char opp = (turn == 'w') ? 'b' : 'w';
                            if (isCheckmate(opp))
                            {
                                recordWin(turn);
                                saveHighscores("highscores.dat");

                                GameResult result = (turn == 'w') ? WHITE_WINS : BLACK_WINS;
                                bool playAgain = showEndingScreen(window, result);

                                if (playAgain)
                                {
                                    initializeBoard();
                                    turn = 'w';
                                    selR = selC = -1;
                                    break; // EXIT GAME LOOP
                                }
                                else
                                {
                                    inGame = false;
                                    break;
                                }
                            }

                            // move accepted, toggle turn
                            turn = (turn == 'w') ? 'b' : 'w';
                        }
                        selR = -1; selC = -1;
                    }
                }
            }

            if (!window.isOpen()) break;

            // RENDER
            window.clear();
            drawBoardAndPieces(window);
            if (selR != -1) drawHighlight(window, selR, selC);
            window.display();
        }
    }

    return 0;
}
