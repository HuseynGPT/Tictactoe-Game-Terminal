#include <iostream>
#include <windows.h>

using namespace std;


void loadingBar()
{	
	system("cls");
	system("color 0A");
	char a = 177, b = 219;
	printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t\t\tLoading...\n\n");
	printf("\t\t\t\t\t");

	for (int i = 0; i < 26; i++)
		printf("%c", a);

	printf("\r");
	printf("\t\t\t\t\t");


	for (int i = 0; i < 26; i++) {
		printf("%c", b);
		Sleep(200);
	}
}


char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7' ,'8', '9' };

void menu()
{
	system("cls");
	cout << "\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t|      1.Start Game       |" << endl;
	cout << "\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t|      2.Exit Game        |" << endl;
	cout << "\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t---------------------------" << endl;


}

void board()
{
	
	system("cls");
	cout << "\t\tTic Tac Toe\t\t" << endl;
	cout << "\tPlayer 1 (X) - Player 2(O)\t" << endl;
	cout << endl;

	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;
	cout << "\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

}

int check() {
	//YAN YANA YOXLAMA
	if (square[1] == square[2] && square[2] == square[3]) return 1;
	else if (square[4] == square[5] && square[5] == square[6]) return 1;
	else if (square[7] == square[8] && square[8] == square[9]) return 1;
	//ALT - ALTA YOXLAMA
	else if (square[1] == square[4] && square[4] == square[7]) return 1;
	else if (square[2] == square[5] && square[5] == square[8]) return 1;
	else if (square[3] == square[6] && square[6] == square[9]) return 1;
	//CARPAZ YOXLAMA
	else if (square[1] == square[5] && square[5] == square[9]) return 1;
	else if (square[3] == square[5] && square[5] == square[7]) return 1;
	//BUTUN XANALAR DOLUBSA
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' &&
		square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9') return 0;
	else return -1;
}




int main() {

	system("color 2");
	
	int player = 1;
	int user_input;
	char x_or_o;
	int isCheck = 0;
	int enter_or_exit;
	menu();
	cout << "Make a choice: "; cin >> enter_or_exit;
	if (enter_or_exit == 1)
	{
		loadingBar();
		do
		{
			board();
			player = player % 2 ? 1 : 2;

			cout << endl;
			cout << "Player " << player << " enter a number: "; cin >> user_input;
			x_or_o = player == 1 ? 'X' : 'O';

			if (user_input == 1 && square[1] == '1') square[1] = x_or_o;
			else if (user_input == 2 && square[2] == '2') square[2] = x_or_o;
			else if (user_input == 3 && square[3] == '3') square[3] = x_or_o;
			else if (user_input == 4 && square[4] == '4') square[4] = x_or_o;
			else if (user_input == 5 && square[5] == '5') square[5] = x_or_o;
			else if (user_input == 6 && square[6] == '6') square[6] = x_or_o;
			else if (user_input == 7 && square[7] == '7') square[7] = x_or_o;
			else if (user_input == 8 && square[7] == '8') square[8] = x_or_o;
			else if (user_input == 9 && square[7] == '9') square[9] = x_or_o;
			else { cout << "wrong input!!!!!!!"; break; }

			isCheck = check();
			player++;
		} while (isCheck == -1);
		board();

		if (isCheck == 1) cout << "Player" << player - 1 << " Winner!!!!!!!!!!!!!!!" << endl;
		else cout << "Nobody Win :'(";

	}
	else return 0;
	
	
}