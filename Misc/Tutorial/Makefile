# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 18:04:16 by cdumais           #+#    #+#              #
#    Updated: 2024/01/09 19:38:30 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	placeholder

COMPILE		:=	c++
C_FLAGS		:=	-Wall -Wextra -Werror
STANDARD	:=	-std=c++98

INC_DIR		:=	inc
INCS		:=	$(wildcard $(INC_DIR)/*.hpp)
HEADERS		:=	-I$(INC_DIR)

SRC_DIR		:=	src
SRCS		:=	$(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR		:=	obj
OBJS		:=	$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

TMP_DIR		:=	tmp

REMOVE		:=	rm -rf
OS			:=	$(shell uname)
NPD			:=	--no-print-directory
# **************************************************************************** #
all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)]\\t$(GREEN)ready$(RESET)"
	@$(COMPILE) $(C_FLAGS) $(STANDARD) $(OBJS) $(HEADERS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "$(CYAN)Compiling...$(ORANGE)\t$(notdir $<)$(RESET)"
	@$(COMPILE) $(C_FLAGS) $(STANDARD) $(HEADERS) -c $< -o $@
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
GIT_URL		:= https://github.com/SaydRomey/42_ressources

pdf:
	@echo "Select pdf"
	@echo "0. Module 00"
	@echo "1. Module 01"
	@echo "2. Module 02"
	@echo "3. Module 03"
	@echo "4. Module 04"
	@read pdf_choice; \
	case $$pdf_choice in \
		0) MODULE=cpp00;; \
		1) MODULE=cpp01;; \
		2) MODULE=cpp02;; \
		3) MODULE=cpp03;; \
		4) MODULE=cpp04;; \
		*) echo "Invalid choice. Exiting." ; exit 1;; \
	esac; \
	$(MAKE) get_pdf MODULE=$$MODULE $(NPD)

get_pdf: | $(TMP_DIR)
	@PDF=$(MODULE)_en.pdf; \
	PDF_URL=$(GIT_URL)/blob/main/pdf/CPP/$$PDF?raw=true; \
	curl -# -L $$PDF_URL -o $(TMP_DIR)/$$PDF; \
	if [ "$(OS)" = "Darwin" ]; then \
		open $(TMP_DIR)/$$PDF; \
	else \
		xdg-open $(TMP_DIR)/$$PDF || echo "Please install a compatible PDF viewer"; \
	fi

.PHONY: pdf get_pdf
# **************************************************************************** #
# ---------------------------------- UTILS ----------------------------------- #
# **************************************************************************** #
run: all
	./$(NAME)

nowarning:	C_FLAGS	=
nowarning:	re

# https://elearning.intra.42.fr/tags/38/notions
# https://elearning.intra.42.fr/notions/piscine-c-d00-c-basics/subnotions

ELEARNING_URL	:=	https://elearning.intra.42.fr
CPP_TUTO		:=	/tags/38/notions
CPP00_TUTO		:=	/notions/piscine-c-d00-c-basics/subnotions
TUTO			=	$(ELEARNING_URL)$(CPP_TUTO)

tuto:
ifeq ($(OS),Darwin)
	@open $(TUTO)
else
	@xdg-open $(TUTO) || echo "Please install a compatible PDF viewer"
endif

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)

ffclean: fclean
	@$(REMOVE) $(TMP_DIR)

.PHONY: run nowarning tuto ffclean
# **************************************************************************** #
ESC			:= \033

# Text
RESET		:= $(ESC)[0m
BOLD		:= $(ESC)[1m

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
