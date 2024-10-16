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
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   int row = position.getRow();
   int col = position.getCol();
   Position move[8] =
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
      r = move[i].getRow();
      c = move[i].getCol();
      if (!(0 <= r && r <= 7 && 0 <= c && c <= 7))
         continue;
      if ((fWhite && !board[Position(c, r)].isWhite()) || board[Position(c, r)].getType() == SPACE)
         moves.insert(Move(position, Position(c, r), PieceType::INVALID, board[Position(c, r)].getType(), Move::MoveType::MOVE, isWhite()));
      //if (fWhite && board[Position(c, r)].isWhite())
      //   moves.insert(Move(position, Position(c, r), PieceType::INVALID, board[Position(c, r)].getType(), Move::MoveType::MOVE, isWhite()));
   }
}