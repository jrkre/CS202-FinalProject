CXX = g++

CXX_FLAGS = -g -Wall -std=c++11

TARGET = wav_processor

HEADERS = Wav.h FileIO.h wavheader.h
SRCS = Wav.cpp FileIO.cpp main.cpp

OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))

.PHONY: default all clean

all: $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o