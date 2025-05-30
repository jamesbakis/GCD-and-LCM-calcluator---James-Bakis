.default: GCDLCM

GCDLCM: main.o
	g++ -Wall -Werror -std=c++17 -O -o $@ $^ && make clean

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -O -c $^

clean:
	rm -f GCDLCM *.o