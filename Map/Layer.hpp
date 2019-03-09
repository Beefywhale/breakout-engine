#pragma once

#include <map>

#include "Actor.hpp"

class Layer
{
public:
  // deafault constructor
  Layer() {}

  std::map<std::pair<int, int>, Actor *> getActors() { return actors; }
  Actor *getActorAt(int x, int y);
  bool isActorAt(int x, int y);

  void addActor(Actor *actor);
  virtual void update();

private:
  std::map<std::pair<int, int>, Actor *> actors;
};
