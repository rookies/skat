TARGET = skat
SRC = src/main.cc src/cards.cc
OBJ = $(SRC:.cc=.o)

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

clean: 
	rm -f $(TARGET) $(OBJ)
