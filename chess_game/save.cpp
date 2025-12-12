#include <fstream>
#include <iostream>
#include <string>
#include "save.h"
#include "board.h"

void saveGameToFile(const char* filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Unable to open save file for writing\n";
        return;
    }
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) out << board[r][c];
        out << '\n';
    }
    out << (turn == 'w' ? 'w' : 'b') << '\n';
    out << whiteWins << '\n';
    out << blackWins << '\n';
    out.close();
}

bool loadGameFromFile(const char* filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Unable to open save file for reading\n";
        return false;
    }
    for (int r = 0; r < 8; ++r) {
        std::string line;
        std::getline(in, line);
        if ((int)line.size() < 8) {
            std::cerr << "Corrupt save file\n";
            in.close();
            return false;
        }
        for (int c = 0; c < 8; ++c) board[r][c] = line[c];
    }
    char t;
    in >> t;
    turn = (t == 'w') ? 'w' : 'b';
    in >> whiteWins;
    in >> blackWins;
    in.close();
    return true;
}
