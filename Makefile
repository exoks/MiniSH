#  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀                𓐓  Makefile 𓐔           
#  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
#  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
#  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
#  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
#  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2025/02/22 11:42:15 by oezzaou
#  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/22 17:27:09 by oezzaou
#  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
#  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
#  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
#  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#====<[ CC compiler: ]>=========================================================
CC						:= cc
CFLAGS				:= -Wall -Wextra -Werror #-g -fsanitize=address
RM						:= rm -rf

#====<[ Colors: ]>==============================================================
GREEN					= \033[0;32m
RED						= \033[1;31m
BLUE					= \033[34m
CYAN					= \033[1;36m
GRAY					= \033[0;90m
PURPLE				= \033[0;35m
YELLOW				= \033[0;93m
BLACK  				= \033[20m
MAGENTA 			= \033[35m
WHITE  				= \033[37m
PINK					= \033[0;38;5;199m
ORANGE 				= \033[38;5;214m
LIGHT_BLACK  	= \033[90m
LIGHT_RED    	= \033[91m
LIGHT_GREEN  	= \033[92m
LIGHT_YELLOW 	= \033[93m
LIGHT_BLUE   	= \033[94m
LIGHT_MAGENTA = \033[95m
LIGHT_CYAN   	= \033[96m
LIGHT_WHITE  	= \033[97m
LIGHT_BLUE		= \033[38;5;45m
RESET					= \033[1;0m

#===<[ Sources: ]>==============================================================
PROJECT				:= Minishell
NAME					:= minishell
NAME_BNS			:= minishell_bonus
# Directories:
SRC_DIR				:= srcs
LIBFT_DIR			:= libft
RDL_DIR				:= readline
OBJ_DIR				:= objs
OBJ_BNS_DIR		:= bonus_objs
# Libraries:
LIBFT					:= $(LIBFT_DIR)/libft.a
# Files:
SRC						:= $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/src/*.c)\
								 $(wildcard $(SRC_DIR)/*/src/*/*.c)

OBJ						:= $(patsubst %.c,$(OBJ_DIR)/%.o, $(notdir $(SRC)))
OBJ_BNS				:= $(patsubst %.c,$(OBJ_BNS_DIR)/%.o, $(notdir $(SRC)))
# include:
INCLUDE				:= ../readline/include/readline.h $(wildcard include/*.h)\
								 $(wildcard */include/*.h) $(wildcard */*/include/*.h)
INCLUDE_DIRS	:= $(sort $(dir $(INCLUDE)))
# Command:
LINKS					:= -lft -lreadline 
LINKS_DIR			:= -L $(LIBFT_DIR) -L $(RDL_DIR)
INCLUDE				:= $(addprefix -I,$(INCLUDE_DIRS))

#====<[ Rules: ]>===============================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .create_dirs
	@$(CC) $(CFLAGS) -D NAME_BNS=0 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/src/%.c | .create_dirs
	@$(CC) $(CFLAGS) -D NAME_BNS=0 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/src/*/%.c | .create_dirs
	@$(CC) $(CFLAGS) -D NAME_BNS=0 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"

# bonus pattern rules:
$(OBJ_BNS_DIR)/%.o: $(SRC_DIR)/%.c | .create_bdirs
	@$(CC) $(CFLAGS) -D NAME_BNS=1 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"

$(OBJ_BNS_DIR)/%.o: $(SRC_DIR)/*/src/%.c | .create_bdirs
	@$(CC) $(CFLAGS) -D NAME_BNS=1 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"

$(OBJ_BNS_DIR)/%.o: $(SRC_DIR)/*/src/*/%.c | .create_bdirs
	@$(CC) $(CFLAGS) -D NAME_BNS=1 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"

# role :
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS_DIR) $^ -o $@ $(LINKS)
	@echo "${GREEN}[OK] ${CYAN}$(NAME) ✔️${RESET}"

$(LIBFT):
	@make -SC $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_BNS_DIR):
	@mkdir -p $(OBJ_BNS_DIR);

bonus: $(NAME_BNS)

signature:
	@printf "${GRAY}%19s${RESET}\n" "𓆩♕𓆪"
	@printf "${GRAY}%s${RESET}\n"		"𓄂 oussama ezzaou𓆃  "

run:
	./$(NAME)

$(NAME_BNS): $(LIBFT) $(OBJ_BNS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS_DIR) $^ -o $@ $(LINKS)
	@echo "$(GREEN) [OK]$(RESET)$(YELLOW)	[ $@ is created ]$(RESET)"
	@echo "${GREEN}[OK] ${CYAN}$(NAME_BNS) ✔️${RESET}"

clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d $(OBJ_DIR) ]; then\
		${RM} $(OBJ_DIR);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-42s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(OBJ_DIR) ✔️";\
	fi
	@if [ -d $(OBJ_BNS_DIR) ]; then\
		${RM} $(OBJ_BNS_DIR);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-42s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(OBJ_BNS_DIR) ✔️";\
	fi

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@if [ -f $(NAME) ]; then\
		${RM} $(NAME);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-42s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(NAME) ✔️";\
	fi
	@if [ -f $(NAME_BNS) ]; then\
		${RM} $(NAME_BNS);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-42s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(NAME_BNS) ✔️";\
	fi

.create_dirs: $(OBJ_DIR)

.create_bdirs: $(OBJ_BNS_DIR)

re: fclean all

.PHONY: all clean fclean re run
#===============================================================================
