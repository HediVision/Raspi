CC = g++ 
CFLAGS = -g -Wall -std=c++11
SRCS = raspcam.cpp
PROG = raspcam

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
