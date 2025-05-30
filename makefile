.default: GCDLCM

GCDLCM: main.o factor.o
	g++ -Wall -Werror -std=c++17 -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -O -c $^

clean:
	rm -f GCDLCM *.o