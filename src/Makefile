CC=gcc
INCLUDES=-Iconnections -Iiso


all: clean iso8583 connect dis app.bin 

clean:
	make -C connections clean
	rm -f app.bin  *.o *~

dis: 
	make -C display

connect:
	make -C connections

iso8583:
	make -C iso

app.bin:
	${CC} -c app.c ${INCLUDES}
	${CC} -o app.bin app.o connections/connections.o display/display.o iso/demo.o


	
