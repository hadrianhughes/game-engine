CC = g++
CPPFLAGS := -I./include -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -pedantic-errors -std=c++17
LDLIBS := -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
LDFLAGS := -L/usr/local/lib -Wl,-rpath=/usr/local/lib
SRC = $(wildcard src/*.cpp)
OBJDIR = dist
OBJ = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SRC))
OUT = dist/game

all: $(OUT)

$(OUT): $(OBJ)
	@mkdir -p dist
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) src/*.o $(OUT)

# Run game
run: all
	./$(OUT)

.PHONY: all clean run
