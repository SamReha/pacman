#include "pacman.hpp"

// Private
bool PacMan::canMove(Map map) {
  std::vector<sf::Vector2<int>> overlappingIndexes;
  
  // Figure out the index of the tile I am currently in (along with the centerpoint of that index's tile)
  int tileWidth = map.getTileWidth();
  sf::Vector2<int> mapIndex = map.convertPositionToIndex(position.x, position.y);
  sf::Vector2<double> occupiedTileCenterPoint((mapIndex.x*tileWidth) + map.getAnchor().x, (mapIndex.y*tileWidth) + map.getAnchor().y);
  sf::Vector2<int> newMapIndex;
  sf::Vector2<double> newTileCenterPoint;
  
  // Then, based on direction, see if pac is now overlapping a non-walkable tile
  if (desiredDirection == "UP") {
    newMapIndex.x = mapIndex.x;
    newMapIndex.y = mapIndex.y-1;
    PacTile newTile = *map.getTileAtIndex(newMapIndex); // This is the tile that Pacman would be trying to move towards
    
    // If the tile above is isn't walkable...
    if (newTile.getType() != "FLOOR") {
      return false;
    }
    
    // Otherwise, if we're aligned with the corridor, let Pac man change directions
    newTileCenterPoint.x = (newMapIndex.x*tileWidth) + map.getAnchor().x;
    
    if (position.x == newTileCenterPoint.x) { // This should probably be checking for a range, instead of exact values. Should also handle corner cutting
      return true;
    }
  } else if (desiredDirection == "DOWN") {
    newMapIndex.x = mapIndex.x;
    newMapIndex.y = mapIndex.y+1;
    PacTile newTile = *map.getTileAtIndex(newMapIndex); // This is the tile that Pacman would be trying to move towards
    
    // If the tile above is isn't walkable...
    if (newTile.getType() != "FLOOR") {
      return false;
    }
    
    // Otherwise, if we're aligned with the corridor, let Pac man change directions
    newTileCenterPoint.x = (newMapIndex.x*tileWidth) + map.getAnchor().x;
    
    if (position.x == newTileCenterPoint.x) { // This should probably be checking for a range, instead of exact values. Should also handle corner cutting
      return true;
    }
  } else if (desiredDirection == "LEFT") {
    newMapIndex.x = mapIndex.x-1;
    newMapIndex.y = mapIndex.y;
    PacTile newTile = *map.getTileAtIndex(newMapIndex); // This is the tile that Pacman would be trying to move towards
    
    // If the tile above is isn't walkable...
    if (newTile.getType() != "FLOOR") {
      return false;
    }
    
    // Otherwise, if we're aligned with the corridor, let Pac man change directions
    newTileCenterPoint.y = (newMapIndex.y*tileWidth) + map.getAnchor().x;
    
    if (position.y == newTileCenterPoint.y) { // This should probably be checking for a range, instead of exact values. Should also handle corner cutting
      return true;
    }
  } else if (desiredDirection == "RIGHT") {
    newMapIndex.x = mapIndex.x+1;
    newMapIndex.y = mapIndex.y;
    PacTile newTile = *map.getTileAtIndex(newMapIndex); // This is the tile that Pacman would be trying to move towards
    
    // If the tile above is isn't walkable...
    if (newTile.getType() != "FLOOR") {
      return false;
    }
    
    // Otherwise, if we're aligned with the corridor, let Pac man change directions
    newTileCenterPoint.y = (newMapIndex.y*tileWidth) + map.getAnchor().x;
    
    if (position.y == newTileCenterPoint.y) { // This should probably be checking for a range, instead of exact values. Should also handle corner cutting
      return true;
    }
  }
  return false;
}

// Public
PacMan::PacMan(double xPos, double yPos, int frmeRte) {
  position.x = xPos;
  position.y = yPos;
  frameRate = frmeRte;
  
  desiredDirection = "";
  
  activeVectorIndex = 0;
  timeOfLastSpriteChange = -1.0;
}

// This could probably stand to be optimized - seems to have some repeated logic
void PacMan::update(Map map) {
  // First, see if the player has attempted to change Pac's direction, and handle it if they have
  if (desiredDirection != "" && desiredDirection != moveDir) {
    if (canMove(map)) {
      moveDir = desiredDirection;
      desiredDirection = "";
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
  }
  
  // Figure out what my new position would be based on my velocity.
  double newX = position.x + velocity.x;
  double newY = position.y + velocity.y;
  
  // Then, consider the direction I am moving. If I'm past the center point of the tile I'm in in
  // that direction, then I must check if the tile one index ahead of me in that direction is
  // walkable. If it isn't, then clamp my position to the centerpoint of my tile, and kill my
  // velocity.
  sf::Vector2<int> currentMapIndex = map.convertPositionToIndex(position.x, position.y);
  int tileWidth = map.getTileWidth();
  sf::Vector2<double> currentTileCenterPoint((currentMapIndex.x*tileWidth) + map.getAnchor().x, (currentMapIndex.y*tileWidth) + map.getAnchor().y);
  sf::Vector2<int> newMapIndex;
  
  if (moveDir == "UP") {
    if (newY < currentTileCenterPoint.y) {
      newMapIndex = map.convertPositionToIndex(position.x, position.y);
      newMapIndex.y -= 1;
    }
  } else if (moveDir == "DOWN") {
    if (newY >= currentTileCenterPoint.y) {
      newMapIndex = map.convertPositionToIndex(position.x, position.y);
      newMapIndex.y += 1;
    }
  } else if (moveDir == "LEFT") {
    if (newX < currentTileCenterPoint.x) {
      newMapIndex = map.convertPositionToIndex(position.x-1, position.y);
      newMapIndex.x -= 1;
    }
  } else if (moveDir == "RIGHT") {
    if (newX >= currentTileCenterPoint.x) {
      newMapIndex = map.convertPositionToIndex(position.x+1, position.y);
      newMapIndex.x += 1;
    }
  }
  
  PacTile tempTile = *map.getTileAtIndex(newMapIndex);
  if (tempTile.getType() != "FLOOR") {
    velocity.x = 0.0;
    velocity.y = 0.0;
    position.x = currentTileCenterPoint.x;
    position.y = currentTileCenterPoint.y;
  } else {
    position.x = newX;
    position.y = newY;
  }

  // Update active sprite vector so we know what animation should be playing
  if (velocity.x != 0.0 && velocity.y != 0.0) {
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
      sprite = activeSpriteVector[activeVectorIndex];
      timeOfLastSpriteChange = (double) clock();
    }
  }
}