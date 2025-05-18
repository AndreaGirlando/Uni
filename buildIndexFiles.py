import os

def crea_struttura_gerarchica(cartella_base):
    struttura = {}

    for radice, _, files in os.walk(cartella_base):
        for file in files:
            if file.lower().endswith(".pdf"):
                percorso_relativo = os.path.relpath(os.path.join(radice, file), cartella_base).replace("\\", "/")
                parti = percorso_relativo.split("/")
                inserisci_nella_struttura(struttura, parti)

    return struttura

def inserisci_nella_struttura(dic, path_parts):
    if len(path_parts) == 1:
        dic.setdefault("__files__", []).append(path_parts[0])
    else:
        cartella = path_parts[0]
        dic.setdefault(cartella, {})
        inserisci_nella_struttura(dic[cartella], path_parts[1:])

def genera_markdown_gerarchico(dic, indentazione=0, etichetta="Root"):
    righe = []
    spazio = "  " * indentazione
    righe.append(f"{spazio}- 📁 {etichetta}:")

    # File nella cartella corrente
    for file in sorted(dic.get("__files__", [])):
        nome_visibile = os.path.splitext(file)[0]
        righe.append(f"{spazio}  - 📄 [[{file}|{nome_visibile}]]")

    # Sottocartelle
    for chiave in sorted(k for k in dic.keys() if k != "__files__"):
        righe.extend(genera_markdown_gerarchico(dic[chiave], indentazione + 1, chiave))

    return righe

def genera_lista_obsidian_nidata(cartella_base, nome_output="indice.md"):
    struttura = crea_struttura_gerarchica(cartella_base)
    righe = genera_markdown_gerarchico(struttura, 0, "Root")

    output_path = os.path.join(cartella_base, nome_output)
    with open(output_path, "w", encoding="utf-8") as f:
        f.write("\n".join(righe))

    print(f"✅ File Obsidian generato: {output_path}")

# Esegui la funzione
genera_lista_obsidian_nidata(r"algebra-lineare-e-geometria[20]")
genera_lista_obsidian_nidata(r"architettura-degli-elaboratori[30L]")
genera_lista_obsidian_nidata(r"programmazione-1[30L]")
genera_lista_obsidian_nidata(r"strutture-discrete[27]")
