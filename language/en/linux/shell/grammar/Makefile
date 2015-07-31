# make file to create/update grammars
NAME=shell

all: $(NAME).dict

$(NAME).dict: $(NAME).vox $(NAME).grammar
	julia $(COMPILE_GRAMMAR) $(NAME) $(MKFA_DIR) $(VOXFORGE_DICT)

clean:
	rm -f *.dict *.dfa *.term *.tmp

