GCC := gcc

OUTPUT := bots
SOURCES := $(wildcard *.c)
CCFLAGS := -std=c99 -lpthread -lrt

all: $(OUTPUT)

$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)

clean:
	rm $(OUTPUT)

.PHONY:
	all

