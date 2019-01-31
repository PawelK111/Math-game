#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cstdlib>

using namespace std;


class Values {

public:

	int * x;
	int * y;
	int result;
	Values(int q, int r);
    ~Values();
};

void score(int total, int correct, int missed, int percent);

void addition(Values &Number, int result, int quantity, int correct, int percent, int missed, int enter);
void subtraction(Values &Number, int result, int quantity, int correct, int percent, int missed, int enter);
void multiplication(Values &Number, int result, int quantity, int correct, int percent, int missed, int enter);
void division(Values &Number, int result, int quantity, int correct, int percent, int missed, int enter);

void check_result(int enter, int result, int &correct, int &percent, int &missed, int total);
void end_game(int correct, int missed, int percent);

int option_game(int &range, int &quantity);
