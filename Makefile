TARGET = skat
SRC = src/main.cc \
      src/Card.cc \
      src/CardHelpers.cc \
      src/CardSorter.cc \
      src/HumanPlayer.cc \
      src/Game.cc
CXXFLAGS = -Wall -Wextra
OBJ = $(SRC:.cc=.o)

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

clean: 
	rm -f $(TARGET) $(OBJ)
