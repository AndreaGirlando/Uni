Fino ad adesso abbiamo usato i seguenti stream:
 - **ostream**: che rappresenta uno stream di output, ad esempio **cout** è una classe di tipo ofstream, di seguito un'esempio di come viene utilizzata nell'overloading di un'operatore
```cpp
ostream& operator<<(ostream& stream,Book& book){
	stream << "Titolo: " << book.getTitolo();
	stream << " Autore: " << book.getAutore();
	stream << " Anno: " << book.getAnno();
	stream << " Next: " << book.getNext() << "\n\n";
	return stream;//ritorno del stream per la concatenazione "cout << libro1 << libro2 ecc..."
}
```
 - **ifstream**: è una classe che viene usata per leggere da un file, di seguito un esempio di come viene usata, anche in questo caso si usa l'operatore di shifting:
```cpp
        void caricaDaArchivio(string nomeFile){
            ifstream file(nomeFile, ios::in);
            if(file.fail()){
                cout << "Errore nell'apertura del file";
                return;
            }
            int len = 0;
            file >> len;//leggo il primo valore e lo salvo in len
            string titolo,autore;
            int anno;
            for (int i = 0;i<len;i++){
                file >> titolo;//leggo e salvo il titolo
                file >> autore;//leggo e salvo l'autore
                file >> anno;//leggo e salvo  l'anno
                this->addBook(new Book(titolo,autore,anno));
            }
        }
```
 - **ofstream**: è una classe usata per scrivere su file, di seguito un esempio di come viene usata, anche qui si usa l'operatore di shifting:
```cpp
   void scriviSuArchivio(string nomeFile){
            ofstream file(nomeFile, ios::out);
            if(file.fail()){
                cout << "Errore nell'apertura del file";
                return;
            }
            Book* tempHead = head;
            file << this->getLen() << endl;
            while(tempHead != nullptr){
                file << tempHead->getTitolo() << endl;
                file << tempHead->getAutore() << endl;
                file << tempHead->getAnno() << endl;
                tempHead = tempHead->getNext();
            }
            file.close();
            return;
        }
```

In questo [[Primo anno/secondo-semestre/programmazione-2/C++/stream/main.cpp|file]] vengono usati tutti è tre.