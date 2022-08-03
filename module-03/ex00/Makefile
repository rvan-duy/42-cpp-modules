NAME			:= ClapTrap
CC				:= c++ -std=c++98
CFLAGS			:= -Wall -Wextra -Werror -g

################################################################################

ifdef ADDRESS
CFLAGS			+= -fsanitize=address -g3
endif
ifdef NO_FLAGS
CFLAGS			:= 
endif

################################################################################

HEADERS 		:= include/ClapTrap.hpp

INCLUDE_FLAGS 	:= $(addprefix -I, $(sort $(dir $(HEADERS))))

SOURCES 		:=	src/main.cpp src/ClapTrap.cpp

BOLD 			:= \e[1m
RESET 			:= \e[0m
LIGHT_GREEN 	:= \e[92m
LIGHT_CYAN 		:= \e[96m

OBJECTS_DIR		:= obj
OBJECTS			:= $(SOURCES:src/%.c=$(OBJECTS_DIR)/%.o)

################################################################################

all: $(NAME)

obj/%.o: src/%.c $(HEADERS)
	@mkdir -p $(@D)
	@printf "$(LIGHT_CYAN)$(BOLD)make$(RESET)   [$(LIGHT_GREEN)$(NAME)$(RESET)] : "
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(LIGHT_CYAN)$(BOLD)make$(RESET)   [$(LIGHT_GREEN)$(NAME)$(RESET)] : "
	@printf "$(NAME) created\n"

test: $(NAME)
	./$(NAME)

clean:
	@printf "$(LIGHT_CYAN)$(BOLD)clean$(RESET)  [$(LIGHT_GREEN)$(NAME)$(RESET)] : "
	/bin/rm -rf obj

fclean: clean
	@printf "$(LIGHT_CYAN)$(BOLD)fclean$(RESET) [$(LIGHT_GREEN)$(NAME)$(RESET)] : "
	/bin/rm -rf $(NAME) $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re

################################################################################
