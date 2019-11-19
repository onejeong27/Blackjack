#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30


//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag






int main(void){
	
	getCardNum();
	printCard();
	
	return 0;
}


//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	int cardnum[4][13] = {
	{1,2,3,4,5,6,7,8,9,10,10,10,10,}
	{1,2,3,4,5,6,7,8,9,10,10,10,10,}
	{1,2,3,4,5,6,7,8,9,10,10,10,10,}
	{1,2,3,4,5,6,7,8,9,10,10,10,10,}
	}
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	
	int i,j;
	int cardnum[i][j];
	for (i=0; i<4; i++){
		for (j=0,; j<13; j++);{
		if(i==0);
			cardnum[i][j] = DiAMOND[j];
		else if(i==1);
			cardnum[i][j] = CLOVER[j];
		else if(i==2);
			cardnum[i][j] = HEART[j];
		else
			cardnum[i][j] = SPACE[j];
		}
		
	}
	
}


