# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 20:33:58 by cdumais           #+#    #+#              #
#    Updated: 2024/08/18 19:27:37 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	CPP
AUTHOR		:=	cdumais
INC_DIR		:=	inc
SRC_DIR		:=	src
TMP_DIR		:=	tmp
REMOVE		:=	rm -rf
OS			:=	$(shell uname)
NPD			:=	--no-print-directory

# Detect OS and define OPEN command
ifeq ($(shell uname), Darwin)
	OPEN := open
else
	OPEN := xdg-open
endif

define MAN

Available 'make' targets:

$(UNDERLINE)Documentation:$(RESET)
'make pdf'     -> get a specific CPP instruction pdf in './$(TMP_DIR)/'
'make ref'     -> open the c++ reference url
'make tuto'    -> open the c++ old tutorial url

$(UNDERLINE)Git and Github:$(RESET)
'make update'  -> pull the github version
'make repo'    -> open this repo on github

$(UNDERLINE)Scripts and Templates:$(RESET)
'make new'     -> create an new exercise (and directory if needed)

endef
export MAN

all:
	@echo "$$MAN"

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
	@echo "5. Module 05"
	@echo "6. Module 06"
	@echo "7. Module 07"
	@echo "8. Module 08"
	@echo "9. Module 09"
	@read pdf_choice; \
	case $$pdf_choice in \
		0) MODULE=cpp00;; \
		1) MODULE=cpp01;; \
		2) MODULE=cpp02;; \
		3) MODULE=cpp03;; \
		4) MODULE=cpp04;; \
		5) MODULE=cpp05;; \
		6) MODULE=cpp06;; \
		7) MODULE=cpp07;; \
		8) MODULE=cpp08;; \
		9) MODULE=cpp09;; \
		*) echo "Invalid choice. Exiting." ; exit 1;; \
	esac; \
	$(MAKE) get_pdf MODULE=$$MODULE $(NPD) $$NPD

get_pdf: | $(TMP_DIR)
	@PDF=$(MODULE)_en.pdf; \
	PDF_URL=$(GIT_URL)/blob/main/pdf/CPP/$$PDF?raw=true; \
	curl -# -L $$PDF_URL -o $(TMP_DIR)/$$PDF; \
	$(OPEN) $(TMP_DIR)/$$PDF;

.PHONY: pdf get_pdf
# **************************************************************************** #
# ------------------------------ DOCUMENTATION ------------------------------- #
# **************************************************************************** #
CPP_REF_URL		:=	https://cplusplus.com/reference/
CPP_TUTO_URL	:=	https://cplusplus.com/doc/oldtutorial/

ref:
	@echo "Opening cplusplus reference's url..."
	@$(OPEN) $(CPP_REF_URL);

tuto:
	@echo "Opening cplusplus oldtutorial's url..."
	@$(OPEN) $(CPP_TUTO_URL);

.PHONY: ref tuto
# **************************************************************************** #
# ----------------------------------- GIT ------------------------------------ #
# **************************************************************************** #
MAIN_BRANCH	:= $(shell git branch -r | grep -E 'origin/(main|master)' \
					| grep -v 'HEAD' | head -n 1 | sed 's@^.*origin/@@')

update:
	@echo "Updating repository from branch $(CYAN)$(MAIN_BRANCH)$(RESET)..."
	@echo "Are you sure you want to update the repo? [y/N] " \
	&& read ANSWER; \
	if [ "$$ANSWER" = "y" ] || [ "$$ANSWER" = "Y" ]; then \
		git pull origin $(MAIN_BRANCH); \
		echo "Repository updated."; \
	else \
		echo "canceling update..."; \
	fi

.PHONY: update
# **************************************************************************** #
# --------------------------------- GITHUB ----------------------------------- #
# **************************************************************************** #
REPO_LINK	:= https://github.com/SaydRomey/CPP

repo:
	@echo "Opening $(AUTHOR)'s github repo..."
	@$(OPEN) $(REPO_LINK);

.PHONY: repo
# **************************************************************************** #
# ---------------------------------- NEW ------------------------------------- #
# **************************************************************************** #
PASSWORD			:=	sudo
MAKEFILE_TEMPLATE	:=	Misc/Makefile.template

new:
	@echo "Select the CPP module:"
	@echo "0. Module 00"
	@echo "1. Module 01"
	@echo "2. Module 02"
	@echo "3. Module 03"
	@echo "4. Module 04"
	@echo "5. Module 05"
	@echo "6. Module 06"
	@echo "7. Module 07"
	@echo "8. Module 08"
	@echo "9. Module 09"
	@read module_choice; \
	case $$module_choice in \
		0) MODULE_NUM=00;; \
		1) MODULE_NUM=01;; \
		2) MODULE_NUM=02;; \
		3) MODULE_NUM=03;; \
		4) MODULE_NUM=04;; \
		5) MODULE_NUM=05;; \
		6) MODULE_NUM=06;; \
		7) MODULE_NUM=07;; \
		8) MODULE_NUM=08;; \
		9) MODULE_NUM=09;; \
		*) echo "Invalid choice. Exiting." ; exit 1;; \
	esac; \
	echo "Enter exercise number (e.g., 00, 01): "; \
	read exnum; \
	exdir="CPP$$MODULE_NUM/ex$$exnum"; \
	if [ -d "$$exdir" ]; then \
		echo "$$exdir already exists. Overwrite? [y/N]: "; \
		read overwrite_choice; \
		if [ "$$overwrite_choice" = "y" ] || [ "$$overwrite_choice" = "Y" ]; then \
			echo "Enter password: "; \
			read user_password; \
			if [ "$$user_password" != "$(PASSWORD)" ]; then \
				echo "Incorrect password. Exiting."; \
				exit 1; \
			fi; \
		else \
			echo "Keeping $$exdir as it was..."; \
			exit 1; \
		fi; \
	fi; \
	mkdir -p $$exdir/$(SRC_DIR) $$exdir/$(INC_DIR); \
	echo "$$MAIN_CPP" > $$exdir/$(SRC_DIR)/main.cpp; \
	cp $(MAKEFILE_TEMPLATE) $$exdir/Makefile; \
	if [ "$(OS)" = "Darwin" ]; then \
		sed -i '' "s/cpp00/cpp$$MODULE_NUM/" $$exdir/Makefile; \
	else \
		sed -i "s/cpp00/cpp$$MODULE_NUM/" $$exdir/Makefile; \
	fi; \
	echo "Should we create a new class? [y/N]: "; \
	read create_class; \
	if [ "$$create_class" = "y" ] || [ "$$create_class" = "Y" ]; then \
		(cd $$exdir; $(MAKE) class $(NPD)); \
	fi; \
	echo "Created exercise environment in $$exdir"

.PHONY: new
# **************************************************************************** #
# ------------------------------- TEMPLATES ---------------------------------- #
# **************************************************************************** #
define MAIN_CPP
/*
*/

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	return (0);
}

endef

export MAIN_CPP
# **************************************************************************** #
# ----------------------------------- ANSI ----------------------------------- #
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
