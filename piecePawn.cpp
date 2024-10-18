/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    Nathan Bird, Brock Hoskins, Jared Davey
 * Summary:
 *    The Pawn class
 ************************************************************************/

#include "board.h"
#include "move.h"
#include "piecePawn.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"
#include <set>

 /**********************************************
  * PAWN : GET POSITIONS
  *********************************************/
void Pawn::getMoves(set<Move>& possible, const Board& board) const
{
   int row = position.getRow();
   int col = position.getCol();
   int r, c;
   Position newPos;

   if (!fWhite)
   {
      c = col;
      r = row - 2;
      newPos.set(c, r);
      if (row == 6 && board[newPos].getType() == PieceType::SPACE)
         possible.insert(createNewMove(newPos, board));  // forward two blank spaces
      r = row - 1;
      newPos.setRow(r);
      if (r >= 0 && board[newPos].getType() == PieceType::SPACE)
         possible.insert(createNewMove(newPos, board));  // forward one black space
      c = col - 1;
      newPos.setCol(c);
      if (board[newPos].isWhite() && board[newPos].getType() != PieceType::SPACE)
         possible.insert(createNewMove(newPos, board));  // attack left
      c = col + 1;
      newPos.setCol(c);
      if (board[newPos].isWhite() && board[newPos].getType() != PieceType::SPACE)
         possible.insert(createNewMove(newPos, board));  // attack right
      // TODO what about en-passant and pawn promotion
   }
   if (fWhite)
   {
      c = col;
      r = row + 2;
      newPos.set(c, r);
      if (row == 1 && board[newPos].getType() == PieceType::SPACE)
         possible.insert(createNewMove(newPos, board));  // forward two blank spaces
      r = row + 1;
      newPos.setRow(r);
      if (r < 8 && board[newPos].getType() == PieceType::SPACE)
         possible.insert(createNewMove(newPos, board));  // forward one blank space
      c = col - 1;
      newPos.setCol(c);
      if (!board[newPos].isWhite() && board[newPos].getType() != PieceType::SPACE)
         possible.insert(createNewMove(newPos, board));  // attack left
      c = col + 1;
      newPos.setCol(c);
      if (!board[newPos].isWhite() && board[newPos].getType() != PieceType::SPACE)
         possible.insert(createNewMove(newPos, board));  // attack right
      // TODO what about en-passant and pawn promotion
   }
}

/***************************************************
 * PAWN : DRAW
 * Draw the pawn.
 ***************************************************/
void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !fWhite);
}
