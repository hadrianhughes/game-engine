CC = g++
CPPFLAGS := -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -pedantic-errors -std=c++17
SRC = $(wildcard src/*.cpp)
OBJDIR = dist
OBJ = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SRC))
OUT = dist/game

all: $(OUT)

$(OUT): $(OBJ)
	@mkdir -p dist
	$(CC) -o $@ $^

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) src/*.o $(OUT)

# Run game
run: all
	./$(OUT)

.PHONY: all clean run
