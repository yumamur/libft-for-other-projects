NAME = libft.a
TITLE = $(FG_GREEN)$(BOLD)[LIBFT]$(CL_END)

##############
##          ##
#   COLOUR   #
##          ##
##############

BOLD		= \033[1m
FG_RED		= \033[31m
FG_GREEN	= \033[32m
FG_YELLOW	= \033[33m
FG_BLUE		= \033[34m
FG_PURPLE	= \033[35m
BG_RED		= \033[41m
BG_GREEN	= \033[42m
BG_YELLOW	= \033[43m
BG_BLUE		= \033[44m
BG_PURPLE	= \033[45m
CL_END		= \033[m


##############
##          ##
#   BINARY   #
##          ##
##############

RM		= rm -rf
archive	= ar -rcs $(NAME) $(OBJ)

CC		= clang
CFLAGS	= -Wall -Werror -Wextra #-fsanitize=address


#############
##         ##
#   FLAGS   #
##         ##
#############

OBJ_DIRS_FLAG		=	.obj_dirs_created
NAME_UPDATE_FLAG	= 	.name_is_up_to_date


#############
##         ##
#   FILES   #
##         ##
#############

DIR_SRC = ./src
DIR_OBJ = ./obj
SUBDIR_SRC = $(wildcard $(DIR_SRC)/*) $(wildcard $(DIR_SRC)/.*)
SUBDIR_OBJ = $(subst $(DIR_SRC),$(DIR_OBJ),$(SUBDIR_SRC))
SRC = $(filter %.c, $(shell find $(DIR_SRC)))
OBJ = $(subst $(DIR_SRC),$(DIR_OBJ),$(SRC:.c=.o))
INCLUDE = -I ./include


#############
##         ##
#   RULES   #
##         ##
#############

$(NAME): $(OBJ) | $(NAME_UPDATE_FLAG)
	@if [ -e $(NAME) ] && [ $(NAME_UPDATE_FLAG) -nt $(NAME) ]; then \
		if [ -e .rebuild ]; then \
			printf "$(TITLE) Done rebuilding.\n"; \
			$(RM) ./.rebuild; \
		else \
			printf "$(TITLE) $(FG_GREEN)$(BOLD)$(NAME)$(CL_END) is up to date.\n"; \
		fi; \
	else \
		$(call archive); \
		touch $(NAME_UPDATE_FLAG); \
	fi

$(OBJ): $(SRC) | $(OBJ_DIRS_FLAG)
	@if [ -e $(NAME) ] && [ $(NAME_UPDATE_FLAG) -nt $(NAME) ]; then \
		for f in $(SRC); do \
			if [ "$$f" -ot "$(NAME)" ]; then \
				continue; \
			else \
				printf "$(TITLE) There is an update in $(FG_YELLOW)$$f$(CL_END), rebuilding.\n"; \
				touch .rebuild; \
				make --silent re; \
				break; \
			fi; \
		done; \
	else \
		n=0; \
		for f in $(SRC); do \
			obj="$$(echo $$f | sed 's|$(DIR_SRC)|$(DIR_OBJ)|;s|\.c|\.o|')"; \
			$(CC) $(CFLAGS) $(INCLUDE) -c "$$f" -o "$$obj" \
				|| { printf "\n$(TITLE) Compilation failed for $(FG_RED)$(BOLD)$$f$(CL_END), check your code.\n" >&2; rm -rf .rebuild; make -s fclean; exit 127; }; \
			n=$$(($$n+1)); \
			printf "$(TITLE) Compiled files: $$n\033[K\r"; \
		done; \
		printf "\n$(TITLE) Successful\n"; \
	fi

$(OBJ_DIRS_FLAG):
	@mkdir -p $(DIR_OBJ) $(SUBDIR_OBJ)
	@touch $(OBJ_DIRS_FLAG)

$(NAME_UPDATE_FLAG):
	@touch $(NAME_UPDATE_FLAG)

$(STACK_VIS): $(SRC_STACK_VIS) | $(NAME)

.PHONY: archive all clean fclean re

all: $(NAME)

clean:
	@$(RM) $(DIR_OBJ)

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIRS_FLAG) $(NAME_UPDATE_FLAG)

re: fclean all
