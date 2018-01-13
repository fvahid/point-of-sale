CC=gcc
INCLUDES=-Iconnections -Iiso


all: connect iso8583 app.bin 

clean:
	make -C connections clean
	make -C iso clean
	rm -f app.bin  *.o *~


connect:
	make -C iso 

iso8583:
	make -C connections
	
app.bin:
	${CC} -c app.c ${INCLUDES}
	${CC} -o app.bin app.o connections/connections.o


	
