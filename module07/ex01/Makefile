
BINARY = iter

COMP = clang++ -Wall -Wextra
# COMP = gcc -Wall -Wextra -g3
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
GREEN='\033[01;32m'
RESET='\033[00m'

all: $(BINARY)

$(BINARY): $(OBJ)
	@echo  "$(GREEN).................Making Iter................ $(RESET)"
	$(COMP) $(OBJ) -o $(BINARY)

%.o: %.cpp
	$(COMP) -c $< -o $@

clean: 
		rm -rf *.o

fclean: clean
	rm -rf $(BINARY) *.dSYM

re: fclean all