#include <fstream>
#include <iostream>
#include "settings.h"

int soundOn = 1;
int theme = 0;

void loadSettings(const char* filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        soundOn = 1;
        theme = 0;
        return;
    }
    in >> soundOn;
    in >> theme;
    in.close();
}

void saveSettings(const char* filename) {
    std::ofstream out(filename);
    if (!out.is_open()) return;
    out << soundOn << '\n';
    out << theme << '\n';
    out.close();
}
