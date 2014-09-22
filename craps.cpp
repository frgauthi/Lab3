#include <iostream>
#include <cstdlib>

using namespace std;



int roll();
int die();
int playGame();

int roll(){
	
	return (die() + die());
}

int die(){
	
	return (rand() % 6 + 1);
}

int playGame(){
	int point = 0;	
	int userRoll = roll();
	

	cout << "You rolled: " << userRoll;
	
	switch (userRoll){
	 	
		default:
			point = userRoll;
			cout << " You must now roll a ( " << point << " ) if you roll a 7 first you will lose					!" << endl;
			bool reRoll = true; 
			while(reRoll)
			{
				userRoll = roll();
				
				cout << "You rolled: " << userRoll;				

				if (userRoll == point){
					reRoll = false;
					cout << " You Win!! " << endl;
				}
				else if (userRoll == 7){
					reRoll = false;
					cout << " You lose! :( " << endl;
				}
				else{
					reRoll = true;
					cout << " Roll again? (y/n) ";
					cin >> reRoll;
				}
			}
		break;
		
		case 2:
		case 3:
		case 4:
			cout << " You lose!" << endl;
		break;
		
		 
		case 7:
		case 11:
			cout << " You win!" << endl;
		break;
		}
}

int main(){
	
	
	char ans;
	bool done = false, won = false;
	
	while(!done)
	{
		playGame();
		cout << " Play again (y/n) ?";
		cin >> ans;
		if( ans == 'y' || ans == 'Y') done = false;
		else done = true;
	}

return 0;
}
