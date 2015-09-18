#include "pacman.hpp"

// Private
bool PacMan::canMove(Map map, sf::String direction) {
  sf::Vector2<double> centerPoint = position;
  int width = sprite.getTextureRect().width;
  centerPoint.x = centerPoint.x + width/2;
  centerPoint.y = centerPoint.y + width/2;
  
  sf::Vector2<int> index = map.convertPositionToIndex(centerPoint.x, centerPoint.y);
  
  if (direction == "UP") {
    index.y -= 1;
  } else if (direction == "DOWN") {
    index.y += 1;
  } else if (direction == "LEFT") {
    index.x -= 1;
  } else if (direction == "RIGHT") {
    index.x += 1;
  }
  
  PacTile newTile = *map.getTileAtIndex(index); // This is the tile that Pacman would be trying to move towards
  
  // If the tile above is isn't walkable...
  return (newTile.getType() == "FLOOR");
}

// Public
PacMan::PacMan(int xIndex, int yIndex, double speed, int frmeRte, Map map) {
  sf::Vector2<double> anchor = map.getAnchor();
  int tileWidth = map.getTileWidth();
  
  position.x = anchor.x + (tileWidth*xIndex) + tileWidth/2;
  position.y = anchor.y + (tileWidth*yIndex) + tileWidth/2;
  
  std::cout << std::to_string(position.x) + '\n';
  std::cout << std::to_string(position.y) + '\n';
  
  velocity.x = speed;
  velocity.y = speed;
  
  frameRate = frmeRte;
  
  desiredDirection = "";
  
  activeVectorIndex = 0;
  timeOfLastSpriteChange = -1.0;
}

// Make a point to call this one AFTER you've set your sprite vectors!
void PacMan::initialize(sf::String direction) {
  desiredDirection = direction;
  
  if (desiredDirection == "UP") {
    activeSpriteVector = upSprites;
  } else if (desiredDirection == "DOWN") {
    activeSpriteVector = downSprites;
  } else if (desiredDirection == "LEFT") {
    activeSpriteVector = leftSprites;
  } else if (desiredDirection == "RIGHT") {
    activeSpriteVector = rightSprites;
  }
  
  sprite = activeSpriteVector[activeVectorIndex];
  
  int width = sprite.getTextureRect().width;
  position.x = position.x - width/2;
  position.y = position.y - width/2;
  
  sprite.setPosition(position.x, position.y);
}

// This could probably stand to be optimized - seems to have some repeated logic
void PacMan::update(Map map) {
  // First, look at the keyboard to see what the user wants.
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    desiredDirection = sf::String("UP");
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    desiredDirection = sf::String("DOWN");
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    desiredDirection = sf::String("LEFT");
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    desiredDirection = sf::String("RIGHT");
  }
  
  // See if the player has attempted to change Pac's direction, and handle it if they have
  if (desiredDirection != "" && desiredDirection != moveDir) {
    if (canMove(map, desiredDirection)) {
      moveDir = desiredDirection;
    }
  }
  
  // Figure out what my new velocity should be
  if (moveDir == "UP") {
    velocity.x = 0.0;
    velocity.y = -1.0;
  } else if (moveDir == "DOWN") {
    velocity.x = 0.0;
    velocity.y = 1.0;
  } else if (moveDir == "LEFT") {
    velocity.x = -1.0;
    velocity.y = 0.0;
  } else if (moveDir == "RIGHT") {
    velocity.x = 1.0;
    velocity.y = 0.0;
  } else {
    velocity.x = 0.0;
    velocity.y = 0.0;
  }
  
  // Figure out what my new position would be based on my velocity.
  if (canMove(map, moveDir)) {
    position.x = position.x + velocity.x;
    position.y = position.y + velocity.y;
  }
  
  // Update active sprite vector so we know what animation should be playing
  if (velocity.x != 0.0 || velocity.y != 0.0) {
    if (moveDir == "UP") {
      activeSpriteVector = upSprites;
    } else if (moveDir == "DOWN") {
      activeSpriteVector = downSprites;
    } else if (moveDir == "LEFT") {
      activeSpriteVector = leftSprites;
    } else if (moveDir == "RIGHT") {
      activeSpriteVector = rightSprites;
    }
  
    // Update the active sprite - but only if we are currently moving!
    double secondsSinceLastSpriteChange = ((double) clock()/CLOCKS_PER_SEC) - timeOfLastSpriteChange;
    if (secondsSinceLastSpriteChange > 1.0/frameRate) {
      activeVectorIndex = (activeVectorIndex+1)%vectorLength;
      
      timeOfLastSpriteChange = (double) clock()/CLOCKS_PER_SEC;
    }
    sprite = activeSpriteVector[activeVectorIndex];
  }
  
  // And before we wrap up, set our new sprite to our current position
  sprite.setPosition(position.x, position.y);
}