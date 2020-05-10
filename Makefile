# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weilin <weilin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/05/10 02:19:18 by weilin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

CHECK_FILES = checker ft_check_args op_push op_swap op_rotate op_rotate2 \
				tool_array tool_mem tool_sort
PSH_SWP_FILES = push_swap ft_check_args op_push op_swap op_rotate op_rotate2 \
				pw pw2 tool_array tool_mem tool_sort

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

$(PUSH_SWAP): $(LIBFT) $(PSH_SWP_OBJ) $(INC_DIR)/push_swap.h
	@$(CC) $(FLAGS) -o $@ $(PSH_SWP_OBJ) -L $(LIB_DIR) -lft 

$(LIBFT):
	make -C libft all
#it will call the makefile in the destination

$(CCH_DIR)%.o: $(SRC_DIR)%.c  | $(CCH_DIR)
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
	# make -C libft fclean

re: fclean
	$(MAKE) all

norm:
	norminette $(SRC) $(INC_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm