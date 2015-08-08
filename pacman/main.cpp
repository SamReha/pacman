#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"
#include "AssetManager.hpp"
#include "map.hpp"
#include "pinky.hpp"
#include "blinky.hpp"
#include "inky.hpp"
#include "sue.hpp"

const int TILE_WIDTH = 24;

int main(int, char const**)
{
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(TILE_WIDTH*28, TILE_WIDTH*31), "PAC MAN");
  
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
  std::map<sf::String, PacTile> tileSet;

  PacTile tlc(spriteSet["outer_top_left_corner"], "WALL");
  PacTile ilc(spriteSet["weird_north_left_corner"], "WALL");
  PacTile ilblc(spriteSet["weird_west_upper_corner"], "WALL");
  PacTile irbrc(spriteSet["weird_east_upper_corner"], "WALL");
  PacTile iltlc(spriteSet["weird_west_lower_corner"], "WALL");
  PacTile irtrc(spriteSet["weird_east_lower_corner"], "WALL");
  PacTile btlc(spriteSet["box_top_left_corner"], "WALL");
  PacTile trc(spriteSet["top_right_corner"], "WALL");
  PacTile irc(spriteSet["weird_north_right_corner"], "WALL");
  PacTile btrc(spriteSet["box_top_right_corner"], "WALL");
  PacTile brc(spriteSet["bottom_right_corner"], "WALL");
  PacTile bbrc(spriteSet["box_bottom_right_corner"], "WALL");
  PacTile blc(spriteSet["bottom_left_corner"], "WALL");
  PacTile bblc(spriteSet["box_bottom_left_corner"], "WALL");
  PacTile te(spriteSet["top_edge"], "WALL");
  PacTile bt(spriteSet["box_top_edge"], "WALL");
  PacTile le(spriteSet["left_edge"], "WALL");
  PacTile ile(spriteSet["inner_left_edge"], "WALL");
  PacTile re(spriteSet["right_edge"], "WALL");
  PacTile ire(spriteSet["inner_right_edge"], "WALL");
  PacTile be(spriteSet["bottom_edge"], "WALL");
  PacTile bb(spriteSet["box_bottom_edge"], "WALL");
  // House tiles!
  PacTile htrc(spriteSet["house_top_right_corner"], "WALL");
  PacTile hbrc(spriteSet["house_bottom_right_corner"], "WALL");
  PacTile htlc(spriteSet["house_top_left_corner"], "WALL");
  PacTile hblc(spriteSet["house_bottom_left_corner"], "WALL");
  PacTile d(spriteSet["door"], "WALL");
  PacTile f(spriteSet["floor"], "FLOOR");
  
  // Load up the map! - man, I wish I could push this off into the asset manager, but pointer logic is nightmarish
  Map map(sf::Vector2<double>(0, 0), sf::Vector2<int>(28, 31), TILE_WIDTH);
  
  map.setTile(sf::Vector2<int>(0, 0), &tlc);
  map.setTile(sf::Vector2<int>(1, 0), &te);
  map.setTile(sf::Vector2<int>(2, 0), &te);
  map.setTile(sf::Vector2<int>(3, 0), &te);
  map.setTile(sf::Vector2<int>(4, 0), &te);
  map.setTile(sf::Vector2<int>(5, 0), &te);
  map.setTile(sf::Vector2<int>(6, 0), &te);
  map.setTile(sf::Vector2<int>(7, 0), &te);
  map.setTile(sf::Vector2<int>(8, 0), &te);
  map.setTile(sf::Vector2<int>(9, 0), &te);
  map.setTile(sf::Vector2<int>(10, 0), &te);
  map.setTile(sf::Vector2<int>(11, 0), &te);
  map.setTile(sf::Vector2<int>(12, 0), &te);
  map.setTile(sf::Vector2<int>(13, 0), &ilc);
  map.setTile(sf::Vector2<int>(14, 0), &irc);
  map.setTile(sf::Vector2<int>(15, 0), &te);
  map.setTile(sf::Vector2<int>(16, 0), &te);
  map.setTile(sf::Vector2<int>(17, 0), &te);
  map.setTile(sf::Vector2<int>(18, 0), &te);
  map.setTile(sf::Vector2<int>(19, 0), &te);
  map.setTile(sf::Vector2<int>(20, 0), &te);
  map.setTile(sf::Vector2<int>(21, 0), &te);
  map.setTile(sf::Vector2<int>(22, 0), &te);
  map.setTile(sf::Vector2<int>(23, 0), &te);
  map.setTile(sf::Vector2<int>(24, 0), &te);
  map.setTile(sf::Vector2<int>(25, 0), &te);
  map.setTile(sf::Vector2<int>(26, 0), &te);
  map.setTile(sf::Vector2<int>(27, 0), &trc);
  
  map.setTile(sf::Vector2<int>(0, 1), &le);
  map.setTile(sf::Vector2<int>(1, 1), &f);
  map.setTile(sf::Vector2<int>(2, 1), &f);
  map.setTile(sf::Vector2<int>(3, 1), &f);
  map.setTile(sf::Vector2<int>(4, 1), &f);
  map.setTile(sf::Vector2<int>(5, 1), &f);
  map.setTile(sf::Vector2<int>(6, 1), &f);
  map.setTile(sf::Vector2<int>(7, 1), &f);
  map.setTile(sf::Vector2<int>(8, 1), &f);
  map.setTile(sf::Vector2<int>(9, 1), &f);
  map.setTile(sf::Vector2<int>(10, 1), &f);
  map.setTile(sf::Vector2<int>(11, 1), &f);
  map.setTile(sf::Vector2<int>(12, 1), &f);
  map.setTile(sf::Vector2<int>(13, 1), &ire);
  map.setTile(sf::Vector2<int>(14, 1), &ile);
  map.setTile(sf::Vector2<int>(15, 1), &f);
  map.setTile(sf::Vector2<int>(16, 1), &f);
  map.setTile(sf::Vector2<int>(17, 1), &f);
  map.setTile(sf::Vector2<int>(18, 1), &f);
  map.setTile(sf::Vector2<int>(19, 1), &f);
  map.setTile(sf::Vector2<int>(20, 1), &f);
  map.setTile(sf::Vector2<int>(21, 1), &f);
  map.setTile(sf::Vector2<int>(22, 1), &f);
  map.setTile(sf::Vector2<int>(23, 1), &f);
  map.setTile(sf::Vector2<int>(24, 1), &f);
  map.setTile(sf::Vector2<int>(25, 1), &f);
  map.setTile(sf::Vector2<int>(26, 1), &f);
  map.setTile(sf::Vector2<int>(27, 1), &re);
  
  map.setTile(sf::Vector2<int>(0, 2), &le);
  map.setTile(sf::Vector2<int>(1, 2), &f);
  map.setTile(sf::Vector2<int>(2, 2), &btlc);
  map.setTile(sf::Vector2<int>(3, 2), &bt);
  map.setTile(sf::Vector2<int>(4, 2), &bt);
  map.setTile(sf::Vector2<int>(5, 2), &btrc);
  map.setTile(sf::Vector2<int>(6, 2), &f);
  map.setTile(sf::Vector2<int>(7, 2), &btlc);
  map.setTile(sf::Vector2<int>(8, 2), &bt);
  map.setTile(sf::Vector2<int>(9, 2), &bt);
  map.setTile(sf::Vector2<int>(10, 2), &bt);
  map.setTile(sf::Vector2<int>(11, 2), &btrc);
  map.setTile(sf::Vector2<int>(12, 2), &f);
  map.setTile(sf::Vector2<int>(13, 2), &ire);
  map.setTile(sf::Vector2<int>(14, 2), &ile);
  map.setTile(sf::Vector2<int>(15, 2), &f);
  map.setTile(sf::Vector2<int>(16, 2), &btlc);
  map.setTile(sf::Vector2<int>(17, 2), &bt);
  map.setTile(sf::Vector2<int>(18, 2), &bt);
  map.setTile(sf::Vector2<int>(19, 2), &bt);
  map.setTile(sf::Vector2<int>(20, 2), &btrc);
  map.setTile(sf::Vector2<int>(21, 2), &f);
  map.setTile(sf::Vector2<int>(22, 2), &btlc);
  map.setTile(sf::Vector2<int>(23, 2), &bt);
  map.setTile(sf::Vector2<int>(24, 2), &bt);
  map.setTile(sf::Vector2<int>(25, 2), &btrc);
  map.setTile(sf::Vector2<int>(26, 2), &f);
  map.setTile(sf::Vector2<int>(27, 2), &re);
  
  map.setTile(sf::Vector2<int>(0, 3), &le);
  map.setTile(sf::Vector2<int>(1, 3), &f);
  map.setTile(sf::Vector2<int>(2, 3), &ire);
  map.setTile(sf::Vector2<int>(3, 3), &f);
  map.setTile(sf::Vector2<int>(4, 3), &f);
  map.setTile(sf::Vector2<int>(5, 3), &ile);
  map.setTile(sf::Vector2<int>(6, 3), &f);
  map.setTile(sf::Vector2<int>(7, 3), &ire);
  map.setTile(sf::Vector2<int>(8, 3), &f);
  map.setTile(sf::Vector2<int>(9, 3), &f);
  map.setTile(sf::Vector2<int>(10, 3), &f);
  map.setTile(sf::Vector2<int>(11, 3), &ile);
  map.setTile(sf::Vector2<int>(12, 3), &f);
  map.setTile(sf::Vector2<int>(13, 3), &ire);
  map.setTile(sf::Vector2<int>(14, 3), &ile);
  map.setTile(sf::Vector2<int>(15, 3), &f);
  map.setTile(sf::Vector2<int>(16, 3), &ire);
  map.setTile(sf::Vector2<int>(17, 3), &f);
  map.setTile(sf::Vector2<int>(18, 3), &f);
  map.setTile(sf::Vector2<int>(19, 3), &f);
  map.setTile(sf::Vector2<int>(20, 3), &ile);
  map.setTile(sf::Vector2<int>(21, 3), &f);
  map.setTile(sf::Vector2<int>(22, 3), &ire);
  map.setTile(sf::Vector2<int>(23, 3), &f);
  map.setTile(sf::Vector2<int>(24, 3), &f);
  map.setTile(sf::Vector2<int>(25, 3), &ile);
  map.setTile(sf::Vector2<int>(26, 3), &f);
  map.setTile(sf::Vector2<int>(27, 3), &re);
  
  map.setTile(sf::Vector2<int>(0, 4), &le);
  map.setTile(sf::Vector2<int>(1, 4), &f);
  map.setTile(sf::Vector2<int>(2, 4), &bblc);
  map.setTile(sf::Vector2<int>(3, 4), &bb);
  map.setTile(sf::Vector2<int>(4, 4), &bb);
  map.setTile(sf::Vector2<int>(5, 4), &bbrc);
  map.setTile(sf::Vector2<int>(6, 4), &f);
  map.setTile(sf::Vector2<int>(7, 4), &bblc);
  map.setTile(sf::Vector2<int>(8, 4), &bb);
  map.setTile(sf::Vector2<int>(9, 4), &bb);
  map.setTile(sf::Vector2<int>(10, 4), &bb);
  map.setTile(sf::Vector2<int>(11, 4), &bbrc);
  map.setTile(sf::Vector2<int>(12, 4), &f);
  map.setTile(sf::Vector2<int>(13, 4), &bblc);
  map.setTile(sf::Vector2<int>(14, 4), &bbrc);
  map.setTile(sf::Vector2<int>(15, 4), &f);
  map.setTile(sf::Vector2<int>(16, 4), &bblc);
  map.setTile(sf::Vector2<int>(17, 4), &bb);
  map.setTile(sf::Vector2<int>(18, 4), &bb);
  map.setTile(sf::Vector2<int>(19, 4), &bb);
  map.setTile(sf::Vector2<int>(20, 4), &bbrc);
  map.setTile(sf::Vector2<int>(21, 4), &f);
  map.setTile(sf::Vector2<int>(22, 4), &bblc);
  map.setTile(sf::Vector2<int>(23, 4), &bb);
  map.setTile(sf::Vector2<int>(24, 4), &bb);
  map.setTile(sf::Vector2<int>(25, 4), &bbrc);
  map.setTile(sf::Vector2<int>(26, 4), &f);
  map.setTile(sf::Vector2<int>(27, 4), &re);
  
  map.setTile(sf::Vector2<int>(0, 5), &le);
  map.setTile(sf::Vector2<int>(1, 5), &f);
  map.setTile(sf::Vector2<int>(2, 5), &f);
  map.setTile(sf::Vector2<int>(3, 5), &f);
  map.setTile(sf::Vector2<int>(4, 5), &f);
  map.setTile(sf::Vector2<int>(5, 5), &f);
  map.setTile(sf::Vector2<int>(6, 5), &f);
  map.setTile(sf::Vector2<int>(7, 5), &f);
  map.setTile(sf::Vector2<int>(8, 5), &f);
  map.setTile(sf::Vector2<int>(9, 5), &f);
  map.setTile(sf::Vector2<int>(10, 5), &f);
  map.setTile(sf::Vector2<int>(11, 5), &f);
  map.setTile(sf::Vector2<int>(12, 5), &f);
  map.setTile(sf::Vector2<int>(13, 5), &f);
  map.setTile(sf::Vector2<int>(14, 5), &f);
  map.setTile(sf::Vector2<int>(15, 5), &f);
  map.setTile(sf::Vector2<int>(16, 5), &f);
  map.setTile(sf::Vector2<int>(17, 5), &f);
  map.setTile(sf::Vector2<int>(18, 5), &f);
  map.setTile(sf::Vector2<int>(19, 5), &f);
  map.setTile(sf::Vector2<int>(20, 5), &f);
  map.setTile(sf::Vector2<int>(21, 5), &f);
  map.setTile(sf::Vector2<int>(22, 5), &f);
  map.setTile(sf::Vector2<int>(23, 5), &f);
  map.setTile(sf::Vector2<int>(24, 5), &f);
  map.setTile(sf::Vector2<int>(25, 5), &f);
  map.setTile(sf::Vector2<int>(26, 5), &f);
  map.setTile(sf::Vector2<int>(27, 5), &re);
  
  map.setTile(sf::Vector2<int>(0, 6), &le);
  map.setTile(sf::Vector2<int>(1, 6), &f);
  map.setTile(sf::Vector2<int>(2, 6), &btlc);
  map.setTile(sf::Vector2<int>(3, 6), &bt);
  map.setTile(sf::Vector2<int>(4, 6), &bt);
  map.setTile(sf::Vector2<int>(5, 6), &btrc);
  map.setTile(sf::Vector2<int>(6, 6), &f);
  map.setTile(sf::Vector2<int>(7, 6), &btlc);
  map.setTile(sf::Vector2<int>(8, 6), &btrc);
  map.setTile(sf::Vector2<int>(9, 6), &f);
  map.setTile(sf::Vector2<int>(10, 6), &btlc);
  map.setTile(sf::Vector2<int>(11, 6), &bt);
  map.setTile(sf::Vector2<int>(12, 6), &bt);
  map.setTile(sf::Vector2<int>(13, 6), &bt);
  map.setTile(sf::Vector2<int>(14, 6), &bt);
  map.setTile(sf::Vector2<int>(15, 6), &bt);
  map.setTile(sf::Vector2<int>(16, 6), &bt);
  map.setTile(sf::Vector2<int>(17, 6), &btrc);
  map.setTile(sf::Vector2<int>(18, 6), &f);
  map.setTile(sf::Vector2<int>(19, 6), &btlc);
  map.setTile(sf::Vector2<int>(20, 6), &btrc);
  map.setTile(sf::Vector2<int>(21, 6), &f);
  map.setTile(sf::Vector2<int>(22, 6), &btlc);
  map.setTile(sf::Vector2<int>(23, 6), &bt);
  map.setTile(sf::Vector2<int>(24, 6), &bt);
  map.setTile(sf::Vector2<int>(25, 6), &btrc);
  map.setTile(sf::Vector2<int>(26, 6), &f);
  map.setTile(sf::Vector2<int>(27, 6), &re);
  
  map.setTile(sf::Vector2<int>(0, 7), &le);
  map.setTile(sf::Vector2<int>(1, 7), &f);
  map.setTile(sf::Vector2<int>(2, 7), &bblc);
  map.setTile(sf::Vector2<int>(3, 7), &bb);
  map.setTile(sf::Vector2<int>(4, 7), &bb);
  map.setTile(sf::Vector2<int>(5, 7), &bbrc);
  map.setTile(sf::Vector2<int>(6, 7), &f);
  map.setTile(sf::Vector2<int>(7, 7), &ire);
  map.setTile(sf::Vector2<int>(8, 7), &ile);
  map.setTile(sf::Vector2<int>(9, 7), &f);
  map.setTile(sf::Vector2<int>(10, 7), &bblc);
  map.setTile(sf::Vector2<int>(11, 7), &bb);
  map.setTile(sf::Vector2<int>(12, 7), &bb);
  map.setTile(sf::Vector2<int>(13, 7), &btrc);
  map.setTile(sf::Vector2<int>(14, 7), &btlc);
  map.setTile(sf::Vector2<int>(15, 7), &bb);
  map.setTile(sf::Vector2<int>(16, 7), &bb);
  map.setTile(sf::Vector2<int>(17, 7), &bbrc);
  map.setTile(sf::Vector2<int>(18, 7), &f);
  map.setTile(sf::Vector2<int>(19, 7), &ire);
  map.setTile(sf::Vector2<int>(20, 7), &ile);
  map.setTile(sf::Vector2<int>(21, 7), &f);
  map.setTile(sf::Vector2<int>(22, 7), &bblc);
  map.setTile(sf::Vector2<int>(23, 7), &bb);
  map.setTile(sf::Vector2<int>(24, 7), &bb);
  map.setTile(sf::Vector2<int>(25, 7), &bbrc);
  map.setTile(sf::Vector2<int>(26, 7), &f);
  map.setTile(sf::Vector2<int>(27, 7), &re);
  
  map.setTile(sf::Vector2<int>(0, 8), &le);
  map.setTile(sf::Vector2<int>(1, 8), &f);
  map.setTile(sf::Vector2<int>(2, 8), &f);
  map.setTile(sf::Vector2<int>(3, 8), &f);
  map.setTile(sf::Vector2<int>(4, 8), &f);
  map.setTile(sf::Vector2<int>(5, 8), &f);
  map.setTile(sf::Vector2<int>(6, 8), &f);
  map.setTile(sf::Vector2<int>(7, 8), &ire);
  map.setTile(sf::Vector2<int>(8, 8), &ile);
  map.setTile(sf::Vector2<int>(9, 8), &f);
  map.setTile(sf::Vector2<int>(10, 8), &f);
  map.setTile(sf::Vector2<int>(11, 8), &f);
  map.setTile(sf::Vector2<int>(12, 8), &f);
  map.setTile(sf::Vector2<int>(13, 8), &ire);
  map.setTile(sf::Vector2<int>(14, 8), &ile);
  map.setTile(sf::Vector2<int>(15, 8), &f);
  map.setTile(sf::Vector2<int>(16, 8), &f);
  map.setTile(sf::Vector2<int>(17, 8), &f);
  map.setTile(sf::Vector2<int>(18, 8), &f);
  map.setTile(sf::Vector2<int>(19, 8), &ire);
  map.setTile(sf::Vector2<int>(20, 8), &ile);
  map.setTile(sf::Vector2<int>(21, 8), &f);
  map.setTile(sf::Vector2<int>(22, 8), &f);
  map.setTile(sf::Vector2<int>(23, 8), &f);
  map.setTile(sf::Vector2<int>(24, 8), &f);
  map.setTile(sf::Vector2<int>(25, 8), &f);
  map.setTile(sf::Vector2<int>(26, 8), &f);
  map.setTile(sf::Vector2<int>(27, 8), &re);
  
  map.setTile(sf::Vector2<int>(0, 9), &blc);
  map.setTile(sf::Vector2<int>(1, 9), &be);
  map.setTile(sf::Vector2<int>(2, 9), &be);
  map.setTile(sf::Vector2<int>(3, 9), &be);
  map.setTile(sf::Vector2<int>(4, 9), &be);
  map.setTile(sf::Vector2<int>(5, 9), &btrc);
  map.setTile(sf::Vector2<int>(6, 9), &f);
  map.setTile(sf::Vector2<int>(7, 9), &ire);
  map.setTile(sf::Vector2<int>(8, 9), &bblc);
  map.setTile(sf::Vector2<int>(9, 9), &bb);
  map.setTile(sf::Vector2<int>(10, 9), &bb);
  map.setTile(sf::Vector2<int>(11, 9), &btrc);
  map.setTile(sf::Vector2<int>(12, 9), &f);
  map.setTile(sf::Vector2<int>(13, 9), &ire);
  map.setTile(sf::Vector2<int>(14, 9), &ile);
  map.setTile(sf::Vector2<int>(15, 9), &f);
  map.setTile(sf::Vector2<int>(16, 9), &btlc);
  map.setTile(sf::Vector2<int>(17, 9), &bb);
  map.setTile(sf::Vector2<int>(18, 9), &bb);
  map.setTile(sf::Vector2<int>(19, 9), &bbrc);
  map.setTile(sf::Vector2<int>(20, 9), &ile);
  map.setTile(sf::Vector2<int>(21, 9), &f);
  map.setTile(sf::Vector2<int>(22, 9), &btlc);
  map.setTile(sf::Vector2<int>(23, 9), &be);
  map.setTile(sf::Vector2<int>(24, 9), &be);
  map.setTile(sf::Vector2<int>(25, 9), &be);
  map.setTile(sf::Vector2<int>(26, 9), &be);
  map.setTile(sf::Vector2<int>(27, 9), &brc);
  
  map.setTile(sf::Vector2<int>(0, 10), &f);
  map.setTile(sf::Vector2<int>(1, 10), &f);
  map.setTile(sf::Vector2<int>(2, 10), &f);
  map.setTile(sf::Vector2<int>(3, 10), &f);
  map.setTile(sf::Vector2<int>(4, 10), &f);
  map.setTile(sf::Vector2<int>(5, 10), &le);
  map.setTile(sf::Vector2<int>(6, 10), &f);
  map.setTile(sf::Vector2<int>(7, 10), &ire);
  map.setTile(sf::Vector2<int>(8, 10), &btlc);
  map.setTile(sf::Vector2<int>(9, 10), &bt);
  map.setTile(sf::Vector2<int>(10, 10), &bt);
  map.setTile(sf::Vector2<int>(11, 10), &bbrc);
  map.setTile(sf::Vector2<int>(12, 10), &f);
  map.setTile(sf::Vector2<int>(13, 10), &bblc);
  map.setTile(sf::Vector2<int>(14, 10), &bbrc);
  map.setTile(sf::Vector2<int>(15, 10), &f);
  map.setTile(sf::Vector2<int>(16, 10), &bblc);
  map.setTile(sf::Vector2<int>(17, 10), &bt);
  map.setTile(sf::Vector2<int>(18, 10), &bt);
  map.setTile(sf::Vector2<int>(19, 10), &btrc);
  map.setTile(sf::Vector2<int>(20, 10), &ile);
  map.setTile(sf::Vector2<int>(21, 10), &f);
  map.setTile(sf::Vector2<int>(22, 10), &re);
  map.setTile(sf::Vector2<int>(23, 10), &f);
  map.setTile(sf::Vector2<int>(24, 10), &f);
  map.setTile(sf::Vector2<int>(25, 10), &f);
  map.setTile(sf::Vector2<int>(26, 10), &f);
  map.setTile(sf::Vector2<int>(27, 10), &f);
  
  map.setTile(sf::Vector2<int>(0, 11), &f);
  map.setTile(sf::Vector2<int>(1, 11), &f);
  map.setTile(sf::Vector2<int>(2, 11), &f);
  map.setTile(sf::Vector2<int>(3, 11), &f);
  map.setTile(sf::Vector2<int>(4, 11), &f);
  map.setTile(sf::Vector2<int>(5, 11), &le);
  map.setTile(sf::Vector2<int>(6, 11), &f);
  map.setTile(sf::Vector2<int>(7, 11), &ire);
  map.setTile(sf::Vector2<int>(8, 11), &ile);
  map.setTile(sf::Vector2<int>(9, 11), &f);
  map.setTile(sf::Vector2<int>(10, 11), &f);
  map.setTile(sf::Vector2<int>(11, 11), &f);
  map.setTile(sf::Vector2<int>(12, 11), &f);
  map.setTile(sf::Vector2<int>(13, 11), &f);
  map.setTile(sf::Vector2<int>(14, 11), &f);
  map.setTile(sf::Vector2<int>(15, 11), &f);
  map.setTile(sf::Vector2<int>(16, 11), &f);
  map.setTile(sf::Vector2<int>(17, 11), &f);
  map.setTile(sf::Vector2<int>(18, 11), &f);
  map.setTile(sf::Vector2<int>(19, 11), &ire);
  map.setTile(sf::Vector2<int>(20, 11), &ile);
  map.setTile(sf::Vector2<int>(21, 11), &f);
  map.setTile(sf::Vector2<int>(22, 11), &re);
  map.setTile(sf::Vector2<int>(23, 11), &f);
  map.setTile(sf::Vector2<int>(24, 11), &f);
  map.setTile(sf::Vector2<int>(25, 11), &f);
  map.setTile(sf::Vector2<int>(26, 11), &f);
  map.setTile(sf::Vector2<int>(27, 11), &f);
  
  map.setTile(sf::Vector2<int>(0, 12), &f);
  map.setTile(sf::Vector2<int>(1, 12), &f);
  map.setTile(sf::Vector2<int>(2, 12), &f);
  map.setTile(sf::Vector2<int>(3, 12), &f);
  map.setTile(sf::Vector2<int>(4, 12), &f);
  map.setTile(sf::Vector2<int>(5, 12), &le);
  map.setTile(sf::Vector2<int>(6, 12), &f);
  map.setTile(sf::Vector2<int>(7, 12), &ire);
  map.setTile(sf::Vector2<int>(8, 12), &ile);
  map.setTile(sf::Vector2<int>(9, 12), &f);
  map.setTile(sf::Vector2<int>(10, 12), &htrc);
  map.setTile(sf::Vector2<int>(11, 12), &be);
  map.setTile(sf::Vector2<int>(12, 12), &be);
  map.setTile(sf::Vector2<int>(13, 12), &d);
  map.setTile(sf::Vector2<int>(14, 12), &d);
  map.setTile(sf::Vector2<int>(15, 12), &be);
  map.setTile(sf::Vector2<int>(16, 12), &be);
  map.setTile(sf::Vector2<int>(17, 12), &htlc);
  map.setTile(sf::Vector2<int>(18, 12), &f);
  map.setTile(sf::Vector2<int>(19, 12), &ire);
  map.setTile(sf::Vector2<int>(20, 12), &ile);
  map.setTile(sf::Vector2<int>(21, 12), &f);
  map.setTile(sf::Vector2<int>(22, 12), &re);
  map.setTile(sf::Vector2<int>(23, 12), &f);
  map.setTile(sf::Vector2<int>(24, 12), &f);
  map.setTile(sf::Vector2<int>(25, 12), &f);
  map.setTile(sf::Vector2<int>(26, 12), &f);
  map.setTile(sf::Vector2<int>(27, 12), &f);
  
  map.setTile(sf::Vector2<int>(0, 13), &te);
  map.setTile(sf::Vector2<int>(1, 13), &te);
  map.setTile(sf::Vector2<int>(2, 13), &te);
  map.setTile(sf::Vector2<int>(3, 13), &te);
  map.setTile(sf::Vector2<int>(4, 13), &te);
  map.setTile(sf::Vector2<int>(5, 13), &bbrc);
  map.setTile(sf::Vector2<int>(6, 13), &f);
  map.setTile(sf::Vector2<int>(7, 13), &bblc);
  map.setTile(sf::Vector2<int>(8, 13), &bbrc);
  map.setTile(sf::Vector2<int>(9, 13), &f);
  map.setTile(sf::Vector2<int>(10, 13), &re);
  map.setTile(sf::Vector2<int>(11, 13), &f);
  map.setTile(sf::Vector2<int>(12, 13), &f);
  map.setTile(sf::Vector2<int>(13, 13), &f);
  map.setTile(sf::Vector2<int>(14, 13), &f);
  map.setTile(sf::Vector2<int>(15, 13), &f);
  map.setTile(sf::Vector2<int>(16, 13), &f);
  map.setTile(sf::Vector2<int>(17, 13), &le);
  map.setTile(sf::Vector2<int>(18, 13), &f);
  map.setTile(sf::Vector2<int>(19, 13), &bblc);
  map.setTile(sf::Vector2<int>(20, 13), &bbrc);
  map.setTile(sf::Vector2<int>(21, 13), &f);
  map.setTile(sf::Vector2<int>(22, 13), &bblc);
  map.setTile(sf::Vector2<int>(23, 13), &te);
  map.setTile(sf::Vector2<int>(24, 13), &te);
  map.setTile(sf::Vector2<int>(25, 13), &te);
  map.setTile(sf::Vector2<int>(26, 13), &te);
  map.setTile(sf::Vector2<int>(27, 13), &te);
  
  map.setTile(sf::Vector2<int>(0, 14), &f);
  map.setTile(sf::Vector2<int>(1, 14), &f);
  map.setTile(sf::Vector2<int>(2, 14), &f);
  map.setTile(sf::Vector2<int>(3, 14), &f);
  map.setTile(sf::Vector2<int>(4, 14), &f);
  map.setTile(sf::Vector2<int>(5, 14), &f);
  map.setTile(sf::Vector2<int>(6, 14), &f);
  map.setTile(sf::Vector2<int>(7, 14), &f);
  map.setTile(sf::Vector2<int>(8, 14), &f);
  map.setTile(sf::Vector2<int>(9, 14), &f);
  map.setTile(sf::Vector2<int>(10, 14), &re);
  map.setTile(sf::Vector2<int>(11, 14), &f);
  map.setTile(sf::Vector2<int>(12, 14), &f);
  map.setTile(sf::Vector2<int>(13, 14), &f);
  map.setTile(sf::Vector2<int>(14, 14), &f);
  map.setTile(sf::Vector2<int>(15, 14), &f);
  map.setTile(sf::Vector2<int>(16, 14), &f);
  map.setTile(sf::Vector2<int>(17, 14), &le);
  map.setTile(sf::Vector2<int>(18, 14), &f);
  map.setTile(sf::Vector2<int>(19, 14), &f);
  map.setTile(sf::Vector2<int>(20, 14), &f);
  map.setTile(sf::Vector2<int>(21, 14), &f);
  map.setTile(sf::Vector2<int>(22, 14), &f);
  map.setTile(sf::Vector2<int>(23, 14), &f);
  map.setTile(sf::Vector2<int>(24, 14), &f);
  map.setTile(sf::Vector2<int>(25, 14), &f);
  map.setTile(sf::Vector2<int>(26, 14), &f);
  map.setTile(sf::Vector2<int>(27, 14), &f);
  
  map.setTile(sf::Vector2<int>(0, 15), &be);
  map.setTile(sf::Vector2<int>(1, 15), &be);
  map.setTile(sf::Vector2<int>(2, 15), &be);
  map.setTile(sf::Vector2<int>(3, 15), &be);
  map.setTile(sf::Vector2<int>(4, 15), &be);
  map.setTile(sf::Vector2<int>(5, 15), &btrc);
  map.setTile(sf::Vector2<int>(6, 15), &f);
  map.setTile(sf::Vector2<int>(7, 15), &btlc);
  map.setTile(sf::Vector2<int>(8, 15), &btrc);
  map.setTile(sf::Vector2<int>(9, 15), &f);
  map.setTile(sf::Vector2<int>(10, 15), &re);
  map.setTile(sf::Vector2<int>(11, 15), &f);
  map.setTile(sf::Vector2<int>(12, 15), &f);
  map.setTile(sf::Vector2<int>(13, 15), &f);
  map.setTile(sf::Vector2<int>(14, 15), &f);
  map.setTile(sf::Vector2<int>(15, 15), &f);
  map.setTile(sf::Vector2<int>(16, 15), &f);
  map.setTile(sf::Vector2<int>(17, 15), &le);
  map.setTile(sf::Vector2<int>(18, 15), &f);
  map.setTile(sf::Vector2<int>(19, 15), &btlc);
  map.setTile(sf::Vector2<int>(20, 15), &btrc);
  map.setTile(sf::Vector2<int>(21, 15), &f);
  map.setTile(sf::Vector2<int>(22, 15), &btlc);
  map.setTile(sf::Vector2<int>(23, 15), &be);
  map.setTile(sf::Vector2<int>(24, 15), &be);
  map.setTile(sf::Vector2<int>(25, 15), &be);
  map.setTile(sf::Vector2<int>(26, 15), &be);
  map.setTile(sf::Vector2<int>(27, 15), &be);
  
  map.setTile(sf::Vector2<int>(0, 16), &f);
  map.setTile(sf::Vector2<int>(1, 16), &f);
  map.setTile(sf::Vector2<int>(2, 16), &f);
  map.setTile(sf::Vector2<int>(3, 16), &f);
  map.setTile(sf::Vector2<int>(4, 16), &f);
  map.setTile(sf::Vector2<int>(5, 16), &le);
  map.setTile(sf::Vector2<int>(6, 16), &f);
  map.setTile(sf::Vector2<int>(7, 16), &ire);
  map.setTile(sf::Vector2<int>(8, 16), &ile);
  map.setTile(sf::Vector2<int>(9, 16), &f);
  map.setTile(sf::Vector2<int>(10, 16), &hblc);
  map.setTile(sf::Vector2<int>(11, 16), &te);
  map.setTile(sf::Vector2<int>(12, 16), &te);
  map.setTile(sf::Vector2<int>(13, 16), &te);
  map.setTile(sf::Vector2<int>(14, 16), &te);
  map.setTile(sf::Vector2<int>(15, 16), &te);
  map.setTile(sf::Vector2<int>(16, 16), &te);
  map.setTile(sf::Vector2<int>(17, 16), &hbrc);
  map.setTile(sf::Vector2<int>(18, 16), &f);
  map.setTile(sf::Vector2<int>(19, 16), &ire);
  map.setTile(sf::Vector2<int>(20, 16), &ile);
  map.setTile(sf::Vector2<int>(21, 16), &f);
  map.setTile(sf::Vector2<int>(22, 16), &re);
  map.setTile(sf::Vector2<int>(23, 16), &f);
  map.setTile(sf::Vector2<int>(24, 16), &f);
  map.setTile(sf::Vector2<int>(25, 16), &f);
  map.setTile(sf::Vector2<int>(26, 16), &f);
  map.setTile(sf::Vector2<int>(27, 16), &f);
  
  map.setTile(sf::Vector2<int>(0, 17), &f);
  map.setTile(sf::Vector2<int>(1, 17), &f);
  map.setTile(sf::Vector2<int>(2, 17), &f);
  map.setTile(sf::Vector2<int>(3, 17), &f);
  map.setTile(sf::Vector2<int>(4, 17), &f);
  map.setTile(sf::Vector2<int>(5, 17), &le);
  map.setTile(sf::Vector2<int>(6, 17), &f);
  map.setTile(sf::Vector2<int>(7, 17), &ire);
  map.setTile(sf::Vector2<int>(8, 17), &ile);
  map.setTile(sf::Vector2<int>(9, 17), &f);
  map.setTile(sf::Vector2<int>(10, 17), &f);
  map.setTile(sf::Vector2<int>(11, 17), &f);
  map.setTile(sf::Vector2<int>(12, 17), &f);
  map.setTile(sf::Vector2<int>(13, 17), &f);
  map.setTile(sf::Vector2<int>(14, 17), &f);
  map.setTile(sf::Vector2<int>(15, 17), &f);
  map.setTile(sf::Vector2<int>(16, 17), &f);
  map.setTile(sf::Vector2<int>(17, 17), &f);
  map.setTile(sf::Vector2<int>(18, 17), &f);
  map.setTile(sf::Vector2<int>(19, 17), &ire);
  map.setTile(sf::Vector2<int>(20, 17), &ile);
  map.setTile(sf::Vector2<int>(21, 17), &f);
  map.setTile(sf::Vector2<int>(22, 17), &re);
  map.setTile(sf::Vector2<int>(23, 17), &f);
  map.setTile(sf::Vector2<int>(24, 17), &f);
  map.setTile(sf::Vector2<int>(25, 17), &f);
  map.setTile(sf::Vector2<int>(26, 17), &f);
  map.setTile(sf::Vector2<int>(27, 17), &f);
  
  map.setTile(sf::Vector2<int>(0, 18), &f);
  map.setTile(sf::Vector2<int>(1, 18), &f);
  map.setTile(sf::Vector2<int>(2, 18), &f);
  map.setTile(sf::Vector2<int>(3, 18), &f);
  map.setTile(sf::Vector2<int>(4, 18), &f);
  map.setTile(sf::Vector2<int>(5, 18), &le);
  map.setTile(sf::Vector2<int>(6, 18), &f);
  map.setTile(sf::Vector2<int>(7, 18), &ire);
  map.setTile(sf::Vector2<int>(8, 18), &ile);
  map.setTile(sf::Vector2<int>(9, 18), &f);
  map.setTile(sf::Vector2<int>(10, 18), &btlc);
  map.setTile(sf::Vector2<int>(11, 18), &bt);
  map.setTile(sf::Vector2<int>(12, 18), &bt);
  map.setTile(sf::Vector2<int>(13, 18), &bt);
  map.setTile(sf::Vector2<int>(14, 18), &bt);
  map.setTile(sf::Vector2<int>(15, 18), &bt);
  map.setTile(sf::Vector2<int>(16, 18), &bt);
  map.setTile(sf::Vector2<int>(17, 18), &btrc);
  map.setTile(sf::Vector2<int>(18, 18), &f);
  map.setTile(sf::Vector2<int>(19, 18), &ire);
  map.setTile(sf::Vector2<int>(20, 18), &ile);
  map.setTile(sf::Vector2<int>(21, 18), &f);
  map.setTile(sf::Vector2<int>(22, 18), &re);
  map.setTile(sf::Vector2<int>(23, 18), &f);
  map.setTile(sf::Vector2<int>(24, 18), &f);
  map.setTile(sf::Vector2<int>(25, 18), &f);
  map.setTile(sf::Vector2<int>(26, 18), &f);
  map.setTile(sf::Vector2<int>(27, 18), &f);
  
  map.setTile(sf::Vector2<int>(0, 19), &tlc);
  map.setTile(sf::Vector2<int>(1, 19), &te);
  map.setTile(sf::Vector2<int>(2, 19), &te);
  map.setTile(sf::Vector2<int>(3, 19), &te);
  map.setTile(sf::Vector2<int>(4, 19), &te);
  map.setTile(sf::Vector2<int>(5, 19), &bbrc);
  map.setTile(sf::Vector2<int>(6, 19), &f);
  map.setTile(sf::Vector2<int>(7, 19), &bblc);
  map.setTile(sf::Vector2<int>(8, 19), &bbrc);
  map.setTile(sf::Vector2<int>(9, 19), &f);
  map.setTile(sf::Vector2<int>(10, 19), &bblc);
  map.setTile(sf::Vector2<int>(11, 19), &bb);
  map.setTile(sf::Vector2<int>(12, 19), &bb);
  map.setTile(sf::Vector2<int>(13, 19), &btrc);
  map.setTile(sf::Vector2<int>(14, 19), &btlc);
  map.setTile(sf::Vector2<int>(15, 19), &bb);
  map.setTile(sf::Vector2<int>(16, 19), &bb);
  map.setTile(sf::Vector2<int>(17, 19), &bbrc);
  map.setTile(sf::Vector2<int>(18, 19), &f);
  map.setTile(sf::Vector2<int>(19, 19), &bblc);
  map.setTile(sf::Vector2<int>(20, 19), &bbrc);
  map.setTile(sf::Vector2<int>(21, 19), &f);
  map.setTile(sf::Vector2<int>(22, 19), &bblc);
  map.setTile(sf::Vector2<int>(23, 19), &te);
  map.setTile(sf::Vector2<int>(24, 19), &te);
  map.setTile(sf::Vector2<int>(25, 19), &te);
  map.setTile(sf::Vector2<int>(26, 19), &te);
  map.setTile(sf::Vector2<int>(27, 19), &trc);
  
  map.setTile(sf::Vector2<int>(0, 20), &le);
  map.setTile(sf::Vector2<int>(1, 20), &f);
  map.setTile(sf::Vector2<int>(2, 20), &f);
  map.setTile(sf::Vector2<int>(3, 20), &f);
  map.setTile(sf::Vector2<int>(4, 20), &f);
  map.setTile(sf::Vector2<int>(5, 20), &f);
  map.setTile(sf::Vector2<int>(6, 20), &f);
  map.setTile(sf::Vector2<int>(7, 20), &f);
  map.setTile(sf::Vector2<int>(8, 20), &f);
  map.setTile(sf::Vector2<int>(9, 20), &f);
  map.setTile(sf::Vector2<int>(10, 20), &f);
  map.setTile(sf::Vector2<int>(11, 20), &f);
  map.setTile(sf::Vector2<int>(12, 20), &f);
  map.setTile(sf::Vector2<int>(13, 20), &ire);
  map.setTile(sf::Vector2<int>(14, 20), &ile);
  map.setTile(sf::Vector2<int>(15, 20), &f);
  map.setTile(sf::Vector2<int>(16, 20), &f);
  map.setTile(sf::Vector2<int>(17, 20), &f);
  map.setTile(sf::Vector2<int>(18, 20), &f);
  map.setTile(sf::Vector2<int>(19, 20), &f);
  map.setTile(sf::Vector2<int>(20, 20), &f);
  map.setTile(sf::Vector2<int>(21, 20), &f);
  map.setTile(sf::Vector2<int>(22, 20), &f);
  map.setTile(sf::Vector2<int>(23, 20), &f);
  map.setTile(sf::Vector2<int>(24, 20), &f);
  map.setTile(sf::Vector2<int>(25, 20), &f);
  map.setTile(sf::Vector2<int>(26, 20), &f);
  map.setTile(sf::Vector2<int>(27, 20), &re);
  
  map.setTile(sf::Vector2<int>(0, 21), &le);
  map.setTile(sf::Vector2<int>(1, 21), &f);
  map.setTile(sf::Vector2<int>(2, 21), &btlc);
  map.setTile(sf::Vector2<int>(3, 21), &bt);
  map.setTile(sf::Vector2<int>(4, 21), &bt);
  map.setTile(sf::Vector2<int>(5, 21), &btrc);
  map.setTile(sf::Vector2<int>(6, 21), &f);
  map.setTile(sf::Vector2<int>(7, 21), &btlc);
  map.setTile(sf::Vector2<int>(8, 21), &bt);
  map.setTile(sf::Vector2<int>(9, 21), &bt);
  map.setTile(sf::Vector2<int>(10, 21), &bt);
  map.setTile(sf::Vector2<int>(11, 21), &btrc);
  map.setTile(sf::Vector2<int>(12, 21), &f);
  map.setTile(sf::Vector2<int>(13, 21), &ire);
  map.setTile(sf::Vector2<int>(14, 21), &ile);
  map.setTile(sf::Vector2<int>(15, 21), &f);
  map.setTile(sf::Vector2<int>(16, 21), &btlc);
  map.setTile(sf::Vector2<int>(17, 21), &bt);
  map.setTile(sf::Vector2<int>(18, 21), &bt);
  map.setTile(sf::Vector2<int>(19, 21), &bt);
  map.setTile(sf::Vector2<int>(20, 21), &btrc);
  map.setTile(sf::Vector2<int>(21, 21), &f);
  map.setTile(sf::Vector2<int>(22, 21), &btlc);
  map.setTile(sf::Vector2<int>(23, 21), &bt);
  map.setTile(sf::Vector2<int>(24, 21), &bt);
  map.setTile(sf::Vector2<int>(25, 21), &btrc);
  map.setTile(sf::Vector2<int>(26, 21), &f);
  map.setTile(sf::Vector2<int>(27, 21), &re);
  
  map.setTile(sf::Vector2<int>(0, 22), &le);
  map.setTile(sf::Vector2<int>(1, 22), &f);
  map.setTile(sf::Vector2<int>(2, 22), &bblc);
  map.setTile(sf::Vector2<int>(3, 22), &bb);
  map.setTile(sf::Vector2<int>(4, 22), &btrc);
  map.setTile(sf::Vector2<int>(5, 22), &ile);
  map.setTile(sf::Vector2<int>(6, 22), &f);
  map.setTile(sf::Vector2<int>(7, 22), &bblc);
  map.setTile(sf::Vector2<int>(8, 22), &bb);
  map.setTile(sf::Vector2<int>(9, 22), &bb);
  map.setTile(sf::Vector2<int>(10, 22), &bb);
  map.setTile(sf::Vector2<int>(11, 22), &bbrc);
  map.setTile(sf::Vector2<int>(12, 22), &f);
  map.setTile(sf::Vector2<int>(13, 22), &bblc);
  map.setTile(sf::Vector2<int>(14, 22), &bbrc);
  map.setTile(sf::Vector2<int>(15, 22), &f);
  map.setTile(sf::Vector2<int>(16, 22), &bblc);
  map.setTile(sf::Vector2<int>(17, 22), &bb);
  map.setTile(sf::Vector2<int>(18, 22), &bb);
  map.setTile(sf::Vector2<int>(19, 22), &bb);
  map.setTile(sf::Vector2<int>(20, 22), &bbrc);
  map.setTile(sf::Vector2<int>(21, 22), &f);
  map.setTile(sf::Vector2<int>(22, 22), &ire);
  map.setTile(sf::Vector2<int>(23, 22), &btlc);
  map.setTile(sf::Vector2<int>(24, 22), &bb);
  map.setTile(sf::Vector2<int>(25, 22), &bbrc);
  map.setTile(sf::Vector2<int>(26, 22), &f);
  map.setTile(sf::Vector2<int>(27, 22), &re);
  
  map.setTile(sf::Vector2<int>(0, 23), &le);
  map.setTile(sf::Vector2<int>(1, 23), &f);
  map.setTile(sf::Vector2<int>(2, 23), &f);
  map.setTile(sf::Vector2<int>(3, 23), &f);
  map.setTile(sf::Vector2<int>(4, 23), &ire);
  map.setTile(sf::Vector2<int>(5, 23), &ile);
  map.setTile(sf::Vector2<int>(6, 23), &f);
  map.setTile(sf::Vector2<int>(7, 23), &f);
  map.setTile(sf::Vector2<int>(8, 23), &f);
  map.setTile(sf::Vector2<int>(9, 23), &f);
  map.setTile(sf::Vector2<int>(10, 23), &f);
  map.setTile(sf::Vector2<int>(11, 23), &f);
  map.setTile(sf::Vector2<int>(12, 23), &f);
  map.setTile(sf::Vector2<int>(13, 23), &f);
  map.setTile(sf::Vector2<int>(14, 23), &f);
  map.setTile(sf::Vector2<int>(15, 23), &f);
  map.setTile(sf::Vector2<int>(16, 23), &f);
  map.setTile(sf::Vector2<int>(17, 23), &f);
  map.setTile(sf::Vector2<int>(18, 23), &f);
  map.setTile(sf::Vector2<int>(19, 23), &f);
  map.setTile(sf::Vector2<int>(20, 23), &f);
  map.setTile(sf::Vector2<int>(21, 23), &f);
  map.setTile(sf::Vector2<int>(22, 23), &ire);
  map.setTile(sf::Vector2<int>(23, 23), &ile);
  map.setTile(sf::Vector2<int>(24, 23), &f);
  map.setTile(sf::Vector2<int>(25, 23), &f);
  map.setTile(sf::Vector2<int>(26, 23), &f);
  map.setTile(sf::Vector2<int>(27, 23), &re);
  
  map.setTile(sf::Vector2<int>(0, 24), &ilblc);
  map.setTile(sf::Vector2<int>(1, 24), &bt);
  map.setTile(sf::Vector2<int>(2, 24), &btrc);
  map.setTile(sf::Vector2<int>(3, 24), &f);
  map.setTile(sf::Vector2<int>(4, 24), &ire);
  map.setTile(sf::Vector2<int>(5, 24), &ile);
  map.setTile(sf::Vector2<int>(6, 24), &f);
  map.setTile(sf::Vector2<int>(7, 24), &btlc);
  map.setTile(sf::Vector2<int>(8, 24), &btrc);
  map.setTile(sf::Vector2<int>(9, 24), &f);
  map.setTile(sf::Vector2<int>(10, 24), &btlc);
  map.setTile(sf::Vector2<int>(11, 24), &bt);
  map.setTile(sf::Vector2<int>(12, 24), &bt);
  map.setTile(sf::Vector2<int>(13, 24), &bt);
  map.setTile(sf::Vector2<int>(14, 24), &bt);
  map.setTile(sf::Vector2<int>(15, 24), &bt);
  map.setTile(sf::Vector2<int>(16, 24), &bt);
  map.setTile(sf::Vector2<int>(17, 24), &btrc);
  map.setTile(sf::Vector2<int>(18, 24), &f);
  map.setTile(sf::Vector2<int>(19, 24), &btlc);
  map.setTile(sf::Vector2<int>(20, 24), &btrc);
  map.setTile(sf::Vector2<int>(21, 24), &f);
  map.setTile(sf::Vector2<int>(22, 24), &ire);
  map.setTile(sf::Vector2<int>(23, 24), &ile);
  map.setTile(sf::Vector2<int>(24, 24), &f);
  map.setTile(sf::Vector2<int>(25, 24), &btlc);
  map.setTile(sf::Vector2<int>(26, 24), &bt);
  map.setTile(sf::Vector2<int>(27, 24), &irbrc);
  
  map.setTile(sf::Vector2<int>(0, 25), &iltlc);
  map.setTile(sf::Vector2<int>(1, 25), &bb);
  map.setTile(sf::Vector2<int>(2, 25), &bbrc);
  map.setTile(sf::Vector2<int>(3, 25), &f);
  map.setTile(sf::Vector2<int>(4, 25), &bblc);
  map.setTile(sf::Vector2<int>(5, 25), &bbrc);
  map.setTile(sf::Vector2<int>(6, 25), &f);
  map.setTile(sf::Vector2<int>(7, 25), &ire);
  map.setTile(sf::Vector2<int>(8, 25), &ile);
  map.setTile(sf::Vector2<int>(9, 25), &f);
  map.setTile(sf::Vector2<int>(10, 25), &bblc);
  map.setTile(sf::Vector2<int>(11, 25), &bb);
  map.setTile(sf::Vector2<int>(12, 25), &bb);
  map.setTile(sf::Vector2<int>(13, 25), &btrc);
  map.setTile(sf::Vector2<int>(14, 25), &btlc);
  map.setTile(sf::Vector2<int>(15, 25), &bb);
  map.setTile(sf::Vector2<int>(16, 25), &bb);
  map.setTile(sf::Vector2<int>(17, 25), &bbrc);
  map.setTile(sf::Vector2<int>(18, 25), &f);
  map.setTile(sf::Vector2<int>(19, 25), &ire);
  map.setTile(sf::Vector2<int>(20, 25), &ile);
  map.setTile(sf::Vector2<int>(21, 25), &f);
  map.setTile(sf::Vector2<int>(22, 25), &bblc);
  map.setTile(sf::Vector2<int>(23, 25), &bbrc);
  map.setTile(sf::Vector2<int>(24, 25), &f);
  map.setTile(sf::Vector2<int>(25, 25), &bblc);
  map.setTile(sf::Vector2<int>(26, 25), &bb);
  map.setTile(sf::Vector2<int>(27, 25), &irtrc);
  
  map.setTile(sf::Vector2<int>(0, 26), &le);
  map.setTile(sf::Vector2<int>(1, 26), &f);
  map.setTile(sf::Vector2<int>(2, 26), &f);
  map.setTile(sf::Vector2<int>(3, 26), &f);
  map.setTile(sf::Vector2<int>(4, 26), &f);
  map.setTile(sf::Vector2<int>(5, 26), &f);
  map.setTile(sf::Vector2<int>(6, 26), &f);
  map.setTile(sf::Vector2<int>(7, 26), &ire);
  map.setTile(sf::Vector2<int>(8, 26), &ile);
  map.setTile(sf::Vector2<int>(9, 26), &f);
  map.setTile(sf::Vector2<int>(10, 26), &f);
  map.setTile(sf::Vector2<int>(11, 26), &f);
  map.setTile(sf::Vector2<int>(12, 26), &f);
  map.setTile(sf::Vector2<int>(13, 26), &ire);
  map.setTile(sf::Vector2<int>(14, 26), &ile);
  map.setTile(sf::Vector2<int>(15, 26), &f);
  map.setTile(sf::Vector2<int>(16, 26), &f);
  map.setTile(sf::Vector2<int>(17, 26), &f);
  map.setTile(sf::Vector2<int>(18, 26), &f);
  map.setTile(sf::Vector2<int>(19, 26), &ire);
  map.setTile(sf::Vector2<int>(20, 26), &ile);
  map.setTile(sf::Vector2<int>(21, 26), &f);
  map.setTile(sf::Vector2<int>(22, 26), &f);
  map.setTile(sf::Vector2<int>(23, 26), &f);
  map.setTile(sf::Vector2<int>(24, 26), &f);
  map.setTile(sf::Vector2<int>(25, 26), &f);
  map.setTile(sf::Vector2<int>(26, 26), &f);
  map.setTile(sf::Vector2<int>(27, 26), &re);
  
  map.setTile(sf::Vector2<int>(0, 27), &le);
  map.setTile(sf::Vector2<int>(1, 27), &f);
  map.setTile(sf::Vector2<int>(2, 27), &btlc);
  map.setTile(sf::Vector2<int>(3, 27), &bt);
  map.setTile(sf::Vector2<int>(4, 27), &bt);
  map.setTile(sf::Vector2<int>(5, 27), &bt);
  map.setTile(sf::Vector2<int>(6, 27), &bt);
  map.setTile(sf::Vector2<int>(7, 27), &bbrc);
  map.setTile(sf::Vector2<int>(8, 27), &bblc);
  map.setTile(sf::Vector2<int>(9, 27), &bt);
  map.setTile(sf::Vector2<int>(10, 27), &bt);
  map.setTile(sf::Vector2<int>(11, 27), &btrc);
  map.setTile(sf::Vector2<int>(12, 27), &f);
  map.setTile(sf::Vector2<int>(13, 27), &ire);
  map.setTile(sf::Vector2<int>(14, 27), &ile);
  map.setTile(sf::Vector2<int>(15, 27), &f);
  map.setTile(sf::Vector2<int>(16, 27), &btlc);
  map.setTile(sf::Vector2<int>(17, 27), &bt);
  map.setTile(sf::Vector2<int>(18, 27), &bt);
  map.setTile(sf::Vector2<int>(19, 27), &bbrc);
  map.setTile(sf::Vector2<int>(20, 27), &bblc);
  map.setTile(sf::Vector2<int>(21, 27), &bt);
  map.setTile(sf::Vector2<int>(22, 27), &bt);
  map.setTile(sf::Vector2<int>(23, 27), &bt);
  map.setTile(sf::Vector2<int>(24, 27), &bt);
  map.setTile(sf::Vector2<int>(25, 27), &btrc);
  map.setTile(sf::Vector2<int>(26, 27), &f);
  map.setTile(sf::Vector2<int>(27, 27), &re);
  
  map.setTile(sf::Vector2<int>(0, 28), &le);
  map.setTile(sf::Vector2<int>(1, 28), &f);
  map.setTile(sf::Vector2<int>(2, 28), &bblc);
  map.setTile(sf::Vector2<int>(3, 28), &bb);
  map.setTile(sf::Vector2<int>(4, 28), &bb);
  map.setTile(sf::Vector2<int>(5, 28), &bb);
  map.setTile(sf::Vector2<int>(6, 28), &bb);
  map.setTile(sf::Vector2<int>(7, 28), &bb);
  map.setTile(sf::Vector2<int>(8, 28), &bb);
  map.setTile(sf::Vector2<int>(9, 28), &bb);
  map.setTile(sf::Vector2<int>(10, 28), &bb);
  map.setTile(sf::Vector2<int>(11, 28), &bbrc);
  map.setTile(sf::Vector2<int>(12, 28), &f);
  map.setTile(sf::Vector2<int>(13, 28), &bblc);
  map.setTile(sf::Vector2<int>(14, 28), &bbrc);
  map.setTile(sf::Vector2<int>(15, 28), &f);
  map.setTile(sf::Vector2<int>(16, 28), &bblc);
  map.setTile(sf::Vector2<int>(17, 28), &bb);
  map.setTile(sf::Vector2<int>(18, 28), &bb);
  map.setTile(sf::Vector2<int>(19, 28), &bb);
  map.setTile(sf::Vector2<int>(20, 28), &bb);
  map.setTile(sf::Vector2<int>(21, 28), &bb);
  map.setTile(sf::Vector2<int>(22, 28), &bb);
  map.setTile(sf::Vector2<int>(23, 28), &bb);
  map.setTile(sf::Vector2<int>(24, 28), &bb);
  map.setTile(sf::Vector2<int>(25, 28), &bbrc);
  map.setTile(sf::Vector2<int>(26, 28), &f);
  map.setTile(sf::Vector2<int>(27, 28), &re);
  
  map.setTile(sf::Vector2<int>(0, 29), &le);
  map.setTile(sf::Vector2<int>(1, 29), &f);
  map.setTile(sf::Vector2<int>(2, 29), &f);
  map.setTile(sf::Vector2<int>(3, 29), &f);
  map.setTile(sf::Vector2<int>(4, 29), &f);
  map.setTile(sf::Vector2<int>(5, 29), &f);
  map.setTile(sf::Vector2<int>(6, 29), &f);
  map.setTile(sf::Vector2<int>(7, 29), &f);
  map.setTile(sf::Vector2<int>(8, 29), &f);
  map.setTile(sf::Vector2<int>(9, 29), &f);
  map.setTile(sf::Vector2<int>(10, 29), &f);
  map.setTile(sf::Vector2<int>(11, 29), &f);
  map.setTile(sf::Vector2<int>(12, 29), &f);
  map.setTile(sf::Vector2<int>(13, 29), &f);
  map.setTile(sf::Vector2<int>(14, 29), &f);
  map.setTile(sf::Vector2<int>(15, 29), &f);
  map.setTile(sf::Vector2<int>(16, 29), &f);
  map.setTile(sf::Vector2<int>(17, 29), &f);
  map.setTile(sf::Vector2<int>(18, 29), &f);
  map.setTile(sf::Vector2<int>(19, 29), &f);
  map.setTile(sf::Vector2<int>(20, 29), &f);
  map.setTile(sf::Vector2<int>(21, 29), &f);
  map.setTile(sf::Vector2<int>(22, 29), &f);
  map.setTile(sf::Vector2<int>(23, 29), &f);
  map.setTile(sf::Vector2<int>(24, 29), &f);
  map.setTile(sf::Vector2<int>(25, 29), &f);
  map.setTile(sf::Vector2<int>(26, 29), &f);
  map.setTile(sf::Vector2<int>(27, 29), &re);
  
  map.setTile(sf::Vector2<int>(0, 30), &blc);
  map.setTile(sf::Vector2<int>(1, 30), &be);
  map.setTile(sf::Vector2<int>(2, 30), &be);
  map.setTile(sf::Vector2<int>(3, 30), &be);
  map.setTile(sf::Vector2<int>(4, 30), &be);
  map.setTile(sf::Vector2<int>(5, 30), &be);
  map.setTile(sf::Vector2<int>(6, 30), &be);
  map.setTile(sf::Vector2<int>(7, 30), &be);
  map.setTile(sf::Vector2<int>(8, 30), &be);
  map.setTile(sf::Vector2<int>(9, 30), &be);
  map.setTile(sf::Vector2<int>(10, 30), &be);
  map.setTile(sf::Vector2<int>(11, 30), &be);
  map.setTile(sf::Vector2<int>(12, 30), &be);
  map.setTile(sf::Vector2<int>(13, 30), &be);
  map.setTile(sf::Vector2<int>(14, 30), &be);
  map.setTile(sf::Vector2<int>(15, 30), &be);
  map.setTile(sf::Vector2<int>(16, 30), &be);
  map.setTile(sf::Vector2<int>(17, 30), &be);
  map.setTile(sf::Vector2<int>(18, 30), &be);
  map.setTile(sf::Vector2<int>(19, 30), &be);
  map.setTile(sf::Vector2<int>(20, 30), &be);
  map.setTile(sf::Vector2<int>(21, 30), &be);
  map.setTile(sf::Vector2<int>(22, 30), &be);
  map.setTile(sf::Vector2<int>(23, 30), &be);
  map.setTile(sf::Vector2<int>(24, 30), &be);
  map.setTile(sf::Vector2<int>(25, 30), &be);
  map.setTile(sf::Vector2<int>(26, 30), &be);
  map.setTile(sf::Vector2<int>(27, 30), &brc);
  
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
  sf::Vector2<double> mapAnchor;
  sf::Vector2<int> mapSize;
  PacTile tempTile(spriteSet["floor"], "FLOOR");
  sf::Sprite tempSprite;
  
  // Play the music
  music.play();
  
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

    // DRAWING THE SCREEN
    // Clear screen
    window.clear();
    
    // Draw the map - logic is a bit messy
    mapAnchor = map.getAnchor();
    mapSize = map.getSize();
    
    for (int i = 0; i < mapSize.x; i++) {
      for (int j = 0; j < mapSize.y; j++) {
        tempTile = *map.getTileAtIndex(sf::Vector2<int>(i, j));
        tempSprite = tempTile.getSprite();
        tempSprite.setPosition(mapAnchor.x + (i*map.getTileWidth()), mapAnchor.y + (j*map.getTileWidth()));
        window.draw(tempSprite);
      }
    }
    
    // Update the window
    window.display();
  }

  return EXIT_SUCCESS;
}
