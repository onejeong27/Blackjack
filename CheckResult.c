int checkResult() {
	
	int i;
	
	for(i=0; i<n_user; i++){
		
		if(i==0)
			printf("   -->YOUR RESULT : ");
		else
			printf("   -->PLAYER %d RESULT : ", i);
		
		if(CardSum[i]>21)
			printf("Lose due to overflow!   $%d\n", dollar[i]);			
		else if(CardSum[i]==21)
			printf("Congratulation~ Black JacK!!   $%d\n", dollar[i]);
		else if(CardSum[n_user]>21)
			dollar[i] += bet[i]; 
			printf("Dealer Overflow, You Win!   $%d\n", dollar[i]);
		else if(CardSum[n_user]==21)
			dollar[i] -= bet[i];
			printf("Dealer Black Jack, Lose!   $%d\n", dollar[i]);
		else if(CardSum[i] > CardSum[n_user] || (CardSum[i]=21 && CardSum[n_user]=21))
			dollar[i] += bet[i]; 
			printf("You Win!(sum:%d)   $%d\n", CardSum[i],dollar[i]);
		else if(CardSum[i] < CardSum[n_user] || (CardSum[i]>21 && CardSum[n_user]>21))
			dollar[i] -= bet[i]; 
			printf("You Lose!(sum:%d)   $%d\n", CardSum[i],dollar[i]);
		
	}
}
