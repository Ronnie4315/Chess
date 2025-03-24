#include "Board.h"
#include <iostream> 
#include<Windows.h> 
using namespace std;

	Board::Board() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chess[j][i] = ' ';
            }
        }

        for (int i = 0; i < 8; i++) {
            chess[1][i] = 'P';
            chess[6][i] = 'P';
        }

        //Black 
        chess[0][0] = 'R';
        chess[0][7] = 'R';
        chess[0][1] = 'N';
        chess[0][6] = 'N';
        chess[0][2] = 'B';
        chess[0][5] = 'B';
        chess[0][4] = 'K';
        chess[0][3] = 'Q';

        //White 
        chess[7][0] = 'R';
        chess[7][7] = 'R';
        chess[7][1] = 'N';
        chess[7][6] = 'N';
        chess[7][2] = 'B';
        chess[7][5] = 'B';
        chess[7][3] = 'K';
        chess[7][4] = 'Q';

	}
	void Board::Move() {
        std::cout << endl;
        std::cout << "Position: ";
        char alpha;
        int num;
        std::cin >> alpha;
        std::cin >> num;
        int column = alpha - 'A';
        int row = num - 1;

        std::cout << "Column Index: " << column << endl;
        std::cout << "Row Index: " << row << endl;

        chess[row][column] = 'K';
	}
	void Board::display() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int c = 0;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (c <= 45) {
                    if (c % 2 == 0) {
                        SetConsoleTextAttribute(hConsole, 144);
                    }

                    if (c % 2 != 0) {
                        SetConsoleTextAttribute(hConsole, 112);
                    }
                }
                if (c > 45) {
                    if (c % 2 == 0) {
                        SetConsoleTextAttribute(hConsole, 159);
                    }
                    if (c % 2 != 0) {
                        SetConsoleTextAttribute(hConsole, 127);
                    }
                }
                std::cout << chess[i][j];
                std::cout << " ";
                c++;
            }
            SetConsoleTextAttribute(hConsole, 7);
            std::cout << "  ";
            std::cout << i + 1;
            std::cout << std::endl;
            c++;
        }
        std::cout << endl;

        for (int i = 65; i < 73; i++) {
            char value = char(i);
            std::cout << value << " ";
        }
	}

