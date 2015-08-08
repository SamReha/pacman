#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.hpp"

class AssetManager {
private:
  int tileWidth;
  std::map<sf::String, sf::Sprite> assetDict;
public:
  AssetManager(int width);
  
  void setWidth(int newWidth);
  std::map<sf::String, sf::Sprite> generateSpriteSet(sf::Texture* tileset_texture);
};