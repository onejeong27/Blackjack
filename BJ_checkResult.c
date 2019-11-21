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

extern dollar[N_MAX_USER];						//dollars that each player has
extern n_user;									//number of users

extern cardSum[N_MAX_USER];					//sum of the cards
extern bet[N_MAX_USER];						//current betting 



int checkResult() {
		
	int i;
	
	for(i=0; i<n_user; i++){
		
		if(i==0)
			printf("   -->YOUR RESULT : ");
		else
			printf("   -->PLAYER %d RESULT : ", i);
		
		if(CardSum[i]>21)
			printf("Lose due to overflow!   $%d\n", dollar[i]);			
		else if(CardSum[i]==21)
			printf("Congratulation~ Black JacK!!   $%d\n", dollar[i]);
		else if(CardSum[n_user]>21)
			dollar[i] += bet[i]; 
			printf("Dealer Overflow, You Win!   $%d\n", dollar[i]);
		else if(CardSum[n_user]==21)
			dollar[i] -= bet[i];
			printf("Dealer Black Jack, Lose!   $%d\n", dollar[i]);
		else if(CardSum[i] > CardSum[n_user] || (CardSum[i]=21 && CardSum[n_user]=21))
			dollar[i] += bet[i]; 
			printf("You Win!(sum:%d)   $%d\n", CardSum[i],dollar[i]);
		else if(CardSum[i] < CardSum[n_user] || (CardSum[i]>21 && CardSum[n_user]>21))
			dollar[i] -= bet[i]; 
			printf("You Lose!(sum:%d)   $%d\n", CardSum[i],dollar[i]);
	}
	
}
