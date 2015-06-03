CXX = g++
CFLAGS= -std=c++11
modules/elkostatki_ai.lib: modules/elkostatki_ai.cpp
	$(CXX) modules/elkostatki_ai.cpp $(CFLAGS) -shared -fPIC -I/usr/include/python2.7 -lpython2.7 -lboost_python -o modules/elkostatki_ai.lib -Wall
	
clean:
	rm modules/elkostatki_ai.lib
