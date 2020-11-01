TARGET = qn
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall
INSTALL_DIR = /usr/local/bin
USER_DATA_DIR = .qn

.PHONY:	clean	all	default

default:	$(TARGET)
all:	default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS:	$(TARGET) $(OBJECTS)

$(TARGET):	$(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@
	mkdir -p -m 0755 $${HOME}/$(USER_DATA_DIR)

clean:
	-rm -f *.o
	-rm -f $(TARGET)

install:
	cp qn $(INSTALL_DIR)
	chmod 755 qnl
	cp qnl $(INSTALL_DIR)