void createSetllementISO(void)
{	
	//get iso data
	PackeISO();
}


void initSetllement(void)
{
	createSetllementISO(void);	
} 

void doSetllement(void)

{
	initSetllement();
	transToJournal();
	sendISO(Trans);
	printRecipt();
	updateJournal();
	destroySetllement();
}

