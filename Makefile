# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weilin <weilin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2020/03/10 20:34:34 by weilin           ###   ########.fr        #
=======
#    Updated: 2020/03/10 18:23:30 by weilin           ###   ########.fr        #
>>>>>>> 55c943122b8d2072c3fa2f414c7f3460416d09a6
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

<<<<<<< HEAD
CHECK_FILES = checker ft_check_args tool_array push swap rotate tool_mem
PSH_SWP_FILES = push_swap ft_check_args push tool_print swap rotate tool_array\
				 tool_mem
=======
CHECK_FILES = checker ft_check_args array_tool push swap rotate
PSH_SWP_FILES = push_swap ft_check_args push tool_print swap rotate math \
	array_tool
>>>>>>> 55c943122b8d2072c3fa2f414c7f3460416d09a6

CCH_DIR = cache/
SRC_DIR = src/
INC_DIR = include/
LIB_DIR = libft/
LIBFT = $(LIB_DIR)libft.a

CC = gcc
FLAG = -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LIB_DIR)
RM = rm -rf

CHECK_SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(CHECK_FILES)))
CHECK_OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(CHECK_FILES)))
PSH_SWP_SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(PSH_SWP_FILES)))
PSH_SWP_OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(PSH_SWP_FILES)))

all: $(CHECKER) $(PUSH_SWAP)
# all: $(PUSH_SWAP)

$(CHECKER): $(LIBFT) $(CHECK_OBJ)
	@$(CC) $(FLAGS) -o $@ $(CHECK_OBJ) -L $(LIB_DIR) -lft

$(PUSH_SWAP): $(LIBFT) $(PSH_SWP_OBJ)
	@$(CC) $(FLAGS) -o $@ $(PSH_SWP_OBJ) -L $(LIB_DIR) -lft

$(LIBFT):
	make -C libft all
#it will call the makefile in the destination

$(CCH_DIR)%.o: $(SRC_DIR)%.c | $(CCH_DIR)
	$(CC) $(FLAG) -c $< -o $@

$(CCH_DIR):
	mkdir $@

clean:
	$(RM) $(CCH_DIR)
	$(RM) *.o
	$(RM) *.out*
	make -C libft clean
	
fclean: clean
	$(RM) $(CHECKER)
	$(RM) $(PUSH_SWAP)
	make -C libft fclean

re: fclean
	$(MAKE) all

norm:
	norminette $(SRC) $(INC_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm