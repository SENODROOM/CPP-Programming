#include <SFML/Graphics.hpp>
#include <iostream>
#include "utilityBox.h"
#include "save.h"
#include <fstream>
#include <vector>
using namespace sf;
using namespace std;
int spritepositions[64]={
    0,1,2,3,4,5,6,7,
    8,9,10,11,12,13,14,15,
    64,64,64,64,64,64,64,64,
    64,64,64,64,64,64,64,64,
    64,64,64,64,64,64,64,64,
    64,64,64,64,64,64,64,64,
    48,49,50,51,52,53,54,55,
    56,57,58,59,60,61,62,63
  };
int board[64]={
   -1,-2,-3,-4,-5,-3,-2,-1,
   -6,-6,-6,-6,-6,-6,-6,-6,
    0, 0, 0, 0,0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    6, 6, 6, 6, 6, 6, 6, 6,
    1, 2, 3, 4, 5, 3, 2, 1};
class ChessBoard{
  private:
    const float WIDTH = 650;
    const float HEIGTH = 650;
  public:
    void loadtextures(Texture texture[64]);
    void loadboard(Texture texture[64],RectangleShape rectangle[64],std::vector<Sprite>& sprite);
    void MainFunctions(int u);
  
};

void ChessBoard::loadtextures(Texture texture[64]){
    for(int i=0;i<64;i++){
      if(spritepositions[i]==0 || spritepositions[i]==7)
        texture[i].loadFromFile("images/blackRook.png");
      if(spritepositions[i]==1 || spritepositions[i]==6)
        texture[i].loadFromFile("images/blackKnight.png");
      if(spritepositions[i]==2 || spritepositions[i]==5)
        texture[i].loadFromFile("images/blackBishop.png");
      if(spritepositions[i]==3)
        texture[i].loadFromFile("images/blackQueen.png");
      if(spritepositions[i]==4)
        texture[i].loadFromFile("images/blackKing.png");
      if(spritepositions[i]>=8 and spritepositions[i]<=15)
        texture[i].loadFromFile("images/blackPawn.png");
      if(spritepositions[i]==63 || spritepositions[i]==56)
        texture[i].loadFromFile("images/whiteRook.png");
      if(spritepositions[i]==62 || spritepositions[i]==57)
         texture[i].loadFromFile("images/whiteKnight.png");
      if(spritepositions[i]==61 || spritepositions[i]==58)
         texture[i].loadFromFile("images/whiteBishop.png");
      if(spritepositions[i]==59)
         texture[i].loadFromFile("images/whiteQueen.png");
      if(spritepositions[i]==60)
         texture[i].loadFromFile("images/whiteKing.png");
      if(spritepositions[i]>=48 and spritepositions[i]<=55)
         texture[i].loadFromFile("images/whitePawn.png");     
    }
  }
  }
void ChessBoard::loadboard(Texture texture[64],RectangleShape rectangle[64],std::vector<Sprite>& sprite){
    for(int j=0;j<64;j++){
        sprite.emplace_back(texture[j]);
        sprite[j].setScale({1.7f,1.7f});
    }
   for (int j = 0; j < 64; ++j)
    {
        rectangle[j].setSize(sf::Vector2f(WIDTH/8.0f, HEIGTH/8.0f));
    }
    int counter=0;
    for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
      {
        rectangle[counter].setPosition({j * rectangle[counter].getSize().y, i * rectangle[counter].getSize().x});  ///x,y
        sprite[counter].setPosition({j * rectangle[counter].getSize().y, i * rectangle[counter].getSize().x});
        if((i+j) % 2 == 0)
          rectangle[counter].setFillColor(sf::Color::White);
        else
          rectangle[counter].setFillColor(sf::Color::Blue);
        counter++;
      }
    }
  }
void ChessBoard::MainFunctions(int u)
  {
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(WIDTH), static_cast<unsigned int>(HEIGTH)}), "Chess The Game Of Kings!");
    sf::RectangleShape rectangle[64];
    sf::Texture texture[65];
    std::vector<sf::Sprite> sprite;
    sprite.reserve(65);
    loadtextures(texture);
    loadboard(texture,rectangle,sprite);
    // Add the 65th sprite (dummy or extra?)
    // The original code had sprite[65], but loadboard only handles 64.
    // The loop at line 228 iterates to 65.
    // Let's add one more sprite to match size 65.
    sprite.emplace_back(); 
    Identity box;
    bool isMove;
    float dx=0,dy=0;
    Vector2f oldPos,newPos;
    int n;
    int cc,turn=1;
    int alience,position;
    Vector2f firstpos,secondpos;
    int v;int q[64];
    static int cap=0;
    for (int j = 0; j < 64; ++j)
      q[j]=64;
    while (window.isOpen())
    {   Vector2i pos= Mouse::getPosition(window);
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){
              save s;
              window.close();
              if(s.smain()){
              ofstream out,out2;
              out.open("spritepositions.txt");
              out2.open("boardpositions.txt");
              for(int i=0;i<64;i++){
                out<<spritepositions[i]<<",";
                out2<<board[i]<<",";
              }
              out.close();
              out2.close();}
              }
            if(u!=0){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
              for (int j = 0; j < 64; ++j){
                if(turn%2==0 and board[j]<0){
                  if (rectangle[j].getGlobalBounds().contains(sf::Vector2f(pos)))
                      {
                        n=j;
                        firstpos=rectangle[j].getPosition();
                        v=spritepositions[j];
                        rectangle[n].setFillColor(sf::Color::Red);
                        if(spritepositions[n]!=64)
                        
                        cap++;
                  }
              }
            }
              for (int j = 0; j < 64; ++j){
                if(turn%2!=0 and board[j]>0){
                  if (rectangle[j].getGlobalBounds().contains(sf::Vector2f(pos)))
                      {
                        n=j;
                        firstpos=rectangle[j].getPosition();
                        v=spritepositions[j];
                        rectangle[n].setFillColor(sf::Color::Red);
                        if(spritepositions[n]!=64)
                        cap++;
                  }
              }
            }

           }
           if(cap!=0)
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
              for (int j = 0; j < 64; ++j){
                  //cout<<box.identifier(n,j,board[j],board)<<"=identity"<<endl;
                  if (rectangle[j].getGlobalBounds().contains(sf::Vector2f(pos))){
                        //if(n==8 and j==16 and board[n]==-6){ 
                        isMove=box.identifier(n,j,board[n],board);//<<"=identity"<<endl;
                        secondpos=rectangle[j].getPosition();
                        int spritepos=spritepositions[n];
                        //cout<<"shaheer"<<endl;
                        if(isMove){
                        turn++;
                        cc=q[j]=spritepositions[j];
                        if(j!=n){
                        sprite[spritepos].setPosition(secondpos);
                        sprite[cc].setPosition({100000000.f,100000000.f});
                        int suppos=spritepositions[j]; 
                        spritepositions[j]=spritepositions[n];
                        spritepositions[n]=64;
                        if(board[j]==-5 || board[j]==5){
                          save s;
                          window.close();
                          if(s.smain()){
                            ofstream out,out2;
                            out.open("spritepositions.txt");
                            out2.open("boardpositions.txt");
                            for(int i=0;i<64;i++){
                              out<<spritepositions[i]<<",";
                              out2<<board[i]<<",";
                            }
                            out.close();
                            out2.close();}
                        }
                        if(j<=63 and j>=56 and board[n]==-6){
                          board[j]=-4;
                        }
                        else if(j>=0 and j<=7 and board[n]==6){
                          board[j]=4;
                        }
                        else{
                        board[j]=board[n];
                        board[n]=0;}
                        n=j;}
                      }
                        int counter=0;
                        for (int i = 0; i < 8; ++i){
                          for (int j = 0; j < 8; ++j){
                            if((i+j) % 2 == 0)
                              rectangle[counter].setFillColor(sf::Color::White);
                            else
                              rectangle[counter].setFillColor(sf::Color::Blue);
                              counter++;
                              
                              }

                          }

                      }
              }
              cap=0;
            
            }
        }
      }

        window.clear();
        for (int j = 0; j < 64; ++j)
         window.draw(rectangle[j]);
      for (int j = 0; j < 65; j++){
          if(q[j]==64)
          window.draw(sprite[j]);
      }
        
        window.display();
    }
}
