main:main.o submit-1AddPolygonBeforeQueryPoint.o submit-2AddPointBeforeQueryPolygon.o submit-3AddBeforeQuery.o submit-4MixQueryPoint.o submit-5MixQueryPolygon.o submit-6MixQuery.o Operation.o
	g++ -O2 -o main main.o submit-1AddPolygonBeforeQueryPoint.o submit-2AddPointBeforeQueryPolygon.o submit-3AddBeforeQuery.o submit-4MixQueryPoint.o submit-5MixQueryPolygon.o submit-6MixQuery.o Operation.o
main.o:main.cpp yourcode/submit-1AddPolygonBeforeQueryPoint.h yourcode/submit-2AddPointBeforeQueryPolygon.h yourcode/submit-3AddBeforeQuery.h yourcode/submit-4MixQueryPoint.h yourcode/submit-5MixQueryPolygon.h yourcode/submit-6MixQuery.h
	g++ -O2 -c main.cpp
submit-1AddPolygonBeforeQueryPoint.o:yourcode/submit-1AddPolygonBeforeQueryPoint.cpp yourcode/submit-1AddPolygonBeforeQueryPoint.h yourcode/Operation.h
	g++ -O2 -c yourcode/submit-1AddPolygonBeforeQueryPoint.cpp
submit-2AddPointBeforeQueryPolygon.o:yourcode/submit-2AddPointBeforeQueryPolygon.cpp yourcode/submit-2AddPointBeforeQueryPolygon.h yourcode/Operation.h
	g++ -O2 -c yourcode/submit-2AddPointBeforeQueryPolygon.cpp
submit-3AddBeforeQuery.o:yourcode/submit-3AddBeforeQuery.cpp yourcode/submit-3AddBeforeQuery.h yourcode/Operation.h
	g++ -O2 -c yourcode/submit-3AddBeforeQuery.cpp
submit-4MixQueryPoint.o:yourcode/submit-4MixQueryPoint.cpp yourcode/submit-4MixQueryPoint.h yourcode/Operation.h
	g++ -O2 -c yourcode/submit-4MixQueryPoint.cpp
submit-5MixQueryPolygon.o:yourcode/submit-5MixQueryPolygon.cpp yourcode/submit-5MixQueryPolygon.h yourcode/Operation.h
	g++ -O2 -c yourcode/submit-5MixQueryPolygon.cpp
submit-6MixQuery.o:yourcode/submit-6MixQuery.cpp yourcode/submit-6MixQuery.h yourcode/Operation.h
	g++ -O2 -c yourcode/submit-6MixQuery.cpp
Operation.o:yourcode/Operation.cpp yourcode/Operation.h
	g++ -O2 -c yourcode/Operation.cpp
clean:
	rm -f *.o main
