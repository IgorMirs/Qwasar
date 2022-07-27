# Set the default compiler to gcc
CC = gcc

# Set the flags
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -fsanitize=leak

# Files to run
SRC = my_ls.c my_string.c array_string.c
TARGET = my_ls
OBJ = my_ls.o array_string.o my_string.o

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