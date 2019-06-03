CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g 
LDFLAGS =  -I /home/krzysztof/Boost/boost_1_66_0

SRC = *.cpp
OBJ = $(SRC:.cc=.o)
EXEC = a.out

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS) -O2

clean:
	rm -rf $(OBJ) $(EXEC)