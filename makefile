# Directories
BINDIR = bin
SRCDIR = src
OBJDIR = obj


# Program name
PROGRAM = $(BINDIR)/cpc.exe

# C compiler
CC = mingw32-gcc

# C compiler flags
CFLAGS = -g -pedantic -std=c11 -Wall


# C files
CFILES = $(SRCDIR)/*.c

# Object files
OBJFILES = $(OBJDIR)/*.o


# Build and compile program
$(PROGRAM) : $(OBJFILES)
	$(CC) -o $(PROGRAM) $(OBJFILES)

$(OBJDIR)/*.o : $(CFILES)
	$(CC) -c $(CFILES) $(CFLAGS)

# Move any '*.o' file(s) to 'obj' directory.
	@mv *.o obj


# Clean working directory
.PHONY: clean
clean :
	rm -f $(PROGRAM) $(OBJFILES)


