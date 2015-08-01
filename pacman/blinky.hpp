# include "ghost.hpp"
class Blinky: public Ghost{
public:
  using Ghost::Ghost;
  void update();
};