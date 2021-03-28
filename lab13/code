#include <iostream>
using namespace std;

int board[8][8];
int rcount = 0;

void Board()
{
    for (int i = 8; i >= 1; i--) {
        cout << i << " ";
        for (int j = 8; j >= 1; j--) {
            if (board[i][j] == 0) {
                if ((i + j) % 2 == 0) {
                    cout << "# ";
                }
                else {
                    cout << "  ";
                }
            }
            else {
                cout << "Ф ";
            }
        }
        cout << '\n';
    }
    cout << "  ";
    for (char i = 'a'; i <= 'h'; i++) {
        cout << i << " ";
    }
}

bool match(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        if (board[i][b]) return false;
    }
    for (int i = 1; i <= a && b - i >= 0; i++)
    {
        if (board[a - i][b - i]) return false;
    }
    for (int i = 1; i <= a && b + i < 8; i++)
    {
        if (board[a - i][b + i]) return false;
    }
    return true;
}

void setqueen(int a)
{
    if (a == 8)
    {
        Board();
        cout << "Решение номер " << ++rcount << '\n';
    }
    for (int i = 0; i < 8; i++)
    {
        if (match(a, i))
        {
            board[a][i] = 1;
            setqueen(a + 1);
            board[a][i] = 0;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    setqueen(0);
}
