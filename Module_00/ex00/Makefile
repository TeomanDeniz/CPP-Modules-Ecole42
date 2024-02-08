# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 10:48:13 by hdeniz            #+#    #+#              #
#    Updated: 2024/10/26 16:31:01 by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************** [v] VARIABLES [v] ***************************** #
	# [COMPILER]
		CC			=	g++
	# [COMPILER]
	# [EXE]
		MAIN_EXE	=	"megaphone"
		MAIN		=	./megaphone.cpp
		MAIN_EXIST	=	$(eval MAIN_EXIST := $$(MAIN:.cpp=.o))$(MAIN_EXIST)
	# [EXE]
	# [COMPILER FLAGS]
		CFLAGS		=	-Wall -Wextra -Werror -std=c++98
	# [COMPILER FLAGS]
# **************************** [^] VARIABLES [^] ***************************** #

# ****************************** [v] COLORS [v] ****************************** #
	C_RESET	=	$(shell tput sgr0)
	C_BLINK	=	$(shell tput blink)
	B1F11	=	$(shell tput setab 1)$(shell tput setaf 11)
	B12F15	=	$(shell tput setab 12)$(shell tput setaf 15)
	B2F15	=	$(shell tput setab 2)$(shell tput setaf 15)
# ****************************** [^] COLORS [^] ****************************** #

all: $(MAIN_EXIST)

$(MAIN_EXIST):
	@$(CC) -c $(MAIN) -o $(MAIN_EXIST)
	@$(CC) $(CFLAGS) $(MAIN) -o "./$(MAIN_EXE)" && \
		echo "\n\n $(C_BLINK)$(B2F15) $(MAIN_EXE) is ready! $(C_RESET)\n"

c: fclean
clear: fclean
clean: fclean

fc: fclean
fclean:
	@rm $(MAIN_EXIST) 2>/dev/null
	@rm $(MAIN_EXE) 2>/dev/null && \
		echo "\n $(B1F11) $(MAIN_EXE) $(F15)deleted! $(C_RESET)\n" || \
		echo "\n $(B12F15) $(MAIN_EXE) is not exist already! $(C_RESET)\n"

re: fc all

.PHONY: all fclean fc clean clear c