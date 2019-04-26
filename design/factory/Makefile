
#set -e

CXX=g++

OPENCV_PATH:=/usr/local/iac
OPENCV_INCLUDE:=$(OPENCV_PATH)/include
OPENCV_LIBPATH:=$(OPENCV_PATH)/lib
OPENCV_LIB:=`pkg-config --libs lanlincv`

FLAGS=-g -Wall

#SRCS=operator.cpp
SRCS:=$(wildcard *.cpp)

EXEC:=operator.bin
#EXEC:=picProcess.bin

all:$(EXEC)
	@echo "compile finish" 


$(EXEC):$(SRCS)	
	$(CXX) $(FLAGS)  -I$(OPENCV_INCLUDE) $^ -o $@ $(OPENCV_LIB) 


debug:
	@echo "haha"
	@echo $0 $1 $2
#@echo "debug"
	 @echo $(OPENCV_INCLUDE) $(OPENCV_LIBPATH) $(OPENCV_LIB) 
