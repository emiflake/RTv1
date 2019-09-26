# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: emiflake <marvin@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/17 12:26:31 by emiflake       #+#    #+#                 #
#    Updated: 2019/09/26 20:15:24 by nmartins      ########   odam.nl          #
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
# Libraries: ft_printf, 42img, libft

LIBFT_DIR=	./libft
LIBFT=		$(LIBFT_DIR)/libft.a
LIBFT_INC=	$(LIBFT_DIR)

$(LIBFT):
	@echo "$(TIME) $(CPLUS) Making libft"
	@$(MAKE) -C $(LIBFT_DIR)

clean_libft:
	@echo "$(TIME) $(CMINUS) Cleaning libft"
	@$(MAKE) -C $(LIBFT_DIR) fclean

FT_PRINTF_DIR=	./ft_printf
FT_PRINTF=	$(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INC=	$(FT_PRINTF_DIR)

$(FT_PRINTF):
	@echo "$(TIME) $(CPLUS) Making ft_printf"
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean_ft_printf:
	@echo "$(TIME) $(CMINUS) Cleaning ft_printf"
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

FTIMG_DIR=	./42img
FTIMG=		./$(FTIMG_DIR)/libftimg.a
FTIMG_INC=	$(FTIMG_INC)/inc

$(FTIMG):
	@echo "$(TIME) $(CPLUS) Making 42img"
	@$(MAKE) -C $(FTIMG_DIR)

clean_ftimg:
	@echo "$(TIME) $(CMINUS) Cleaning 42img"
	@$(MAKE) -C $(FTIMG_DIR) fclean

OBJ_DIR=	.obj
OBJ_NAMES=	\
		main \
		app \
		primitives \
		scene \
		object_container \
		shape \
		sphere \
		vec3_add \
		vec3_calc \
		vec3_length \
		vec3_rot \
		vec3_mut \
		camera \
		keystate \
		color \

OBJECTS=	$(patsubst %, $(OBJ_DIR)/%.o, $(OBJ_NAMES))

SRC_DIR=	./src
SOURCES=	$(patsubst %, %.c, $(OBJ_NAMES))

INC_DIR=	./inc
INCLUDES=	$(wildcard $(INC_DIR)/*.h)
IFLAGS=		-I$(INC_DIR) -I$(FT_PRINTF_INC) \
			-I$(LIBFT_DIR) \
			-I$(shell brew --prefix)/include

LFLAGS=		\
		-L$(FT_PRINTF_DIR) -lftprintf \
		-L$(FTIMG_DIR) -lftimg \
		-L$(LIBFT_DIR) -lft \
		$(shell sdl2-config --libs) \

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(FT_PRINTF) $(FTIMG) $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -c -o $@ $< $(IFLAGS) $(FLAGS)

$(NAME): $(OBJECTS)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -o $(NAME) $(LFLAGS) $(OBJECTS)

clean: clean_ft_printf clean_ftimg clean_libft
	@echo "$(TIME) $(CMINUS) $(OBJ_DIR)"
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(NAME)"
	@$(RM) -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)
