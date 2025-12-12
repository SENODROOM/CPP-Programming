#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include "board.h"

// =========================
// TEXTURES AND SPRITES
// =========================
static sf::Texture pieceTextures[12]; // 0-5 white, 6-11 black
static bool texturesLoaded = false;
static sf::Texture boardTexture;
static bool boardTextureLoaded = false;

static const char* pieceFiles[12] = {
    "assets/pieces/white_pawn.png",
    "assets/pieces/white_rook.png",
    "assets/pieces/white_knight.png",
    "assets/pieces/white_bishop.png",
    "assets/pieces/white_queen.png",
    "assets/pieces/white_king.png",
    "assets/pieces/black_pawn.png",
    "assets/pieces/black_rook.png",
    "assets/pieces/black_knight.png",
    "assets/pieces/black_bishop.png",
    "assets/pieces/black_queen.png",
    "assets/pieces/black_king.png"
};

// =========================
// LOAD TEXTURES
// =========================
void loadTextures() {
    if (texturesLoaded) return;

    bool ok = true;
    for (int i = 0; i < 12; ++i) {
        if (!pieceTextures[i].loadFromFile(pieceFiles[i])) {
            std::cerr << "Failed to load: " << pieceFiles[i] << "\n";
            ok = false;
        }
    }

    if (!boardTexture.loadFromFile("assets/board.png")) {
        std::cerr << "Failed to load board.png\n";
    } else boardTextureLoaded = true;

    texturesLoaded = true;
    if (!ok) std::cerr << "One or more piece textures failed to load!\n";
}

// =========================
// MAP CHAR TO TEXTURE INDEX
// =========================
int getTextureIndex(char ch) {
    switch(ch) {
        case 'P': return 0; case 'R': return 1; case 'N': return 2;
        case 'B': return 3; case 'Q': return 4; case 'K': return 5;
        case 'p': return 6; case 'r': return 7; case 'n': return 8;
        case 'b': return 9; case 'q': return 10; case 'k': return 11;
        default: return -1;
    }
}

// =========================
// DRAW BOARD + PIECES
// =========================
void drawBoardAndPieces(sf::RenderWindow &window) {
    int winW = window.getSize().x;
    int winH = window.getSize().y;
    float cellW = winW / 8.0f;
    float cellH = winH / 8.0f;

    // Draw board background
    if (boardTextureLoaded) {
        sf::Sprite bs(boardTexture);
        bs.setScale(float(winW) / boardTexture.getSize().x,
                    float(winH) / boardTexture.getSize().y);
        window.draw(bs);
    } else {
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                sf::RectangleShape rect(sf::Vector2f(cellW, cellH));
                rect.setPosition(c * cellW, r * cellH);
                rect.setFillColor((r + c) % 2 == 0 ? sf::Color(235,235,208) : sf::Color(119,149,86));
                window.draw(rect);
            }
        }
    }

    // Draw pieces
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            char ch = board[r][c];
            int idx = getTextureIndex(ch);
            if (idx >= 0) {
                sf::Sprite spr(pieceTextures[idx]);
                // scale assuming all textures are 100x100
                float scaleX = cellW / 100.0f;
                float scaleY = cellH / 100.0f;
                spr.setScale(scaleX, scaleY);
                spr.setPosition(c * cellW, r * cellH);
                window.draw(spr);
            }
        }
    }
}

// =========================
// DRAW HIGHLIGHT
// =========================
void drawHighlight(sf::RenderWindow &window, int r, int c) {
    int winW = window.getSize().x;
    int winH = window.getSize().y;
    float cellW = winW / 8.0f;
    float cellH = winH / 8.0f;

    sf::RectangleShape rect(sf::Vector2f(cellW, cellH));
    rect.setPosition(c * cellW, r * cellH);
    rect.setFillColor(sf::Color(255, 255, 0, 90)); // semi-transparent yellow
    window.draw(rect);
}

// =========================
// MAP MOUSE TO BOARD
// =========================
std::pair<int,int> windowToBoard(sf::RenderWindow &window, sf::Vector2i mousePos) {
    int winW = window.getSize().x;
    int winH = window.getSize().y;
    float cellW = winW / 8.0f;
    float cellH = winH / 8.0f;

    int c = int(mousePos.x / cellW);
    int r = int(mousePos.y / cellH);

    // clamp 0-7
    if (r < 0) r = 0; if (r > 7) r = 7;
    if (c < 0) c = 0; if (c > 7) c = 7;

    return {r, c};
}
