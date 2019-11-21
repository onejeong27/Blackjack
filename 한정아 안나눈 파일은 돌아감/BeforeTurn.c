#include <stdio.h>
#include <stdlib.h>

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

void init(void) {
	int i;
	for (i = 0; i <= n_user; i++) {
		numCard[i] = 0;
		win[i] = FALSE;
		dead[i] = FALSE;
	}
}

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
