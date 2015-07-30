
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "map.hpp"
#include "ghost.hpp"

int main(int, char const**)
{
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  
  // Set the Icon
  sf::Image icon;
  if (!icon.loadFromFile(resourcePath() + "icon.png")) {
    return EXIT_FAILURE;
  }
  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

  // Load a sprite to display
  sf::Texture texture;
  if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
    return EXIT_FAILURE;
  }
  sf::Sprite sprite(texture);
  
  // More importantly, let's build up a tileset.
  sf::Texture level_texture;
  if (!level_texture.loadFromFile(resourcePath() + "data/full_texture_x3.png")) {
    return EXIT_FAILURE;
  }
  sf::Sprite top_left_corner(level_texture, sf::Rect<int>(0, 0, 24, 24));
  PacTile tlc(top_left_corner, sf::String("WALL"));
  
  // These are the double-line left corners that appear within the maze
  sf::Sprite lower_left_corner(level_texture, sf::Rect<int>(24*22, 9*24, 24, 24));
  PacTile llc(lower_left_corner, sf::String("WALL"));
  
  sf::Sprite inner_left_corner(level_texture, sf::Rect<int>(24*13, 0, 24, 24));
  PacTile ilc(inner_left_corner, sf::String("WALL"));
  
  sf::Sprite box_top_left_corner(level_texture, sf::Rect<int>(24*2, 24*2, 24, 24));
  PacTile btlc(box_top_left_corner, sf::String("WALL"));

  sf::Sprite top_right_corner(level_texture, sf::Rect<int>(24*27, 0, 24, 24));
  PacTile trc(top_right_corner, sf::String("WALL"));
  
  // These are the double-line right corners that appear within the maze
  sf::Sprite lower_right_corner(level_texture, sf::Rect<int>(24*5, 9*24, 24, 24));
  PacTile lrc(lower_right_corner, sf::String("WALL"));
  
  sf::Sprite inner_right_corner(level_texture, sf::Rect<int>(24*14, 0, 24, 24));
  PacTile irc(inner_right_corner, sf::String("WALL"));
  
  sf::Sprite box_top_right_corner(level_texture, sf::Rect<int>(24*5, 24*2, 24, 24));
  PacTile btrc(box_top_right_corner, sf::String("WALL"));

  sf::Sprite bottom_right_corner(level_texture, sf::Rect<int>(24*27, 9*24, 24, 24));
  PacTile brc(bottom_right_corner, sf::String("WALL"));
  
  sf::Sprite box_bottom_right_corner(level_texture, sf::Rect<int>(24*5, 24*4, 24, 24));
  PacTile bbrc(box_bottom_right_corner, sf::String("WALL"));

  sf::Sprite bottom_left_corner(level_texture, sf::Rect<int>(0, 9*24, 24, 24));
  PacTile blc(bottom_left_corner, sf::String("WALL"));
  
  sf::Sprite box_bottom_left_corner(level_texture, sf::Rect<int>(24*2, 24*4, 24, 24));
  PacTile bblc(box_bottom_left_corner, sf::String("WALL"));

  sf::Sprite top_edge(level_texture, sf::Rect<int>(48, 0, 24, 24));
  PacTile te(top_edge, sf::String("WALL"));
  
  sf::Sprite box_top(level_texture, sf::Rect<int>(24*4, 24*2, 24, 24));
  PacTile bt(box_top, sf::String("WALL"));

  sf::Sprite left_edge(level_texture, sf::Rect<int>(0, 32, 24, 24));
  PacTile le(left_edge, sf::String("WALL"));
  
  sf::Sprite inner_left_edge(level_texture, sf::Rect<int>(24*14, 24, 24, 24));
  PacTile ile(inner_left_edge, sf::String("WALL"));

  sf::Sprite right_edge(level_texture, sf::Rect<int>(24*27, 24, 24, 24));
  PacTile re(right_edge, sf::String("WALL"));
  
  sf::Sprite inner_right_edge(level_texture, sf::Rect<int>(24*13, 24, 24, 24));
  PacTile ire(inner_right_edge, sf::String("WALL"));

  sf::Sprite bottom_edge(level_texture, sf::Rect<int>(24, 9*24, 24, 24));
  PacTile be(bottom_edge, sf::String("WALL"));
  
  sf::Sprite box_bottom(level_texture, sf::Rect<int>(24*4, 24*4, 24, 24));
  PacTile bb(box_bottom, sf::String("WALL"));

  sf::Sprite floor(level_texture, sf::Rect<int>(30*24, 24, 32, 24));
  PacTile f(floor, sf::String("FLOOR"));
  
  // Load up the map!
  Map map(sf::Vector2<double>(0, 0), sf::Vector2<int>(28, 10), 24);
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
  map.setTile(sf::Vector2<int>(5, 9), &lrc);
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
  map.setTile(sf::Vector2<int>(22, 9), &llc);
  map.setTile(sf::Vector2<int>(23, 9), &be);
  map.setTile(sf::Vector2<int>(24, 9), &be);
  map.setTile(sf::Vector2<int>(25, 9), &be);
  map.setTile(sf::Vector2<int>(26, 9), &be);
  map.setTile(sf::Vector2<int>(27, 9), &brc);
  
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

  // Play the music
  music.play();
  
  // Declare the ghosts!
  // Restructure these such that each ghost type is it's own subclass of ghost. Switch-casing based on personality type would be ridiculous
  Ghost Pinky(sf::String("HOUSE"), sf::String(""));
  Ghost Blinky(sf::String("HOUSE"), sf::String(""));
  Ghost Inky(sf::String("HOUSE"), sf::String(""));
  Ghost Sue(sf::String("HOUSE"), sf::String(""));
  
  // Game variables
  // Variabes used to draw map
  sf::Vector2<double> mapAnchor;
  sf::Vector2<int> mapSize;
  PacTile tempTile(floor, sf::String("FLOOR"));
  sf::Sprite tempSprite;
  
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
    
    window.draw(tlc.getSprite());
    
    // Update the window
    window.display();
  }

  return EXIT_SUCCESS;
}
