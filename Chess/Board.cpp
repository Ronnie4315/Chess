#include "Board.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Board::Board() {
    // Initialize the board with nullptrs
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            BoardArray[i][j] = nullptr;
        }
    }

    // Create white pawns and black pawns
    for (int i = 0; i < 8; i++) {
        BoardArray[1][i] = new Pawn('B');  // Black pawns
        BoardArray[6][i] = new Pawn('W');  // White pawns
    }
}

Board::~Board() {
    // Clean up dynamically allocated pieces
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (BoardArray[i][j] != nullptr) {
                delete BoardArray[i][j];
            }
        }
    }
}

void Board::display() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int c = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (c % 2 == 0) {
                SetConsoleTextAttribute(hConsole, 144);  // Light square
            }
            else {
                SetConsoleTextAttribute(hConsole, 112);  // Dark square
            }

            // Display the piece symbol if a piece exists
            if (BoardArray[i][j] != nullptr) {
                cout << BoardArray[i][j]->GetPiece();
            }
            else {
                cout << " ";  // Empty square
            }

            cout << " ";
            c++;
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout << "  " << 8 - i << endl;  // Show row numbers on the side
        c++;
    }
    cout << endl;

    // Print column labels (A-H)
    for (int i = 65; i < 73; i++) {
        char value = char(i);
        cout << value << " ";
    }
    cout << endl;
}

void Board::Move() {
    char startCol, destCol;
    int startRow, destRow;

    cout << "Enter move (e.g., A2 A3): ";
    cin >> startCol >> startRow >> destCol >> destRow;

    // Convert input to board indices
    int startColIndex = startCol - 'A';
    int startRowIndex = 8 - startRow;
    int destColIndex = destCol - 'A';
    int destRowIndex = 8 - destRow;

    // Check if the starting position is valid
    if (startRowIndex < 0 || startRowIndex >= 8 || startColIndex < 0 || startColIndex >= 8 ||
        destRowIndex < 0 || destRowIndex >= 8 || destColIndex < 0 || destColIndex >= 8) {
        cout << "Invalid move! Out of bounds." << endl;
        return;
    }

    // Check if there is a piece at the starting position
    if (BoardArray[startRowIndex][startColIndex] == nullptr) {
        cout << "No piece at the starting position!" << endl;
        return;
    }

    // Get the selected piece
    BasePiece* piece = BoardArray[startRowIndex][startColIndex];

    // Check if the move is legal for this piece
    if (piece->LegalSquare(startRowIndex, startColIndex, destRowIndex, destColIndex, BoardArray)) {
        // Move the piece to the destinationA
        delete BoardArray[destRowIndex][destColIndex];  // Capture if there's a piece at the destination
        BoardArray[destRowIndex][destColIndex] = piece;
        BoardArray[startRowIndex][startColIndex] = nullptr;

        cout << "Move successful!" << endl;
    }
    else {
        cout << "Illegal move for this piece!" << endl;
    }
}
