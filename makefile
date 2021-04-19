findcomp: PGMImageProcessor.o Driver.o
	g++ PGMImageProcessor.o Driver.o -o findcomp -std=c++2a
PGMImageProcessor.o: PGMImageProcessor.cpp
	g++ -c PGMImageProcessor.cpp -o PGMImageProcessor.o -std=c++2a
ConnectedComponent.o: ConnectedComponent.cpp
	g++ -c ConnectedComponent.cpp -o ConnectedComponent.o -std=c++2a
Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o -std=c++2a
run:
	./findcomp $(argument)
clean:
	rm *.o findcomp
