/*
Assignment 4
Sean Miner - miners@my.normandale.edu

This program simulates escalating series of coin flips and die rolls,
giving an illustration of how random rand() is.
*/

#include <stdio.h>

void callBoth(int count);

void flipCountCoins(int count);
void rollCountDice(int count);

int flipCoin();
int rollDie();

float getPer(int part, int total);


int main() {
	
	// Store test number values.
	int countArray[5] = {10, 100, 1000, 10000, 10000};
	int i;
	
	// Perform the indicated number of both tests.
	for (i = 0; i < 5; i++) {
		callBoth(countArray[i]);
	}
	
	return 0;
	
} // End main()


void callBoth(int count){

	flipCountCoins(count);
	rollCountDice(count);	
	printf("********************\n\n");
	
} // End callBoth(int)


void flipCountCoins(int count) {

	int headsCount = 0;
	int tailsCount = 0;
	int i = 0;
	
	// Call flipCoin() count times,
	// incrementing appropriate counter based on result	
	for (i = count; i>0; i--){
		flipCoin() ? headsCount++ : tailsCount++;
	}
	
	//Print count and percentages
	printf("Coin:\n-----\nFlips: %d\n", count);
	printf("\nHeads: %2.2f%%", getPer(headsCount, count));
	printf("\nTails: %2.2f%%\n\n", getPer(tailsCount, count));
	
} // End flipCountCoins(int)


void rollCountDice(int count) {
	
	int resultCountArray[6] = {0, 0, 0, 0, 0, 0};
	int i = 0;

	// Call rollDie() count times, 
	// incrementing appropriate array elements based on result	
	for (i = count; i>0; i--){
		resultCountArray[rollDie()]++;
	}

	// Print results
	printf("Die:\n----\nRolls: %d\n", count);
	for (i = 0; i<6; i++) {
		printf("\n%ds: %2.2f%%", (i+1), getPer(resultCountArray[i], count));
	}
	
	printf("\n\n");
			
} // End rollCountDice(int)


int flipCoin() {
	
	return (rand()%2);		

} // End flipCoin()


int rollDie() {
	
	return (rand()%6);		

} // End flipCoin()


float getPer(int part, int total) {
	
	return 100 * ((float)part/(float)total);
	
} // End getPer(2)
