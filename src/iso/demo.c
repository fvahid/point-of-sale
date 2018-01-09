#include "dl_iso8583.h"
#include "dl_iso8583_defs_1993.h"
#include "dl_output.h" 

#define kBUFFER_SIZE    1000
/* Balance ISO message fields */
//	(void)DL_ISO8583_MSG_SetField_Str(0,"0100",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(2,"1234567890123456",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(3,"000000",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(11,"123456",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(12,"123456",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(13,"1234",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(14,"1234",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(22,"123",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(24,"123",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(25,"12",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(35,"6037123456789098",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(41,"123456",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(42,"123456789087654",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(52,"FFFFFFFF",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(61,"00",&isoMsg);
//	(void)DL_ISO8583_MSG_SetField_Str(64,"FFFFFFFF",&isoMsg);


//
// DL ISO8583 library demo
//

int main (int argc, char *argv[])
{
	DL_ISO8583_HANDLER isoHandler;
	DL_ISO8583_MSG     isoMsg;
	DL_UINT8           packBuf[1000];
	DL_UINT16          packedSize;
	int i;
	/* get ISO-8583 1993 handler */
	DL_ISO8583_DEFS_1993_GetHandler(&isoHandler);
    //
    // Populate/Pack message
    //
	/* initialise ISO message */

	if(strcmp(argv[1],"p") == 0)
	{
		DL_ISO8583_MSG_Init(NULL,0,&isoMsg);
		for(i=2;i<argc;i++)
		{
			printf( "arg %d: %s\n", i, argv[i] );
			(void)DL_ISO8583_MSG_SetField_Str(atoi(argv[i]),argv[i+1],&isoMsg);
			i++;
		}
		(void)DL_ISO8583_MSG_Pack(&isoHandler,&isoMsg,packBuf,&packedSize);
	        /* free ISO message */
        	DL_ISO8583_MSG_Free(&isoMsg);
        	/* output packed message (in hex) */
        	DL_OUTPUT_Hex(stdout,NULL,packBuf,packedSize);
	}
	if(strcmp(argv[1],"n") == 0)
	{
		packedSize = strlen(argv[2]);
 		int i = 0, j = 0;
        	char temp[1024];
		for(i=0; i<packedSize; i++){
			if(argv[2][i] == 'A' || argv[2][i] == 'a')
				argv[2][i] = 58;
			if(argv[2][i] == 'B' || argv[2][i] == 'b')
				argv[2][i] = 59;
			if(argv[2][i] == 'C' || argv[2][i] == 'c')
				argv[2][i] = 60;
			if(argv[2][i] == 'D' || argv[2][i] == 'd')
				argv[2][i] = 61;
			if(argv[2][i] == 'E' || argv[2][i] == 'e')
				argv[2][i] = 62;
			if(argv[2][i] == 'F' || argv[2][i] == 'f')
				argv[2][i] = 63;
		}
        	for(i=0; i<packedSize; i++){
                	temp[j] = (argv[2][i] * 16 )+ argv[2][i+1];
                	i++;
                	j++;
        	}
        	for(i=0; i<packedSize; i++)
                	packBuf[i] = temp[i] - 0x30;


		DL_ISO8583_MSG_Init(NULL,0,&isoMsg);
	        // unpack ISO message

        	(void)DL_ISO8583_MSG_Unpack(&isoHandler,packBuf,packedSize,&isoMsg);
        	// output ISO message content
        	DL_ISO8583_MSG_Dump(stdout,NULL,&isoHandler,&isoMsg);
        	// free ISO message
        	DL_ISO8583_MSG_Free(&isoMsg);
	}

	return 0;
}


