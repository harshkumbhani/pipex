# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2023/10/12 10:35:21 by hkumbhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME 	= pipex
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -MMD -MP
LIBFT_DIR = ./srcs/myLib
LIBFT_LIB = ./srcs/myLib/libft.a
HEADERS = -I./include -I./srcs/myLib/header -g
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

OBJDIR = ./objs

VPATH 		= .:./srcs/:./srcs/bonus/:

SRCS_ERR	= handle_error.c
SRCS_OTHERS	= check_files.c utils.c pipe.c

SRCS_BONUS	= pipex_bonus.c utils_bonus.c handle_pipe.c handle_error_bonus.c \
				execute_bonus.c init.c
################################################################################
#                                  Makefile  objs                              #
################################################################################

SRCS = pipex.c $(SRCS_ERR) $(SRCS_OTHERS)
OBJS = $(addprefix $(OBJDIR)/, ${SRCS:%.c=%.o})

BONUS_SRC = $(SRCS_BONUS)
BONUS_OBJS = $(addprefix $(OBJDIR)/, ${BONUS_SRC:%.c=%.o})
################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m # Blue
OBJ_COLOR   = \033[0;36m # Cyan
ERROR_COLOR = \033[0;31m # Red
WARN_COLOR  = \033[0;33m # Yellow
OK_COLOR    = \033[0;32m # Green
NO_COLOR    = \033[m 

COM_STRING   = "Compiling"

################################################################################
#                                 Makefile rules                             #
################################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR) $(OBJS) $(NO_COLOR)"
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT_LIB) -o $@

$(LIBFT_LIB):
	@make re -C $(LIBFT_DIR) > make_output.txt 2>&1; \
	if [ $$? -eq 0 ]; then \
		echo "$(OK_COLOR)LIBFT.A compilation successful.$(NO_COLOR)"; \
	else \
		echo "$(ERROR_COLOR)LIBFT.A compilation failed.$(NO_COLOR) Check make_output.txt for details."; \
		exit 1; \
	fi

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

bonus: pipex_bonus

pipex_bonus: $(BONUS_OBJS) $(LIBFT_LIB)
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR) $(BONUS_OBJS) $(NO_COLOR)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) -o $@

clean:
	@echo
	@printf "%b" "$(COM_COLOR)Cleaning objects and dependency files...$(NO_COLOR)"
	@make clean -C $(LIBFT_DIR)
	@rm -rf objs program make_output.txt
	@echo

fclean: clean
	@printf "%b" "$(COM_COLOR)Cleaning libft library...$(NO_COLOR)"
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) bonus
	@echo

norm: $(SRCS)
	$(shell norminette | grep Error)

re: fclean all

.PHONY: all clean fclean re $(LIBFT) bonus