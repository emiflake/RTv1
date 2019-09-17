# **************************************************************************** #
#                                                                              #
#                                                              ::::::::        #
#    Makefile                                                :+:    :+:        #
#                                                           +:+                #
#    By: emiflake <marvin@student.codam.nl>                +#+                 #
#                                                         +#+                  #
#    Created: 2019/09/17 12:26:31 by emiflake            #+#    #+#            #
#    Updated: 2019/09/17 12:31:11 by emiflake            ########   odam.nl    #
#                                                                              #
# **************************************************************************** #

include colors.mk

NAME=RTv1
CC=clang
AR=ar
RM=rm
FLAGS=-Werror -Wall -Wextra

OBJ_DIR=	.obj
OBJ_NAMES=	\
		main \

OBJECTS=	$(patsubst %, $(OBJ_DIR)/%.o, $(OBJ_NAMES))

SRC_DIR=	./src
SOURCES=	$(patsubst %, %.c, $(OBJ_NAMES))

INC_DIR=	./inc
INCLUDES=	$(wildcard $(INC_DIR)/*.h)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -c -o $@ $< -I$(INC_DIR) $(FLAGS)

$(NAME): $(OBJECTS)
	@echo "$(TIME) $(CPLUS) $@"
	@$(CC) -o $(NAME) $(OBJECTS)

clean:
	@echo "$(TIME) $(CMINUS) $(OBJ_DIR)"
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(NAME)"
	@$(RM) -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)
