#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BJ_number of players.c
#include "BJ_card array controllers.c"
#include "BJ_betting.c"
#include "BJ_initial card offer&print.c"
#include "BJ_playerturn.c"
#include "BJ_checkResult.c"
#include "BJ_checkWinner.c"--
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
int cardnum;


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}


int main(int argc, char *argv[]) {
	int roundIndex = 1;
	int user;
	
	srand((unsigned)time(NULL));
	
//----------------set the number of players----------------------
	
	n_user = configUser();


//----------------Game initialization ---------------------------
	//1. players' dollar
	for (user=0; user<n_user; user++)
		dollar[user] =  N_DOLLAR;
	
	//2. card tray	
	mixCardTray();

//------------------------------Game start -----------------------
	do {
		printf("\n----------------------------------------------------------");
		printf("\n*************** ROUND %d (CardIndex %d)*******************", roundIndex, cardIndex);
		printf("\n----------------------------------------------------------\n");
		
		printf("********************* BETTING STEP *************************\n");
		betDollar();
		printf("----------------------------------------------------------\n\n");
		
		offerCards(); //1. give cards to all the players
		printf("********************** CARD OFFERING ***********************\n");
		printCardInitialStatus();
		
		
		printf("\n********************* GAME start *************************\n");
		
		//each player's turn
		for (user=0; user<=n_user; user++) //each player
		{
			while () //do until the player dies or player says stop
			{
				printUserCardStatus();
				calcStepResult();//check the card status ::: calcStepResult()
				getAction();
				
				if(cardindex)
			}
		}
		
//--------------------------------------ROUND RESULT-------------------------------------------------
		
		printf("\n\n******************ROUND %d RESULT******************************", roundIndex);
		checkResult();
		
		for (user=0, user < n_user, user++)
			if dollar[user] = 0;
			
		//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<game End.............i want to go Result!!	
		roundIndex++	
		 
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}
