#ifndef RENDER_H
#define RENDER_H

#include <SFML/Graphics.hpp>

void loadTextures();
void drawBoardAndPieces(sf::RenderWindow &window);
void drawHighlight(sf::RenderWindow &window, int r, int c);
std::pair<int,int> windowToBoard(sf::RenderWindow &window, sf::Vector2i mousePos);

#endif // RENDER_H
