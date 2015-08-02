# make file to create/update grammars

# update this path to your voxshell directory

FIREFOX_DIR=firefox
RHYTHMBOX_DIR=rhythmbox
SHELL_DIR=shell
LIBREOFFICE_DIR=libreoffice
GNOME_DIR=gnome

all: firefox_grammar rhythmbox_grammar shell_grammar libreoffice_grammar gnome_grammar

rhythmbox_grammar:
	 $(MAKE) -s -C $(RHYTHMBOX_DIR)

firefox_grammar:
	 $(MAKE) -s -C $(FIREFOX_DIR)

shell_grammar:
	 $(MAKE) -s -C $(SHELL_DIR)

libreoffice_grammar:
	 $(MAKE) -s -C $(LIBREOFFICE_DIR)

gnome_grammar:
	 $(MAKE) -s -C $(GNOME_DIR)

clean:
	$(MAKE) -s clean -C $(FIREFOX_DIR)
	$(MAKE) -s clean -C $(RHYTHMBOX_DIR)
	$(MAKE) -s clean -C $(SHELL_DIR)
	$(MAKE) -s clean -C $(LIBREOFFICE_DIR)
	$(MAKE) -s clean -C $(GNOME_DIR)

