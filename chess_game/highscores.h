#ifndef HIGHSCORES_H
#define HIGHSCORES_H

void loadHighscores(const char* filename);
void saveHighscores(const char* filename);
void recordWin(char winner); // 'w' or 'b'

#endif // HIGHSCORES_H
