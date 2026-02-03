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

# LIB ist die Make-Variable für die statische Library libmylib.a

LIB = libmylib.a

# LIB_OBJS ist die Make-Variable für die Objektdatei der Addierfunktion, die in der Library enthalten ist.

LIB_OBJS = add.o

# MAIN_OBJS ist die Make-Variable für die Objektdatei des Hauptprogramm, also der main-Funktion.

MAIN_OBJS = main.o

# HDRS ist die Make-Variable für die Header-Datei der Addierfunktion 
#
HDRS = add.h

#---------------------------------------------
# Standardziel
#---------------------------------------------

# all ist das Standardziel der Makefile
# Wenn 'make' ohne Parameter aufgerufen wird, wird ${TARGET}, hier also main, gebaut.

all: $(TARGET)

#---------------------------------------------
# Statische Library erzeugen
#---------------------------------------------

# Die Library libmylib.a (repräsentiert durch ${LIB}) wird aus der Objektdatei der Addierfunktion add.o (repräsentiert durch
# ${LIB_OBJS}) erzeugt.
# Der Befehl $(AR) $(ARFLAGS) $@ $^ bewirkt dabei Folgendes:
	# Ruft das Archivierungswerkzeug 'ar' (Variable ${AR}) mit den Optionen 'rcs' und erzeugt (ar-Option 'c') damit die Zieldatei
	# 'libmylib.a' (hier repräsentiert durch die Automatikvariable $@) durch Hinzufügen (ar-Option 'r') der Abhängigkeit 'add.o' 
	# (hier repräsentiert durch die Automatikvariable $^).
	# Zusätzlich wird über die ar-Option 's' der Symbolindex für den Linker erzeugt.

$(LIB): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $^

#---------------------------------------------
# Executable Linken
#---------------------------------------------

# Das Executable 'main' (${TARGET}) wird aus main.o (${MAIN_OBJS}) und der statischen Library (${LIB}) gebaut.
# Der Befehl '$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJS) -L. -lmylib' bewirkt dabei Folgendes:
	# Der C++-Compiler ($(CXX)) wird als Linker verwendet, um das Executable $@ (mit dem Namen des $(TARGETS) = main) zu erzeugen,
	# indem die Objektdatei $(MAIN_OBJS) (main.o) mit der statischen Library $(LIB) (libmylib.a) über -lmylib verknüpft wird. 
	# Dabei wird durch -L. das aktuelle Verzeichnis als Library-Suchpfad verwendet.

$(TARGET): $(MAIN_OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJS) -L. -lmylib

#---------------------------------------------
# Objektdateien kompilieren
#---------------------------------------------

# main.o wird aus main.cpp erzeugt
# Abhängig von $(HDRS) (add.h), damit bei Änderungen am Header neu kompiliert wird.
# Der Befehl $(CXX) $(CXXFLAGS) -c $^ bewirkt dabei Foglendes:
	# Der C++-Compiler kompiliert (-c) die Quelldatei main.cpp. Dabei wird die in der Quelldatei eingebundene Header-Datei (add.h)
	# berücksichtigt ($^ beinhaltet main.cpp und add.h, der Compiler kompiliert jedoch nur main.cpp und ignoriert die add.h,
	# add.h ist eine Build-Abhängigkeit, keine eigenständige Compile-Einheit).
	# Als Ergebnis entsteht die Objektdatei main.o 

$(MAIN_OBJS): main.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $^

# add.o wird aus add.cpp nach gleichem Muster wie zuvor main.o erzeugt.

$(LIB_OBJS): add.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $^

#---------------------------------------------
# Aufräumen
#---------------------------------------------

# 'clean' entfernt alle erzeugten Dateien
# rm ist der Unix-Befehl zum löschen von Dateien
# -f (force) erzwingt das Löschen der Dateien ohne Rückfrage von rm

clean:
	rm -f $(TARGET) $(LIB_OBJS) $(MAIN_OBJS) $(LIB)

#---------------------------------------------
# Phony Targets
# #-------------------------------------------

.PHONY: all clean
