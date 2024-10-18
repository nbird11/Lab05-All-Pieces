/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      




/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3     p p p           3
 * 2     p(q)p           2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_blocked()
{
   //      // SETUP
   // BoardEmpty board;
   // Queen queen(7, 7, true /*white*/);
   // queen.fWhite = false;  // black
   // queen.position.set(2, 1);
   // board.board[2][1] = &queen;
   // Black black1(PAWN);
   // board.board[1][1] = &black1;
   // Black black2(PAWN);
   // board.board[2][2] = &black2;
   // Black black3(PAWN);
   // board.board[2][0] = &black3;
   // Black black4(PAWN);
   // board.board[3][1] = &black4;
   // Black black5(PAWN);
   // board.board[3][0] = &black5;
   // Black black6(PAWN);
   // board.board[1][0] = &black6;
   // Black black7(PAWN);
   // board.board[1][2] = &black7;
   // Black black8(PAWN);
   // board.board[3][2] = &black8;
   // set <Move> moves;

   // // EXERCISE
   // queen.getMoves(moves, board);

   // // VERIFY
   // assertUnit(moves.size() == 0);  // no possible moves

   // // TEARDOWN
   // board.board[2][1] = nullptr; // black
   // board.board[1][1] = nullptr; // black1
   // board.board[2][0] = nullptr; // black2
   // board.board[3][1] = nullptr; // black3
   // board.board[2][2] = nullptr; // black4
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}
