#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

extern n_user
extern cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];

//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	
	int i = cadnum % N_MAX_CARDNUM ;
	
	if(i>= 1 && i<=10)
		return i;
	else if(i==0 || i == 11 || i == 12)
		return 10;
	  
}


//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	
	scanf("%d", &cardnum);
	
	int i = cardnum / N_MAX_CARDNUM; 	//int i =0,1,2,3
	int j = cardnum % N_MAX_CARDNUM;	//int j =0,1,2,3,4,5,6,7,8,9,10,11,12
	
	if(i==0)
		printf("DIAMOND");
	else if(i==1)
		printf("HEART");
	else if(i==2)
		printf("CLOVER");
	else 
		printf("SPADE");	
	
	
	if(j==0)
		printf("K");
	else if(j==1)
		printf("A");
	else if(j==11)
		printf("J");
	else if(j==12)
		printf("Q");
	else 
		printf("%d", j);
	
}

//offering initial 2 cards
void offerCards(void) {
	
	int i;
	
	cardhold[n_user][0] = pullCard();
	
	for (i=0;i<n_user;i++){
		cardhold[i][0] = pullCard();	
	}
	
	cardhold[n_user][1] = pullCard();

	for (i=0;i<n_user;i++){
		cardhold[i][1] = pullCard();	
	}
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
	
	int i;
	
	printf("-----server : ?  ");
	printCard(cardhold[n_user][1]);
	
	printf("\n   -->you: ");
	printCard(cardhold[i][0]);
	printf("  ")
	printCard(cardhold[i][1]);
	
	for(i=1; i<n_user; i++){
		
		printf("\n   -->player %d : ", i);
		printCard(cardhold[i][0]);
		printf("  ")
		printCard(cardhold[i][1]);
	}
}

