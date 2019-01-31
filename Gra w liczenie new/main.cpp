#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cstdlib>
#include "game.h"

using namespace std;



int main() {

	int range = 100;
	int quantity = 10;
	char choose;
	int missed = 0, correct = 0, percent = 0;
	int enter = 0;

	srand(time(NULL));
	Values Number(quantity, range);
	for (;;)
	{ 
		
		cout << "---GRA W LICZENIE---\n"
			<< endl
			<< "\nMENU GLOWNE:\n"
			<< "---------------------\n"
			<< "1. Dodawanie\n"
			<< "2. Odejmowanie\n"
			<< "3. Mnozenie\n"
			<< "4. Dzielenie\n"
			<< "---------------------\n"
			<< "5. Opcje\n"
			<< "---------------------\n"
			<< "9. Wyjscie\n";

		choose = _getch();

		switch (choose)
		{
		case '1':
			addition(Number, range, quantity, correct, missed, percent, enter);
			break;

		case '2':
			subtraction(Number, range, quantity, correct, missed, percent, enter);
			break;

		case'3':
			multiplication(Number, range, quantity, correct, missed, percent, enter);
			break;

		case '4':
			division(Number, range, quantity, correct, missed, percent, enter);
			break;
			
		case '5':
			option_game(range, quantity);
			break;
		case '9':
			exit(0);
				break;
		}
		system("cls");
	}

	return 0;
}