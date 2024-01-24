# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 20:33:58 by cdumais           #+#    #+#              #
#    Updated: 2024/01/24 16:04:00 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TODO: adapt the pdf module to match the chosen module when 'make new' copies the Makefile.template

NAME		:=	CPP
INC_DIR		:=	inc
SRC_DIR		:=	src
TMP_DIR		:=	tmp
REMOVE		:=	rm -rf
OS			:=	$(shell uname)
NPD			:=	--no-print-directory

all:

	@echo "'make pdf' \t-> get a CPP instruction pdf in './$(TMP_DIR)/'"
	@echo "'make update' \t-> pull the github version"
	@echo "'make ref' \t-> open the c++ reference url"
	@echo "'make class \t-> create a class template in hpp file and cpp file"
	@echo "'make new' \t-> create an new exercise basic template"

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
# --------------------------------- CLASS ------------------------------------ #
# **************************************************************************** #
class:
	@echo "Enter the class name: "; \
	read classname; \
	classname_upper=`echo $$classname | tr a-z A-Z`; \
	if [ -f inc/$$classname.hpp ] || [ -f src/$$classname.cpp ]; then \
		read -p "Files exist. Overwrite? [y/N]: " confirm; \
		if [ "$$confirm" != "y" ] || [ "$$confirm" != "Y" ]; then \
			echo "Canceling class creation"; \
			exit 1; \
		fi; \
	fi; \
	mkdir -p $(INC_DIR) $(SRC_DIR); \
	echo "$$CLASS_HEADER" \
	| sed "s/CLASSNAME_UPPER/$$classname_upper/g" \
	| sed "s/CLASSNAME/$$classname/g" > inc/$$classname.hpp; \
	echo "$$CLASS_CPP" \
	| sed "s/CLASSNAME/$$classname/g" > src/$$classname.cpp; \
	echo "$$classname created"

.PHONY: class
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
	@read module_choice; \
	case $$module_choice in \
		0) MODULE=CPP00;; \
		1) MODULE=CPP01;; \
		2) MODULE=CPP02;; \
		3) MODULE=CPP03;; \
		4) MODULE=CPP04;; \
		*) echo "Invalid choice. Exiting." ; exit 1;; \
	esac; \
	echo "Enter exercise number (e.g., 00, 01): "; \
	read exnum; \
	exdir="$$MODULE/ex$$exnum"; \
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
	echo "Should we create a new class? [y/N]: "; \
	read create_class; \
	if [ "$$create_class" = "y" ] || [ "$$create_class" = "Y" ]; then \
		(cd $$exdir; $(MAKE) class $(NPD)); \
	fi; \
	echo "Created exercise environment in $$exdir"

.PHONY: new
# $(MAKE) -C $$exdir class #(insted of cd $$exdir...)?
# **************************************************************************** #
# ------------------------------- TEMPLATES ---------------------------------- #
# **************************************************************************** #
define MAIN_CPP
#include <iostream>

int	main(void)
{
	std::cout << "Don't panic !" << std::endl;
	return (0);
}
endef

export MAIN_CPP
# **************************************************************************** #
define CLASS_HEADER
#ifndef CLASSNAME_UPPER_HPP
# define CLASSNAME_UPPER_HPP

class CLASSNAME
{
	public:
		CLASSNAME(void);
		CLASSNAME(const CLASSNAME &src);
		~CLASSNAME(void);

		CLASSNAME & operator=(const CLASSNAME &rhs);

	private:
};

#endif // CLASSNAME_UPPER_HPP
endef

export CLASS_HEADER
# **************************************************************************** #
define CLASS_CPP
#include "CLASSNAME.hpp"

CLASSNAME::CLASSNAME(void)
{
	// Constructor
}

CLASSNAME::CLASSNAME(const CLASSNAME &src)
{
	// Copy constructor
	*this = src;
}

CLASSNAME::~CLASSNAME(void)
{
	// Destructor
}

CLASSNAME&	CLASSNAME::operator=(const CLASSNAME &rhs)
{
	// Copy assignment overload
	return (*this);
}
endef

export CLASS_CPP
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
