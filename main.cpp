#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

void makeTable(vector<vector<char>> &table);

void printTable(vector<vector<char>> &table);

void clear();

void userOrder(vector<vector<char>> &table);

int win(vector<vector<char>> table);

void up(vector<vector<char>> table);

void down(vector<vector<char>> table);

void left(vector<vector<char>> table);

void right(vector<vector<char>> table);

void chooseXO(vector<vector<char>> &table);

int i = 1, j = 1, counter = 1;

int main() {
    vector<vector<char>> table;
    makeTable(table);
    table[1][1] = '*';
    printTable(table);
    table[1][1] = '-';
    while (!win(table)) {
        userOrder(table);
    }
    if (win(table)) {
        cout << "X won!";
    } else if (win(table) == 2)
        cout << "O won!";
}

void makeTable(vector<vector<char>> &table) {
    const int size = 3;
    for (int n = 0; n < size; n++) {
        vector<char> dashT;
        for (int m = 0; m < size; m++) {
            dashT.push_back('-');
        }
        table.push_back(dashT);
    }
}

void printTable(vector<vector<char>> &table) {
    clear();
    for (int row = 0; row < table.size(); row++) {
        for (int col = 0; col < table[row].size(); col++) {
            cout << table[row][col] << "  ";
        }
        cout << "\b\n";
    }
}

void userOrder(vector<vector<char>> &table) {
    char direction;
    direction = getch();
    direction = (char) tolower(direction);
    switch (direction) {
        case 'w' :
            up(table);
            break;
        case 's' :
            down(table);
            break;
        case 'a' :
            left(table);
            break;
        case 'd' :
            right(table);
            break;
        case 'p' :
            chooseXO(table);
            break;
        case 'q' :
            exit(0);
    }
}

void up(vector<vector<char>> table) {
    if (i != 0) {
        if (table[i - 1][j] == '-')
            table[--i][j] = '*';
        else
            --i;
        printTable(table);
    }
}

void down(vector<vector<char>> table) {
    if (i != 2) {
        if (table[i + 1][j] == '-')
            table[++i][j] = '*';
        else
            ++i;
        printTable(table);
    }
}

void left(vector<vector<char>> table) {
    if (j != 0) {
        if (table[i][j - 1] == '-')
            table[i][--j] = '*';
        else
            --j;
        printTable(table);
    }
}

void right(vector<vector<char>> table) {
    if (j != 2) {
        if (table[i][j + 1] == '-')
            table[i][++j] = '*';
        else
            ++j;
        printTable(table);
    }
}

void chooseXO(vector<vector<char>> &table) {
    if (table[i][j] == '-') {
        if (counter % 2 == 1) {
            table[i][j] = 'X';
            counter++;
        } else if (counter % 2 == 0) {
            table[i][j] = 'O';
            counter++;
        }
    }
    printTable(table);
}

int win(vector<vector<char>> table) {
    int flag = 0;
    if (table[0][0] == table[1][1] && table[0][0] == table[2][2]) {
        if (table[0][0] == 'X') {
            flag = 1;
            return flag;
        } else if (table[0][0] == 'O') {
            flag = 2;
            return flag;
        }
    }
    if (table[0][2] == table[1][1] && table[0][2] == table[2][0]) {
        if (table[0][2] == 'X') {
            flag = 1;
            return flag;
        } else if (table[0][2] == 'O') {
            flag = 2;
            return flag;
        }
    }
    for (int row = 0; row < table.size(); row++) {
        int col = 0;
        if (table[row][col] == table[row][++col] && table[row][col] == table[row][++col]) {
            if (table[row][col] == 'X') {
                flag = 1;
                return flag;
            } else if (table[row][col] == 'O') {
                flag = 2;
                return flag;
            }
        }
    }
    for (int col = 0; col < table.size(); col++) {
        int row = 0;
        if (table[row][col] == table[++row][col] && table[row][col] == table[++row][col]) {
            if (table[row][col] == 'X') {
                flag = 1;
                return flag;
            } else if (table[row][col] == 'O') {
                flag = 2;
                return flag;
            }
        }
    }
    return flag;
}

void clear() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}