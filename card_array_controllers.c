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




//card array controllers -------------------------------
//mix the card sets and put in the array
int MixCardTray(void) {

	int i;
	for(i=0; i< N_CARD; i++){
		CardTray[i] = rand() % N_CARD;
	
	}
		
	printf("--> Card is Mixed and Put into the Tray");
}

//get one card from the tray
int pullCard(void) {
	
	int i;
	
	i = CardTray[cardIndex];
	cardIndex = cardIndex++;
	
	return i;
}

