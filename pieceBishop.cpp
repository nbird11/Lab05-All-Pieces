/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    <your name here>
 * Summary:
 *    The Bishop class
 ************************************************************************/

#include <set>
#include "board.h"
#include "move.h"
#include "piece.h"
#include "pieceBishop.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"    // for draw*()

 /**********************************************
  * BISHOP : GET POSITIONS
  *********************************************/
void Bishop::getMoves(set <Move>& possible, const Board& board) const
{
   int row = position.getRow();
   int col = position.getCol();
   RelativePos moves[4] =
   {
      {-1, 1}, {1, 1},
      {-1, -1}, {1, -1}
   };
   int r;
   int c;
   for (int i = 0; i < 4; i++)
   {
      r = row + moves[i].row;
      c = col + moves[i].col;
      Position newPos(c, r);

      while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
             board[newPos].getType() == PieceType::SPACE)
      {
         possible.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
         r += moves[i].row;
         c += moves[i].col;
         newPos = Position(c, r);
      }
      if (fWhite && !board[newPos].isWhite())
         possible.insert(Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite()));
   }
}

/***************************************************
 * BISHOP : DRAW
 * Draw the bishop.
 ***************************************************/
void Bishop::display(ogstream* pgout) const
{
   pgout->drawBishop(position, fWhite);
}

