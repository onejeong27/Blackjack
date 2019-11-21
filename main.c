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

#define TRUE 1
#define FALSE 0

//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int numCard[N_MAX_USER+1];
int win[N_MAX_USER+1];
int dead[N_MAX_USER+1];
int sum[N_MAX_USER+1];

int n_user;									//number of users


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
	else if(j==1);
		printf("A");
	else if(j==11)
		printf("J");
	else if(j==12)
		printf("Q");
	else 
		printf("%d", j);
	
	
}


//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	
	int i;
	for(i=0; i< N_CARD; i++){
		CardTray[i] = rand() % N_CARD;
	
	}
		
	printf("--> Card is Mixed and Put into the Tray");
}

}

//get one card from the tray
int pullCard(void) {
	
	int i;
	if (cardIndex == N_CARD) {
		printf("card ran out of the tray!! finishing the game...\n");
		checkFinalWinner();
	}
	
	i = CardTray[cardIndex];
	cardIndex = cardIndex++;
	
	return i;
}

void checkFinalWinner(void) {
	int winner;
	int maxFortune = 0;
	for (int i = 0; i < n_user; i++) {
		if (dollar[user] > maxFortue) {
			winner = user;
			maxFortue = dollar[user];
		}
	}
	
	printf(" -------------------------------------------\n");
	printf(" -------------------------------------------\n");
	printf(" -------------------------------------------\n");
	printf(" -------------------------------------------\n");
	printf("game end! your money :$%d, players' money : \n", dollar[0]);
	for (int i = 1; i < n_user; i++) {
		printf("$%d ", dollar[user]);
	}
	printf("\n\n");
	printf("player%d's win \n", winner);
	exit(0);
}


//playing game functions -----------------------------

//player settiing
int configUser(void) {
	
	do{
	
	printf("Input the player of numbers(Max:5) : ")
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
		printf("your betting(total $ %d ) = $ ", dollar[0]);
		my_bet = getIntegerInput();
	
		if(my_bet > dollar[0])
			printf("you only have $ %d ! Bet again", dollar[0]);
		else if(my_bet <= 0 )
			printf("-->invalid input for betting");
		else return my_bet;
	}
	while(my_bet <=0 || my_bet > dollar[0]);
	
	int i;
	for(i=1; i<n_user; i++)
		bet[i] = (rand() % N_MAX_BET) + 1;
		printf("player %d bets $ %d\n", i, bet[i]);
	
}


//offering initial 2 cards
void offerCards(void) {
	int i;
	
	cardhold[n_user][0] = pullCard();
	cardNum[n_user]++;
	
	for (i=0;i<n_user;i++){
		cardhold[i][0] = pullCard();
		cardNum[i]++;
	}
	
	cardhold[n_user][1] = pullCard();
	cardNum[n_user]++; 

	for (i=0;i<n_user;i++){
		cardhold[i][1] = pullCard();
		cardNum[i]++;
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

int getAction(int userNum) {
	int act;
	if(userNum==0) {
		printf("Action? (0 - go, others - stay) : ");
		act=getIntegerInput();
		if (act == 0) {
			printf("GO");
		}
		else {
			printf("STAY");
		}
		retrun act; // 
	}
	else {
		if(CardSum[i]>=17) {
			printf("STAY");
			return 1;
		}
		else {
			printf("GO");
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

// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int userNum, int cardNum) {
	int ace = 0, sum = 0;
	for (int i = 0; i < cardNum; i++) {
		if (getCardNum(i) == 1) ace++;
		sum += getCardNum(i);
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

void calcDealer(int sum) {
	sum[n_user] = sum;
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
	sum[userNum] = sum;
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

void checkResult(void) {
	if (sum[n_user] == 21) {
		printf("[[[[[[[ server result is .... ....blackjack!! ]]]]]]]\n\n\n");
		for (int i = 0; i < n_user ; i++) {
			if (win[i] || dead[i]) { // 이미 승 결정난 블랙잭, 죽은(+패 결정) 오버플로우 플레이어 제외
				continue;
			}
			
			dollar[i] -= bet[i]; // 딜러가 블랙잭인 경우 블랙잭, 오버플로우 아닌 플레이어(승패 결정 없이 살아남음) 모두 패. 배팅 차감.
		}
	}
	else if (sum[n_user] > 21) {
		printf("[[[[[[[ server result is .... ....overflow!! ]]]]]]]\n\n\n");
		for (int i = 0; i < n_user; i++) {
			if (win[i] || dead[i]) { // 이미 승 결정난 블랙잭, 죽은(+패 결정) 오버플로우 플레이어 제외
				continue;
			}
			
			win[i] = TRUE; // 딜러가 오버플로우인 경우 블랙잭, 오버플로우 아닌 플레이어(승패 결정 없이 살아남음) 모두 승. 배팅 획득.
			dollar[i] += bet[i];
		}
	}
	else {
		printf("[[[[[[[ server result is ....  %d ]]]]]]]\n\n\n", dealer->sumOfCards);
		for (int i = 0; i < n_user; i++) {
			if (win[i] || dead[i]) { // 이미 승 결정난 블랙잭, 죽은(+패 결정) 오버플로우 플레이어 제외
				continue;
			}

			if (sum[i] >= sum[n_user]) { // 딜러 카드합보다 플레이어 카드합이 크거나 같은 경우 승. 배팅 획득.
				win[i] = TRUE;
				dollar[i] += bet[i];
			}
			else if (sum[i] < sum[n_user]) { // 딜러 카드합보다 플레어어 카드합이 작은 경우 팬. 배팅 차감.
				dollar[i] -= bet[i];
			}
		}
	}	
}

int checkWinner() {
	for (int i = 0; i < n_user; i++) {
		if (i == 0)
			printf("   -> your result : ");
		else
			printf("   -> %d'th player's result : ", i);

		if (sum[i] == 21) { // 블랙잭
			printf("BlackJack! win ($%d) \n", dollar[i]);
		}
		else if (win[i]) // 블랙잭 아니지만 딜러가 오버플루우인 경우 // 블랙잭 아니지만 딜러 카드합보다 플레어어 카드합이 크거나 같은 경우
			printf("win (sum : %d) --> $%d \n", sum[i], dollar[i]);
		else if (dead[i]) // 오버플로우
			printf("lose due to overflow! ($%d) \n", dollar[i]);
		else // 오버플로우 아니지만 딜러가 블랙잭인 경우 // 오버플로우 아니지만 딜러 카드합보다 플레이어 카드합이 작은 경우
			printf("lose (sum : %d) --> $%d \n", sum[i], dollar[i]);
	}
	printf("\n\n");
}
