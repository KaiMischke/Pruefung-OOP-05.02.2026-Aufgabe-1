# Pruefung-OOP-05.02.2026-Aufgabe-1
Erstellung eines eigenen Programms, das ein ,,Hello World!" ausgibt und über eine Addierfunktion verfügt. Für die Addierfunktion wird eine eigenen Library gebaut und in die main-Funktion gelinkt. Das Programm wird einmal mit Make (Aufgabenteil 1) und einmal mit CMake (Aufgabenteil 2) kompiliert.

# Aufgabenteil 1: HelloWorld_Addierer (Build über Makefile)

Es handelt sich um ein einfaches C++–Programm, das:

- eine **Hello-World-Ausgabe** erzeugt
- zwei Zahlen vom Benutzer einliest
- die Addition dieser Zahlen über eine **eigene Library-Funktion** durchführt

Das Programm wird in dieser Teilaufgabe vollständig mit **GNU Make** gebaut.

---

## Projektstruktur
```text
src/
├── Makefile
├── main.cpp
├── add.cpp
├── add.h
``` 
## Beschreibung der einzelnen Programmbestandteile/Programmdateien

* `main.cpp`: Enthält die `main()`-Funktion und die Benutzereingabe.
* `add.h`: Header-Datei mit der Deklaration der Addierfunktion.
* `add.cpp`: Implementierung der Addierfunktion (Teil der Library).
* `Makefile`: Beschreibt den vollständigen Build-Prozess mit GNU Make.

## Voraussetzungen:
* LINUX-System oder WSL
* GNU MAKE
* C++ Compiler (z. B. g++) mit Unterstützung für C++17

## Überprüfung der Voraussetzungen:
`g++ --version`  
`make --version`

## Kompilieren des Programms:

1. In das Projektverzeichnis wechseln:
`cd src`

2. Programm bauen:
`make`

Dabei werden automatisch von GNU make:
* die Objektdateien erzeugt
* eine statische Library gebaut
* das ausführbare Programm `main` gelinkt

3. Programm ausführen:
`./main`

Aufräumen der Build-Dateien:
`make clean`

Dieser Befehl löscht:
* das ausführbare Programm
* alle Objektdateien
* die statische Library
---
# Aufgabenteil 2: HelloWorld_Addierer (Build über CMake)

Das Programm ist identisch zu dem in Aufgabenteil 1.
In diesem Aufgabenteil 2 erfolgt der Build-Prozess jedoch mit **CMake**.
---

## Projektstruktur

```
HelloWorld_Addierer_CMake/
├─ CMakeLists.txt
├─ src/
|  └─ main.cpp
|  └─ add.cpp
|  └─ add.h
├─ build/
```

## Beschreibung der Verzeichnisse und Dateien
* `CMakeLists.txt` --> Ist die zentrale Build-Konfigurationsdatei für CMake
* `src/` --> Enthält den vollständigen Quellcode.
* `build/` --> Separates Build-Verzeichnis

## Voraussetzungen
* CMake (Version ≥ 3.10)
* C++ Compiler (z. B. g++) mit Unterstützung für C++17

## Überprüfung der Voraussetzungen
`cmake --version`
`g++ --version`

## Build-Prozess mit CMake
1) In das Projektverzeichnis wechseln

   `cd HelloWorld_Addierer_Cmake`

2) Build-Verzeichnis vorbereiten

   `cd build`
   `cmake ..`

   Dabei:
   * liest CMake die CMakeLists.txt
   * Überprüft CMake den Compiler und die Spracheinstellungen
   * erzeugt CMake ein plattformspezifisches Buildsystem (z. B. Makefiles)

3) Programm builden

   `cmake --build`.

4) Programm ausführen

   Nach erfolgreichem Build:

   `./HelloWorld_Addierer`

   (Der Name des Executables entspricht dem Projektnamen aus `project(...)`)
