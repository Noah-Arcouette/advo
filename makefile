CC      = gcc -Wall -Wextra -O0 -g -I./inc
CCBUILD = gcc -O3 -I./inc
OUT     = ./bin/AO
OUTD    = ./bin/libadvo.so
OUTA    = ./bin/libadvo.a
OUTH    = advo.h

all: ${OUT}
	${OUT}

${OUT}: ./obj/main.o
	${CC} -o ${OUT} ./obj/*.o

./obj/main.o: ./obj/nums.o ./obj/color.o ./obj/boxs.o ./src/main.c ./obj/string.o
	${CC} -c -o ./obj/main.o ./src/main.c

./obj/string.o: ./src/string.c
	${CC} -c -o ./obj/string.o ./src/string.c

./obj/boxs.o: ./src/boxs.c
	${CC} -c -o ./obj/boxs.o ./src/boxs.c

./obj/color.o: ./src/color.c
	${CC} -c -o ./obj/color.o ./src/color.c

./obj/nums.o: ./src/nums.c
	${CC} -c -o ./obj/nums.o ./src/nums.c



build_d:
	${CCBUILD} --shared -o ${OUTD} \
	./src/boxs.c \
	./src/color.c \
	./src/nums.c \
	./src/string.c

	strip -s ${OUTD}

build_a:
	${CCBUILD} -c -o ./obj/boxs.o ./src/boxs.c
	${CCBUILD} -c -o ./obj/color.o ./src/color.c
	${CCBUILD} -c -o ./obj/nums.o ./src/nums.c
	${CCBUILD} -c -o ./obj/string.o ./src/string.c

	ar rcs ${OUTA} \
	./obj/boxs.o \
	./obj/color.o \
	./obj/nums.o \
	./obj/string.o

# 	strip -s ${OUTA}

clean:
	rm ./obj/* ./bin/* *.stackdump -f

configure:
	mkdir -p ./obj ./bin


install_d: configure build_d
	chown root:root ${OUTD}
	chmod a+x ${OUTD}
	mv ${OUTD} /usr/lib/libadvo.so

	cp ./inc/ao.h /usr/include/${OUTH}

install_a: configure build_a
	chown root:root ${OUTA}
	chmod a+x ${OUTA}
	mv ${OUTA} /usr/lib/libadvo.a

	cp ./inc/ao.h /usr/include/${OUTH}

uninstall:
	rm /usr/lib/libadvo.so /usr/lib/libadvo.a -f

	rm /usr/include/${OUTH}

