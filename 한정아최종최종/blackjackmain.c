#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BeforeTurn.c"
#include "Card.c"
#include "Result.c"
#include "Turn.c"

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

//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							

//player info
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	// 플레이어가 현재 어떤 카드를 들고 있는지 
int numCard[N_MAX_USER+1];                  // 플레이어가 현재 몇장의 카드를 들고 있는 
int sumCard[N_MAX_USER+1];					// 플레이어가 현재 들고 있는 카드의 합(각 turn마다 계산해서 갱신됨) 
int dead[N_MAX_USER+1];				        // 디폴트 FALSE. 오버플로우 발생시 TRUE. 
int win[N_MAX_USER+1];						// 디폴트 FALSE. 승리시 TRUE. 
int dollar[N_MAX_USER];						// 플레이어 현재 자본 
int bet[N_MAX_USER];						// 플레이어가 이번 라운드에서 배팅한 금액 

int n_user;									// 플레이어 수 






//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void);


//get one card from the tray
void pullCard(int user);




//playing game functions -----------------------------

//player settiing
int configUser(void);


//betting
void betDollar(void);

//offering initial 2 cards
void offerCards(void);

//print initial card status
void printCardInitialStatus(void);

int getAction(int userNum);


void printUserCardStatus(int user, int cardcnt);

int calcStepResult(int userNum, int cardNum);
void checkResult(void);
void checkWinner();

void init(void);

int main(int argc, char *argv[]) {
	int i;
	int roundIndex = 1;
	
	srand((unsigned)time(NULL));
	
	
//----------------set the number of players----------------------
	n_user = configUser();
//----------------Game initialization ---------------------------
	//1. players' dollar
	for (i = 0; i < n_user; i++)
		dollar[i] =  N_DOLLAR;

	mixCardTray();
	while (1) {
		printf("\n----------------------------------------------------------");
		printf("\n*************** ROUND %d (CardIndex %d)*******************", roundIndex++, cardIndex);
		printf("\n----------------------------------------------------------\n\n");
		init();
		
		printf("********************* BETTING STEP *************************\n");
		betDollar();
		printf("----------------------------------------------------------\n\n");
		
		printf("********************** CARD OFFERING ***********************\n");
		offerCards(); //1. give cards to all the players
		printCardInitialStatus();
		
		///////////////////////////////////////////////////////////////////////////////
		printf("\n********************* GAME start *************************\n");
			
		for (i = 0; i <= n_user; i++) {
			if (i == 0) {
				printf(">>> my turn! -------------\n");
			}
			else if (i < n_user){
				printf(">>> player %d turn! -------------\n", i);
			}
			else {
				printf(">>> server turn! ------------------------\n");
			}
			
			while(1) {
				printUserCardStatus(i, numCard[i]);
				calcStepResult(i, numCard[i]);
			
				if (dead[i] || win[i]) {
					break;
				}
			
				if (getAction(i) != 0) {
					break;
				}
			
				pullCard(i);
			}
			printf("\n\n");
		}
		checkResult();
		
		printf("-------------------- ROUND %d result ....\n", roundIndex);
		checkWinner();
	} // end of round
	
	return 0;
}
