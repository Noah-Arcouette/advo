CC      = gcc -Wall -Wextra -O0 -g -I./inc
CCBUILD = gcc -O3 -I./inc
OUT     = ./bin/AO
OUTA    = ./bin/libadvo.a
OUTH    = advo.h

all: ${OUT}
	${OUT}

${OUT}: ./obj/main.o
	${CC} -o ${OUT} ./obj/*.o

./obj/main.o: ./obj/input.o ./obj/shapes.o ./obj/nums.o ./obj/color.o ./obj/boxs.o ./src/main.c ./obj/string.o
	${CC} -c -o ./obj/main.o ./src/main.c

./obj/string.o: ./src/string.c
	${CC} -c -o ./obj/string.o ./src/string.c

./obj/boxs.o: ./src/boxs.c
	${CC} -c -o ./obj/boxs.o ./src/boxs.c

./obj/color.o: ./src/color.c
	${CC} -c -o ./obj/color.o ./src/color.c

./obj/nums.o: ./src/nums.c
	${CC} -c -o ./obj/nums.o ./src/nums.c

./obj/shapes.o: ./src/shapes.c
	${CC} -c -o ./obj/shapes.o ./src/shapes.c

./obj/input.o: ./src/input.c
	${CC} -c -o ./obj/input.o ./src/input.c


build:
	${CCBUILD} -c -o ./obj/boxs.o ./src/boxs.c
	${CCBUILD} -c -o ./obj/color.o ./src/color.c
	${CCBUILD} -c -o ./obj/nums.o ./src/nums.c
	${CCBUILD} -c -o ./obj/string.o ./src/string.c
	${CCBUILD} -c -o ./obj/shapes.o ./src/shapes.c
	${CCBUILD} -c -o ./obj/input.o ./src/input.c

	ar rcs ${OUTA} \
	./obj/boxs.o \
	./obj/color.o \
	./obj/nums.o \
	./obj/string.o \
	./obj/input.o \
	./obj/shapes.o

# 	strip -s ${OUTA}

clean:
	rm ./obj/* ./bin/* *.stackdump -f

configure:
	mkdir -p ./obj ./bin


install: configure build_a
	chown root:root ${OUTA}
	chmod a+x ${OUTA}
	mv ${OUTA} /usr/lib/libadvo.a

	cp ./inc/ao.h /usr/include/${OUTH}

uninstall:
	rm /usr/lib/libadvo.a -f

	rm /usr/include/${OUTH}

