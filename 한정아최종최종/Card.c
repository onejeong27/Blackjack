#include <stdio.h>
#include <stdlib.h>
#include "Result.c"

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

#define TRUE 1
#define FALSE 0

extern int CardTray[N_CARDSET*N_CARD];
extern int cardIndex;	

extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	// 플레이어가 현재 어떤 카드를 들고 있는지 
extern int numCard[N_MAX_USER+1];                  // 플레이어가 현재 몇장의 카드를 들고 있는 
extern int sumCard[N_MAX_USER+1];					// 플레이어가 현재 들고 있는 카드의 합(각 turn마다 계산해서 갱신됨) 
extern int dead[N_MAX_USER+1];				        // 디폴트 FALSE. 오버플로우 발생시 TRUE. 
extern int win[N_MAX_USER+1];						// 디폴트 FALSE. 승리시 TRUE. 
extern int dollar[N_MAX_USER];						// 플레이어 현재 자본 
extern int bet[N_MAX_USER];						// 플레이어가 이번 라운드에서 배팅한 금액 

extern int n_user;

void checkFinalWinner(void);

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

void pullCard(int user) {
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
