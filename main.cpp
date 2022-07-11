#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

int pointerRow = 1, pointerCol = 1;
char turn = 'X';
vector<vector<char>> table = {{'-', '-', '-'},
                              {'-', '-', '-'},
                              {'-', '-', '-'}};

void clear() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void printTable() {
    clear();
    for (int row = 0; row < table.size(); row++) {
        for (int col = 0; col < table[row].size(); col++) {
            if (row == pointerRow && col == pointerCol && table[row][col] == '-') {
                cout << "*" << "  ";
            }
            else
                cout << table[row][col] << "  ";
        }
        cout << "\b\n";
    }
}

void up() {
    pointerRow = max (pointerRow - 1, 0);
}

void down() {
    pointerRow = min (pointerRow + 1, 2);
}

void left() {
    pointerCol = max (pointerCol - 1, 0);
}

void right() {
    pointerCol = min (pointerCol + 1, 2);
}

void chooseXO() {
    if (table[pointerRow][pointerCol] == '-') {
        table[pointerRow][pointerCol] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    }
}

void userOrder() {
    char direction;
    direction = getch();
    direction = (char) tolower(direction);
    switch (direction) {
        case 'w' :
            up();
            break;
        case 's' :
            down();
            break;
        case 'a' :
            left();
            break;
        case 'd' :
            right();
            break;
        case 'p' :
            chooseXO();
            break;
        case 'q' :
            exit(0);
    }
    printTable();
}

int checkWin() {
    if ( (table[0][0] != '-' && table[0][0] == table[0][1] && table[0][1] == table[0][2]) ||
         (table[1][0] != '-' && table[1][0] == table[1][1] && table[1][1] == table[1][2]) ||
         (table[2][0] != '-' && table[2][0] == table[2][1] && table[2][1] == table[2][2]) ||
         (table[0][0] != '-' && table[0][0] == table[1][0] && table[1][0] == table[2][0]) ||
         (table[0][1] != '-' && table[0][1] == table[1][1] && table[1][1] == table[2][1]) ||
         (table[0][2] != '-' && table[0][2] == table[1][2] && table[1][2] == table[2][2]) ||
         (table[0][0] != '-' && table[0][0] == table[1][1] && table[1][1] == table[2][2]) ||
         (table[0][2] != '-' && table[0][2] == table[1][1] && table[1][1] == table[2][0]) )
        return true;
    return false;
}

int main() {
    printTable();
    while (!checkWin()) {
        userOrder();
    }
    if (turn == 'O') {
        cout << "X won!";
    } else if (turn == 'X')
        cout << "O won!";
}