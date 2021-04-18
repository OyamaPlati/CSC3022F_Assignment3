Driver.exe: PGMImageProcessor.o Driver.o
        g++ PGMImageProcessor.o Driver.o -o Driver.exe -std=c++2a
PGMImageProcessor.o: PGMImageProcessor.cpp
        g++ -c PGMImageProcessor.cpp -o PGMImageProcessor.o -std=c++2a
Driver.o: Driver.cpp
        g++ -c Driver.cpp -o Driver.o -std=c++2a
run:
        ./Driver.exe $(argument)
clean:
        rm *.o Driver.exe
