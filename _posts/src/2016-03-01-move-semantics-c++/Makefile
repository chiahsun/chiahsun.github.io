BINS = $(patsubst %.cc, %.out, $(wildcard *.cc))
OBJS = $(patsubst %.cc, %.o, $(wildcard *.cc))
TARGET = $(BINS) $(OBJS)

CFLAGS = -std=c++11

.PHONY: debug all clean


all : $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

.cc.o :
	clang++ -c $< -o $@ $(CFLAGS)

%.out : $(OBJS)
	clang++ -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGET)
