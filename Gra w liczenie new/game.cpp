#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cstdlib>
#include "game.h"

using namespace std;


Values::Values(int quantity, int result) {

	int * x = new int[quantity];
	int * y = new int[quantity];
	this->x = x;
	this->y = y;

	for (int i = 0; i < quantity; i++)
	{
		do {
			x[i] = rand() % result + 1;
			y[i] = rand() % result + 1;
		} while (x[i] + y[i] > result);
	}
}

Values::~Values()
{
	x = NULL;
	y = NULL;
	delete [] x;
	delete [] y;
};

void score(int total, int correct, int missed, int percent)
{
	system("cls");
	cout << "Prawidlowych: " + to_string(correct) + " | Blednych: " + to_string(missed) + " | Procent poprawnych: " + to_string(percent) + "%" + "  Dzialanie: " + to_string(total + 1) << endl << endl
		<< "\n\nWpisz wynik i nacisnij ENTER\n\n\n";

}

void addition(Values &Number, int result, int quantity, int correct, int percent, int missed, int enter)
{ 

	for (int total = 0; total < quantity; total++)
	{
		score(total, correct, missed, percent);
		cout << to_string(Number.x[total]) + " + " + to_string(Number.y[total]) << endl;
		Number.result = Number.x[total] + Number.y[total];
		cin >> enter;
		check_result(enter, Number.result, correct, percent, missed, total);

	}
	end_game(correct, missed, percent);
}

void subtraction(Values &Number, int result, int quantity, int correct, int percent, int missed, int enter)
{
	for (int total = 0; total < quantity; total++)
	{
		score(total, correct, missed, percent);
		if (Number.x[total] < Number.y[total])
		{
			cout << to_string(Number.y[total]) + " - " + to_string(Number.x[total]) << endl;
			Number.result = Number.y[total] - Number.x[total];
		}
		else
		{
			cout << to_string(Number.x[total]) + " - " + to_string(Number.y[total]) << endl;
			Number.result = Number.x[total] - Number.y[total];
		}
		cin >> enter;
		check_result(enter, Number.result, correct, percent, missed, total);

	}
	end_game(correct, missed, percent);
}


void multiplication(Values &Number, int result, int quantity, int correct, int percent, int missed, int enter)
{
	for (int total = 0; total < quantity; total++)
	{
		score(total, correct, missed, percent);
		cout << to_string(Number.x[total]) + " x " + to_string(Number.y[total]) << endl;
		Number.result = Number.x[total] * Number.y[total];
		cin >> enter;
		check_result(enter, Number.result, correct, percent, missed, total);

	}
	end_game(correct, missed, percent);
}

void division(Values &Number, int result, int quantity, int correct, int percent, int missed, int enter)
{
	for (int total = 0; total < quantity; total++)
	{
		score(total, correct, missed, percent);
		if (Number.x[total] < Number.y[total])
		{
			cout << to_string(Number.y[total]) + " : " + to_string(Number.x[total]) << endl;
			Number.result = Number.y[total] / Number.x[total];
		}
		else
		{
			cout << to_string(Number.x[total]) + " : " + to_string(Number.y[total]) << endl;
			Number.result = Number.x[total] / Number.y[total];
		}
		cin >> enter;
		check_result(enter, Number.result, correct, percent, missed, total);

	}
	end_game(correct, missed, percent);
}

void check_result(int enter, int result, int &correct, int &percent, int &missed, int total)
{
	total++;
	if (enter == result) {
		cout << "\nDOBRZE! Zdobywasz punkt!" << endl;
		correct++;
		percent = 100 * (correct) / total;
		Sleep(1000);
	}
	else
	{
		cout << "\nZLE!Poprawna odpowiedz to: " << result << endl;
		missed++;
		percent = 100 * (correct) / total;
		cin.clear();
		cin.ignore(1000, '\n');
		Sleep(2000);
	}
}

void end_game(int correct, int missed, int percent)
{
	cout << endl << endl;
	system("cls");
	cout << "Koniec gry! Twoje wyniki: " << endl << endl
		<< "Prawidlowych: " + to_string(correct) << endl
		<< "Blednych: " + to_string(missed) << endl
		<< "Procent poprawnych: " + to_string(percent) + "%" << endl << endl;
	system("pause");
	system("cls");
}

int option_game(int &range, int &quantity)
{
	char choose2;
	for(;;){
		system("cls");

		cout << "OPCJE: \n"
			<< "---------------------\n"
			<< "1. Zmien zakres liczb\n"
			<< "2. Zmien ilosc wykonywanych dzialan\n"
			<< "3. Przywroc ustawienia domyslne\n";
		choose2 = _getch();
		switch (choose2)
		{
		case '1':
			cout << "\nPodaj nowy zakres liczb od 50 do 10000 (domyslnie 100): \n";
			do {
				cin >> range;
			} while ((range < 50 || range > 10000) && cout << "Niepoprawnie wprowadzone dane! Sprobuj jeszcze raz: \n");

			cout << "Zakres liczb zmieniony na: " + to_string(range) << endl;
			Sleep(2000);
			return range;
			break;

		case '2':
			cout << "\nPodaj nowa ilosc dzialan do wykonania - max. 20 (domyslnie 10): \n";
			do {
				cin >> quantity;
			} while ((quantity > 20 || quantity < 1) && cout << "Niepoprawnie wprowadzone dane! Sprobuj jeszcze raz : \n");
			cout << "Ilosc do wykonania dzialan: " + to_string(quantity) << endl;
			Sleep(2000);
			return quantity;
			break;

		case '3':
				cout << "\nUstawienia domyslne zostaly przywrocone! \n";
				Sleep(2000);
				return quantity = 10, range = 100;
			break;
		}
	}
}