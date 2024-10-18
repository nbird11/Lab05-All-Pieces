/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include <cassert>     // because we are paranoid
#include "board.h"     // for BOARD
#include "move.h"
#include "piece.h"     // for all the PIECE class definitions
#include "pieceKnight.h"
#include "pieceSpace.h"
#include "position.h"  // for POSITION
#include "uiDraw.h"    // for draw*()
using namespace std;


Piece::Piece(const Piece& piece)
{
   this->nMoves = piece.nMoves;
   this->fWhite = piece.fWhite;
   this->position = piece.position;
   this->lastMove = piece.lastMove;
}

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
   this->nMoves = rhs.nMoves;
   this->fWhite = rhs.fWhite;
   this->position = rhs.position;
   this->lastMove = rhs.lastMove;
   return *this;
}

bool Piece::operator==(PieceType pt) const
{
   return this->getType() == pt;
}

bool Piece::operator!=(PieceType pt) const
{
   return this->getType() != pt;
}

Move Piece::createNewMove(const Position& newPos, const Board& board) const
{
   return Move(position, newPos, PieceType::INVALID, board[newPos].getType(), Move::MoveType::MOVE, isWhite());
}

void Piece::setLastMove(int currentMove)
{
   lastMove = currentMove;
   nMoves++;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

