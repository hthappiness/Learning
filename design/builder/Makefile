
#set -e

CXX=g++

OPENCV_PATH:=/usr/local/iac
OPENCV_INCLUDE:=$(OPENCV_PATH)/include
OPENCV_LIBPATH:=$(OPENCV_PATH)/lib
OPENCV_LIB:=`pkg-config --libs lanlincv`

PWD:=$(shell pwd)

FLAGS=-g -Wall

#SRCS=operator.cpp
SRCS:=$(wildcard *.cpp)

EXEC:=builder
#EXEC:=picProcess.bin

all:$(EXEC)
	@echo "compile finish" 


$(EXEC):$(SRCS)	
	##$(CXX) $(FLAGS)  -I$(OPENCV_INCLUDE) -I$(PWD) $^ -o $@ $(OPENCV_LIB) 
	$(CXX) $(FLAGS) -I$(PWD) $^ -o $@

debug:
	@echo "haha"
	@echo $0 $1 $2
clean:
	rm $(EXEC)
run:
	./$(EXEC)
##@echo "debug"
##@echo $(OPENCV_INCLUDE) $(OPENCV_LIBPATH) $(OPENCV_LIB) 
