#include <SFML/Graphics.hpp>

class Ghost {
private:
  sf::Sprite* upSprites;
  sf::Sprite* downSprites;
  sf::Sprite* leftSprites;
  sf::Sprite* rightSprites;
  sf::Sprite* ghostBlueSprites;
  sf::Sprite* ghostWhiteSprites;
  sf::Sprite ghostEyesUp;
  sf::Sprite ghostEyesDown;
  sf::Sprite ghostEyesLeft;
  sf::Sprite ghostEyesRight;
  
  sf::Sprite currentSprite;
  sf::String state;
  sf::String personality;
  sf::Vector2<double> position;
  sf::Vector2<double> velocity;
public:
  Ghost(sf::String, sf::String);
  
  sf::Sprite getSprite();   // Fetches the current sprite for this ghost
  sf::String getState();    // Fetches current state
  sf::Vector2<double> getPosition();
  
  void update();            // Update state and velocity based on world state, update current sprite based on state, update position based on velocity
};