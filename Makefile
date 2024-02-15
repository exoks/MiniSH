# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 11:01:09 by hael-mou          #+#    #+#              #
#    Updated: 2023/07/27 22:01:01 by hael-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:=	minishell
BONUS			:=	minishell_bonus

# Directories:
SRC_DIR			:=	srcs
LIBFT_DIR		:= 	libft
RDL_DIR			:=	readline
OBJ_DIR			:=	objs
BOBJ_DIR		:=	bonus_objs

# Libraries:
LIBFT			:=	$(LIBFT_DIR)/libft.a

# Files:
SRC_FILES		:=	$(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/src/*.c)\
					$(wildcard $(SRC_DIR)/*/src/*/*.c)
OBJ_FILES		:=	$(patsubst %.c,$(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))
BOBJ_FILES		:=	$(patsubst %.c,$(BOBJ_DIR)/%.o, $(notdir $(SRC_FILES)))

# include:
INCLUDE_FILES	:= 	../readline/includes/readline.h $(wildcard includes/*.h) \
					$(wildcard */includes/*.h) $(wildcard */*/includes/*.h)
INCLUDE_DIRS	:=	$(sort $(dir $(INCLUDE_FILES)))

# Command:
CC				:= 	cc
RM				:= 	rm -rf
CFLAGS 			:= 	-Wall -Wextra -Werror #-g -fsanitize=address
LINKS			:= 	-lft -lreadline 
LINKS_DIR		:=	-L $(LIBFT_DIR) -L $(RDL_DIR)
INCLUDE			:=	$(addprefix -I,$(INCLUDE_DIRS))

# Colors :
DEF				= \033[0;39m
GRAY			= \033[0;90m
PINK			= \033[0;38;5;199m
RED				= \033[0;91m
GREEN			= \033[0;32m
CYAN			= \033[0;96m
PURPLE			= \033[0;35m
YELLOW			= \033[0;93m

# compiling Rules:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .create_dirs
	@$(CC) $(CFLAGS) -D BONUS=0 $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]$(DEF)	$(PURPLE)Compiling$(DEF)  $<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/src/%.c | .create_dirs
	@$(CC) $(CFLAGS) -D BONUS=0 $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]$(DEF)	$(PURPLE)Compiling$(DEF)  $<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/src/*/%.c | .create_dirs
	@$(CC) $(CFLAGS) -D BONUS=0 $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]$(DEF)	$(PURPLE)Compiling$(DEF)  $<"

# bonus pattern rules:
$(BOBJ_DIR)/%.o: $(SRC_DIR)/%.c | .create_bdirs
	@$(CC) $(CFLAGS) -D BONUS=1 $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]$(DEF)	$(PURPLE)Compiling$(DEF)  $<"

$(BOBJ_DIR)/%.o: $(SRC_DIR)/*/src/%.c | .create_bdirs
	@$(CC) $(CFLAGS) -D BONUS=1 $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]$(DEF)	$(PURPLE)Compiling$(DEF)  $<"

$(BOBJ_DIR)/%.o: $(SRC_DIR)/*/src/*/%.c | .create_bdirs
	@$(CC) $(CFLAGS) -D BONUS=1 $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]$(DEF)	$(PURPLE)Compiling$(DEF)  $<"

.create_dirs: $(OBJ_DIR)

.create_bdirs: $(BOBJ_DIR)

# role :
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS_DIR) $^ -o $@ $(LINKS)
	@echo "$(GREEN) [OK]$(DEF)$(YELLOW)	[ $@ is created ]$(DEF)"

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BOBJ_FILES) 
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS_DIR) $^ -o $@ $(LINKS)
	@echo "$(GREEN) [OK]$(DEF)$(YELLOW)	[ $@ is created ]$(DEF)"

run:
	./$(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		echo "$(GREEN) [OK]$(DEF)	$(CYAN)$(NAME) Object files cleaned!$(DEF)";\
	fi
	@if [ -d $(BOBJ_DIR) ]; then\
		$(RM) $(BOBJ_DIR);\
		echo "$(GREEN) [OK]$(DEF)	$(CYAN)$(BONUS) Object files cleaned!$(DEF)";\
	fi

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		echo "$(GREEN) [OK]$(DEF)	$(RED)$(NAME) cleaned!$(DEF)";\
	fi
	@if [ -f $(BONUS) ]; then\
		$(RM) $(BONUS);\
		echo "$(GREEN) [OK]$(DEF)	$(RED)$(BONUS) cleaned!$(DEF)";\
	fi
	
re: fclean all

$(LIBFT):
	@make -SC $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BOBJ_DIR):
	@mkdir -p $(BOBJ_DIR);

.PHONY: all clean fclean re run
