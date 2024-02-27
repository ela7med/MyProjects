#include <iostream>
using namespace std;

char mainBoard[6][7]  {'#','#','#','#','#','#','#',
                       '#','#','#','#','#','#','#',
                       '#','#','#','#','#','#','#',
                       '#','#','#','#','#','#','#',
                       '#','#','#','#','#','#','#',
                       '#','#','#','#','#','#','#'};
int top[7] {5, 5, 5, 5, 5, 5, 5};
//                 r     l      u     d     ru       ld    lu     rd
int dirRow[]    {0, 0,-1,1,-1, 1,-1,1};
int dirColumn[] {1,-1,0 ,0, 1,-1,-1,1};

int TakePlay()
{
    int x;
        cin >> x;
    if (x > 7 || x < 1)
    {
        return TakePlay();
    }
    else
    {
        if (top[x - 1] == -1)
        {
            return TakePlay();
        }
        else
        {
            return x;
        }
    }

}

void PrintTheBoard()
{
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 7; c++)
            cout << mainBoard[r][c] << ' ';
        cout << '\n';
    }
    cout << "1 2 3 4 5 6 7\n";
}

void ChangeBoard(int player, int x)
{
    mainBoard[top[x - 1]][x - 1] = (player == 1 ? 'R' : 'Y' );
    top[x - 1]--;
}

bool CheckWin(int player, int x)
{
    char cPlayer = (player == 1 ? 'R' : 'Y');
    int d = 0;
    for (int i = 0; i < 4; i++)
    {
        int count = 1;
        for (int j = 0; j < 2; j++)
        {
            int r = top[x - 1] + dirRow[d] + 1, c = x - 1 + dirColumn[d];
            while(mainBoard[r][c] == cPlayer)
            {
                count++;
                r += dirRow[d];
                c += dirColumn[d];
            }
            if (count >= 4) return true;
            d++;
        }
    }
    return false;
}

void Run()
{
    int s = 42;

    while (s--)
    {
        PrintTheBoard();
        cout << "Player 1: \n";
        int x1 = TakePlay();
        ChangeBoard(1, x1);
        if (CheckWin(1, x1))
        {
            cout << "Player 1\n";
            PrintTheBoard();
            break;
        }
        PrintTheBoard();
        cout << "Player 2\n";
        int x2 = TakePlay();
        ChangeBoard(2, x2);
        if (CheckWin(2, x2))
        {
            cout << "Player 2: \n";
            PrintTheBoard();
            break;
        }
    }
}
int main()
{
    Run();
}




