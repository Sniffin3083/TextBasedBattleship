#include "Battleship.h"
using namespace std;
using namespace N;

int main() {
	bool Hit = NULL;
	int position1, position2;
	string choice, ship1 = "ship1", ship2 = "ship2", ship3 = "ship3", ship4 = "ship4";
	int TotalHits = 0, shots = 0;
	/* random number generator between 1 and 10 */
	int RandomNumber = rand() % 10 + 1;

	/* dimentions of the board */
	string BattleShipBoard[10][10];

	cout << "Would you like to play battleship? y/n" << endl;
	cin >> choice;

	if (boost::iequals(choice, "y") || boost::iequals(choice, "yes")) {
		cout << "Randomizing ship locations" << endl;
		/* set ship locations */
		BattleShipBoard[RandomNumber][RandomNumber] = ship1;
		BattleShipBoard[RandomNumber][RandomNumber] = ship2;
		BattleShipBoard[RandomNumber][RandomNumber] = ship3;
		BattleShipBoard[RandomNumber][RandomNumber] = ship4;

		for (int i = 0; i <= sizeof(BattleShipBoard) / sizeof(BattleShipBoard[0]); i++) {
			cout << "Enter the first position (number)" << endl;
			cin >> position1;

			cout << "Enter the second position (number)" << endl;
			cin >> position2;

			cout << "Did you hit it..." << endl;
			Sleep(1000);

			if (BattleShipBoard[position1][position2] == "ship1" || BattleShipBoard[position1][position2] == "ship2" || BattleShipBoard[position1][position2] == "ship3" || BattleShipBoard[position1][position2] == "ship4") {
				cout << "HIT" << endl;
				TotalHits++;
			}
			else
				cout << "Miss :(" << endl;

			if (TotalHits == 4)
				break;

			shots++;

			if (shots == 10) {
				cout << "Do you still wanna keep playing? y/n" << endl;
				cin >> choice;

				if (boost::iequals(choice, "y") || boost::iequals(choice, "yes")) {
					shots = 0;
				}
				else
					break;
			}
		}
		cout << "You hit... \nDrumroll please..." << endl;
		Sleep(1000);
		cout << TotalHits << " SHIPS!!!!";

		if (TotalHits == 4)
			cout << "You got them all! CONGRATS!!" << endl;
		else
			cout << "Better luck next time!" << endl;
	}
	else {
		cout << "Ok. Goodbye. :(" << endl;
		abort;
	}

	return 0;
}