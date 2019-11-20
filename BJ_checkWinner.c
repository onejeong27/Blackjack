int checkWinner() {
	
	int i,winner;
	int dollar_MAX = 0;
	
	for(i=0; i<n_user; i++){
		
		if(i==0)
			printf("Your Total = $ ", dollar[i]);
		else
			printf("Player Total = $ ", dollar[i]);
	}
	
	for(i=0; i<n_user; i++){
		if (dollar[i] > dollar_MAX)
			dollar_Max = dollar[i];
			winner = i;
	}
	if(winner==0)
		printf("Winner is YOU !!")
	else
		printf("Winner is player %d\n", winner); 
}

