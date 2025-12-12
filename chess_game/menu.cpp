#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.h"
#include "settings.h"

// =====================
// FONT LOADER
// =====================
sf::Font loadSystemFont()
{
    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font!\n";
    }

    const char *fallbackFonts[] = {
        "/usr/share/fonts/TTF/Arial.ttf",
        "/usr/share/fonts/truetype/freefont/FreeSans.ttf",
        "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf"};
    for (auto &f : fallbackFonts)
    {
        if (font.loadFromFile(f))
            return font;
    }

    std::cerr << "No system fonts found! Using empty font.\n";
    return font;
}

// =====================
// DRAW RECTANGLE
// =====================
void drawRect(sf::RenderWindow &win, sf::Vector2f pos, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, float outlineThickness = 3.0f)
{
    sf::RectangleShape rect(size);
    rect.setPosition(pos);
    rect.setFillColor(fillColor);
    rect.setOutlineColor(outlineColor);
    rect.setOutlineThickness(outlineThickness);
    win.draw(rect);
}

// =====================
// MAIN MENU
// =====================
MenuResult mainMenu(sf::RenderWindow &window)
{
    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font!\n";
    }

    sf::Text title("Chess Game", font, 60);
    title.setFillColor(sf::Color(240, 240, 240));
    title.setPosition(300, 40);

    const char *items[] = {"Start New Game", "Load Game", "Settings", "High Scores", "Exit"};
    const char *key[] = {"e for Exit ", "p for Pause", "s for Save ", "esc to Exit the Menu"};
    const int y = 4;
    const int n = 5;
    sf::Text texts[n];
    sf::RectangleShape blocks[n];

    for (int i = 0; i < n; ++i)
    {
        blocks[i].setSize(sf::Vector2f(300, 60));
        blocks[i].setPosition(300, 170 + i * 85);

        texts[i].setFont(font);
        texts[i].setString(items[i]);
        texts[i].setCharacterSize(28);

        // Center text inside block
        sf::FloatRect textRect = texts[i].getLocalBounds();
        texts[i].setOrigin(textRect.left + textRect.width / 2.0f,
                           textRect.top + textRect.height / 2.0f);
        texts[i].setPosition(blocks[i].getPosition().x + blocks[i].getSize().x / 2.0f,
                             blocks[i].getPosition().y + blocks[i].getSize().y / 2.0f);
    }

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                return MENU_EXIT;

            if (e.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mp = sf::Mouse::getPosition(window);
                for (int i = 0; i < n; i++)
                {
                    if (blocks[i].getGlobalBounds().contains((float)mp.x, (float)mp.y))
                    {
                        switch (i)
                        {
                        case 0:
                            return MENU_START;
                        case 1:
                            return MENU_LOAD;
                        case 2:
                            return MENU_SETTINGS;
                        case 3:
                            return MENU_HIGHSCORES;
                        case 4:
                            return MENU_EXIT;
                        }
                    }
                }
            }
        }

        sf::Vector2i mp = sf::Mouse::getPosition(window);
        window.clear(sf::Color(119, 149, 86)); // background color
        window.draw(title);

        for (int i = 0; i < n; i++)
        {
            bool isHover = blocks[i].getGlobalBounds().contains((float)mp.x, (float)mp.y);
            sf::Color normalFill(235, 235, 208);
            sf::Color hoverFill(130, 140, 200);
            sf::Color outline(100, 200, 20);

            drawRect(window, blocks[i].getPosition(), blocks[i].getSize(), isHover ? hoverFill : normalFill, outline, 3);
            texts[i].setFillColor(isHover ? sf::Color(255, 215, 0) : sf::Color::Black);
            window.draw(texts[i]);
        }

        window.display();
    }

    return MENU_EXIT;
}

// =====================
// PAUSE MENU
// =====================
MenuResult pauseMenu(sf::RenderWindow &window)
{
   sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font!\n";
    }
    const char *items[] = {"Resume", "Save Game", "Exit to Main Menu"};
    const int n = 3;
    sf::Text texts[n];
    sf::RectangleShape blocks[n];

    for (int i = 0; i < n; ++i)
    {
        blocks[i].setSize(sf::Vector2f(320, 70));
        blocks[i].setPosition(300, 210 + i * 90);

        texts[i].setFont(font);
        texts[i].setString(items[i]);
        texts[i].setCharacterSize(28);

        // Center text inside block
        sf::FloatRect textRect = texts[i].getLocalBounds();
        texts[i].setOrigin(textRect.left + textRect.width / 2.0f,
                           textRect.top + textRect.height / 2.0f);
        texts[i].setPosition(blocks[i].getPosition().x + blocks[i].getSize().x / 2.0f,
                             blocks[i].getPosition().y + blocks[i].getSize().y / 2.0f);
    }

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                return MENU_EXIT;

            if (e.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mp = sf::Mouse::getPosition(window);
                for (int i = 0; i < n; i++)
                {
                    if (blocks[i].getGlobalBounds().contains((float)mp.x, (float)mp.y))
                    {
                        switch (i)
                        {
                        case 0:
                            return MENU_NONE;
                        case 1:
                            return MENU_LOAD;
                        case 2:
                            return MENU_EXIT;
                        }
                    }
                }
            }
        }

        sf::Vector2i mp = sf::Mouse::getPosition(window);
        window.clear(sf::Color(35, 35, 55));

        for (int i = 0; i < n; i++)
        {
            bool isHover = blocks[i].getGlobalBounds().contains((float)mp.x, (float)mp.y);
            sf::Color normalFill(100, 100, 130);
            sf::Color hoverFill(150, 150, 200);
            sf::Color outline(220, 220, 240);

            drawRect(window, blocks[i].getPosition(), blocks[i].getSize(), isHover ? hoverFill : normalFill, outline, 3);
            texts[i].setFillColor(isHover ? sf::Color(255, 215, 0) : sf::Color::White);
            window.draw(texts[i]);
        }

        window.display();
    }

    return MENU_EXIT;
}

// =====================
// HIGH SCORES SCREEN
// =====================
void showHighScores(sf::RenderWindow &window, int whiteWins, int blackWins)
{
   sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font!\n";
    }

    sf::Text title("High Scores", font, 46);
    title.setFillColor(sf::Color::White);
    title.setPosition(240, 60);

    sf::RectangleShape panel(sf::Vector2f(500, 250));
    panel.setPosition(140, 150);
    panel.setFillColor(sf::Color(70, 70, 100));
    panel.setOutlineColor(sf::Color(200, 200, 220));
    panel.setOutlineThickness(3);

    sf::Text white("White wins: " + std::to_string(whiteWins), font, 28);
    white.setPosition(200, 190);

    sf::Text black("Black wins: " + std::to_string(blackWins), font, 28);
    black.setPosition(200, 240);

    sf::Text back("Press any key to return", font, 22);
    back.setPosition(220, 380);

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                return;
            if (e.type == sf::Event::KeyPressed || e.type == sf::Event::MouseButtonPressed)
                return;
        }

        window.clear(sf::Color(30, 30, 50));
        window.draw(title);
        window.draw(panel);
        window.draw(white);
        window.draw(black);
        window.draw(back);
        window.display();
    }
}
MenuResult showSettings(sf::RenderWindow &window)
{
   sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font!\n";
    }

    sf::Text title("Settings", font, 50);
    title.setPosition(260, 80);
    title.setFillColor(sf::Color::White);

    sf::Text sound("Toggle Sound (click)", font, 30);
    sound.setPosition(200, 200);
    sound.setFillColor(sf::Color::Yellow);

    sf::Text themeText("Toggle Theme (click)", font, 30);
    themeText.setPosition(200, 260);
    themeText.setFillColor(sf::Color::Yellow);

    sf::Text back("Press ESC to return", font, 22);
    back.setPosition(250, 400);
    back.setFillColor(sf::Color(200, 200, 200));

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                return MENU_EXIT;

            if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
            {
                saveSettings("settings.cfg");
                return MENU_NONE;
            }

            if (e.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mp = sf::Mouse::getPosition(window);

                if (sound.getGlobalBounds().contains(mp.x, mp.y))
                {
                    soundOn = 1 - soundOn; // toggle sound
                }
                if (themeText.getGlobalBounds().contains(mp.x, mp.y))
                {
                    theme = (theme == 0 ? 1 : 0); // toggle theme
                }
            }
        }

        window.clear(sf::Color(40, 60, 90));
        window.draw(title);
        window.draw(sound);
        window.draw(themeText);
        window.draw(back);
        window.display();
    }

    return MENU_NONE;
}
