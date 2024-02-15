# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 12:36:30 by hael-mou          #+#    #+#              #
#    Updated: 2023/07/27 21:03:18 by hael-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

# Directories:
SRC_DIR		= src/
OBJ_DIR		= obj/
INCLUDE		= includes/
CHECKS_DIR	= ft_Checks/
CONVERT_DIR	= ft_Convert/
MEMORY_DIR	= ft_Memory/
NUMBER_DIR	= ft_Number/
STIRNG_DIR	= ft_String/
PRINT_DIR	= ft_Print/
LIST_DIR	= ft_List/
GNL_DIR		= get_next_line/

# files:
FT_CHECKS	= ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_islower \
			  ft_isprint ft_isspace ft_isupper ft_isxdigit
FT_CONVERT	= ft_atoi ft_itoa ft_tolower ft_toupper
FT_MEMORY	= ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove\
			  ft_memset ft_realloc
FT_NUMBER	= ft_nbrlen ft_nbrnchr
FT_STRING	= ft_split ft_strchr ft_strcount ft_strdup ft_striteri ft_strjoin\
			  ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr\
			  ft_strrchr ft_strtok ft_strtrim ft_substr ft_strcmp ft_toklen\
			  ft_strnjoin ft_strreplace ft_vstrjoin ft_free_array ft_array_size
FT_PRINT	= ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_print_error
FT_GNL		= get_next_line get_next_line_utils
FT_LIST		= ft_lstdelone ft_lstadd_front ft_lstadd_back ft_lstdelone ft_lstclear\
			  ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize ft_lstsearch\
			  ft_lstrmif

SRC_FILES	 = $(addprefix $(CHECKS_DIR), $(FT_CHECKS))
SRC_FILES	+= $(addprefix $(CONVERT_DIR), $(FT_CONVERT))
SRC_FILES	+= $(addprefix $(MEMORY_DIR), $(FT_MEMORY))
SRC_FILES	+= $(addprefix $(NUMBER_DIR), $(FT_NUMBER))
SRC_FILES	+= $(addprefix $(STIRNG_DIR), $(FT_STRING))
SRC_FILES	+= $(addprefix $(PRINT_DIR), $(FT_PRINT))
SRC_FILES	+= $(addprefix $(LIST_DIR), $(FT_LIST))
SRC_FILES	+= $(addprefix $(GNL_DIR), $(FT_GNL))

SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Command:
CC			:= cc
AR			:= ar rc
RM			:= rm -rf
FLAGS 		:= -Wall -Wextra -Werror #-g -fsanitize=address

# Colors :
DEF			= \033[0;39m
GRAY		= \033[0;90m
PINK		= \033[0;38;5;199m
RED			= \033[0;91m
GREEN		= \033[0;32m
CYAN		= \033[0;96m
YELLOW		= \033[0;93m

# compiling Rules:
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)libft.h | .cache
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]$(DEF)	$(PINK)Compiling$(DEF) $<"

# role :
all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "$(GREEN) [OK]$(DEF)	$(YELLOW)[ libft.a is created ]$(DEF)"

clean:
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		echo "$(GREEN) [OK]$(DEF)	$(CYAN)LIBFT  Object files cleaned!$(DEF)";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		echo "$(GREEN) [OK]$(DEF)	$(CYAN)[ libft file cleaned!$ ]$(DEF)";\
	fi

re: fclean all

# cache dirs:
.cache: $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/$(CHECKS_DIR)
	@mkdir $(OBJ_DIR)/$(CONVERT_DIR)
	@mkdir $(OBJ_DIR)/$(MEMORY_DIR)
	@mkdir $(OBJ_DIR)/$(NUMBER_DIR)
	@mkdir $(OBJ_DIR)/$(STIRNG_DIR)
	@mkdir $(OBJ_DIR)/$(PRINT_DIR)
	@mkdir $(OBJ_DIR)/$(LIST_DIR)
	@mkdir $(OBJ_DIR)/$(GNL_DIR)

.PHONY: all clean fclean re
