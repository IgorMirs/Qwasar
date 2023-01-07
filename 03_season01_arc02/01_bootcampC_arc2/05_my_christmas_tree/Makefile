# Set the default compiler to gcc
CC = gcc

# Set the flags
CFLAGS =  -fsanitize=address -g3 -Wall -Wextra -Werror
# Files to run
SRC = my_christmas_tree.c
TARGET = my_christmas_tree
OBJ = my_christmas_tree.o

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