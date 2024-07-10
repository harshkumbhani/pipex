# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harsh <harsh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2024/07/09 22:59:24 by harsh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
###############                     CONFIG                        ##############
################################################################################

NAME := pipex
CC := cc
CFLAGS = -Wextra -Wall -Werror -MMD -MP $(addprefix -I, $(INC_DIRS))
LIBFT_DIR = ./libft
LIBFT_LIB = ./libft/libft.a

################################################################################
###############                 PRINT OPTIONS                     ##############
################################################################################

G := \033[32m
X := \033[0m
BO := $(shell tput bold)
LOG := printf "[$(BO)$(G)ⓘ INFO$(X)] %s\n"

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj
INC_DIRS := ./include ./libft/include
SRC_DIRS := ./ ./srcs/mandatory/ ./srcs/bonus/

# Tell the Makefile where headers and source files are
vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRCS_MANDATORY	= pipex.c pipe.c check_files.c utils.c \
					handle_error.c

SRCS_BONUS	= pipex_bonus.c utils_bonus.c handle_pipe.c \
			handle_error_bonus.c execute_bonus.c init.c

ifdef BONUS
	SRCS := $(SRCS_BONUS)
else
	SRCS := $(SRCS_MANDATORY)
endif

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

################################################################################
########                         COMPILING                      ################
################################################################################

all: submodule ft_lib $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Linking object files to $@"
	@$(CC) $(CFLAGS) $(LIBFT_LIB) $^ -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $@)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(LOG) "Creating object directory."
	@mkdir -p $@

submodule:
	@git submodule update --init

ft_lib:
	@if [ ! -f $(LIBFT_LIB) ]; then \
		$(LOG) "Creating ft_lib"; \
		make -C $(LIBFT_DIR); \
	else \
		$(LOG) "ft_lib already created"; \
	fi

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(LOG) "Cleaning $(notdir $(OBJ_DIR))"; \
		rm -rf $(OBJ_DIR); \
	else \
		$(LOG) "No objects to clean."; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(LOG) "Cleaning $(notdir $(NAME))"; \
		rm -f $(NAME); \
	else \
		$(LOG) "No library to clean."; \
	fi

re: fclean all

-include $(OBJS:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.d)

.PHONY: all fclean clean re

bonus:
	@$(MAKE) BONUS=1 all
