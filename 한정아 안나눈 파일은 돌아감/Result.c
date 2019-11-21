#include <stdio.h>

void checkResult(void) {
	int i;
	if (sumCard[n_user] == 21) {
		printf("[[[[[[[ server result is .... ....blackjack!! ]]]]]]]\n\n\n");
		for (i = 0; i < n_user ; i++) {
			if (win[i] || dead[i]) { // �̹� �� ������ ����, ����(+�� ����) �����÷ο� �÷��̾� ����
				continue;
			}
			
			dollar[i] -= bet[i]; // ������ ������ ��� ����, �����÷ο� �ƴ� �÷��̾�(���� ���� ���� ��Ƴ���) ��� ��. ���� ����.
		}
	}
	else if (sumCard[n_user] > 21) {
		printf("[[[[[[[ server result is .... ....overflow!! ]]]]]]]\n\n\n");
		for (i = 0; i < n_user; i++) {
			if (win[i] || dead[i]) { // �̹� �� ������ ����, ����(+�� ����) �����÷ο� �÷��̾� ����
				continue;
			}
			
			win[i] = TRUE; // ������ �����÷ο��� ��� ����, �����÷ο� �ƴ� �÷��̾�(���� ���� ���� ��Ƴ���) ��� ��. ���� ȹ��.
			dollar[i] += bet[i];
		}
	}
	else {
		printf("[[[[[[[ server result is ....  %d ]]]]]]]\n\n\n", sumCard[n_user]);
		for (i = 0; i < n_user; i++) {
			if (win[i] || dead[i]) { // �̹� �� ������ ����, ����(+�� ����) �����÷ο� �÷��̾� ����
				continue;
			}

			if (sumCard[i] >= sumCard[n_user]) { // ���� ī���պ��� �÷��̾� ī������ ũ�ų� ���� ��� ��. ���� ȹ��.
				win[i] = TRUE;
				dollar[i] += bet[i];
			}
			else if (sumCard[i] < sumCard[n_user]) { // ���� ī���պ��� �÷���� ī������ ���� ��� ��. ���� ����.
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

		if (sumCard[i] == 21) { // ����
			printf("BlackJack! win --> $%d \n", dollar[i]);
		}
		else if (win[i]) // ���� �ƴ����� ������ �����÷���� ��� // ���� �ƴ����� ���� ī���պ��� �÷���� ī������ ũ�ų� ���� ���
			printf("win (sum : %d) --> $%d \n", sumCard[i], dollar[i]);
		else if (dead[i]) { // �����÷ο�
			printf("lose due to overflow! --> $%d \n", dollar[i]);
			if (dollar[i] == 0) {
				bankrupt = TRUE;
				printf("   -> bankrupted! game will be ended \n");
			}
		}
		else { // �����÷ο� �ƴ����� ������ ������ ��� // �����÷ο� �ƴ����� ���� ī���պ��� �÷��̾� ī������ ���� ���
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
