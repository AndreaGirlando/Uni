mkdir -p notebook_md
find . -type f \( -name "*.c" -o -name "*.h" \) ! -path "./notebook_md/*" | while read -r file; do
    # Pulisce il percorso rimuovendo il "./" iniziale
    clean_path=$(echo "$file" | sed 's|^\./||')
    # Sostituisce i caratteri "/" con "_" per creare un nome di file piatto e univoco
    md_filename=$(echo "$clean_path" | sed 's|/|_|g').md
    
    # Genera il file markdown nella cartella di output
    echo "# File: $clean_path" > "notebook_md/$md_filename"
    echo '```c' >> "notebook_md/$md_filename"
    cat "$file" >> "notebook_md/$md_filename"
    echo '```' >> "notebook_md/$md_filename"
done
