#include "BoardState.h"

#include <assert.h>

#include <string>

namespace {
const static uint8_t NO_PIECE = 0;
const static uint8_t WHITE_PAWN = 1;
const static uint8_t WHITE_KNIGHT = 2;
const static uint8_t WHITE_BISHOP = 3;
const static uint8_t WHITE_ROOK = 4;
const static uint8_t WHITE_QUEEN = 5;
const static uint8_t WHITE_KING = 6;
const static uint8_t BLACK_PAWN = 9;
const static uint8_t BLACK_KNIGHT = 10;
const static uint8_t BLACK_BISHOP = 11;
const static uint8_t BLACK_ROOK = 12;
const static uint8_t BLACK_QUEEN = 13;
const static uint8_t BLACK_KING = 14;
const char PIECE_CHARS[] = ".PNBRQK..pnbrqk.";

const static uint8_t WHITE_OO = 0x01;
const static uint8_t WHITE_OOO = 0x02;
const static uint8_t BLACK_OO = 0x04;
const static uint8_t BLACK_OOO = 0x08;

std::string squareToString(const uint8_t square) {
  assert(square < 64);
  std::string output;
  output.push_back('a' + square % 8);
  output.push_back('1' + square / 8);
  return output;
}
}  // namespace

namespace clamp {
BoardState::BoardState() {
  squares_[0] = WHITE_ROOK;
  squares_[1] = WHITE_KNIGHT;
  squares_[2] = WHITE_BISHOP;
  squares_[3] = WHITE_QUEEN;
  squares_[4] = WHITE_KING;
  squares_[5] = WHITE_BISHOP;
  squares_[6] = WHITE_KNIGHT;
  squares_[7] = WHITE_ROOK;
  squares_[8] = WHITE_PAWN;
  squares_[9] = WHITE_PAWN;
  squares_[10] = WHITE_PAWN;
  squares_[11] = WHITE_PAWN;
  squares_[12] = WHITE_PAWN;
  squares_[13] = WHITE_PAWN;
  squares_[14] = WHITE_PAWN;
  squares_[15] = WHITE_PAWN;
  squares_[16] = NO_PIECE;
  squares_[17] = NO_PIECE;
  squares_[18] = NO_PIECE;
  squares_[19] = NO_PIECE;
  squares_[20] = NO_PIECE;
  squares_[21] = NO_PIECE;
  squares_[22] = NO_PIECE;
  squares_[23] = NO_PIECE;
  squares_[24] = NO_PIECE;
  squares_[25] = NO_PIECE;
  squares_[26] = NO_PIECE;
  squares_[27] = NO_PIECE;
  squares_[28] = NO_PIECE;
  squares_[29] = NO_PIECE;
  squares_[30] = NO_PIECE;
  squares_[31] = NO_PIECE;
  squares_[32] = NO_PIECE;
  squares_[33] = NO_PIECE;
  squares_[34] = NO_PIECE;
  squares_[35] = NO_PIECE;
  squares_[36] = NO_PIECE;
  squares_[37] = NO_PIECE;
  squares_[38] = NO_PIECE;
  squares_[39] = NO_PIECE;
  squares_[40] = NO_PIECE;
  squares_[41] = NO_PIECE;
  squares_[42] = NO_PIECE;
  squares_[43] = NO_PIECE;
  squares_[44] = NO_PIECE;
  squares_[45] = NO_PIECE;
  squares_[46] = NO_PIECE;
  squares_[47] = NO_PIECE;
  squares_[48] = BLACK_PAWN;
  squares_[49] = BLACK_PAWN;
  squares_[50] = BLACK_PAWN;
  squares_[51] = BLACK_PAWN;
  squares_[52] = BLACK_PAWN;
  squares_[53] = BLACK_PAWN;
  squares_[54] = BLACK_PAWN;
  squares_[55] = BLACK_PAWN;
  squares_[56] = BLACK_ROOK;
  squares_[57] = BLACK_KNIGHT;
  squares_[58] = BLACK_BISHOP;
  squares_[59] = BLACK_QUEEN;
  squares_[60] = BLACK_KING;
  squares_[61] = BLACK_BISHOP;
  squares_[62] = BLACK_KNIGHT;
  squares_[63] = BLACK_ROOK;

  white_ = 0x000000000000ffff;
  black_ = 0xffff000000000000;
  whiteToMove_ = true;
  enPassant_ = 0;
  castling_ = WHITE_OO | WHITE_OOO | BLACK_OO | BLACK_OOO;
  halfmoveCounter_ = 0;
  fullmoveCounter_ = 1;
}

std::ostream& operator<<(std::ostream& os, const BoardState& state) {
  for (int row = 56; row >= 0; row -= 8) {
    int numEmpty = 0;
    for (int col = 0; col < 8; ++col) {
      if (state.squares_[row + col] == NO_PIECE) {
        numEmpty++;
      } else {
        if (numEmpty > 0) {
          os << numEmpty;
          numEmpty = 0;
        }
        os << PIECE_CHARS[state.squares_[row + col]];
      }
    }
    if (numEmpty > 0) {
      os << numEmpty;
    }
    os << (row > 0 ? '/' : ' ');
  }
  os << (state.whiteToMove_ ? 'w' : 'b') << " ";

  if (state.castling_) {
    if (state.castling_ & WHITE_OO) {
      os << "K";
    }
    if (state.castling_ & WHITE_OOO) {
      os << "Q";
    }
    if (state.castling_ & BLACK_OO) {
      os << "k";
    }
    if (state.castling_ & BLACK_OOO) {
      os << "q";
    }
  } else {
    os << "-";
  }
  os << " " << (state.enPassant_ ? squareToString(state.enPassant_) : "-");
  os << " " << state.halfmoveCounter_ << " " << state.fullmoveCounter_;
  return os;
}
}  // namespace clamp
