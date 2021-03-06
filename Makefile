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
NON_MAIN_OBJECTS := $(filter-out ./build/main.o,$(OBJECTS))

#Default Make
all: directories $(TARGETDIR)/$(TARGET) bin/test

#Remake
remake: spotless all

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

docs: docs/index.html

docs/index.html: $(SOURCES) $(HEADERS) README.md docs.config 
	$(DGEN) $(DGENCONFIG)
	cp .nojekyll docs

#Clean only Objects
clean:
	@$(RM) -rf $(BUILDDIR)/*.o

#Full Clean, Objects and Binaries
spotless: clean
	@$(RM) -rf $(TARGETDIR)/$(TARGET) *.db
	@$(RM) -rf build lib docs/*
	

#Unit Tester
bin/test: $(NON_MAIN_OBJECTS) $(HEADERS) ./src/unit_test.cc ./src/test_main.cpp
	$(CC) $(CFLAGS) $(INC) -c -o build/test_main.o ./src/test_main.cpp
	$(CC) $(CFLAGS) -o bin/test build/test_main.o $(NON_MAIN_OBJECTS) $(LIB)

#Link
$(TARGETDIR)/$(TARGET): $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGETDIR)/$(TARGET) $(OBJECTS) $(LIB)

#Compile
$(BUILDDIR)/%.o: $(SRCDIR)/%.cc $(HEADERS)/%.h 
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

.PHONY: directories remake clean cleaner apidocs $(BUILDDIR) $(TARGETDIR)