# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: emiflake <marvin@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/17 12:26:31 by emiflake       #+#    #+#                 #
#    Updated: 2019/10/18 18:24:39 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include colors.mk

NAME=RTv1
CC=clang
AR=ar
RM=rm
EXTRA=
FLAGS=-Werror -Wall -Wextra -O2 $(EXTRA)

all: $(NAME)

# Libraries sections
#
# Libraries: 42img, libft

LIBFT_DIR=	./libft
LIBFT=		$(LIBFT_DIR)/libft.a
LIBFT_INC=	$(LIBFT_DIR)

$(LIBFT):
	@echo "$(TIME) $(CPLUS) Making libft"
	@$(MAKE) -C $(LIBFT_DIR)

clean_libft:
	@echo "$(TIME) $(CMINUS) Cleaning libft"
	@$(MAKE) -C $(LIBFT_DIR) fclean

OBJ_DIR=	.obj
OBJ_NAMES=	\
		main \
		app \
		primitives \
		scene \
		object_container \
		material \
		shape \
		sphere \
		cylinder \
		cone \
		plane \
		vec3_add \
		vec3_calc \
		vec3_length \
		vec3_rot \
		vec3_mut \
		vec3_clamp \
		camera \
		keystate \
		color \
		light_container \

OBJECTS=	$(patsubst %, $(OBJ_DIR)/%.o, $(OBJ_NAMES))

SRC_DIR=	./src
SOURCES=	$(patsubst %, %.c, $(OBJ_NAMES))

INC_DIR=	./inc
INCLUDES=	$(wildcard $(INC_DIR)/*.h)
IFLAGS=		-I$(INC_DIR) \
			-I$(LIBFT_DIR) \
			-I$(shell brew --prefix)/include

LFLAGS=		\
		-L$(LIBFT_DIR) -lft \
		$(shell sdl2-config --libs) \

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -c -o $@ $< $(IFLAGS) $(FLAGS)

$(NAME): $(OBJECTS)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -o $(NAME) $(LFLAGS) $(OBJECTS)

clean: clean_libft
	@echo "$(TIME) $(CMINUS) $(OBJ_DIR)"
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(NAME)"
	@$(RM) -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)
