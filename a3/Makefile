#    Dong Lin
#    cssc4206
#    redid: 827228799

GCC := g++


OUTPUT := sim
SOURCES := $(wildcard *.cpp)
CCFLAGS := -std=c++11

all: $(OUTPUT)

$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)

clean:
	rm $(OUTPUT)

.PHONY:
	all

