#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

//player info
extern dollar[N_MAX_USER];						//dollars that each player has
extern n_user;									//number of users


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

