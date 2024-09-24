#!/bin/bash

# Pfad zum Verzeichnis, dessen Dateien ausgedruckt werden sollen
directory="./"

# Ausgabe-Datei
output_file="out.txt"

# Leere die Ausgabedatei, falls sie bereits existiert
> "$output_file"

# Funktion zum rekursiven Durchsuchen des Verzeichnisses
process_directory() {
    local dir="$1"
    for item in "$dir"/*; do
        # Überprüfe, ob das aktuelle Verzeichnis 'libft' ist
        if [[ "$(basename "$item")" == "libft" ]]; then
            continue  # Überspringe das 'libft' Verzeichnis
        fi

        if [ -f "$item" ] && [[ "$item" == *.c ]]; then
            # Dateiinhalt ab Zeile 12 in die Ausgabedatei schreiben
            tail -n +12 "$item" >> "$output_file"
            # Eine Leerzeile nach jeder Datei hinzufügen
            echo "" >> "$output_file"
        elif [ -d "$item" ]; then
            # Rekursiv in Unterverzeichnisse gehen
            process_directory "$item"
        fi
    done
}

# Starte die rekursive Verarbeitung
process_directory "$directory"
