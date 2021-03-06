#pragma once

#include <string>
#include "Direction.h"

struct Position {
  const int x;
  const int y;

  Position(int x, int y);
  Position shift(Direction direction);

  std::string toString();
};

bool operator==(const Position& a, const Position& b);
bool operator<(const Position& a, const Position& b);
