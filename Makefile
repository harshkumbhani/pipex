# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2023/09/06 14:17:01 by hkumbhan         ###   ########.fr        #
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

VPATH 		= .:./srcs/:./srcs/bonus/:./srcs/handle_error

SRCS_ERR	= handle_error.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SRCS = pipex.c check_files.c utils.c $(SRCS_ERR)
OBJS = $(addprefix $(OBJDIR)/, ${SRCS:%.c=%.o})

# BONUS_SRC = $(SRC_PARSE) $(SRC_LISTFN) $(SRC_OPS) checker.c bonus_utils.c
# BONUS_OBJS = $(addprefix $(OBJDIR)/, ${BONUS_SRC:%.c=%.o})
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
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR)$(OBJS) $(NO_COLOR)"
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

# bonus: checker

# checker: $(BONUS_OBJS) $(LIBFT_LIB)
# 	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR)$(OBJS) $(NO_COLOR)"
# 	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) -o $@

clean:
	@echo
	@printf "%b" "$(COM_COLOR)Cleaning objects and dependency files...$(NO_COLOR)"
	@make clean -C $(LIBFT_DIR)
	@rm -rf objs program make_output.txt
	@echo

fclean: clean
	@printf "%b" "$(COM_COLOR)Cleaning libft library...$(NO_COLOR)"
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) checker
	@echo

norm: $(SRCS)
	$(shell norminette | grep Error)

re: fclean all

.PHONY: all clean fclean re $(LIBFT) bonus