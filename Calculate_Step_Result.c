int calcStepResult() { 
	
	int CardSum(int cardum, int user){
		
		CardSum[user]=0; 
		
		if(cardnum%13>=2 && cardnum%13<=10)
			CardSum[user]+=cardnum%13;
		
		else if(cardnum%13==11 || cardnum%13==12 || cardnum%13==0)
			CardSum[user]+=10;
		else (card%13==1)
			CardSum[user]+=1;
	}
	
	int Calculate_A(int user){
		
		int i
		
		if (cardhold[user][i]%13==1){
			if(CardSum[user]<=11)
			CardSum[user]+=10;}
			
	}
}
