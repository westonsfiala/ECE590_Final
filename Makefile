#Architecture
ARCH := $(shell uname -m)

#Compilers
CC          := g++ -std=c++14 -Wno-psabi
DGEN        := doxygen

# Target
TARGET      := ECE590_Final

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := ./src
INCDIR      := ./include 
BUILDDIR    := ./build
TARGETDIR   := ./bin
SRCEXT      := cc

#Asan library
ifeq ($(ARCH),armv7l)
	ASAN := -static-libasan
else
	ASAN := -lasan
endif

#Flags, Libraries and Includes
CFLAGS      := -fsanitize=address -ggdb
LIB         := -L../lib -lgtest -lpthread $(ASAN) -lelma -lssl -lcrypto -lcurses
INC         := -I$(INCDIR)

#Files
DGENCONFIG  := docs.config
HEADERS     := $(wildcard $(INCDIR)/*.h)
SOURCES     := $(wildcard $(SRCDIR)/*.cc)
OBJECTS     := $(patsubst %.cc, $(BUILDDIR)/%.o, $(notdir $(SOURCES)))

#Default Make
all: directories $(TARGETDIR)/$(TARGET) tests

#Remake
remake: spotless all

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

tests:
	cd test && $(MAKE)

docs: docs/index.html

docs/index.html: $(SOURCES) $(HEADERS) README.md docs.config dox/* examples/*.cc
	$(DGEN) $(DGENCONFIG)
	cp .nojekyll docs

#Clean only Objects
clean:
	@$(RM) -rf $(BUILDDIR)/*.o
	cd test && $(MAKE) clean

#Full Clean, Objects and Binaries
spotless: clean
	@$(RM) -rf $(TARGETDIR)/$(TARGET) *.db
	@$(RM) -rf build lib docs/*
	cd test && $(MAKE) spotless

#Link
$(TARGETDIR)/$(TARGET): $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGETDIR)/$(TARGET) $(OBJECTS) $(LIB)
	
#Compile
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

