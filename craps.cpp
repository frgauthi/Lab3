#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int userBet= 0,tokens = 50;

int roll();
int die();		// prototypes of the functions used
int playGame();

void bet(){
	do{
	cout << "You currently have " << tokens << " tokens." << endl;
	cout << "How much do you want to bet?: ";
	cin >> userBet;
	cout << endl;
	}while (userBet > tokens);

}

int roll(){
	
	return (die() + die());		// roll two die and combine the sum
}

int die(){
			// get clock seed value
	return (rand() % 6 + 1);	// roll a random number between 1 and 6
}

int playGame(){
	bool reRoll = true;		// initialize reRoll for the reroll loop
	int point = 0;			// initialize the point value
	int userRoll = roll();		// roll the dice and assign the value to userRoll
	

	cout << "You rolled: " << userRoll; 		// output what the user rolled
	
	switch (userRoll){
	 	
		default: 				// if the user rolls 4,5,6,8,9, or 10
			
			point = userRoll; 		// set the point value for the user to try to roll

			cout << " You must now roll a ( " << point << " ) if you roll a 7 first you will lose!" << endl; // prompt user to hit enter to reroll
			cout << "Press <Enter> to roll again... " << endl << endl;		
			cin.ignore();
			cin.ignore();

					// loop to reroll until the user rolls a 7 or the point value
			while(reRoll) 	// reRoll is initially true and is set in every case after the dice are rerolled according to the new roll
			{
				
				userRoll = roll();			// reroll and assign the value to userRoll 
				
				cout << "You rolled: " << userRoll;

				if (userRoll == point){ 		// if the user rolls the point value dont reRoll output that the user won
					reRoll = false;
					cout << " You Win!! " << endl;
					tokens = tokens + 2*userBet;
				}
				else if (userRoll == 7){		// if a 7 is rolled before the user rolls the point value dont reroll, output that the user lost
					reRoll = false;
					cout << " You lose! :( " << endl;
					tokens = tokens - userBet;
				}
				else{
					reRoll = true;			// if any other value is rolled prompt user to hit enter to reroll
					cout << endl <<  "Press <Enter> to roll again.. " << endl;
					cin.ignore();
				}
			cout << endl;
			}
		break;
		
		case 2:
		case 3:
		case 4:
			cout << endl << "The house wins and you lose :(" <<  endl<< endl;
					tokens = tokens - userBet;						 	//if the user rolls 2,3, or 4 output that the user lost
		break;
		
		 
		case 7:
		case 11:
			cout << " You win!" << endl << endl; // if a user rolls 7 or 11 out put that the user wins
			tokens = tokens + 2*userBet;
		break;
		}
}

int main(){
	
	
	
	char ans; 		// declare ans to store user y/n for playing again 
	bool playAgain = true,canPlay =true; 	// initialize playAgain to be true 
	
	while(playAgain && canPlay) 	// loop until player answers no to playagain
	{
		
		bet();
		srand(time(NULL)); // get seed value for rand
		playGame(); 					// call the playgame function
		cout << " Play again? (y/n): ";			// ask user to play again
		cin >> ans;					// store users answer in ans
		if( ans == 'y' || ans == 'Y') playAgain = true;	// if user enters y, set playAgain to true 	
		else playAgain = false;				// otherwise playAgain is assigned false
		cout << endl;
		if (tokens > 0)	canPlay = true;
		else {
		cout << endl << "You ran out of tokens! better luck next time.. " << endl;
		canPlay = false;
		}	
	}

return 0;
}
