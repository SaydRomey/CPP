# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 13:41:10 by cdumais           #+#    #+#              #
#    Updated: 2024/01/03 16:51:14 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	megaphone

COMPILE		:=	c++
C_FLAGS		:=	-Wall -Wextra -Werror
STANDARD	:=	-std=c++98

SRC_DIR		:=	.
OBJ_DIR		:=	obj
TMP_DIR		:=	tmp

SRCS		:=	$(wildcard $(SRC_DIR)/*.cpp)
OBJS		:=	$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

REMOVE		:= rm -rf
OS			:= $(shell uname)
# **************************************************************************** #
all: $(NAME)

$(NAME): $(OBJS)
	@echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)]\\t$(GREEN)ready$(RESET)"
	@$(COMPILE) $(C_FLAGS) $(STANDARD) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "$(CYAN)Compiling...$(ORANGE)\t$(notdir $<)$(RESET)"
	@$(COMPILE) $(C_FLAGS) $(STANDARD) -c $< -o $@
	@printf "$(UP)$(ERASE_LINE)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@if [ -n "$(wildcard $(OBJ_DIR))" ]; then \
		$(REMOVE) $(OBJ_DIR); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)Object files removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No object files to remove$(RESET)"; \
	fi

fclean: clean
	@if [ -n "$(wildcard $(NAME))" ]; then \
		$(REMOVE) $(NAME); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)Executable removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No executable to remove$(RESET)"; \
	fi

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
# ---------------------------------- PDF ------------------------------------- #
# **************************************************************************** #
# PDF		:= cpp_00.pdf
# GIT_URL	:= https://github.com/SaydRomey/42_ressources
# PDF_URL	= $(GIT_URL)/blob/main/pdf/$(PDF)?raw=true

# pdf: | $(TMP_DIR)
# 	@curl -# -L $(PDF_URL) -o $(TMP_DIR)/$(PDF)
# ifeq ($(OS),Darwin)
# 	@open $(TMP_DIR)/$(PDF)
# else
# 	@xdg-open $(TMP_DIR)/$(PDF) || echo "Please install a compatible PDF viewer"
# endif

# .PHONY: pdf
# **************************************************************************** #
# ---------------------------------- UTILS ----------------------------------- #
# **************************************************************************** #
run: all
	./$(NAME)

debug: C_FLAGS += -g
debug: re

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)

ffclean: fclean
	@$(REMOVE) $(TMP_DIR) $(NAME).dSYM

.PHONY: run debug ffclean
# **************************************************************************** #
ESC			:= \033

# Text
RESET		:= $(ESC)[0m
BOLD		:= $(ESC)[1m

BLACK		:= $(ESC)[30m
RED			:= $(ESC)[91m
GREEN		:= $(ESC)[32m
YELLOW		:= $(ESC)[93m
ORANGE		:= $(ESC)[38;5;208m
BLUE		:= $(ESC)[94m
PURPLE		:= $(ESC)[95m
CYAN		:= $(ESC)[96m

# Cursor movement
UP			:= $(ESC)[A

# Erasing
ERASE_LINE	:= $(ESC)[2K
