CXX = g++
CXXFLAGS = -Iinclude -std=c++11

SRC = src/main.cpp src/spreadsheet.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

clean:
	del /f $(OBJ) $(TARGET)  # This will work on Windows. Use 'rm -f' on Unix-based systems.
