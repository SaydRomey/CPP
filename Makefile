# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 20:33:58 by cdumais           #+#    #+#              #
#    Updated: 2024/01/15 15:45:20 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TODO: 'update' target has problems when last push was other (laptop/school Mac)
# TODO: specify with '-a' the opening of an url (like in make ref) ((or change default on laptop))

NAME		:=	CPP
TMP_DIR		:=	tmp
REMOVE		:=	rm -rf
OS			:=	$(shell uname)
NPD			:=	--no-print-directory

all:
	@echo "'make pdf' \t-> get a CPP instruction pdf in './$(TMP_DIR)/'"
	@echo "'make update' \t-> pull the github version"
	@echo "'make ref' \t-> open the c++ reference url"

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)

clean fclean ffclean:
	@if [ -n "$(wildcard $(TMP_DIR))" ]; then \
		$(REMOVE) $(TMP_DIR); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(CYAN)$(TMP_DIR)$(RESET)$(GREEN) removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)Nothing to remove$(RESET)"; \
	fi

.PHONY: all clean fclean ffclean
# **************************************************************************** #
CPP_REF_URL		:=	https://cplusplus.com/reference/

ref:
	@if [ "$(OS)" = "Darwin" ]; then \
		open $(CPP_REF_URL); \
	else \
		xdg-open $(CPP_REF_URL) || echo "Please install a compatible PDF viewer"; \
	fi

.PHONY: ref
# **************************************************************************** #
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
	$(MAKE) get_pdf MODULE=$$MODULE $(NPD) $$NPD

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
ITALIC		:= $(ESC)[3m
UNDERLINE	:= $(ESC)[4m

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
