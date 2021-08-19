# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 02:53:19 by ocmarout          #+#    #+#              #
#    Updated: 2021/08/19 11:47:04 by ocmarout         ###   ########.fr        #
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
				ft_strcpy.c			\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isspace.c		\
				ft_isdigit.c		\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_split.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_itoa.c			\
				ft_itoa_base.c		\
				ft_utoa.c			\
				ft_utoa_base.c		\
				bin64_to_hex.c		\
				ft_check_base.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				trim_spaces.c		\
				$(addprefix Printf/, ft_printf.c)	\
				$(addprefix Printf/, parsing.c)	\
				$(addprefix Printf/, conversion_c.c)	\
				$(addprefix Printf/, conversion_d.c)	\
				$(addprefix Printf/, conversion_xX.c)	\
				$(addprefix Printf/, $(addprefix ${OS}, _conversion_s.c))	\
				$(addprefix Printf/, $(addprefix ${OS}, _conversion_p.c))	\
				$(addprefix lists/, ft_2lstnew.c)	\
				$(addprefix lists/, ft_2lstlast.c)	\
				$(addprefix lists/, ft_2lstadd_back.c)	\
				$(addprefix lists/, ft_2lstadd_front.c)	\

OBJS		=	${SRCS:.c=.o}

OBJS_DIR	=	./.objs/

CFLAGS		=	-Wall -Wextra -Werror ${INCLUDES}
INCLUDES	=	-I./includes/

NAME		=	libft.a

CC			=	clang
AR			=	ar rc
RANLIB		=	ranlib
MKDIR		=	mkdir -p
RM			=	rm -rf

OS			=	mac

UNAME	:=	$(shell uname)

ifeq	($(UNAME), Linux)
OS		=	linux
endif

all		:	${NAME}

${NAME}	:	$(addprefix ${OBJS_DIR}, ${OBJS})
			${AR} $@ $^
			${RANLIB} $@

${OBJS_DIR}:
			${MKDIR} ${OBJS_DIR}
			${MKDIR} $(addprefix ${OBJS_DIR}, Printf)
			${MKDIR} $(addprefix ${OBJS_DIR}, lists)

${OBJS_DIR}%.o : ${SRCS_DIR}%.c | ${OBJS_DIR}
			${CC} ${CFLAGS} -c $< -o $@

clean	:
			${RM} -r ${OBJS_DIR}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean ${OBJS_DIR} all

norme	:
			norminette
