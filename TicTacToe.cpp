
#include <iostream>
#include <iomanip>     
using namespace std;

//printing board on screen
void show_board(char* array)
{
    cout << "\n";
    cout << "\t" << "   " << array[0] << "    |   " << array[1] << "   |   " << array[2] << "\n";
    cout << "\t" << "-----------------------\n";
    cout << "\t" << "   " << array[3] << "    |   " << array[4] << "   |   " << array[5] << "\n";
    cout << "\t" << "-----------------------\n";
    cout << "\t" << "   " << array[6] << "    |   " << array[7] << "   |   " << array[8] << "\n";

}

//choice of the cell number
char choice(int count)
{
    char choice_cell;
    if (count % 2 == 0)
    {
        cout << "\n\n\nPlayer 2,";
        cout << "Enter cell ";
        cin >> choice_cell;
        return choice_cell;
    }
    else
    {
        cout << "\n\n\nPlayer 1, ";
        cout << "Enter cell ";
        cin >> choice_cell;
        return choice_cell;
    }
}

//fill the zero and cross on board
void fill_choice(char* array, char choice, int count, char* board)
{
    for (int i = 0; i < 9; i++)
    {
        if (array[i] == choice)
        {
            if (count % 2 == 0)
            {
                board[i] = 'X';
            }
            else
            {
                board[i] = '0';
            }
        }
    }

}

//checking whether the gameover or not
int check_gameover(char* board)
{
    if ((board[1] == '0' && board[4] == '0' && board[7] == '0') ||
        (board[3] == '0' && board[4] == '0' && board[5] == '0') ||
        (board[6] == '0' && board[7] == '0' && board[8] == '0') ||
        (board[0] == '0' && board[3] == '0' && board[6] == '0') ||
        (board[1] == '0' && board[4] == '0' && board[7] == '0') ||
        (board[2] == '0' && board[5] == '0' && board[8] == '0') ||
        (board[0] == '0' && board[4] == '0' && board[8] == '0') ||
        (board[2] == '0' && board[4] == '0' && board[6] == '0'))
    {
        cout << "\nPlayer 1 winner!!!!!!!!!\n\n\n";
        return 1;
    }
    else if ((board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
        (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
        (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
        (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
        (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
        (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
        (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
        (board[2] == 'X' && board[4] == 'X' && board[6] == 'X'))
    {
        cout << "\nPlayer 2 winner!!!!!!!!!\n\n\n";
        return 2;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char array[] = { '1','2','3','4','5','6','7','8','9' };
    char choice_cell;              //choose the cell
    cout << setw(30) << "\n     --------------------------------------------------"
        << "Tic Tac Toe----------------------------------------------- "
        << "\n";

    cout << "\nChoose a cell numbered from 1 to 9 as below and play";
    show_board(array);          //showing board
    cout << "\n";

    cout << "\n\nPlayer 1 <x>\t Player 2 <1>";

    int count = 1, i;        //checking of player 1 and 2
    char board[9] = " ";      //board showing for game
    for (i = 0; i < 9; i++)
    {
        choice_cell = choice(count);        //choice cell
        fill_choice(array, choice_cell, count, board);
        show_board(board);

        if (check_gameover(board))
        {
            break;
        }
        count++;

    }
    if (i == 9)
    {
        cout << "\nDraw";
    }

}

