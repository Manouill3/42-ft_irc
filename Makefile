RED=\033[31m
GREEN=\033[32m
PURPLE=\033[35m
RESET=\033[0m

NAME = ircserv

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp

DIR = build
OBJ = $(SRC:%.cpp=$(DIR)/%.o)

all: $(NAME)

$(DIR):
		@mkdir -p $(DIR)

$(NAME): $(OBJ)
		@$(CC) $(SRC) $(CFLAGS) -o $(NAME)
		@echo "$(GREEN)SUCCESS$(RESET)"

$(DIR)/%.o : %.cpp | $(DIR)
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(DIR)
		@echo "$(PURPLE)CLEAN$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(RED)FCLEAN$(RESET)"

re: fclean all

.PHONY : all clean fclean re