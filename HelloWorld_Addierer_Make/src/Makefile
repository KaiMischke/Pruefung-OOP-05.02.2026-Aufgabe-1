# CXX definiert den verwendeten C++-Compiler
CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

#--------------------------------------------
# Werkzeuge für statische Libraries
# -------------------------------------------

# AR ist das Werkzeug/Werkzeugkasten zum Erzeugen und verwalten statischer Libraries (.a).
# Die Library entsteht durch die Kombination der Archivoptionen (ARFLAGS).
AR = ar

# r = Objektdateien hinzufügen oder ersetzen (hier: add.o)
# c = Library neu anlegen, falls sie noch nicht existiert (hier: libmylib.a)
# s = Symbolindex/Symboltabelle für den Linker erzeugen

ARFLAGS = rcs

#--------------------------------------------
# Projektziele und Dateien
# -------------------------------------------

# Name des erzeugten Executables.
# TARGET ist eine Make-Variable mit dem Inhalt main.
# Wenn später in diesem Makefile $TARGET geschrieben wird, ersetzt Make das textuell durch main. 
# Gleiches gilt auch für die anderen festgelegten Make-Variablen.

TARGET = main
LIB = libmylib.a
LIB_OBJS = add.o
MAIN_OBJS = main.o
HDRS = add.h


all: $(TARGET)

$(LIB): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(TARGET): $(MAIN_OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJS) -L. -lmylib

$(MAIN_OBJS): main.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $^

$(LIB_OBJS): add.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm -f $(TARGET) $(LIB_OBJS) $(MAIN_OBJS) $(LIB)

.PHONY: all clean
