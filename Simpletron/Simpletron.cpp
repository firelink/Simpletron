// Simpletron.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//0. 1099 - Read input into 99
//1. 1020 - Read input into 20
//2. 2020 - Load input from 20
//3. 4217 - Branch to halt if zero
//4. 2001 - Load 1 into accumulator
//5. 3099 - Add 99 to accumulator
//6. 2101 - Store accumulator at 1
//7. 2002 - Load 2 into accumulator
//8. 3099 - Add 99 to accumulator
//9. 2102 - Store accumulator at 2
//10. 2098 - Load 1 to add
//11. 3020 - Add 20 to 2098
//12. 2198 - Store as new 98
//13. 2011 - Load 11 into accumulator
//14. 3099 - Add 1 to accumulator
//15. 2111 - Store as new 11
//16. 4001 - Go back to 1
//17. 1198 - Write out the sum
//18. 4300 - Halt


int _tmain(int argc, _TCHAR* argv[])
{
	// I/O
	const int READ = 10;
	const int WRITE = 11;

	// Load/store
	const int LOAD = 20;
	const int STORE = 21;

	// Arithmetic
	const int ADD = 30;
	const int SUBTRACT = 31;
	const int DIVIDE = 32;
	const int MULTIPLY = 33;

	// Transfer of control
	const int BRANCH = 40;
	const int BRANCHNEG = 41;
	const int BRANCHZERO = 42;
	const int HALT = 43;

	int inMemory = 0;
	int memory[100];

	int counter;
	int accumulator;
	int operationCode;
	int operand;
	int instructionRegister;

	cout << "*** Welcome to Simpletron! ***" << endl;
	cout << endl;
	cout << "*** Please enter your program one instruction ***" << endl;
	cout << "*** (or data word) at a time. I will type the ***" << endl;
	cout << "*** location number and a question mark (?).  ***" << endl;
	cout << "*** You then type the word for that location. ***" << endl;
	cout << "*** Type the sentinel -99999 to stop entering ***" << endl;
	cout << "*** your program. ***" << endl << endl;

	for(int i = 0; i < 100; i++)
		memory[i] = 0;

	while(true)
	{
		int temp;

		if(inMemory < 10)
			cout << "0" << inMemory << " ? ";
		else
			cout << inMemory << " ? ";

		cin >> temp;

		if(temp == -99999){break;}
		else{memory[inMemory++] = temp;}
	}

	cout << endl;

	cout << endl << "*** Program loading completed ***" << endl;
	cout << "*** Program execution begins  ***" << endl;

	//begin execution
	counter = 0;
	accumulator = 0;
	operationCode = 0;
	operand = 0;
	instructionRegister = 0;

	while(true)
	{
		instructionRegister = memory[counter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;

		switch(operationCode)
		{
		case READ:
			cout << "? ";
			cin >> memory[operand];
			counter++;
			break;
		case LOAD:
			accumulator = memory[operand];
			counter++;
			break;
		case STORE:
			memory[operand] = accumulator;
			counter++;
			break;
		case ADD:
			accumulator += memory[operand];
			counter++;
			break;
		case SUBTRACT:
			accumulator -= memory[operand];
			counter++;
			break;
		case MULTIPLY:
			accumulator *= memory[operand];
			counter++;
			break;
		case DIVIDE:
			accumulator /= memory[operand];
			counter++;
			break;
		case WRITE:
			cout << endl << memory[operand] << endl;
			counter++;
			break;
		case BRANCH:
			counter = operand;
			break;
		case BRANCHZERO:
			if(accumulator == 0)
				counter = operand;
			else{counter++;}
			break;
		case BRANCHNEG:
			if(accumulator < 0)
				counter = operand;
			else{counter++;}
			break;
		case HALT:
			cout << endl << "*** Simpletron execution terminated ***" << endl;
			cout << endl << endl;
			cout << setw(4) << " " << "REGISTERS:" << endl;
			cout << setw(4) << " " << "accumulator" << setw(12) << "+";
			if(accumulator < 10){cout << "000";}
			else if(accumulator < 100){cout << "00";}
			else if(accumulator < 1000){cout << "0";}
			cout << accumulator << endl;
			cout << setw(4) << " " << "counter" << setw(20) << counter << endl;
			cout << setw(4) << " " << "instructionRegister" << setw(4) << "+";
			if(instructionRegister < 10){cout << "000";}
			else if(instructionRegister < 100){cout << "00";}
			else if(instructionRegister < 1000){cout << "0";}
			cout << instructionRegister << endl;
			cout << setw(4) << " " << "operationCode" << setw(14) << operationCode << endl;
			cout << setw(4) << " " << "operand" << setw(20) << operand << endl;
			cout << " " << endl << setw(4) << " " << "MEMORY:" << endl;
			for(int i = 0; i < 10; i++)
			{
				if(0 == i){cout << setw(12) << i;}
				else{cout << setw(7) << i;}
			}
			for(int i = 0; i < 100; i++)
			{
				if(!(i % 10))
				{
					cout << endl << " " << setw(2) << i << setw(5) << "+";
					if(memory[i] < 10){cout << "000";}
					else if(memory[i] < 100){cout << "00";}
					else if(memory[i] < 1000){cout << "0";}
					cout << memory[i];
				}
				else
				{
					cout << setw(3) << "+";
					if(memory[i] < 10){cout << "000";}
					else if(memory[i] < 100){cout << "00";}
					else if(memory[i] < 1000){cout << "0";}
					cout << memory[i];
				}
			}
			cout << endl;
			counter++;
			exit(0);
		}

		//if(counter >= inMemory){break;}
	}


	return 0;
}

