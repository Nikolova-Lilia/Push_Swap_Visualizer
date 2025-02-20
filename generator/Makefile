# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Output executables
GENERATOR = generator

# Source files
SRC = RandNumbGen.cpp PassNumbers.cpp Visualize.cpp main.cpp
OBJ = &(SRC:.cpp = .o)

# Default target: compile everything
all: $(GENERATOR)

# Rule to build the generator executable
$(GENERATOR): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(GENERATOR) $(OBJ)

# Compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -rf $(OBJ)
	@echo "Object files removed."

# Remove object files + executable
fclean: clean
	rm -rf $(GENERATOR)
	@echo "Executable removed."

# Recompile everything from scratch
re: fclean all

.PHONY: all clean fclean re