# 1. Compiler and Flags
CXX := g++
# `sdl2-config` automatically finds where SDL is installed on Ubuntu
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude `sdl2-config --cflags`
LIBS := `sdl2-config --libs` -lSDL2_image

# 2. Source and Object Files
SRCS := src/main.cpp src/gameField.cpp src/canon.cpp src/shot.cpp src/shotFactory.cpp src/chicken.cpp src/chickenFactory.cpp src/vector.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := chicken_invaders

# 3. Build Rules
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 4. Cleanup Rule
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean