void createBalanceISO(void)
{
	PackeISO();
}


void initBalanceInq(void)
{
	createBalanceISO(void);	
	
}


void doBalanceInq(void)

{
	initBalanceInq();
	getCardPIN();
	sendISO(Trans);
	printRecipt();
	destroyBalance();
}
