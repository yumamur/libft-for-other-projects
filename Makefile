NAME = libft.a

##############
##          ##
#   COLOUR   #
##          ##
##############

BOLD		= \033[1m
FG_RED		= \033[38;2;250;0;20m
FG_GREEN	= \033[38;2;20;250;0m
FG_BLUE		= \033[38;2;0;80;250m
FG_PURPLE	= \033[38;2;200;10;200m
FG_YELLOW	= \033[38;2;10;240;240m
FG_ORANGE	= \033[38;2;255;150;0m
BG_RED		= \033[38;2;250;0;20m
BG_GREEN	= \033[38;2;20;250;0m
BG_BLUE		= \033[38;2;0;80;250m
BG_PURPLE	= \033[38;2;200;10;200m
BG_YELLOW	= \033[38;2;10;240;240m
BG_ORANGE	= \033[38;2;255;150;0m
CL_END		= \033[m


##############
##          ##
#   BINARY   #
##          ##
##############

RM		= /usr/bin/rm -rf
archive	= /usr/bin/ar -rcs $(NAME) $(OBJ); \
		  /usr/bin/ranlib $(NAME)

CC		= /usr/bin/clang
CFLAGS	= -Wall -Werror -Wextra


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
SUBDIR_SRC = $(wildcard $(DIR_SRC)/*)
SUBDIR_OBJ = $(subst $(DIR_SRC),$(DIR_OBJ),$(SUBDIR_SRC))
SRC = $(filter %.c,$(shell find $(DIR_SRC)))
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
			printf "\t\033[38;2;40;240;60;1mDone rebuilding.\033[m"; \
			$(RM) ./.rebuild; \
		else \
			printf "\033[Kmake: '$(NAME)' is up to date.\n"; \
		fi; \
	else \
		$(call archive); \
		touch $(NAME_UPDATE_FLAG); \
	fi

$(OBJ): $(SRC) | $(OBJ_DIRS_FLAG)
	@if [ -e $(NAME) ] && [ $(NAME_UPDATE_FLAG) -nt $(NAME) ]; then \
		for c in $(SRC); do \
			if [ "$$c" -ot "$(NAME)" ]; then \
				continue; \
			else \
				printf "There is an update in $(FG_RED)$$c$(CL_END), rebuilding.\n"; \
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
				|| { printf "\nCompilation failed for $(FG_RED)$(BOLD)$$f$(CL_END), un-doing."; rm -rf .rebuild; make -s fclean; exit 1; }; \
			n=$$(($$n+1)); \
			printf "$(FG_GREEN)$(BOLD)[LIBFT]\033[m Compiled files: $$n\033[K\r"; \
		done; \
		printf "\n$(FG_GREEN)$(BOLD)[LIBFT]\033[m Successful.\n"; \
	fi

$(OBJ_DIRS_FLAG):
	@mkdir -p $(DIR_OBJ) $(SUBDIR_OBJ)
	@touch $(OBJ_DIRS_FLAG)

$(NAME_UPDATE_FLAG):
	@touch $(NAME_UPDATE_FLAG)

.PHONY: archive all clean fclean re

all: $(NAME)

clean:
	@$(RM) $(DIR_OBJ)

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIRS_FLAG) $(NAME_UPDATE_FLAG)

re: fclean all
