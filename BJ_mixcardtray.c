//mix the card sets and put in the array
int MixCardTray(void) {

	int i;
	for(i=0; i< N_CARD; i++){
		CardTray[i] = rand() % N_CARD;
	
	}
		
	printf("--> Card is Mixed and Put into the Tray");
}
