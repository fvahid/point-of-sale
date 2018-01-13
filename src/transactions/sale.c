void createSaleISO(void)
{
	PackeISO();
}


void initSale(void)
{
	createSaleISO(void);	
	
}


void doSale(void)

{
	initSale();
	getSaleAmout();
	getCardPIN();
	transToJournal();
	sendISO(Trans);
	printRecipt();
	updateJournal();
	doSetllement();
	destroySale();
}

