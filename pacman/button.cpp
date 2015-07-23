#include "button.hpp"

Button::Button(sf::Vector2<double> sze, sf::Sprite spr, sf::Rect<double> collBox){
  size = sze;
  sprite = spr;
  collisionBox = collBox;
}

// Private

// Public
sf::Vector2<double> Button::getPosition() {
  return sf::Vector2<double>(sprite.getPosition().x, sprite.getPosition().y);
}

sf::Sprite Button::getSprite() {
  return sprite;
}

void Button::setPosition(sf::Vector2<double> newPosition) {
  sprite.setPosition(newPosition.x, newPosition.y);
  collisionBox.left = newPosition.x;
  collisionBox.top = newPosition.y;
}

bool Button::isClicked(sf::Vector2<double> clickPosition) {
  return collisionBox.contains(clickPosition);
}
