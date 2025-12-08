#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
using namespace sf;
class save{
	private:
		 float W = 650;
		 float H = 650;
	public:
		save(){

		}
bool smain()
{
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(W), static_cast<unsigned int>(H)}), "Chess The Game Of Kings!");
    sf::Texture texture[2];
    std::vector<sf::Sprite> sprite;
    texture[0].loadFromFile("images/save-disk.png");
    texture[1].loadFromFile("images/gameOver.png");

    sprite.emplace_back(texture[0]);
    sprite.emplace_back(texture[1]);

    sprite[0].setScale({2.0f,2.0f});
    sprite[0].setPosition({250.f,20.f});
    sprite[1].setScale({0.73f,0.73f});
    sprite[1].setPosition({0.f,0.f});

    while (window.isOpen())
    {   Vector2i pos= Mouse::getPosition(window);
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
              window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) ){
            if (sprite[0].getGlobalBounds().contains(sf::Vector2f(pos))){
              return true;
              window.close();

              }
            }
          
      }

     window.clear();
     window.draw(sprite[1]);
     window.draw(sprite[0]);
     window.display();
  }
    
    
    return 0;
}
};
