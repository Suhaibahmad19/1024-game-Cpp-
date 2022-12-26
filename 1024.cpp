#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

void PrintBox(int board[][4]);
void RandomLoc(int board[][4], int& i, int& j);
void UnitCheck(int check);
void intro();
void ZeroInitialization(int board[][4]);
void StartingRandom(int& i, int& i1, int& j, int& j1, int board[][4]);
void UP(int board[][4], int bug);
void DOWN(int board[][4], int bug);
void LEFT(int board[][4], int bug);
void RIGHT(int board[][4], int bug);
int a = 0;
int l = 0, m = 0;
int GameOverCheck(const int board[][4]);


int main()
{
    int ch, bug = -1, game_check[4][4];
    while (1)
    {
        intro();

        srand(time(0));
        cin >> ch;

        if (ch == 1)
        {

            int board[4][4];

            ZeroInitialization(board);

            int i = 0, j = 0, i1 = 0, j1 = 0;

            StartingRandom(i, i1, j, j1, board);

            cout << " - - - - - - - -" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << "|";
                for (int j = 0; j < 4; j++)
                {
                    if (board[i][j] == 0)
                    {
                        cout << "   |";
                    }
                    else
                    {
                        cout << " " << board[i][j] << " |";
                    }
                }
                cout << endl;
                cout << " - - - - - - - -" << endl;
            }
            while (1)
            {
                char up;
                int check = 0, gc = 0, checkup = 0;
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        game_check[i][j] = board[i][j];
                    }
                }
                cout << "Enter" << endl;
                cin >> up;
                system("CLS");
                if (up == 'U')
                {
                    UP(board, bug);
                }
                else if (up == 'D')
                {
                    DOWN(board, bug);
                }
                else if (up == 'L')
                {
                    LEFT(board, bug);
                }
                else if (up == 'R')
                {
                    RIGHT(board, bug);
                }
                else if (up != 'U' || up != 'L' || up != 'R' || up != 'D')
                {
                    cout << "Invalid Enter U,D,L,R" << endl;
                }
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (game_check[i][j] == board[i][j])
                        {
                            checkup++;
                        }
                    }
                }
                if (checkup != 16)
                {
                    RandomLoc(board, i, j);
                    PrintBox(board);
                    if (GameOverCheck(board) == 1)
                    {
                        break;
                    }
                    if (a == 3)
                    {
                        break;
                    }
                }
                else
                    PrintBox(board);
            }
            break;
        }
        else if (ch == 2)
        {
            string str;
            ifstream file2("1024_instruction.txt");

            while (!file2.eof())
            {
                getline(file2, str);
                cout << str << endl;
            }
        }
        else if (ch == 3)
        {
            cout << "O---------O" << endl;
            cout << "| GOODBYE |" << endl;
            cout << "O---------O" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    if (a == 3)
    {
        cout << "O-----------O" << endl;
        cout << "|  YOU WON  |" << endl;
        cout << "O-----------O" << endl;
    }
    else if (ch == 1)
    {
        cout << "O------------O" << endl;
        cout << "|  GAMEOVER  |" << endl;
        cout << "|  YOU LOST  |" << endl;
        cout << "O------------O" << endl;
    }
}

void PrintBox(int board[][4])
{
    cout << " - - - - - - - -";
    if (a == 1)
    {
        cout << " - -";
    }
    if (a == 2)
    {
        cout << " - - - - - -";
    }
    if (a == 3)
    {
        cout << " - - - - - - - -";
    }
    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "|";
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0 && a == 1)
            {
                cout << "    |";
            }
            else if (board[i][j] == 0 && a == 2)
            {
                cout << "      |";
            }
            else if (board[i][j] == 0 && a == 3)
            {
                cout << "      |";
            }
            else if (board[i][j] == 0)
            {
                cout << "   |";
            }
            else if (board[i][j] != 0)
            {
                if ((board[i][j] > 0 && board[i][j] <= 9) && a == 3)
                {
                    cout << " " << board[i][j] << "    |";
                }
                else if ((board[i][j] > 0 && board[i][j] <= 9) && a == 2)
                {
                    cout << "  " << board[i][j] << "   |";
                }
                else if ((board[i][j] > 0 && board[i][j] <= 9) && a == 1)
                {
                    cout << "  " << board[i][j] << " |";
                }
                else if (board[i][j] > 10 && board[i][j] < 100 && a == 1)
                {
                    cout << " " << board[i][j] << " |";
                }
                else if (board[i][j] > 10 && board[i][j] < 100 && a == 2)
                {
                    cout << "  " << board[i][j] << "  |";
                }
                else if (board[i][j] > 100 && board[i][j] < 1000 && a == 2)
                {
                    cout << " " << board[i][j] << "  |";
                }
                else if (board[i][j] > 0 && board[i][j] < 10)
                {
                    cout << " " << board[i][j] << " |";
                }
                else if (board[i][j] > 1000)
                {
                    cout << " " << board[i][j] << " " << endl;

                }
            }
        }
        cout << endl;
        if (a == 1)
        {
            cout << " - -";
        }
        if (a == 2)
        {
            cout << " - - - - - -";
        }
        if (a == 3)
        {
            cout << " - - - - - - - -";
        }
        cout << " - - - - - - - -" << endl;
    }
}
void RandomLoc(int board[][4], int& i, int& j)
{
    i = rand() % 4;
    j = rand() % 4;
    while (board[i][j] != 0)
    {
        i = rand() % 4;
        j = rand() % 4;
    }
    board[i][j] = rand() % 2 + 1;
    l = i;
    m = j;
}
int b = 0;
void UnitCheck(int check)
{
    int c = 0;
    while (check != 0)
    {
        check /= 10;
        c++;
    }
    if (c == 2 && b == 0)//b==0
    {
        a = 1;
        b++;
    }
    else if (c == 3 && b == 1)//&& b==1
    {
        a = 2;
        b++;
    }
    else if (c == 4 && b == 2)//&& b==2
    {
        a = 3;
        b++;
    }
}
void intro()
{
    string str;
    ifstream file("menu.txt");
    while (!file.eof())
    {
        getline(file, str);
        cout << str << endl;
    }
    cout << endl;
}
void ZeroInitialization(int board[][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) 
            board[i][j] = 0;
       
}
void StartingRandom(int& i, int& i1, int& j, int& j1, int board[][4])
{
    i = rand() % 4;
    j = rand() % 4;
    i1 = rand() % 4;
    j1 = rand() % 4;
    while (i == j)
    {
        j = rand() % 4;
    }
    while (i1 == i || j1 == j)
    {
        i1 = rand() % 4;
        j1 = rand() % 4;
    }
    board[i][j] = rand() % 2 + 1;
    board[i1][j1] = rand() % 2 + 1;

}
int GameOverCheck(const int board[][4])
{
    int copy_of_board[4][4], box = 0, copy_bug = -1, box_check = 0, arr_check = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            copy_of_board[i][j] = board[i][j];
            if (copy_of_board[i][j] != 0)
            {
                box++;
            }
        }
    }
    if (box == 16)
    {
        UP(copy_of_board, copy_bug);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (copy_of_board[i][j] == board[i][j])
                {
                    arr_check++;
                }
            }
        }
        if (arr_check == 16)
        {
            box_check++;
        }
        else
        {
            return -1;
        }
        arr_check = 0;
        DOWN(copy_of_board, copy_bug);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (copy_of_board[i][j] == board[i][j])
                {
                    arr_check++;
                }
            }
        }

        if (arr_check == 16)
        {
            box_check++;
        }
        else
        {
            return -1;
        }
        arr_check = 0;
        LEFT(copy_of_board, copy_bug);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (copy_of_board[i][j] == board[i][j])
                {
                    arr_check++;
                }
            }
        }

        if (arr_check == 16)
        {
            box_check++;
        }
        else
        {
            return -1;
        }
        arr_check = 0;
        RIGHT(copy_of_board, copy_bug);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (copy_of_board[i][j] == board[i][j])
                {
                    arr_check++;
                }
            }
        }
        if (arr_check == 16)
        {
            box_check++;
        }
        else
        {
            return -1;
        }
        if (box_check == 4)
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }
    else
    {
        return -1;
    }
}
void UP(int board[][4], int bug)
{
    for (int a = 1; a < 4; a++)
    {
        for (int i = 1; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (bug != j)
                {
                    int temp = board[i][j];
                    if (board[i - 1][j] == 0)
                    {
                        swap(board[i][j], board[i - 1][j]);
                        board[i][j] = 0;
                    }
                    else if (board[i - 1][j] == temp)
                    {
                        board[i - 1][j] += board[i][j];
                        board[i][j] = 0;
                        UnitCheck(board[i - 1][j]);
                        if (board[i - 1][j] == board[i - 2][j])//|| board[i-1][j]==board[i+1][j])
                        {
                            bug = j;
                        }
                    }
                }
            }
        }
    }
    bug = -1;
}
void DOWN(int board[][4], int bug)
{
    for (int a = 1; a < 4; a++)
    {
        for (int i = 2; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (bug != j)
                {
                    int temp = board[i][j];
                    if (board[i + 1][j] == 0)
                    {
                        swap(board[i][j], board[i + 1][j]);
                        board[i][j] = 0;
                    }
                    else if (board[i + 1][j] == temp)
                    {
                        board[i + 1][j] += board[i][j];
                        board[i][j] = 0;
                        UnitCheck(board[i + 1][j]);
                        if (board[i + 1][j] == board[i + 2][j])//|| board[i+1][j]==board[i-1][j])
                        {
                            bug = j;
                        }
                    }
                }
            }
        }
    }
    bug = -1;
}
void LEFT(int board[][4], int bug)
{
    for (int a = 1; a < 4; a++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i != bug)
            {
                for (int j = 1; j < 4; j++)
                {
                    int temp = board[i][j];
                    if (board[i][j - 1] == 0)
                    {
                        swap(board[i][j], board[i][j - 1]);
                        board[i][j] = 0;
                    }
                    else if (board[i][j - 1] == temp)
                    {
                        board[i][j - 1] += board[i][j];
                        board[i][j] = 0;
                        UnitCheck(board[i][j - 1]);
                        if (board[i][j - 1] == board[i][j - 2])//|| board[i][j-1]==board[i][j+1])
                        {
                            bug = i;
                        }
                    }
                }
            }
        }
    }
    bug = -1;
}
void RIGHT(int board[][4], int bug)
{
    for (int a = 1; a < 4; a++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i != bug)
            {
                for (int j = 2; j >= 0; j--)
                {
                    int temp = board[i][j];
                    if (board[i][j + 1] == 0)
                    {
                        swap(board[i][j + 1], board[i][j]);
                        board[i][j] = 0;
                    }
                    else if (board[i][j + 1] == temp)
                    {
                        board[i][j + 1] += board[i][j];
                        board[i][j] = 0;
                        UnitCheck(board[i][j + 1]);
                        if (board[i][j + 1] == board[i][j - 1])//|| board[i][j+1]==board[i][j+2])
                        {
                            bug = i;
                        }
                    }
                }
            }
        }
    }
    bug = -1;
}
