# Paths to subprojects
PUSH_SWAP_DIR = push_swap
GENERATOR_DIR = generator

# Compiler settings for generator
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Generator executable
GENERATOR = $(GENERATOR_DIR)/generator

# Source files for generator
SRC = $(GENERATOR_DIR)/RandNumGen.cpp $(GENERATOR_DIR)/PassNumbers.cpp \
	$(GENERATOR_DIR)/main.cpp
OBJ = $(SRC:.cpp=.o)

# Default target: Compile both sorter and generator
all:
	$echo "Building sorter..."
	@$(MAKE) -C $(SORTER_DIR)
	@echo "Building generator..."
	@$(MAKE) generator

# Compile generator
generator: $(GENERATOR)

$(GENERATOR): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(GENERATOR) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "Cleaning sorter..."
	@$(MAKE) -C $(SORTER_DIR) clean
	@echo "Cleaning generator..."
	rm -f $(OBJ)

#Fully clean everything (binaries and object files)
fclean: clean
	@echo "Full clean sorter..."
	@$(MAKE) -C $(SORTER_DIR) fclean
	@echo "Full clean generator..."
	rm -f $(GENERATOR)

# Recompile everything from scratch
re: fclean all

# Declare phony targets
.PHONY: all generator clean fclean re