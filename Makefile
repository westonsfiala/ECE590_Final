#Compilers
CC          := g++ -std=c++14 -Wno-psabi
DGEN        := doxygen

# Target
TARGET      := ECE590_Final

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := ./src
INCDIR      := ./include 
ELMAINCLUDE := ./elma/include
BUILDDIR    := ./build
TARGETDIR   := ./bin
SRCEXT      := cc

LIBDIR		:= -L./elma/lib
ELMALIB		:= ./elma/lib/libelma.a

#Flags, Libraries and Includes
CFLAGS      := -fsanitize=address -ggdb
LIB         := -lgtest -lpthread -lasan -lelma -lssl -lcrypto
INC         := -I$(INCDIR) -I$(ELMAINCLUDE)

#Files
DGENCONFIG  := docs.config
HEADERS     := $(wildcard $(INCDIR)/*.h) $(wildcard $(ELMAINCLUDE)/*.h)
SOURCES     := $(wildcard $(SRCDIR)/*.cc)
OBJECTS     := $(patsubst %.cc, $(BUILDDIR)/%.o, $(notdir $(SOURCES)))

#Default Make
all: directories elmas $(TARGETDIR)/$(TARGET) tests 
	echo $(SOURCES) $(HEADERS)

#Remake
remake: cleaner all

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

elmas:
	cd elma && $(MAKE)

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
	cd elma && $(MAKE) clean

#Full Clean, Objects and Binaries
spotless: clean
	@$(RM) -rf $(TARGETDIR)/$(TARGET) *.db
	@$(RM) -rf build lib docs/*
	cd test && $(MAKE) spotless
	cd elma && $(MAKE) spotless

#Link
$(TARGETDIR)/$(TARGET): $(OBJECTS) $(HEADERS)
	ar rvs $@ $(OBJECTS)
	
#Compile
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c -fPIC -o $@ $<

