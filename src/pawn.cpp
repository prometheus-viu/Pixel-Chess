#include "../include/pawn.h"
#include "../include/chessboard.h"


Pawn::Pawn(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWPawn : kBPawn;
}


unordered_set<Position> Pawn::LegalMoves()
{
    unordered_set<Position> moves;

    if (Colour() == kBlack) {
        if (IsEnemy(position() + Position(1,1))) 
        {
            moves.insert(position()+Position(1,1));
        }
        if (IsEnemy(position() + Position(1,-1))) 
        {
            moves.insert(position() + Position(1,-1));
        }
        if (IsLegalMove((position() + Position(1,0)))) 
        {
            moves.insert(position() + Position(1,0));
        }
        if (position() == starting_position()) 
        {
            if (IsLegalMove(position()+Position(2,0))) 
            { 
                moves.insert(position() + Position(2,0));
            }
        }
    }

    if (Colour() == kWhite) {
        if (IsEnemy(position() + Position(-1,-1)))
        {
            moves.insert(position()+Position(-1,-1));
        }
        if (IsEnemy(position() + Position(-1,1)))
        {
            moves.insert(position() + Position(1,-1));
        }
        if (IsLegalMove((position() + Position(-1,0)))) 
        {
            moves.insert(position() + Position(-1,0));
        }
        if (position() == starting_position()) 
        {
            if (IsLegalMove(position()+Position(-2,0))) 
            { 
                moves.insert(position() + Position(-2,0));
            }
        }
    }
    
    return moves;
}

