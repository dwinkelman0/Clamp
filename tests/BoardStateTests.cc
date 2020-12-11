#include <BoardState.h>
#include <gtest/gtest.h>

#include <iostream>

TEST(BoardState, FEN) {
  clamp::BoardState state;
  std::cout << state << std::endl;
}
