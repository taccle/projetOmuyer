CC = g++
CFLAGS = -g -Wall -pthread -std=c++11
SRCS = main.cpp camera.cpp affichage.cpp traitement.cpp calculs.cpp Coordonnee.cpp
PROG = exec

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
