// implementazione delle funzioni per la classe Pila

//! Definiamo 2 come valore default per la dimensione della pila
template <typename T> Pila<T>::Pila() : top(0) , dim(2) {
    array = new T[dim];
}
template <typename T> Pila<T>::~Pila(){ //? Distruttore per deallocare l'array
    free(array);
}

template <typename T>
int Pila<T>::Len(){
    return dim;
}
template <typename T> void Pila<T>::Push(T elem){
    if (top == dim){
        dim = top * 2; //? Raddopio la dimensione
        T *newArray = new T[dim]; //? Alloco un nuovo array con la nuova dimensione
        for(int i = 0; i<dim/2; i++){
            newArray[i] = array[i]; //? Copio ogni singolo elemento
        }
        newArray[top] = elem; //? Inserisco l'ultimo elemento
        top++;
        free(array); //? dealloco l'array
        array = newArray; //? Punto al nuovo array
    }else{
        array[top] = elem;
        top++;
    }
}

template <typename T> T Pila<T>::Pop(){
    top--;
    return array[top];
}
