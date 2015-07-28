# !!!!!!
#LIBSENT=../libsent
#LIBJULIUS=../libjulius
LIBSENT=libsent
LIBJULIUS=libjulius
# !!!!!!!
CC=gcc
CFLAGS=-g -O2 

####
#### When using system-installed libraries
####
# CPPFLAGS=`libjulius-config --cflags` `libsent-config --cflags`
# LDFLAGS=`libjulius-config --libs` `libsent-config --libs`

####
#### When using within-package libraries
####
CPPFLAGS=-I$(LIBJULIUS)/include -I$(LIBSENT)/include  `$(LIBSENT)/libsent-config --cflags` `$(LIBJULIUS)/libjulius-config --cflags`
LDFLAGS= -L$(LIBJULIUS) `$(LIBJULIUS)/libjulius-config --libs` -L$(LIBSENT) `$(LIBSENT)/libsent-config --libs`

############################################################

all: julius-simple

julius-simple: julius-simple.c
# !!!!!!
	#$(CC) $(CFLAGS) $(CPPFLAGS) -o julius-simple julius-simple.c $(LDFLAGS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -m32 -o julius-simple julius-simple.c $(LDFLAGS)
	#$(CC) $(CFLAGS) $(CPPFLAGS) -m32 -o bob julius-simple.c $(LDFLAGS)
# !!!!!!
clean:
	$(RM) *.o *.bak *~ core TAGS

distclean:
	$(RM) *.o *.bak *~ core TAGS
	$(RM) julius-simple
