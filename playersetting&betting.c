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



//player settiing
int configUser(void) {
	
	do{
	
	
	printf("Input the player of numbers(Max:5) : ");
	scanf("%d", &n_user);
	
	n_user = getIntegerInput();
	
	if(n_user > N_MAX_USER)
		printf("Too Many Players\n");
	else if(n_user <= 0)
		printf("Invalid Players Input\n");
	else 
		return n_user;
	}
	
	while(n_user <= 0 || n_user > N_MAX_USER);
}

//betting
int betDollar(void) {
	
	int my_bet;
	bet[0] = my_bet;
	
	do{
	dollar[0] =50;
	printf("your betting(total $ %d ) = $ ", dollar[0]);
	scanf("%d", &my_bet);
	
	if(my_bet > dollar[0])
		printf("you only have $ %d ! Bet again", dollar[0]);
	else if(my_bet <= 0 )
		printf("-->invalid input for betting");
	else return my_bet;
	}
	
	while(my_bet <=0 || my_bet > dollar[0]);
	
	int i;
	for(i=1;i<(n_user);i++)
		bet[i] = (rand() % N_MAX_BET) + 1;
		printf("player %d bets $ %d\n", i, bet[i]);
}
