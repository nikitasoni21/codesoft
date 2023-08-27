// < TASK3 : TIC-TAC-TOE GAME >

#include <iostream>
using namespace std;

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void board();
int checkresult();

int main()
{
    int player = 1, choice;
    char mark;

    do
    {
        board();
        player = (player % 2 == 1) ? 1 : 2;
        cout << "Player " << player << " turn.\nEnter a number: ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == static_cast<char>(choice + '0'))
            square[choice] = mark;
        else
        {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        
        int result = checkresult();
        player++;

        if (result == 1)
        {
            board();
            cout << "Congratulations!!!\nPlayer " << player - 1 << " won ";
            break;
        }
        else if (result == 0)
        {
            board();
            cout << "It's a TIE";
            break;
        }

    } while (true);

    return 0;
}

void board()
{
    system("cls");  // Clears the console screen
   cout << "\n\n\tTIC TAC TOE\n\n";
   cout << " \tTwo Player Game  \n\n  ";
   cout << "Player 1 is X  and  Player 2 is O \n\n\n";
   cout << "     |     |     \n";
   cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "\n";
   cout << "_____|_____|_____\n";
   cout << "     |     |     \n";
   cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "\n";
   cout << "_____|_____|_____\n";
   cout << "     |     |     \n";
   cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "\n";
   cout << "     |     |     \n\n";
}

int checkresult()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
