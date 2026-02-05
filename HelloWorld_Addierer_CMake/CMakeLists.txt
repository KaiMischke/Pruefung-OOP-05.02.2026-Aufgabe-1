# 1) Legt fest, welche cmake-Version mindestens benötigt wird, um das Projekt zu konfigurieren

cmake_minimum_required(VERSION 3.10)

# 2) Definiert das Projekt, setzt den Projektnamen auf HelloWorld_Addierer (interne Variable $(PROJECT_NAME)), legt die Sprache auf C++ fest

project (HelloWorld_Addierer LANGUAGES CXX)

# 3) Legt den erforderlichen c++-Standard fest, REQUIRED ON verhindert, dass cmake auf einen anderen Standard ausweicht, sondern stattdessen abbricht.

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4) Statische Library erzeugen und include-Pfad für Header festlegen
#`add_library` erzeugt eine statische Bibliothek namens ´mylib´ in der add.cpp landet.
# `target_include_directories` legt fest, wo der Compiler Head-Dateien suchen soll, wenn irgendwo `#include "add.h"` steht.
# `{$CMAKE_CURRENT_SOURCE_DIR}` ist das Verzeichnis, in dem diese CMakeLists.txt liegt
# PULIC bedeutet hier: Dieser Include-Pfad gilt für die Library selbst (damit add.cpp seinen Header findet) und auch für alle
# Targets, die gegen die Library linken (z. B. das Executable), damit auch main.cpp add.h findet.

add_library(mylib STATIC src/add.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 5) Executable erzeugen und gegen die Library linken
# `add_executable` Baut das ausführbare Programm mit dem Namen `HelloWorld_Addierer` aus der main.cpp 
# `target_link_libraries` linkt das executable `HelloWorld_Addierer` gegen `mylib`

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE mylib)
