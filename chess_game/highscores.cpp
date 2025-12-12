#include <fstream>
#include <iostream>
#include "highscores.h"
#include "board.h"

void loadHighscores(const char* filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        // file doesn't exist yet
        whiteWins = 0;
        blackWins = 0;
        return;
    }
    in >> whiteWins;
    in >> blackWins;
    in.close();
}

void saveHighscores(const char* filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Unable to write highscores\n";
        return;
    }
    out << whiteWins << '\n';
    out << blackWins << '\n';
    out.close();
}

void recordWin(char winner) {
    if (winner == 'w') whiteWins++;
    else if (winner == 'b') blackWins++;
}
