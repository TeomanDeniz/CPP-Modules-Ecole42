# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 10:48:13 by hdeniz            #+#    #+#              #
#    Updated: 2025/01/08 ??:??:?? by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *************************** [v] MAIN SOURCES [v] *************************** #
MAIN_SRC	=	./Bureaucrat.cpp
# *************************** [^] MAIN SOURCES [^] *************************** #

# **************************** [v] VARIABLES [v] ***************************** #
	# [COMPILER]
		CC			=	c++
	# [COMPILER]
	# [EXE]
		MAIN_EXE	=	"bureaucrat"
		MAIN		=	./main.cpp
		MAIN_EXIST	=	$(MAIN:.cpp=.o)
	# [EXE]
	# [COMPILER FLAGS]
		CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98
	# [COMPILER FLAGS]
	# [.c STRINGS TO .o]
		MAIN_OBJ	=	$(MAIN_SRC:.cpp=.o)
	# [.c STRINGS TO .o]
# **************************** [^] VARIABLES [^] ***************************** #

# ****************************** [v] COLORS [v] ****************************** #
	C_RESET	=	$(shell tput sgr0)
	C_BLINK	=	$(shell tput blink)
	B1F11	=	$(shell tput setab 1)$(shell tput setaf 11)
	B12F15	=	$(shell tput setab 12)$(shell tput setaf 15)
	B1F15	=	$(shell tput setab 1)$(shell tput setaf 15)
	B2F15	=	$(shell tput setab 2)$(shell tput setaf 15)
# ****************************** [^] COLORS [^] ****************************** #

%.o: %.cpp
	@rm -f $(MAIN_EXIST) 2>/dev/null
	@$(CC) $(CPPFLAGS) -c $< -o $@

all: $(MAIN_EXIST)

$(MAIN_EXIST): $(MAIN_SRC) $(MAIN)
	@$(CC) -c $(MAIN) -o $(MAIN_EXIST)
	@$(CC) $(CPPFLAGS) $(MAIN) $(MAIN_SRC) -o "./$(MAIN_EXE)" && \
		echo "\n\n $(C_BLINK)$(B2F15) $(MAIN_EXE) is ready! $(C_RESET)\n"

c: clean
clear: clean
clean:
	@rm $(MAIN_OBJ) 2>/dev/null && \
		echo "\n $(B1F15) Objects are cleared! $(C_RESET)\n" || \
		echo "\n $(B12F15) Nothing to clear! $(C_RESET)\n"

fc: fclean
fclean: clean
	@rm -f $(MAIN_EXIST) 2>/dev/null
	@rm $(MAIN_EXE) 2>/dev/null && \
		echo "\n $(B1F11) $(MAIN_EXE) $(F15)deleted! $(C_RESET)\n" || \
		echo "\n $(B12F15) $(MAIN_EXE) is not exist already! $(C_RESET)\n"

re: fc all

.PHONY: all fclean fc clean clear c
