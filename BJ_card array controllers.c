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
extern CardTray[N_CARDSET*N_CARD];
extern cardIndex = 0;							


//---------------card array controllers----------------------------
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

