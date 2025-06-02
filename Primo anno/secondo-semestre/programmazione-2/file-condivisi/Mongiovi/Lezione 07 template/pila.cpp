// implementazione delle funzioni per la classe Pila 

template <typename T> 
Pila<T>::Pila() : top(0)
{
}

template <typename T>
void Pila<T>::Push(T elem)
{
    array[top] = elem;
    top++;
}

template <typename T>
T Pila<T>::Pop()
{
    top--;
    return array[top];
}
