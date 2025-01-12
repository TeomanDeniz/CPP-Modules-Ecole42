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

# **************************** [v] VARIABLES [v] ***************************** #
	# [COMPILER]
		CC			=	c++
	# [COMPILER]
	# [EXE]
		MAIN_EXE	=	"mutantStack"
		MAIN		=	./main.cpp
	# [EXE]
	# [COMPILER FLAGS]
		CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98
	# [COMPILER FLAGS]
# **************************** [^] VARIABLES [^] ***************************** #

# ****************************** [v] COLORS [v] ****************************** #
	C_RESET	=	$(shell tput sgr0)
	C_BLINK	=	$(shell tput blink)
	B1F11	=	$(shell tput setab 1)$(shell tput setaf 11)
	B12F15	=	$(shell tput setab 12)$(shell tput setaf 15)
	B2F15	=	$(shell tput setab 2)$(shell tput setaf 15)
# ****************************** [^] COLORS [^] ****************************** #

all: $(MAIN_EXE)

$(MAIN_EXE):
	@$(CC) $(CPPFLAGS) $(MAIN) -o "./$(MAIN_EXE)" && \
		echo "\n\n $(C_BLINK)$(B2F15) $(MAIN_EXE) is ready! $(C_RESET)\n"

fc: fclean
fclean:
	@rm $(MAIN_EXE) 2>/dev/null && \
		echo "\n $(B1F11) $(MAIN_EXE) $(F15)deleted! $(C_RESET)\n" || \
		echo "\n $(B12F15) $(MAIN_EXE) is not exist already! $(C_RESET)\n"

re: fc all

.PHONY: all fclean fc