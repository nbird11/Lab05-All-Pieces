/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
   pgout->drawKnight(position, fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& possible, const Board& board) const
{
   int row = position.getRow();
   int col = position.getCol();
   Position moves[8] =
   {
      {Position(col - 1, row + 2)}, 
      {Position(col + 1, row + 2)},
      {Position(col - 2, row + 1)},                    
      {Position(col + 2, row + 1)},
      {Position(col - 2, row - 1)},
      {Position(col + 2, row - 1)},
      {Position(col - 1, row - 2)},
      {Position(col + 1, row - 2)}
   };
   int r;
   int c;
   for (int i = 0; i < 8; i++)
   {
      r = moves[i].getRow();
      c = moves[i].getCol();
      if (0 <= r && r <= 7 && 0 <= c && c <= 7)
         if ((fWhite && !board[moves[i]].isWhite()) || board[moves[i]].getType() == SPACE)
            possible.insert(Move(position, moves[i], PieceType::INVALID, board[moves[i]].getType(), Move::MoveType::MOVE, isWhite()));
   }
}