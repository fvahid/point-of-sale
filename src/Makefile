
CC=gcc
INCLUDES=-Iiso -Iconnections


all: connections app

clean:
	make -C iso clean
	make -C connections clean
	rm -f  app.bin  *.o *~

iso:
	make -C iso

connections:
	make -C connections

app:
	${CC} -c app.c ${INCLUDES}
	${CC} -o app.bin app.o connections/connections.o


