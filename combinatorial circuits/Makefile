CPP=g++ --std=c++11
CFLAGS= -Wall

all : combinatorialCircuits

combinatorialCircuits : main.o Circuit.o InputGate.o Gate.o AndGate.o OrGate.o XorGate.o NandGate.o NorGate.o NxorGate.o NegationGate.o OutputGate.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

Circuit.o : Circuit.cpp Circuit.hpp
	$(CPP) $(CFLAGS) -c $<

InputGate.o : InputGate.cpp InputGate.hpp
	$(CPP) $(CFLAGS) -c $<

Gate.o : Gate.cpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

AndGate.o : AndGate.cpp AndGate.hpp
	$(CPP) $(CFLAGS) -c $<

OrGate.o : OrGate.cpp OrGate.hpp
	$(CPP) $(CFLAGS) -c $<

XorGate.o : XorGate.cpp XorGate.hpp
	$(CPP) $(CFLAGS) -c $<

NandGate.o : NandGate.cpp NandGate.hpp
	$(CPP) $(CFLAGS) -c $<

NorGate.o : NorGate.cpp NorGate.hpp
	$(CPP) $(CFLAGS) -c $<

NxorGate.o : NxorGate.cpp NxorGate.hpp
	$(CPP) $(CFLAGS) -c $<

NegationGate.o : NegationGate.cpp NegationGate.hpp
	$(CPP) $(CFLAGS) -c $<

OutputGate.o : OutputGate.cpp OutputGate.hpp	
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o

test: all
	./combinatorialCircuits