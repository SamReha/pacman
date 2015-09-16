#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"
#include "AssetManager.hpp"
#include "map.hpp"
#include "pacman.hpp"
#include "pinky.hpp"
#include "blinky.hpp"
#include "inky.hpp"
#include "sue.hpp"

const int TILE_WIDTH = 24;
const int FRAME_RATE = 60;

void drawMap(sf::RenderWindow* window, Map map);

int main(int, char const**)
{
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(TILE_WIDTH*28, TILE_WIDTH*31), "PAC MAN");
  window.setFramerateLimit(FRAME_RATE);
  
  // Set the Icon
  sf::Image icon;
  if (!icon.loadFromFile(resourcePath() + "icon.png")) {
    return EXIT_FAILURE;
  }
  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
  
  // Try to open the given texture
  sf::Texture tileset_texture;
  if (!tileset_texture.loadFromFile(resourcePath() + "data/full_texture_x3.png")) {
    return EXIT_FAILURE;
  }
  
  // More importantly, let's generate our tileset from that texture.
  AssetManager assetManager(TILE_WIDTH);
  std::map<sf::String, sf::Sprite> spriteSet = assetManager.generateSpriteSet(&tileset_texture);
  std::map<sf::String, PacTile*> tileSet;

  PacTile outer_top_left_corner(spriteSet["outer_top_left_corner"], "WALL");
  tileSet["outer_top_left_corner"] = &outer_top_left_corner;
  
  PacTile weird_north_left_corner(spriteSet["weird_north_left_corner"], "WALL");
  tileSet["weird_north_left_corner"] = &weird_north_left_corner;
  
  PacTile weird_west_upper_corner(spriteSet["weird_west_upper_corner"], "WALL");
  tileSet["weird_west_upper_corner"] = &weird_west_upper_corner;
  
  PacTile weird_east_upper_corner(spriteSet["weird_east_upper_corner"], "WALL");
  tileSet["weird_east_upper_corner"] = &weird_east_upper_corner;
  
  PacTile weird_west_lower_corner(spriteSet["weird_west_lower_corner"], "WALL");
  tileSet["weird_west_lower_corner"] = &weird_west_lower_corner;
  
  PacTile weird_east_lower_corner(spriteSet["weird_east_lower_corner"], "WALL");
  tileSet["weird_east_lower_corner"] = &weird_east_lower_corner;
  
  PacTile box_top_left_corner(spriteSet["box_top_left_corner"], "WALL");
  tileSet["box_top_left_corner"] = &box_top_left_corner;
  
  PacTile top_right_corner(spriteSet["top_right_corner"], "WALL");
  tileSet["top_right_corner"] = &top_right_corner;
  
  PacTile weird_north_right_corner(spriteSet["weird_north_right_corner"], "WALL");
  tileSet["weird_north_right_corner"] = &weird_north_right_corner;
  
  PacTile box_top_right_corner(spriteSet["box_top_right_corner"], "WALL");
  tileSet["box_top_right_corner"] = &box_top_right_corner;
  
  PacTile bottom_right_corner(spriteSet["bottom_right_corner"], "WALL");
  tileSet["bottom_right_corner"] = &bottom_right_corner;
  
  PacTile box_bottom_right_corner(spriteSet["box_bottom_right_corner"], "WALL");
  tileSet["box_bottom_right_corner"] = &box_bottom_right_corner;
  
  PacTile bottom_left_corner(spriteSet["bottom_left_corner"], "WALL");
  tileSet["bottom_left_corner"] = &bottom_left_corner;
  
  PacTile box_bottom_left_corner(spriteSet["box_bottom_left_corner"], "WALL");
  tileSet["box_bottom_left_corner"] = &box_bottom_left_corner;
  
  PacTile top_edge(spriteSet["top_edge"], "WALL");
  tileSet["top_edge"] = &top_edge;
  
  PacTile box_top_edge(spriteSet["box_top_edge"], "WALL");
  tileSet["box_top_edge"] = &box_top_edge;
  
  PacTile left_edge(spriteSet["left_edge"], "WALL");
  tileSet["left_edge"] = &left_edge;
  
  PacTile inner_left_edge(spriteSet["inner_left_edge"], "WALL");
  tileSet["inner_left_edge"] = &inner_left_edge;
  
  PacTile right_edge(spriteSet["right_edge"], "WALL");
  tileSet["right_edge"] = &right_edge;
  
  PacTile inner_right_edge(spriteSet["inner_right_edge"], "WALL");
  tileSet["inner_right_edge"] = &inner_right_edge;
  
  PacTile bottom_edge(spriteSet["bottom_edge"], "WALL");
  tileSet["bottom_edge"] = &bottom_edge;
  
  PacTile box_bottom_edge(spriteSet["box_bottom_edge"], "WALL");
  tileSet["box_bottom_edge"] = &box_bottom_edge;
  
  // House tiles!
  PacTile house_top_right_corner(spriteSet["house_top_right_corner"], "WALL");
  tileSet["house_top_right_corner"] = &house_top_right_corner;
  
  PacTile house_bottom_right_corner(spriteSet["house_bottom_right_corner"], "WALL");
  tileSet["house_bottom_right_corner"] = &house_bottom_right_corner;
  
  PacTile house_top_left_corner(spriteSet["house_top_left_corner"], "WALL");
  tileSet["house_top_left_corner"] = &house_top_left_corner;
  
  PacTile house_bottom_left_corner(spriteSet["house_bottom_left_corner"], "WALL");
  tileSet["house_bottom_left_corner"] = &house_bottom_left_corner;
  
  PacTile door(spriteSet["door"], "WALL");
  tileSet["door"] = &door;
  
  PacTile floor(spriteSet["floor"], "FLOOR");
  tileSet["floor"] = &floor;
  
  // Load up the map!
  Map map(sf::Vector2<double>(0, 0), sf::Vector2<int>(28, 31), TILE_WIDTH);
  map.configureMap(tileSet);
  
  // Create a graphical text to display
  sf::Font font;
  if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
    return EXIT_FAILURE;
  }
  sf::Text text("Hello SFML", font, 50);
  text.setColor(sf::Color::Black);

  // Load a music to play
  sf::Music music;
  if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
    return EXIT_FAILURE;
  }
  
  // Declare the ghosts!
  Pinky pinky(sf::Vector2<double>(0, 0), "HOME");
  Blinky blinky(sf::Vector2<double>(0, 0), "HOME");
  Inky inky(sf::Vector2<double>(0, 0), "HOME");
  Sue sue(sf::Vector2<double>(0, 0), "HOME");
  
  // Game variables
  // Variabes used to draw map
  
  // Assemble the PacMan!
  PacMan pacman(1, 1, 1, 24, map);
  std::vector<sf::Sprite> pacUpSprites;
  std::vector<sf::Sprite> pacDownSprites;
  std::vector<sf::Sprite> pacLeftSprites;
  std::vector<sf::Sprite> pacRightSprites;
  
  pacUpSprites.push_back(spriteSet["pacUp0"]);
  pacUpSprites.push_back(spriteSet["pacUp1"]);
  pacUpSprites.push_back(spriteSet["pacUp2"]);
  
  pacDownSprites.push_back(spriteSet["pacDown0"]);
  pacDownSprites.push_back(spriteSet["pacDown1"]);
  pacDownSprites.push_back(spriteSet["pacDown2"]);
  
  pacLeftSprites.push_back(spriteSet["pacLeft0"]);
  pacLeftSprites.push_back(spriteSet["pacLeft1"]);
  pacLeftSprites.push_back(spriteSet["pacLeft2"]);
  
  pacRightSprites.push_back(spriteSet["pacRight0"]);
  pacRightSprites.push_back(spriteSet["pacRight1"]);
  pacRightSprites.push_back(spriteSet["pacRight2"]);
  
  pacman.setUpSprites(pacUpSprites, 3);
  pacman.setDownSprites(pacDownSprites, 3);
  pacman.setLeftSprites(pacLeftSprites, 3);
  pacman.setRightSprites(pacRightSprites, 3);
  pacman.setVelocity(sf::Vector2<double>(0.0, 1.0));
  pacman.tryToMove("RIGHT");
  
  
  // Play the music
  // music.play();
  
  // Start the game loop
  while (window.isOpen()) {
    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
      // Close window: exit
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Escape pressed: exit
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        window.close();
      }
    }
    
    pacman.update(map);

    // DRAWING THE SCREEN
    // Clear screen
    window.clear();
    
    // Draw the map - logic is a bit messy
    drawMap(&window, map);
    
    // Then, draw any pellets / fruits, those type things
    
    // Then, draw the ghosts
    
    // Then, draw pacman
    window.draw(pacman.getSprite());
    
    // Update the window
    window.display();
  }

  return EXIT_SUCCESS;
}

void drawMap(sf::RenderWindow* window, Map map) {
  sf::Sprite tempSprite;
  sf::Vector2<double> mapAnchor = map.getAnchor();
  sf::Vector2<int> mapSize = map.getSize();
  PacTile tempTile(0);
  
  for (int i = 0; i < mapSize.x; i++) {
    for (int j = 0; j < mapSize.y; j++) {
      tempTile = *map.getTileAtIndex(sf::Vector2<int>(i, j));
      tempSprite = tempTile.getSprite();
      tempSprite.setPosition(mapAnchor.x + (i*map.getTileWidth()), mapAnchor.y + (j*map.getTileWidth()));
      window->draw(tempSprite);
    }
  }
}
