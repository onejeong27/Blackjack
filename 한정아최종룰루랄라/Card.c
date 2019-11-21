#include <stdio.h>
#include <stdlib.h>

int mixCardTray(void) {
	int i;
	int cardnum;
	int cardChoosen[N_CARD];
	
	for (i = 0; i < N_CARD; i++) { // cardChoosen 배열을 통해 중복된 카드 선택을 체크한다.  
		cardChoosen[i] = FALSE;
	}
	
	
	for(i=0; i< N_CARD; i++){
		cardnum = rand() % N_CARD; 
		if (cardChoosen[cardnum] == TRUE) { // TRUE면 이미 골라진거 
			i--;
			continue;
		}
		
		cardChoosen[cardnum] = TRUE;
		CardTray[i] = cardnum;
	}
		
	printf("--> Card is Mixed and Put into the Tray \n");
}

int pullCard(user) {
	if (cardIndex == N_CARD) {
		printf("card ran out of the tray!! finishing the game...\n");
		checkFinalWinner();
	}
	
	cardhold[user][numCard[user]++] = CardTray[cardIndex];
	cardIndex++;
}

void printCard(int cardnum) {
	int i, j;
	i = cardnum / 13;
	j = cardnum % 13;
	
	if(i==0)
		printf("DIA");
	else if(i==1)
		printf("HRT");
	else if(i==2)
		printf("CLV");
	else 
		printf("SPD");	
	
	
	if(j==0)
		printf("King ");
	else if(j==1)
		printf("Ace ");
	else if(j==11)
		printf("Jack ");
	else if(j==12)
		printf("Queen ");
	else 
		printf("%d ", j);
}

void printCardInitialStatus(void) {
	int i;
	printf(" --- server      : ");
	printf("X "); printCard(cardhold[n_user][1]);
	printf("\n");
	
	printf("   -> you        : ");
	printCard(cardhold[i][0]); printCard(cardhold[i][1]);
	printf("\n");
	
	for(i=1; i<n_user; i++){
		printf("   -> player%d    : ", i);
		printCard(cardhold[i][0]); printCard(cardhold[i][1]);
		printf("\n");
	}
}

void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}
