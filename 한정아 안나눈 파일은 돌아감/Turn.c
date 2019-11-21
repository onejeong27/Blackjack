#include <stdio.h>



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

int getCardNum(int cardnum) {
	
	int i = cardnum % 13;
	
	if(i>= 1 && i<=10)
		return i;
	else if(i==0 || i == 11 || i == 12)
		return 10;
	  
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
