#include <BoardState.h>
#include <gtest/gtest.h>

#include <iostream>

TEST(BoardState, Init) {
  clamp::BoardState state;
  std::ostringstream oss;
  oss << state;
  ASSERT_EQ(oss.str(),
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

class BoardStateFENTest : public testing::TestWithParam<std::string> {};

TEST_P(BoardStateFENTest, Parse) {
  std::string fen = GetParam();
  std::ostringstream oss;
  clamp::BoardState state(fen);
  oss << state;
  ASSERT_EQ(oss.str(), fen);
}

INSTANTIATE_TEST_SUITE_P(
    BoardState, BoardStateFENTest,
    testing::Values(
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1",
        "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1",
        "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2",
        "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2",
        "8/5k2/5P2/6KP/8/8/8/8 b - - 0 1",
        "8/5k2/5P2/6KP/8/8/8/8 b - - 23 12"));
