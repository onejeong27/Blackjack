#include <stdio.h>

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
