# Name: Dang Tran
# ID:S856F975
# File: main.cpp
# Assignment:4

CXX=g++
CXXFLAGS=-Wall
SRCS=PFAString.cpp main.cpp
SRCSDIR=src/
EXE=hw5
OBJS=$(SRCS:%.cpp=%.o)

PREOBJS=$(addprefix $(SRCSDIR),$(OBJS))

$(EXE):$(PREOBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	@rm -f $(PREOBJS) $(EXE)