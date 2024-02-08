CXX=g++
FLAGS= -std=c++17
SRC = src/*.cpp
INC = include/*.h
BIN = nes

emulator:
	$(CXX) main.cpp $(SRC) $(FLAGS) -I $(INC) -o $(BIN) 

clean:
	rm -f $(BIN)
