all: main main-debug

CXX = clang++
CXXFLAGS = -g -Wall -static

SRCS = memory.cpp

main: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) 
	$(CXX) $(CXXFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug
