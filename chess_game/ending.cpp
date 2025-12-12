#include <SFML/Graphics.hpp>
#include <iostream>
#include "ending.h"

// =====================
// ENDING SCREEN
// =====================
bool showEndingScreen(sf::RenderWindow &window, GameResult result) {
    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Failed to load font!\n";
    }

    // Result title
    sf::Text title;
    title.setFont(font);
    title.setCharacterSize(60);
    title.setStyle(sf::Text::Bold);
    title.setPosition(250, 150);

    // Set text and color based on result
    switch(result) {
        case WHITE_WINS:
            title.setString("White Wins!");
            title.setFillColor(sf::Color::White);
            break;
        case BLACK_WINS:
            title.setString("Black Wins!");
            title.setFillColor(sf::Color::Black);
            break;
        case DRAW:
            title.setString("Draw!");
            title.setFillColor(sf::Color::Yellow);
            break;
        case STALEMATE:
            title.setString("Stalemate!");
            title.setFillColor(sf::Color::Cyan);
            break;
    }

    // Menu options
    const char* items[] = {"Play Again", "Exit to Main Menu"};
    const int n = 2;
    sf::Text texts[n];
    for (int i = 0; i < n; ++i) {
        texts[i].setFont(font);
        texts[i].setString(items[i]);
        texts[i].setCharacterSize(32);
        texts[i].setPosition(280, 300 + i*80);
    }

    // Semi-transparent overlay
    sf::RectangleShape overlay(sf::Vector2f(800, 800));
    overlay.setFillColor(sf::Color(119, 149, 86));

    // Button backgrounds
    sf::RectangleShape buttons[n];
    for (int i = 0; i < n; ++i) {
        buttons[i].setSize(sf::Vector2f(300, 60));
        buttons[i].setPosition(250, 290 + i*80);
        buttons[i].setFillColor(sf::Color(70, 70, 70));
        buttons[i].setOutlineThickness(2);
        buttons[i].setOutlineColor(sf::Color::White);
    }

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) return false;
            
            if (e.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mp = sf::Mouse::getPosition(window);
                for (int i = 0; i < n; ++i) {
                    if (texts[i].getGlobalBounds().contains((float)mp.x, (float)mp.y)) {
                        switch(i) {
                            case 0: return true;   // Play Again
                            case 1: return false;  // Exit to Main Menu
                        }
                    }
                }
            }
            
            // Keyboard shortcuts
            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Enter || e.key.code == sf::Keyboard::Space) {
                    return true;  // Play Again
                }
                if (e.key.code == sf::Keyboard::Escape) {
                    return false; // Exit
                }
            }
        }
        
        // Hover effect
        sf::Vector2i mp = sf::Mouse::getPosition(window);
        for (int i = 0; i < n; ++i) {
            if (buttons[i].getGlobalBounds().contains((float)mp.x, (float)mp.y)) {
                buttons[i].setFillColor(sf::Color(119, 149, 86));
            } else {
                buttons[i].setFillColor(sf::Color(130, 140, 200));
                 sf::Color outline(100, 200, 20);
            }
        }

        window.clear(sf::Color(119, 149, 86));
        window.draw(overlay);
        window.draw(title);
        for (int i = 0; i < n; ++i) {
            window.draw(buttons[i]);
            window.draw(texts[i]);
        }
        window.display();
    }
    return false;
}