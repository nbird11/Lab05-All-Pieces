/***********************************************************************
 * Header File:
 *    Rook
 * Author:
*    <your name here>
 * Summary:
 *    The Rook class
 ************************************************************************/

#pragma once

#include <set>
#include "board.h"
#include "move.h"
#include "piece.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"

/***************************************************
 * Rook
 * The Rook
 ***************************************************/
class Rook : public Piece
{
public:
   Rook(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Rook(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Rook() { }
   PieceType getType() const { return ROOK; }
   void getMoves(set <Move>& moves, const Board& board) const override;
   void display(ogstream* pgout) const override;
};