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

int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}

int getCardNum(int cardnum) {
	
	int i = cardnum % 13;
	
	if(i>= 1 && i<=10)
		return i;
	else if(i==0 || i == 11 || i == 12)
		return 10;
	  
}

//print the card information (e.g. DiaA)
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


//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	int i;
	int cardnum;
	int cardChoosen[N_CARD];
	
	
	
	for (i = 0; i < N_CARD; i++) {
		cardChoosen[i] = FALSE;
	}
	
	
	
	for(i=0; i< N_CARD; i++){
		cardnum = rand() % N_CARD; 
		if (cardChoosen[cardnum] == TRUE) {
			i--;
			continue;
		}
		
		cardChoosen[cardnum] = TRUE;
		CardTray[i] = cardnum;
	}
		
	printf("--> Card is Mixed and Put into the Tray \n");
}


void checkFinalWinner(void) {
	int i;
	int winner;
	int maxFortune = 0;
	for (i = 0; i < n_user; i++) {
		if (dollar[i] > maxFortune) {
			winner = i;
			maxFortune = dollar[i];
		}
	}
	
	printf("\n\n\n -------------------------------------------\n");
	printf(" -------------------------------------------\n");
	printf(" -------------------------------------------\n");
	printf(" -------------------------------------------\n");
	printf("game end! your money :$%d, players' money : \n", dollar[0]);
	for (i = 1; i < n_user; i++) {
		printf("$%d ", dollar[i]);
	}
	printf("\n\n");
	printf("player%d's win \n", winner);
	exit(1);
}

//get one card from the tray
int pullCard(user) {
	if (cardIndex == N_CARD) {
		printf("card ran out of the tray!! finishing the game...\n");
		checkFinalWinner();
	}
	
	cardhold[user][numCard[user]++] = CardTray[cardIndex];
	cardIndex++;
}




//playing game functions -----------------------------

//player settiing
int configUser(void) {
	
	do{
	printf("Input the player of numbers(Max:5) : ");
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
void betDollar(void) {
	int my_bet;

	do{
		printf("your betting(total $%d) = $", dollar[0]);
		my_bet = getIntegerInput();
	
		if(my_bet > dollar[0])
			printf("you only have $%d ! Bet again", dollar[0]);
		else if(my_bet <= 0 )
			printf("-->invalid input for betting");
		else
			bet[0] = my_bet;
	}
	while(my_bet <= 0 || my_bet > dollar[0]);
	
	int i;
	for(i=1; i<n_user; i++) {
		bet[i] = (rand() % N_MAX_BET) + 1;
		printf("player%d bets $%d\n", i, bet[i]);
	}
}


//offering initial 2 cards
void offerCards(void) {
	int i;
	
	pullCard(n_user);
	
	for (i=0;i<n_user;i++){
		pullCard(i);
	}
	
	pullCard(n_user);

	for (i=0;i<n_user;i++){
		pullCard(i);
	}
	return;
}

//print initial card status
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

int getAction(int userNum) {
	int act;
	if(userNum==0) {
		printf("Action? (0 - go, others - stay) : ");
		act=getIntegerInput();
		return act; // 
	}
	else {
		if(sumCard[userNum]>=17) {
			printf("STAY \n");
			return 1;
		}
		else {
			printf("GO \n");
			return 0;
		}
	}	
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}

void calcDealer(int sum) {
	sumCard[n_user] = sum;
	if (sum == 21) {
		win[n_user] = TRUE;
		printf("server BLACKJACK!!! \n");
	}
	else if (sum > 21) {
		dead[n_user] = TRUE;
		printf("server DEAD (sum:%d) \n", sum);
	}
}

void calcPlayer(int userNum, int sum) {
	sumCard[userNum] = sum;
	if (sum == 21) {
		win[userNum] = TRUE;
		dollar[userNum] += 2 * bet[userNum];
		printf("Black Jack! congratulation, you win!! --> +$%d ($%d) \n", 2 * bet[userNum], dollar[userNum]);
	}
	else if (sum > 21) {
		dead[userNum] = TRUE;
		dollar[userNum] -= bet[userNum];
		printf("DEAD (sum:%d) --> -$%d ($%d) \n", sum, bet[userNum], dollar[userNum]);
	}
}

// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int userNum, int cardNum) {
	int i;
	int ace = 0, sum = 0;
	for (i = 0; i < cardNum; i++) {
		if (getCardNum(cardhold[userNum][i]) == 1) {
			ace++;
		}
		sum += getCardNum(cardhold[userNum][i]);
	}
	while (ace > 0) {
		if (sum + 10 <= 21) {
			sum += 10;
		}
		ace--;
	}
	
	if (userNum == n_user) {
		calcDealer(sum);
	}
	else {
		calcPlayer(userNum, sum);
	}
}

void checkResult(void) {
	int i;
	if (sumCard[n_user] == 21) {
		printf("[[[[[[[ server result is .... ....blackjack!! ]]]]]]]\n\n\n");
		for (i = 0; i < n_user ; i++) {
			if (win[i] || dead[i]) { // 이미 승 결정난 블랙잭, 죽은(+패 결정) 오버플로우 플레이어 제외
				continue;
			}
			
			dollar[i] -= bet[i]; // 딜러가 블랙잭인 경우 블랙잭, 오버플로우 아닌 플레이어(승패 결정 없이 살아남음) 모두 패. 배팅 차감.
		}
	}
	else if (sumCard[n_user] > 21) {
		printf("[[[[[[[ server result is .... ....overflow!! ]]]]]]]\n\n\n");
		for (i = 0; i < n_user; i++) {
			if (win[i] || dead[i]) { // 이미 승 결정난 블랙잭, 죽은(+패 결정) 오버플로우 플레이어 제외
				continue;
			}
			
			win[i] = TRUE; // 딜러가 오버플로우인 경우 블랙잭, 오버플로우 아닌 플레이어(승패 결정 없이 살아남음) 모두 승. 배팅 획득.
			dollar[i] += bet[i];
		}
	}
	else {
		printf("[[[[[[[ server result is ....  %d ]]]]]]]\n\n\n", sumCard[n_user]);
		for (i = 0; i < n_user; i++) {
			if (win[i] || dead[i]) { // 이미 승 결정난 블랙잭, 죽은(+패 결정) 오버플로우 플레이어 제외
				continue;
			}

			if (sumCard[i] >= sumCard[n_user]) { // 딜러 카드합보다 플레이어 카드합이 크거나 같은 경우 승. 배팅 획득.
				win[i] = TRUE;
				dollar[i] += bet[i];
			}
			else if (sumCard[i] < sumCard[n_user]) { // 딜러 카드합보다 플레어어 카드합이 작은 경우 팬. 배팅 차감.
				dollar[i] -= bet[i];
			}
		}
	}	
}

int checkWinner() {
	int i, bankrupt = FALSE;
	for (i = 0; i < n_user; i++) {
		if (i == 0)
			printf("   -> your result : ");
		else
			printf("   -> %d'th player's result : ", i);

		if (sumCard[i] == 21) { // 블랙잭
			printf("BlackJack! win --> $%d \n", dollar[i]);
		}
		else if (win[i]) // 블랙잭 아니지만 딜러가 오버플루우인 경우 // 블랙잭 아니지만 딜러 카드합보다 플레어어 카드합이 크거나 같은 경우
			printf("win (sum : %d) --> $%d \n", sumCard[i], dollar[i]);
		else if (dead[i]) { // 오버플로우
			printf("lose due to overflow! --> $%d \n", dollar[i]);
			if (dollar[i] == 0) {
				bankrupt = TRUE;
				printf("   -> bankrupted! game will be ended \n");
			}
		}
		else { // 오버플로우 아니지만 딜러가 블랙잭인 경우 // 오버플로우 아니지만 딜러 카드합보다 플레이어 카드합이 작은 경우
			printf("lose (sum : %d) --> $%d \n", sumCard[i], dollar[i]);
			if (dollar[i] == 0) {
				bankrupt = TRUE;
				printf("   -> bankrupted! game will be ended \n");
			}
		}	
	}
	if (bankrupt == TRUE) {
		checkFinalWinner();
	}
	printf("\n\n");
}

void init(void) {
	int i;
	for (i = 0; i <= n_user; i++) {
		numCard[i] = 0;
		win[i] = FALSE;
		dead[i] = FALSE;
	}
}

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
