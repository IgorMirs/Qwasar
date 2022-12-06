# Set the default compiler to gcc
CC = gcc

# Set the flags
CFLAGS =  -fsanitize=address -g3
# -Wall -Wextra -Werror
# Files to run
SRC = my_bsq.c main.c my_readline.c my_string.c
TARGET = my_bsq
OBJ = my_bsq.o main.o my_readline.o my_string.o

all : $(TARGET) clean

$(TARGET) : $(OBJ)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ) 

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all	