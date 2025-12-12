#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

enum MenuResult { MENU_NONE, MENU_START, MENU_LOAD, MENU_SETTINGS, MENU_HIGHSCORES, MENU_EXIT };

MenuResult mainMenu(sf::RenderWindow &window);
MenuResult pauseMenu(sf::RenderWindow &window);
MenuResult showSettings(sf::RenderWindow &window);

#endif // MENU_H
