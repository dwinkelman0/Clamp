#pragma once

#include <stdint.h>

#include <iostream>

namespace clamp {

class BoardState {
 public:
  /* Create the initial game state */
  BoardState();

  /* Create a game state from a FEN string */
  BoardState(const std::string& fen);

  /* Output the game state to a FEN string */
  friend std::ostream& operator<<(std::ostream& os, const BoardState& state);

 private:
  uint8_t squares_[64];
  uint64_t white_;
  uint64_t black_;
  bool whiteToMove_;
  uint8_t enPassant_;
  uint8_t castling_;
  uint32_t halfmoveCounter_;
  uint32_t fullmoveCounter_;
};

}  // namespace clamp
