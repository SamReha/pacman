#include "maze_obj.hpp"

class Ghost: public Maze_obj {
private:
  std::vector<sf::Sprite> upSprites;
  std::vector<sf::Sprite> downSprites;
  std::vector<sf::Sprite> leftSprites;
  std::vector<sf::Sprite> rightSprites;
  std::vector<sf::Sprite> ghostBlueSprites;
  std::vector<sf::Sprite> ghostWhiteSprites;
  sf::Sprite ghostEyesUp;
  sf::Sprite ghostEyesDown;
  sf::Sprite ghostEyesLeft;
  sf::Sprite ghostEyesRight;

  sf::String state;
  sf::Vector2<double> velocity;
public:
  Ghost(sf::Vector2<double>, sf::String);

  void setUpSprites(std::vector<sf::Sprite>);
  void setDownSprites(std::vector<sf::Sprite>);
  void setLeftSprites(std::vector<sf::Sprite>);
  void setRightSprites(std::vector<sf::Sprite>);
  void setBlueSprites(std::vector<sf::Sprite>);
  void setWhiteSprites(std::vector<sf::Sprite>);
  void setEyeBallSprites(std::vector<sf::Sprite>);
  
  sf::String getState();    // Fetches current state
  
  void update();
};