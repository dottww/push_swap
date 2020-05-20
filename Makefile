# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weilin <weilin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/05/20 20:29:51 by weilin           ###   ########.fr        #
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
INC_DIR = inc/
LINC_DIR = libft/inc/
LIB_DIR = libft/
LIBFT = $(LIB_DIR)libft.a

INCS += $(INC_DIR)push_swap.h 
INCS += $(LINC_DIR)libft.h 
INCS += $(LINC_DIR)ft_printf.h 

CC = clang
FLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LINC_DIR)
RM = rm -rf

CHECK_SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(CHECK_FILES)))
CHECK_OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(CHECK_FILES)))
PSH_SWP_SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(PSH_SWP_FILES)))
PSH_SWP_OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(PSH_SWP_FILES)))

#OBJS = $(patsubst src/%.c, $(CCH_DIR)%.o, $(wildcard src/*))

vpath  %.h inc/
vpath  %.h libft/inc/

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(LIBFT) $(CCH_DIR) $(CHECK_OBJ) $(INCS)
	$(CC) $(FLAGS) -o $@ $< $(CHECK_OBJ) -L $(LIB_DIR) -lft

$(PUSH_SWAP): $(LIBFT) $(CCH_DIR) $(PSH_SWP_OBJ) $(INCS)
	$(CC) $(FLAGS) -o $@ $< $(PSH_SWP_OBJ) -L $(LIB_DIR) -lft

$(LIBFT): force
	@make -C libft all
#it will call the makefile in the destination

force:
	@true

$(CCH_DIR)%.o: $(SRC_DIR)%.c $(INCS)| $(CCH_DIR)
	$(CC) $(FLAGS) -c $< -o $@

#$(CCH_DIR)%.o: $(INCS)

$(CCH_DIR):
	mkdir $@

clean:
	$(RM) $(CCH_DIR)
	$(RM) $(CHECKER).dSYM
	$(RM) $(PUSH_SWAP).dSYM
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
	norminette $(SRC_DIR) $(INC_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
