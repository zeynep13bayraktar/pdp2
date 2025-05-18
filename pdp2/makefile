all: compile run

compile:

	gcc -std=c11 -c -I ./include/ ./src/zaman.c -o ./lib/zaman.o
	gcc -std=c11 -D_GNU_SOURCE -c -I ./include/ ./src/kisi.c -o ./lib/kisi.o
	gcc -std=c11 -D_GNU_SOURCE -c -I ./include/ ./src/gezegen.c -o ./lib/gezegen.o
	gcc -std=c11 -c -I ./include/ ./src/uzayAraci.c -o ./lib/uzayAraci.o
	gcc -std=c11 -c -I ./include/ ./src/buzDeviGezegen.c -o ./lib/buzDeviGezegen.o
	gcc -std=c11 -c -I ./include/ ./src/cuceGezegen.c -o ./lib/cuceGezegen.o
	gcc -std=c11 -c -I ./include/ ./src/gazDeviGezegen.c -o ./lib/gazDeviGezegen.o
	gcc -std=c11 -c -I ./include/ ./src/kayacGezegen.c -o ./lib/kayacGezegen.o
	gcc -std=c11 -c -I ./include/ ./src/dosyaOkuma.c -o ./lib/dosyaOkuma.o
	gcc -std=c11 -D_GNU_SOURCE -c -I ./include/ ./src/simulasyon.c -o ./lib/simulasyon.o
	gcc -std=c11 -I ./include/ -o ./bin/simulasyon.exe \
    ./lib/zaman.o ./lib/kisi.o ./lib/gezegen.o \
    ./lib/uzayAraci.o ./lib/buzDeviGezegen.o ./lib/cuceGezegen.o \
    ./lib/gazDeviGezegen.o ./lib/kayacGezegen.o ./lib/dosyaOkuma.o ./lib/simulasyon.o -lm

	
run:
	./bin/simulasyon.exe

clean:
	del /Q .\lib\*.o .\bin\*.exe 2>nul
