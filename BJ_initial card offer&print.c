//offering initial 2 cards
void offerCards(void) {
	
	int i;
	
	cardhold[n_user][0] = pullCard();
	
	for (i=0;i<n_user;i++){
		cardhold[i][0] = pullCard();	
	}
	
	cardhold[n_user][1] = pullCard();

	for (i=0;i<n_user;i++){
		cardhold[i][1] = pullCard();	
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

