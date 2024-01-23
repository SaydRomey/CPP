
NAME		:=	RepetitiveWork

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
	@$(MAKE) get_pdf MODULE=cpp03 $(NPD)

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
	echo "$$classname created"

.PHONY: class
# **************************************************************************** #
# ---------------------------------- UTILS ----------------------------------- #
# **************************************************************************** #
run: all
	./$(NAME)

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)

ffclean: fclean
	@$(REMOVE) $(TMP_DIR)

.PHONY: run ffclean
# **************************************************************************** #
# ------------------------------- TEMPLATES ---------------------------------- #
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

		CLASSNAME&	operator=(const CLASSNAME &rhs);

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