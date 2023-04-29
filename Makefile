NAME = libft.a

DIR_SRC = ./src
DIR_OBJ = ./obj
SUBDIR_SRC = $(wildcard $(DIR_SRC)/*)
SUBDIR_OBJ = $(subst $(DIR_SRC),$(DIR_OBJ),$(SUBDIR_SRC))
SRC = $(filter %.c,$(shell find $(DIR_SRC)))
OBJ = $(subst $(DIR_SRC),$(DIR_OBJ),$(SRC:.c=.o))
INCLUDE = -I ./include

ARCH	= /bin/ar
RM		= /bin/rm
CC		= /bin/clang
CFLAGS	= -Wall -Werror -Wextra

OBJ_DIRS_FLAG		= .obj_dirs_created
NAME_UPDATE_FLAG	= .name_is_up_to_date

$(NAME): $(OBJ) | $(NAME_UPDATE_FLAG)
	@if [ -e $(NAME) ] && [ $(NAME_UPDATE_FLAG) -nt $(NAME) ]; then \
		printf "\033[Kmake: 'libft.a' is up to date.\n"; \
	else \
		$(ARCH) -rcs $(NAME) $(OBJ); \
		ranlib $(NAME); \
		touch $(NAME_UPDATE_FLAG); \
	fi

$(OBJ): $(SRC) | $(OBJ_DIRS_FLAG)
	@if [ -e $(NAME) ] && [ $(NAME_UPDATE_FLAG) -nt $(NAME) ]; then \
		for c in $(SRC); do \
			if [ "$$c" -ot "$(NAME)" ]; then \
				continue; \
			else \
				printf "There is an update in \033[38;2;240;20;20;1m%s\033[m, rebuilding.\n" `echo $$c | cut -d/ -f3-4`; \
				make --silent re; \
				break; \
			fi; \
		done; \
	else \
		printf "\033[38;2;40;240;60;48;2;20;20;20;1m\033[M  [LIBFT]\n"; \
		n=0; \
		for f in $(SRC); do \
			obj="$$(echo $$f | sed 's|$(DIR_SRC)|$(DIR_OBJ)|;s|\.c|\.o|')"; \
			$(CC) $(CFLAGS) $(INCLUDE) -c "$$f" -o "$$obj"; \
			n=$$(($$n+1)); \
			printf "\tCompiled files: $$n\033[K\r"; \
		done; \
		printf "\n\tDone compiling.\n\033[m"; \
	fi

$(OBJ_DIRS_FLAG):
	@mkdir -p $(DIR_OBJ) $(SUBDIR_OBJ)
	@touch $(OBJ_DIRS_FLAG)

$(NAME_UPDATE_FLAG):
	@touch $(NAME_UPDATE_FLAG)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@$(RM) -rf $(OBJ) $(DIR_OBJ)

fclean: clean
	@$(RM) -rf $(NAME) $(OBJ_DIRS_FLAG) $(NAME_UPDATE_FLAG)

re: fclean all
