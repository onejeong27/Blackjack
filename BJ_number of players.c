#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

extern n_user;


//player settiing
int configUser(void) {
	
	do{
	
	printf("Input the player of numbers(Max:5) : ")
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

