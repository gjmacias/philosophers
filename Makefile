
NAME	=	philosophers


CC		=	gcc

CFLAGS	=	-g -Wall -Wextra -Werror -MMD -MP


SRC 	=	philosophers.c	inits.c	launcher.c	error_manager.c	utils.c
OBJ 	=	addprefix($(OBJ_DIR), $(SRC:.c=.o))
DEPS	=	addprefix($(DPS_DIR), $(SRC:.c=.d))


SRC_DIR	=	src/
OBJ_DIR	=	obj/
DPS_DIR	=	dps/


INCS        = -I./includes/


all			:		$(NAME)

make_dir	:
		mkdir -p $(DIR_OBJ)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | make_dir
		$(CC) $(CFLAGS) $(INCS) -c $< -o $@



$(NAME)		:		$(OBJ)
		@echo "Compiling $(NAME)"
		$(CC) $(CFLAGS) $(INCS) $(OBJ) -o $(NAME)
		@echo "Created $(NAME) executable"

clean		:
		@echo "Removing $(NAME) objects..."
		rm -rf $(OBJ_DIR) $(DPS_DIR)
		@echo "Done!"

fclean		:		clean
		@echo "Removing execute $(NAME)..."
		rm -f $(NAME)
		@echo "Done!"

re			:		fclean all

-include $(DEPS)

.PHONY		:		all make_dir clean fclean re
