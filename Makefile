CXX = g++
CXXFLAGS = -Iinclude -std=c++11

SRC = src/main.cpp src/spreadsheet.cpp
OBJ = $(SRC:.cpp=.o)
RES = resource.res  # Resource file
TARGET = app

all: $(TARGET)

# Compile .rc file into .res
$(RES): resource.rc
	windres $< -O coff -o $@

$(TARGET): $(OBJ) $(RES)  # Link resource file
	$(CXX) -o $@ $^  

clean:
	del /f $(OBJ) $(TARGET) $(RES)  # Use 'rm -f' on Unix-based systems.
