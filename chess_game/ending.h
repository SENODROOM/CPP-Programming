#ifndef ENDING_H
#define ENDING_H

#include <SFML/Graphics.hpp>

enum GameResult { WHITE_WINS, BLACK_WINS, DRAW, STALEMATE };

bool showEndingScreen(sf::RenderWindow &window, GameResult result);

#endif // ENDING_H