##############
# Directories
##############
BINDIR = bin
BUILDDIR = build
SRCDIR = src
OBJDIR = obj


###################
# Compiler options
###################
# Program name
PROGRAM = $(BINDIR)/cpc.exe

# C compiler
CC = mingw32-gcc

# C compiler flags
CFLAGS = -g -pedantic -std=c11 -Wall


########
# Files
########
# C files
CFILES = $(SRCDIR)/*.c

# Object files
OBJFILES = $(OBJDIR)/*.o


.PHONY: build-debug clean-all clean-build-files debug


############################
# Build and compile program
############################
debug : $(PROGRAM)
$(PROGRAM) : $(OBJFILES)
	$(CC) -o $(PROGRAM) $(OBJFILES)

$(OBJFILES) : $(CFILES)
	$(CC) -c $(CFILES) $(CFLAGS)

# Create obj directory.
	@mkdir -p obj;

# Move any '*.o' file(s) to 'obj' directory.
	@mv *.o obj;


# Create build directory
build-dir :
	@mkdir -p $(BUILDDIR)/CPC/bin; cp -p bin/cpc.exe $(BUILDDIR)/CPC/bin;
	@cp -p doc.txt $(BUILDDIR)/CPC; cp -p GPLv2.txt $(BUILDDIR)/CPC;
	@cp -p LICENSE $(BUILDDIR)/CPC


##########################
# Clean working directory
##########################
clean-build-files :
	rm -f $(PROGRAM) $(OBJFILES)

clean-all :
	rm -f $(PROGRAM)
	rm -r $(BUILDDIR) $(OBJDIR)


###############################
# Build debug build for release
###############################
build-debug : debug build-dir


