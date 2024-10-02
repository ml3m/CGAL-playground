CXX = g++
CXXFLAGS = -std=c++11 -O2

# CGAL setup
CGAL_INC = /usr/local/include
CGAL_LIB = /usr/local/lib

# Target executable
TARGET = geometry_program

# Source file
SRC = points_and_segment.cpp

# Include directories and libraries
INCLUDES = -I$(CGAL_INC)
LIBS = -L$(CGAL_LIB) -lCGAL -lboost_system -lgmp

# Build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LIBS)

# Clean up the build
clean:
	rm -f $(TARGET)
