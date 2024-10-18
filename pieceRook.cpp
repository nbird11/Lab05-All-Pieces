/***********************************************************************
 * Source File:
 *    Rook
 * Author:
 *    <your name here>
 * Summary:
 *    The Rook class
 ************************************************************************/

#include <set>
#include "board.h"
#include "move.h"
#include "piece.h"
#include "pieceRook.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"

 /**********************************************
  * ROOK : GET POSITIONS
  *********************************************/
void Rook::getMoves(set <Move>& possible, const Board& board) const
{
   int row = position.getRow();
   int col = position.getCol();
   RelativePos moves[4] =
   {
               {0,  1},
      {-1, 0},         {1, 0},
               {0, -1}
   };
   int r, c;
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
 * ROOK : DRAW
 * Draw the rook.
 ***************************************************/
void Rook::display(ogstream* pgout) const
{
   pgout->drawRook(position, isWhite());
}

