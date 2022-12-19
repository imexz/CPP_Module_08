NAME = mutated
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SOURCES =	./main.cpp

#build everything
all: $(NAME)

#creates programm
$(NAME): $(SOURCES)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

#removes executable
clean:
	$(RM) $(NAME)

#removes executable and rebuild it
re: clean all