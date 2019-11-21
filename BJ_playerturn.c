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

extern CardTray[N_CARDSET*N_CARD];							
extern n_user;									//number of users
extern cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
extern cardSum[N_MAX_USER];	 				   //sum of the cards
extern cardnum;



void printUserCardStatus(int user, int cardcnt) {

	int i;
	
	printf("   -> card : ");
	
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}


int getAction(void) {
	
	int i;
	int act;
	
	if(i==0)
		
		printf("Do you Want to Go?(1:YES , 2:others):  ");
		act=getIntegerInput();
		
		if(act==1)
			cardhold[i][cardnum] = pullcard();		
		
		
	else 
		if(CardSum[i]>=17);
			pirntf("   STAY")
		else
			printf("   GO")
			cardhold[i][cardnum] = pullcard();
	
}

int calcStepResult() {
		
	int CardSum(int cardum, int user){
		
		CardSum[user]=0; 
		
		if(cardnum%13>=2 && cardnum%13<=10)
			CardSum[user]+=cardnum%13;
		
		else if(cardnum%13==11 || cardnum%13==12 || cardnum%13==0)
			CardSum[user]+=10;
		else (card%13==1)
			CardSum[user]+=1;
	}
	
	int Calculate_A(int user){
		
		int i
		
		if (cardhold[user][i]%13==1){
			if(CardSum[user]<=11)
				CardSum[user]+=10;}
			
	}
	
}


