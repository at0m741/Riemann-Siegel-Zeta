NAME = zeta_zeros

CC = gcc

SRCS = $(wildcard *.c) 

CFLAGS = -O3 -mavx2 -mfma -fopenmp -lm 
OBJ = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -lm

all: $(NAME)
	
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -lm

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re

