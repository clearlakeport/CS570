#    Dong Lin
#    cssc4206
#    redid: 827228799

GCC := gcc


OUTPUT := msh
SOURCES := $(wildcard *.c)
CCFLAGS := -std=c99

all: $(OUTPUT)

$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)

clean:
	rm $(OUTPUT)

.PHONY:
	all

