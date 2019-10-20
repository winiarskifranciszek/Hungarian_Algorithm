// Hungarian_Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int SIZE = 0;
	cout << "Podaj rozmiar maciezy." << endl;
	cin >> SIZE;
	int **  INPUT_MATRIX;
	
	INPUT_MATRIX = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
		INPUT_MATRIX[i] = new int[SIZE];
	int CHOOSE;
	cout << "Podaj opcje" << endl;
	cout << "1: wpisanie racznie" << endl;
	cout << "2: wartosli losowe" << endl;
	cout << "3:wprowadz z pliku" << endl;
	cin >> CHOOSE;
	if (CHOOSE == 1)
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				cin >> INPUT_MATRIX[i][j];

		}

	if (CHOOSE == 2) {
		cout << "Zakres wartosci [min][max]" << endl;
		int min, max;
		cin >> min >> max;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++) {
				int x = rand() % (max - min)+min;
				INPUT_MATRIX[i][j] = x;

			}

		}
	}


	if (CHOOSE == 3) {
		//dodanie z pliku
	}
	int **  ORGIN_MATRIX;

	ORGIN_MATRIX = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
		ORGIN_MATRIX[i] = new int[SIZE];

	ORGIN_MATRIX = INPUT_MATRIX;

	cout << "Wprowadzona maciez" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			cout << ORGIN_MATRIX[i][j] << " ";

		}
		cout << endl;

	}

	for (int i = 0; i < SIZE; i++)
	{
		int index;
		index = INPUT_MATRIX[i][0];
		for (int j = 0; j < SIZE; j++)
		{
			if (INPUT_MATRIX[i][j] < index)
				index = INPUT_MATRIX[i][j];
		}

		for (int j = 0; j < SIZE; j++)
		{
			INPUT_MATRIX[i][j] -= index;
		}
	}


	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			cout << INPUT_MATRIX[i][j] << " ";

		}
		cout << endl;

	}

	for (int i = 0; i < SIZE; i++)
	{
		int index;
		index = INPUT_MATRIX[0][i];
		for (int j = 0; j < SIZE; j++)
		{
			if (INPUT_MATRIX[j][i] < index)
				index = INPUT_MATRIX[j][i];
		}

		for (int j = 0; j < SIZE; j++)
		{
			INPUT_MATRIX[j][i] -= index;
		}
	}

	cout << endl;
	cout << endl;
	cout << "Maciez po zerowaniu elementow" << endl;
	


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			cout << INPUT_MATRIX[i][j] << " ";

		}
		cout << endl;

	}

	cout << endl; 
	cout << endl;
	cout << "2 mazxiec   " << endl;
	int **  SECOND_MATRIX;

	SECOND_MATRIX = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
		SECOND_MATRIX[i] = new int[SIZE];

	SECOND_MATRIX = INPUT_MATRIX;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			cout << SECOND_MATRIX[i][j] << " ";

		}
		cout << endl;

	}
	cout << endl;
	cout << endl;




	// sprawdzanie ilosci zer
	bool ZERO_EX = true;
	int count = 0;
	while (ZERO_EX==true) {

		int CHEEK = 1;
		int ROW, CEL = 0;
		int ZERO_COUNT = 0;
		int CURRENT_ZERO = 0;
		for (int i = 0; i < SIZE; i++) {
			CURRENT_ZERO = 0;
			int j = 0;
			for (j = 0; j < SIZE; j++) {
				if (SECOND_MATRIX[j][i] == 0)
					CURRENT_ZERO++;

			}
			if (CURRENT_ZERO > ZERO_COUNT)
			{

				ROW = i;


				ZERO_COUNT = CURRENT_ZERO;

			}
		}
		cout << "Najwieksza ilosc zer w kolumnach   " << ZERO_COUNT << " w kolumnie  " << ROW << endl;


		int ZERO_COUNT_2 = 0;
		int CURRENT_ZERO_2 = 0;
		for (int i = 0; i < SIZE; i++) {
			CURRENT_ZERO_2 = 0;
			int j = 0;
			for (j = 0; j < SIZE; j++) {
				if (SECOND_MATRIX[i][j] == 0) {
					CURRENT_ZERO_2++;
				}
			}
			if (CURRENT_ZERO_2 > ZERO_COUNT_2) {
				ZERO_COUNT_2 = CURRENT_ZERO_2;

				CEL = i;


			}
		}
		cout << "Najwieksza ilosc zer w wersach    " << ZERO_COUNT_2 <<  "w wierszu " << CEL << endl;
		cout << ZERO_COUNT << endl;
		cout << ZERO_COUNT_2 << endl;

		if (ZERO_COUNT >= ZERO_COUNT_2) {
			
			for (int j = 0; j < SIZE; j++) {
			
						SECOND_MATRIX[j][ROW] = 999;
				}

		}
		else
			
			for (int j = 0; j < SIZE; j++) {
				
					SECOND_MATRIX[CEL][j] = 999;
			}

			
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++) {
				if (SECOND_MATRIX[j][i] == 0)
					CHEEK = 0;
				
			}


		}
		if (CHEEK == 1) {
			ZERO_EX = false;
			break;
		}
		
		if (count>10)
			ZERO_EX = false;
		count++;
	}


	cout << endl;
	cout << endl;
	cout << endl;
	cout <<"maciez po elminacji zer"<< endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			cout << SECOND_MATRIX[i][j] << " ";

		}
		cout << endl;

	}
return 0;


}