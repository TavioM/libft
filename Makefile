# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 02:53:19 by ocmarout          #+#    #+#              #
#    Updated: 2020/03/06 14:18:22 by ocmarout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strnstr.c		\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c

SRC_BNS		=	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_backuis c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c

OBJS		=	${SRCS:.c=.o}
OBJS_BNS	=	$(addprefix ${OBJS_DIR}, ${SRC_BNS:.c=.o})

OBJS_DIR	=	./.objs/

CFLAGS		=	-Wall -Wextra -Werror ${INCLUDES}
INCLUDES	=	-I./includes/

NAME		=	libft.a

CC			=	clang
AR			=	ar rc
RANLIB		=	ranlib
MKDIR		=	mkdir -p
RM			=	rm -f

all		:	${NAME}

${NAME}	:	$(addprefix ${OBJS_DIR}, ${OBJS})
			${AR} $@ $^
			${RANLIB} $@

${OBJS_DIR}:
			${MKDIR} ${OBJS_DIR}

${OBJS_DIR}%.o : ${SRCS_DIR}%.c | ${OBJS_DIR}
			${CC} ${CFLAGS} -c $< -o $@

bonus	:	${NAME} ${OBJS_BNS}
			${AR} $^
			
clean	:
			${RM} -r ${OBJS_DIR} ${OBJ_BNS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean ${OBJS_DIR} all

.PHONY	:			re			\
					all			\
					clean		\
					fclean
