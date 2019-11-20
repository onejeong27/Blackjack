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
