/***********************************************************************
 * Header File:
 *    King
 * Author:
*    Nathan Bird, Brock Hoskins, Jared Davey
 * Summary:
 *    The King class
 ************************************************************************/

#pragma once

#include "piece.h"

/***************************************************
 * King
 * The King
 ***************************************************/
class King : public Piece
{
public:
   King(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   King(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~King() { }
   PieceType getType() const { return KING; }
   void getMoves(set <Move>& moves, const Board& board) const override;
   void display(ogstream* pgout) const override;
};