#include "AssetManager.hpp"

// Private

// Public
AssetManager::AssetManager(int width) {
  tileWidth = width;
}

void AssetManager::setWidth(int newWidth) {
  tileWidth = newWidth;
}

std::map<sf::String, sf::Sprite> AssetManager::generateSpriteSet(sf::Texture tileset_texture) {
  sf::Sprite top_left_corner(tileset_texture, sf::Rect<int>(0, 0, tileWidth, tileWidth));
  assetDict["outer_top_left_corner"] = top_left_corner;
  
  sf::Sprite top_right_corner(tileset_texture, sf::Rect<int>(tileWidth*27, 0, tileWidth, tileWidth));
  assetDict["top_right_corner"] = top_right_corner;
  
  sf::Sprite bottom_right_corner(tileset_texture, sf::Rect<int>(tileWidth*27, 9*tileWidth, tileWidth, tileWidth));
  assetDict["bottom_right_corner"] = bottom_right_corner;
  
  sf::Sprite bottom_left_corner(tileset_texture, sf::Rect<int>(0, 9*tileWidth, tileWidth, tileWidth));
  assetDict["bottom_left_corner"] = bottom_left_corner;
  
  sf::Sprite top_edge(tileset_texture, sf::Rect<int>(tileWidth*2, 0, tileWidth, tileWidth));
  assetDict["top_edge"] = top_edge;
  
  sf::Sprite left_edge(tileset_texture, sf::Rect<int>(0, tileWidth, tileWidth, tileWidth));
  assetDict["left_edge"] = left_edge;
  
  sf::Sprite inner_left_edge(tileset_texture, sf::Rect<int>(tileWidth*14, tileWidth, tileWidth, tileWidth));
  assetDict["inner_left_edge"] = inner_left_edge;
  
  sf::Sprite right_edge(tileset_texture, sf::Rect<int>(tileWidth*27, tileWidth, tileWidth, tileWidth));
  assetDict["right_edge"] = right_edge;
  
  sf::Sprite inner_right_edge(tileset_texture, sf::Rect<int>(tileWidth*13, tileWidth, tileWidth, tileWidth));
  assetDict["inner_right_edge"] = inner_right_edge;
  
  sf::Sprite bottom_edge(tileset_texture, sf::Rect<int>(tileWidth, 9*tileWidth, tileWidth, tileWidth));
  assetDict["bottom_edge"] = bottom_edge;
  
  // Weird tiles - the ones that form the base of the north, west and east peninsulas!
  sf::Sprite weird_north_left_corner(tileset_texture, sf::Rect<int>(tileWidth*13, 0, tileWidth, tileWidth));
  assetDict["weird_north_left_corner"] = weird_north_left_corner;
  
  sf::Sprite weird_west_upper_corner(tileset_texture, sf::Rect<int>(tileWidth*0, tileWidth*24, tileWidth, tileWidth));
  assetDict["weird_west_upper_corner"] = weird_west_upper_corner;
  
  sf::Sprite weird_west_lower_corner(tileset_texture, sf::Rect<int>(tileWidth*0, tileWidth*25, tileWidth, tileWidth));
  assetDict["weird_west_lower_corner"] = weird_west_lower_corner;
  
  sf::Sprite weird_east_upper_corner(tileset_texture, sf::Rect<int>(tileWidth*27, tileWidth*24, tileWidth, tileWidth));
  assetDict["weird_east_upper_corner"] = weird_east_upper_corner;
  
  sf::Sprite weird_east_lower_corner(tileset_texture, sf::Rect<int>(tileWidth*27, tileWidth*25, tileWidth, tileWidth));
  assetDict["weird_east_lower_corner"] = weird_east_lower_corner;
  
  sf::Sprite weird_north_right_corner(tileset_texture, sf::Rect<int>(tileWidth*14, 0, tileWidth, tileWidth));
  assetDict["weird_north_right_corner"] = weird_north_right_corner;
  
  sf::Sprite weird_right_corner(tileset_texture, sf::Rect<int>(tileWidth*22, tileWidth*13, tileWidth, tileWidth));
  
  sf::Sprite weird_left_corner(tileset_texture, sf::Rect<int>(tileWidth*5, tileWidth*13, tileWidth, tileWidth));
  
  // Box tiles!
  sf::Sprite box_top_edge(tileset_texture, sf::Rect<int>(tileWidth*4, tileWidth*2, tileWidth, tileWidth));
  assetDict["box_top_edge"] = box_top_edge;
  
  sf::Sprite box_top_left_corner(tileset_texture, sf::Rect<int>(tileWidth*2, tileWidth*2, tileWidth, tileWidth));
  assetDict["box_top_left_corner"] = box_top_left_corner;
  
  sf::Sprite box_top_right_corner(tileset_texture, sf::Rect<int>(tileWidth*5, tileWidth*2, tileWidth, tileWidth));
  assetDict["box_top_right_corner"] = box_top_right_corner;
  
  sf::Sprite box_bottom_edge(tileset_texture, sf::Rect<int>(tileWidth*4, tileWidth*4, tileWidth, tileWidth));
  assetDict["box_bottom_edge"] = box_bottom_edge;
  
  sf::Sprite box_bottom_right_corner(tileset_texture, sf::Rect<int>(tileWidth*5, tileWidth*4, tileWidth, tileWidth));
  assetDict["box_bottom_right_corner"] = box_bottom_right_corner;
  
  sf::Sprite box_bottom_left_corner(tileset_texture, sf::Rect<int>(tileWidth*2, tileWidth*4, tileWidth, tileWidth));
  assetDict["box_bottom_left_corner"] = box_bottom_left_corner;
  
  // House tiles!
  sf::Sprite house_top_right_corner(tileset_texture, sf::Rect<int>(tileWidth*10, tileWidth*12, tileWidth, tileWidth));
  assetDict["house_top_right_corner"] = house_top_right_corner;
  
  sf::Sprite house_bottom_right_corner(tileset_texture, sf::Rect<int>(tileWidth*17, tileWidth*16, tileWidth, tileWidth));
  assetDict["house_bottom_right_corner"] = house_bottom_right_corner;
  
  sf::Sprite house_top_left_corner(tileset_texture, sf::Rect<int>(tileWidth*17, tileWidth*12, tileWidth, tileWidth));
  assetDict["house_top_left_corner"] = house_top_left_corner;
  
  sf::Sprite house_bottom_left_corner(tileset_texture, sf::Rect<int>(tileWidth*10, tileWidth*16, tileWidth, tileWidth));
  assetDict["house_bottom_left_corner"] = house_bottom_left_corner;
  
  sf::Sprite door(tileset_texture, sf::Rect<int>(tileWidth*13, tileWidth*12, tileWidth, tileWidth));
  assetDict["door"] = door;
  
  sf::Sprite floor(tileset_texture, sf::Rect<int>(30*tileWidth, tileWidth, tileWidth, tileWidth));
  assetDict["floor"] = floor;

  return assetDict;
}