#include <SFML/Graphics.hpp>

class Button {
private:
  sf::Vector2<double> size, position;
  sf::Sprite sprite;
  sf::Rect<double> collisionBox;
public:
  Button(sf::Vector2<double> size, sf::Sprite spr, sf::Rect<double> collBox);
  
  sf::Vector2<double> getPosition();      // Gets the the position of the button
  void setPosition(sf::Vector2<double>);  // Sets the button to a specific position (x, y)
  bool isClicked(sf::Vector2<double>);    // returns true if the given (x, y) is within the button
  sf::Sprite getSprite();                 // Fetches the sf::Sprite associated with this paddle
};