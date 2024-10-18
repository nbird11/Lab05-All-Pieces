/***********************************************************************
 * Header File:
 *    Pawn
 * Author:
*    Nathan Bird, Brock Hoskins, Jared Davey
 * Summary:
 *    The Pawn class
 ************************************************************************/

#pragma once

#include "piece.h"

/***************************************************
 * Pawn
 * The Pawn
 ***************************************************/
class Pawn : public Piece
{
public:
   Pawn(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Pawn(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Pawn() { }
   PieceType getType() const { return PAWN; }
   void getMoves(set <Move>& moves, const Board& board) const override;
   void display(ogstream* pgout) const override;
};