NAME = zeta_zeros

CC = clang

SRCS = main.c \
	   print_zeros.c \
	   refine.c \
	   riemann_siegel.c \
	   utils.c

CFLAGS = -O3 -mavx2 -mfma -Xpreprocessor -fopenmp -L/usr/local/Cellar/libomp/18.1.8/lib -lomp -g

OBJ = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)
	
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re

