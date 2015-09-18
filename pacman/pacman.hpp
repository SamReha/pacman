#include <time.h>
#include <iostream>

#include "character.hpp"
#include "map.hpp"

class PacMan: public Character {
protected:
  int frameRate;   // Frame Rate in changes per second, controls rate of animation playback
  sf::String desiredDirection;    // The direction that the player wants Pac to move in
  double timeOfLastSpriteChange;
  bool canMove(Map map, sf::String direction);
public:
  PacMan(int xIndex, int yIndex, double speed, int frmeRte, Map map);
  
  void initialize(sf::String direction);    // This one guarantees the sprite is in the correct position after the sprite vectors have been configured
  
  void update(Map map);   // Needs a copy of the map to ask questions about it's position
};