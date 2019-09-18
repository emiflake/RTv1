# **************************************************************************** #
#                                                                              #
#                                                              ::::::::        #
#    Makefile                                                :+:    :+:        #
#                                                           +:+                #
#    By: emiflake <marvin@student.codam.nl>                +#+                 #
#                                                         +#+                  #
#    Created: 2019/09/17 12:26:31 by emiflake            #+#    #+#            #
#    Updated: 2019/09/18 15:11:03 by emiflake            ########   odam.nl    #
#                                                                              #
# **************************************************************************** #

include colors.mk

NAME=RTv1
CC=clang
AR=ar
RM=rm
FLAGS=-Werror -Wall -Wextra

all: $(NAME)

# Libraries sections
#
# Libraries: ft_printf, 42img

FT_PRINTF_DIR=	./ft_printf
FT_PRINTF=	$(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INC=	$(FT_PRINTF_DIR)

$(FT_PRINTF):
	@echo "$(TIME) $(CPLUS) Making ft_printf"
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean_ft_printf:
	@echo "$(TIME) $(CMINUS) Cleaning ft_printf"
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

OBJ_DIR=	.obj
OBJ_NAMES=	\
		main \

OBJECTS=	$(patsubst %, $(OBJ_DIR)/%.o, $(OBJ_NAMES))

SRC_DIR=	./src
SOURCES=	$(patsubst %, %.c, $(OBJ_NAMES))

INC_DIR=	./inc
INCLUDES=	$(wildcard $(INC_DIR)/*.h)
IFLAGS=		-I$(INC_DIR) -I$(FT_PRINTF_INC)

LFLAGS=		-L$(FT_PRINTF_DIR) -lftprintf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) $(FT_PRINTF)
	@mkdir -p $(OBJ_DIR)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -c -o $@ $< $(IFLAGS) $(FLAGS)

$(NAME): $(OBJECTS)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -o $(NAME) $(LFLAGS) $(OBJECTS)

clean: clean_ft_printf
	@echo "$(TIME) $(CMINUS) $(OBJ_DIR)"
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(NAME)"
	@$(RM) -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)
