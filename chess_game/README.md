USE THESE COMMAND TO RUN ON WINDOWS:
g++ main.cpp board.cpp moves.cpp render.cpp menu.cpp checkmate.cpp save.cpp highscores.cpp settings.cpp ending.cpp -o chess_game \
 -I"/c/SFML-2.6.2/include" \
 -L"/c/SFML-2.6.2/lib" \
 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

./chess_game