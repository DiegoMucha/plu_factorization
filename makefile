# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Output program name
TARGET = program

# Source files
SRCS = factorizer.cpp Matrix.cpp

# Default rule: compile everything in one step
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean compiled program
clean:
	rm -f $(TARGET)
