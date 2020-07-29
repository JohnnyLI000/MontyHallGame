// MontyHallGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void displayDoor(char choice[]);

int main()
{
	char door[3] = { 0,0,0 };
	int playerChoice;
	int prize;
	int AIChoice;
	int lastDoor;
	char respond;
	std::cout << "The Monty Hall game show !\n";
	std::cout << "--------------------------\n";

	do {
		door[0] = 0;
		door[1] = 0;
		door[2] = 0;
		srand(rand());
		prize = 1 + (rand() % 3);
		displayDoor(door);

		std::cout << "which door does the player choose (1/2/3)?";
		std::cin >> playerChoice;
		door[playerChoice - 1] = 'x';

		//determine which door is not player choice and wrong one 
		do {
			srand(rand());
			AIChoice = 1 + (rand() % 3);
			std::cout << "dada" << AIChoice<<"\n";
		} while (AIChoice != prize && door[AIChoice-1] == 0);
		door[AIChoice - 1] = 'o';
		std::cout << "\nAI choose door " << AIChoice << "\n";
		displayDoor(door);

		//check the last door 
		for (int i = 0; i < 3; i++)
		{
			if (door[i] == 0)
			{
				lastDoor = i + 1;
			}
		}

		//check the player wants to swich 
		std::cout << "does the player want to switch from " << playerChoice << "to door " << lastDoor << " (y/n)?";
		std::cin >> respond;
		if (respond == 'y')
		{
			door[playerChoice - 1] = '0';
			door[lastDoor - 1] = 'x';
			playerChoice = lastDoor;
		}
		//std::cout << "prize " << prize << std::endl;
		//for (int i = 0; i < 3; i++)
		//{
		//	std::cout << i << " : " << door[i] << std::endl;

		//}

		//reveal the answer
		for (int i = 0; i < 3; i++)
		{

			door[i] = 'x';

		}
		door[prize - 1] = '$';


		displayDoor(door);

		if (playerChoice == prize)
		{
			std::cout << "congradulation you got the prize!!!" << std::endl;
		}
		else {
			std::cout << "you got it nothing" << std::endl;
		}

		std::cout << "enter y to continue this game ,else enter anything to quit";
		std::cin >> respond;
	} while (respond == 'y');

}

void displayDoor(char choice[]) {
	std::cout << "  ";
	std::cout << "Door" << 1 << "  ";
	std::cout << "Door" << 2 << "  ";
	std::cout << "Door" << 3 << "  " << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "  +---+";
	}
	std::cout << "\n";

	for (int i = 0; i < 3; i++)
	{
		std::cout << "  |   |";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		if(choice[i]!=0)
		{
			std::cout << "  | " << choice[i] << " |";
		}
		else
		{
			std::cout << "  | " << i+1 << " |";
		}
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "  |   |";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "  +---+";
	}
	std::cout << "\n";
	
}


