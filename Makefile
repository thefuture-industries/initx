TARGET=initx

GCC=gcc
CFLAGS= -Wall -Wextra -O2

OBJDIR=.out
BINDIR=.app

SRCS=initx.c
OBJS=$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

initx:
	$(BINDIR)/$(TARGET)
	
clean:
	rm -rf $(OBJDIR) $(BINDIR)