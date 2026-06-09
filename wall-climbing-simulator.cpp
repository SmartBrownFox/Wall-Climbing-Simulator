// Purpose: This program is supposed to simulate a wall climbing competition between 2 players.
// The players are of which whom randomly ascend or descend a wall at a random given moment.
// (This program contains objects, class design, random (%) game mechanics)
// Author: Wesley Charlton


#include "wall.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>  // used to generate a random number
#include<windows.h> // used to pause a windows display

using namespace std;
const int TOP_OF_WALL = 20; // Change this if you would like the height of the wall to be your own "#"
int main()
{
	wall player1("Player 001"), player2("Player 456");
	int player1turn, player2turn; // use to decide if the player should climb or drop
	bool winner = false;		// use to terminate the loop once a player reaches the top of the wall

	unsigned seed = time(0);	// use top get a different set of ramdom numbers
	srand(seed);				// part of the random number process

	while (!winner)				// while there is not a winner the loop iterates
	{
		system("CLS");			// clears the screen (stdlib needed)

		cout << "==================== Top of the World!! =======================\n";
		player1turn = (rand() % 2);	// randomly generates a number from 0 to 1
		player2turn = (rand() % 2);	// 1 means the player will climb, 0 means player drops

		// Execute moves for player 1
		if (player1turn == 1) {
			player1.climb();  // Climb up if turn is 1
		} else {
			player1.drop();   // Drop down if turn is 0
		}

		// Execute moves for player 2
		if (player2turn == 1) {
			player2.climb();  // Climb up if turn is 1
		} else {
			player2.drop();   // Drop down if turn is 0
		}

		//My test to make sure the a player does go below the ground.
		if (player1.getposition() < 0 || player2.getposition() < 0)
		{
			cout << "ERROR IN CODE" << endl;
			exit(1);
		}
		//animated wall with player labels
		cout << "---------------------------------------------------------------\n";
		for (int k = TOP_OF_WALL; k >= 0; k--)
		{
			if (k == 0 || k == 19)
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << setw(5) << k;
			if (player1.getposition() == k || (k == TOP_OF_WALL && player1.getposition() >= TOP_OF_WALL))
				cout << setw(15) << player1.getname();
			else
				cout << setw(15) << " ";

			if (player2.getposition() == k || (k == TOP_OF_WALL && player2.getposition() >= TOP_OF_WALL))
				cout << setw(15) << player2.getname();
			cout << endl;

		}
		cout << "---------------------------------------------------------------\n";
		Sleep(400); // pauses
		//Determine if there is a winner. Display the winner and set the condition
		//to exit the loop. If there is a tie, player 1 wins.

		// If tie, player 1 wins
		if (player1.getposition() >= TOP_OF_WALL || player2.getposition() >= TOP_OF_WALL) {
			winner = true; // Exit loop

// Determine and announce winner
			if (player1.getposition() >= TOP_OF_WALL) {
				cout << "\n*** " << player1.getname() << " WINS THE CLIMBING COMPETITION! ***\n";
			} else {
				cout << "\n*** " << player2.getname() << " WINS THE CLIMBING COMPETITION! ***\n";
			}
		}
	}

	return 0;
}




}
return 0;
}
//end of code