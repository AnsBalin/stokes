CPPC=g++
LDFLAGS=-std=c++14 -Wfatal-errors
SOURCES=src/test.cpp src/sd_data.cpp src/sd_particleSet.cpp src/sd_attractiveForce.cpp src/sd_rawData.cpp
OBJECTS=$(SOURCES: .cpp=.o)
EXECUTABLE=sd_out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CPPC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm sd_out