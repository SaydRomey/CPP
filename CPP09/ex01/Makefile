
NAME		:=	RPN
AUTHOR		:=	cdumais

COMPILE		:=	c++
C_FLAGS		:=	-Wall -Wextra -Werror
STANDARD	:=	-std=c++98

INC_DIR		:=	inc
INCS		:=	$(wildcard $(INC_DIR)/*.hpp)
HEADERS		:=	-I$(INC_DIR)

SRC_DIR		:=	src
SRCS		:=	$(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR		:=	obj
OBJS		:=	$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

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

# Conditional flag for Linux to allow implicit fall-through in switch statements
ifeq ($(OS), Linux)
	C_FLAGS += -Wno-error=implicit-fallthrough -Wimplicit-fallthrough=0
endif

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
	@echo "Obtaining pdf..."
	@$(MAKE) get_pdf MODULE=cpp09 $(NPD)

get_pdf: | $(TMP_DIR)
	@PDF=$(MODULE)_en.pdf; \
	PDF_URL=$(GIT_URL)/blob/main/pdf/CPP/$$PDF?raw=true; \
	curl -# -L $$PDF_URL -o $(TMP_DIR)/$$PDF; \
	$(OPEN) $(TMP_DIR)/$$PDF

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
# --------------------------------- GITHUB ----------------------------------- #
# **************************************************************************** #
REPO_LINK	:= https://github.com/SaydRomey/CPP

repo:
	@echo "Opening $(AUTHOR)'s github repo..."
	@$(OPEN) $(REPO_LINK);

.PHONY: repo
# **************************************************************************** #
# ---------------------------------- UTILS ----------------------------------- #
# **************************************************************************** #
run: all
	./$(NAME)

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)

ffclean: fclean
	@if [ -n "$(wildcard $(TMP_DIR))" ]; then \
		$(REMOVE) $(TMP_DIR); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)Temporary files removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No temporary files to remove$(RESET)"; \
	fi

.PHONY: run ffclean
# **************************************************************************** #
# --------------------------------- CLASS ------------------------------------ #
# **************************************************************************** #
class:
	@echo "Enter the class name: "; \
	read classname; \
	classname_upper=`echo $$classname | tr a-z A-Z`; \
	if [ -f inc/$$classname.hpp ] || [ -f src/$$classname.cpp ]; then \
		read -p "Files exist. Overwrite? [y/N]: " confirm; \
		if [ "$$confirm" != "y" ] && [ "$$confirm" != "Y" ]; then \
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
	if [ -f $(SRC_DIR)/main.cpp ]; then \
		awk 'BEGIN {count=0} \
			/^$$/ {count++} \
			{print} \
			count==1 && !printed {print "#include \"'$$classname'.hpp\""; printed=1}' \
			$(SRC_DIR)/main.cpp > $(SRC_DIR)/tmp && mv $(SRC_DIR)/tmp $(SRC_DIR)/main.cpp; \
	fi; \
	echo "$$classname created"

.PHONY: class
# **************************************************************************** #
# ------------------------------- TEMPLATES ---------------------------------- #
# **************************************************************************** #
define CLASS_HEADER
#ifndef CLASSNAME_UPPER_HPP
# define CLASSNAME_UPPER_HPP

# include <iostream>

# define RESET		"\\033[0m"
# define RED		"\\033[91m"
# define GREEN		"\\033[32m"
# define YELLOW		"\\033[33m"
# define PURPLE		"\\033[95m"
# define ORANGE		"\\033[38;5;208m"
# define GRAYTALIC	"\\033[3;90m"

class CLASSNAME
{
	private:
		// Attributes
	
	public:
		// Constructors / Destructors
		CLASSNAME(void);
		CLASSNAME(const CLASSNAME &other);
		~CLASSNAME(void);

		// Getters / Setters

		// Functions / Methods

		// Operators
		CLASSNAME&	operator=(const CLASSNAME &other);

		// Exceptions
};

// std::ostream&	operator<<(std::ostream &out, const CLASSNAME &param);

#endif // CLASSNAME_UPPER_HPP
endef

export CLASS_HEADER
# **************************************************************************** #
define CLASS_CPP
#include "CLASSNAME.hpp"

/* ************************************************************************** */ // Constructors / Destructors

CLASSNAME::CLASSNAME(void)
{
	std::cout << GRAYTALIC << "CLASSNAME [default constructor]" << RESET << std::endl;
}

CLASSNAME::CLASSNAME(const CLASSNAME &other)
{
	*this = other;
	std::cout << GRAYTALIC << "CLASSNAME [copy constructor]" << RESET << std::endl;
}

CLASSNAME::~CLASSNAME(void)
{
	std::cout << GRAYTALIC << "CLASSNAME [default destructor]" << RESET << std::endl;
}

/* ************************************************************************** */ // Getters / Setters

/* ************************************************************************** */ // Functions / Methods

/* ************************************************************************** */ // Operators

CLASSNAME&	CLASSNAME::operator=(const CLASSNAME &other)
{
	// if (this != &other)
	// {}
	
	return (*this);
}

// std::ostream&	operator<<(std::ostream &out, const CLASSNAME &param)

/* ************************************************************************** */ // Exceptions

endef

export CLASS_CPP
# **************************************************************************** #
# ----------------------------------- ANSI ----------------------------------- #
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
