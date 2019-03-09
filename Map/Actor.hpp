#pragma once

#include <vector>
#include "../Base/Color.hpp"
#include <string>

struct positionData
{
  int x;
  int y;
};

class Actor
{
public:
  // default constructor
  Actor() {}

  // create an actor with a value, position and color
  Actor(std::string value, int x, int y, Color color);

  // move the Actor from current position by adding to it.
  void move(int x, int y);
  // move the Actor to any x,y coordinate.
  void setPosition(int x, int y);
  // set the actors value to a new char*
  void setValue(std::string newVal);

  positionData getPosition() { return position; }
  std::string getValue() { return val; }
  Color getColor() { return colors; }

  virtual void update() {}

protected:
  positionData position;
  std::string val;
  Color colors;
};
