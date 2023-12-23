all: proj3.exe 

main.o: main.cpp constants.h checkPixelValue.h checkPatternValue.h checkCin.h chooseColor.h ColorClass.h RowColumnClass.h RectangleClass.h PatternClass.h ColorImageClass.h
	g++ -std=c++98 -g -Wall -c main.cpp -o main.o

checkPatternValue.o: checkPatternValue.cpp checkPatternValue.h constants.h
	g++ -std=c++98 -g -Wall -c checkPatternValue.cpp -o checkPatternValue.o

checkPixelValue.o: checkPixelValue.cpp checkPixelValue.h constants.h
	g++ -std=c++98 -g -Wall -c checkPixelValue.cpp -o checkPixelValue.o

checkCin.o: checkCin.cpp checkCin.h constants.h
	g++ -std=c++98 -g -Wall -c checkCin.cpp -o checkCin.o

chooseColor.o: chooseColor.cpp chooseColor.h constants.h checkCin.o
	g++ -std=c++98 -g -Wall -c chooseColor.cpp -o chooseColor.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -std=c++98 -g -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -std=c++98 -g -Wall -c RowColumnClass.cpp -o RowColumnClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h constants.h ColorClass.h RowColumnClass.h
	g++ -std=c++98 -g -Wall -c RectangleClass.cpp -o RectangleClass.o

PatternClass.o: PatternClass.cpp PatternClass.h constants.h checkPatternValue.h ColorClass.h RowColumnClass.h
	g++ -std=c++98 -g -Wall -c PatternClass.cpp -o PatternClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h constants.h RowColumnClass.h ColorClass.h RectangleClass.h PatternClass.h checkPixelValue.h
	g++ -std=c++98 -g -Wall -c ColorImageClass.cpp -o ColorImageClass.o

proj3.exe: main.o checkPatternValue.o checkPixelValue.o checkCin.o chooseColor.o ColorClass.o RowColumnClass.o RectangleClass.o PatternClass.o ColorImageClass.o 
	g++ -std=c++98 main.o checkPatternValue.o checkPixelValue.o checkCin.o chooseColor.o ColorClass.o RowColumnClass.o RectangleClass.o PatternClass.o ColorImageClass.o -o proj3.exe

clean:
	rm -f *.o *.exe