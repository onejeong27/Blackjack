//---------------card array controllers----------------------------
//mix the card sets and put in the array
int MixCardTray(void) {

	int i;
	for(i=0; i< N_CARD; i++){
		CardTray[i] = rand() % N_CARD;
	
	}
		
	printf("--> Card is Mixed and Put into the Tray");
}

//get one card from the tray
int pullCard(void) {
	
	int i;
	
	i = CardTray[cardIndex];
	cardIndex = cardIndex++;
	
	return i;
}

