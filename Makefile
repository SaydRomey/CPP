# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 20:33:58 by cdumais           #+#    #+#              #
#    Updated: 2024/01/05 21:09:20 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	CPP
TMP_DIR		:=	tmp
REMOVE		:=	rm -rf
OS			:=	$(shell uname)

# Default target
all:
	@echo "'make pdf' \t-> get a CPP instruction pdf in './$(TMP_DIR)/'"
	@echo "'make update' \t-> pull the github version"

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)

clean:
	@if [ -n "$(wildcard $(TMP_DIR))" ]; then \
		$(REMOVE) $(TMP_DIR); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)$(TMP_DIR) removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)Nothing to remove$(RESET)"; \
	fi

.PHONY: all clean
# **************************************************************************** #
# ----------------------------------- GIT ------------------------------------ #
# **************************************************************************** #
update:
	@echo "Are you sure you want to update the repo? [y/N] " \
	&& read ANSWER; \
	if [ "$$ANSWER" = "y" ] || [ "$$ANSWER" = "Y" ]; then \
		git pull origin main; \
		echo "Repository updated."; \
	else \
		echo "canceling update..."; \
	fi

.PHONY: update
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
	$(MAKE) get_pdf MODULE=$$MODULE

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
