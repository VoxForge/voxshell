CC=gcc
CFLAGS=$(CFLAGS_MOD) -g -O2 -Wall

# older than Julius r4.3.1
CPPFLAGS=-I../include
LDFLAGS=$(LDFLAGS_MOD) -ljulius -ldl -lpthread -lsent -lasound -lm

# Julius r4.3.1 or later 
#CPPFLAGS=-I/usr/include
#LDFLAGS=-L/usr/lib64 -ljulius -ldl -lpthread -lsent -lasound -lm -lpulse-simple -lz

############################################################
TARGET=voxshell

all: $(TARGET)

voxshell: voxshell.c
# older than Julius r4.3.1
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) voxshell.c $(LDFLAGS) 
# Julius r4.3.1 or later (make sure you keep the tab at beginning of this line)
#	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) voxshell.c $(LDFLAGS) 

install: $(TARGET)
	${INSTALL} $(TARGET) $(VOXSHELL)/bin

clean:
	$(RM) *.o *.bak *~ 
	$(RM) voxshell

