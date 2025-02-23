#  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀                𓐓  Makefile 𓐔           
#  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
#  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
#  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
#  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
#  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2025/02/22 11:42:15 by oezzaou
#  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/23 17:06:31 by oezzaou
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
GREEN					= \033[1;32m
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
SRC_DIR				:= src
RDL_DIR				:= readline
OBJ_DIR				:= obj
LIBFT					:= libft 
SRC						:= $(wildcard $(SRC_DIR)/*.c)\
								 $(wildcard $(SRC_DIR)/*/$(SRC_DIR)/*.c)\
								 $(wildcard $(SRC_DIR)/*/$(SRC_DIR)/*/*.c)

OBJ						:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

INCLUDE				:= ../readline/include/readline.h\
								 $(wildcard include/*.h)\
								 $(wildcard */include/*.h)\
								 $(wildcard */*/include/*.h)

INCLUDE_DIRS	:= $(sort $(dir $(INCLUDE)))
INCLUDE				:= $(addprefix -I,$(INCLUDE_DIRS))
EXTERNAL_LIBS	:= -L $(LIBFT) -lft -L $(RDL_DIR) -lreadline 

#====<[ Rules: ]>===============================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .create_dir
	@$(CC) $(CFLAGS) -D NAME_BNS=1 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/$(SRC_DIR)/%.c | .create_dir
	@$(CC) $(CFLAGS) -D NAME_BNS=1 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"
#
$(OBJ_DIR)/%.o: $(SRC_DIR)/*/$(SRC_DIR)/*/%.c | .create_dir
	@$(CC) $(CFLAGS) -D NAME_BNS=1 $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-42s| $@\n" "$<"

all: $(NAME)

$(NAME): $(LIBFT) | $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $| -o $@ $(EXTERNAL_LIBS)
	@echo "${GREEN}[OK] ${CYAN}$(NAME) ✔️${RESET}"

run:
	./$(NAME)

signature:
	@printf "${GRAY}%19s${RESET}\n" "𓆩♕𓆪"
	@printf "${GRAY}%s${RESET}\n"		"𓄂 oussama ezzaou𓆃  "

$(LIBFT):
	@make -C $@ 

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make -C $(LIBFT) fclean
	@if [ -d $(OBJ_DIR) ]; then\
		${RM} $(OBJ_DIR);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-42s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(OBJ_DIR) ✔️";\
	else\
		printf "${RED}[KO]${RESET} ${BLUE}Not Found %-42s${RESET}| ./%s\n"\
					 "..." "$(PROJECT)/$(OBJ_DIR) ✖️";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		${RM} $(NAME);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-42s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(NAME) ✔️";\
	fi

re: fclean all

.create_dir: $(OBJ_DIR)

.PHONY: all clean fclean re $(LIBFT) run signature 
#===============================================================================
