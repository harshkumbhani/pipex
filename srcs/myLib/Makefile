# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:34:52 by hkumbhan          #+#    #+#              #
#    Updated: 2023/08/07 11:50:30 by hkumbhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME 	= libft.a
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -MMD -I./header -g
AUTHOR	= hkumbhan
DATE	= 10.07.2023
NOVISU 	= 0

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

OBJDIR = objs
FILE_EXTENSION = .c
VPATH = ./gnl ./printf ./libft

SRC_LIBFT = ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c \
			ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_memchr.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_print_bit.c \
			ft_isspace.c ft_atol.c 

SRC_LIST = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_GNL = get_next_line_utils.c get_next_line.c 

SRC_PRINTF = ft_printstr.c ft_printnum.c ft_printf.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SRCS = $(SRC_LIBFT) $(SRC_GNL) $(SRC_LIST) $(SRC_PRINTF)
OBJS = $(addprefix objs/, ${SRCS:%$(FILE_EXTENSION)=%.o})

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m # Blue
OBJ_COLOR   = \033[0;36m # Cyan
ERROR_COLOR = \033[0;31m # Red
WARN_COLOR  = \033[0;33m # Yellow
OK_COLOR    = \033[0;32m # Green
NO_COLOR    = \033[m 


################################################################################
#                                 Makefile rules                             #
################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling Libft.a library...\n"
	@ar rcs $@ $^

$(OBJDIR)/%.o: %$(FILE_EXTENSION)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)
	
norm: $(SRCS)
	$(shell norminette | grep Error)
	 	
re: fclean all

.PHONY: all clean fclean re header