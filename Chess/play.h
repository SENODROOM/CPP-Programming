                char c,d;
                in>>a>>c;
                spritepositions[j]=a;
                in2>>b>>d;
                board[j]=b;}
              ChessBoard graphics;
              graphics.MainFunctions(0);
            }
            }
      }

     window.clear();
     window.draw(rectangle);
     window.draw(sprite[2]);
     window.draw(sprite[0]);
     window.draw(sprite[1]);
     window.display();
  } 

}
};