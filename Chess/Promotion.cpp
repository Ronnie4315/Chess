#include "Promotion.h"

BasePiece* Promotion::PromotePawn(char color)
{
    char choice;
    cout << "Pawn promotion! Choose a piece (Q - Queen, R - Rook, B - Bishop, N - Knight): ";
    cin >> choice;
  
    if (color == 'W') {

        switch (choice) {
        case 'Q':
            cout << "Promoting to Queen!" << endl;
            return new Queen('W');
        case 'R':
            cout << "Promoting to Rook!" << endl;
            return new Rook('W');
        case 'B':
            cout << "Promoting to Bishop!" << endl;
            return new Bishop('W');
        case 'N':
            cout << "Promoting to Knight!" << endl;
            return new Knight('W');
        default:
            cout << "Invalid choice, promoting to Queen by default!" << endl;
            return new Queen(color);
        }
    }
    else if (color == 'B') {
        switch (choice) {
        case 'Q':
            cout << "Promoting to Queen!" << endl;
            return new Queen('B');
        case 'R':
            cout << "Promoting to Rook!" << endl;
            return new Rook('B');
        case 'B':
            cout << "Promoting to Bishop!" << endl;
            return new Bishop('B');
        case 'N':
            cout << "Promoting to Knight!" << endl;
            return new Knight('B');
        default:
            cout << "Invalid choice, promoting to Queen by default!" << endl;
            return new Queen(color);
        }
    }
}
