#include <iostream>
using namespace std;
class Heap{
    public:
        Heap(){
            array = new int[100];
        }
        Heap(int* tempArray, int tempSize){
            array = tempArray;
            size = tempSize;
        }

        int left(int i){
            return (2*i)+1; //Mettiamo +1 perché gli array partono da 0
        }

        int right(int i){
            return (2*i)+2;
        }

        int parent(int i){
            return (i-1)/2;
        }

        void max_heapify(int i){
            int l = left(i);
            int r = right(i);
            int max = i;

            if(l < size && array[l] > array[max]) max = l;
            if(r < size && array[r] > array[max]) max = r;

            if(max != i){
                int scambio = array[i];
                array[i] = array[max];
                array[max] = scambio;
                max_heapify(max);
            }
        }

        void buildMaxHeap(){
            for(int i = size/2-1; i >= 0; i--){
                max_heapify(i);
            }
        }

        void insert(int k){
            array[size++] = k;

            int i = size - 1;
            int p = parent(i);

            //Questa insert mantiene una struttura max-heap, per min-heap modificare questa condizione in: array[p]>array[i]
            while(i>0 && array[p]<array[i]){
                int scambio = array[i];
                array[i] = array[p];
                array[p] = scambio;

                i = p;
                p = parent(i);
            }
        }

        int extractMax(){
            int max = array[0];

            int scambio = array[0];
            array[0] = array[size-1];
            array[size-1] = scambio;

            size--;
            max_heapify(0);

            return max;
        }

        void printHeap(){
            cout << "\n\n";
            for(int i = 0; i < size; i++){
                cout << array[i] << "\t";
            }
        }

        void HeapSort(){
            buildMaxHeap();
            int len = size;
            for(int i = len-1; i > 2; i--){

                int scambio = array[i];
                array[i] = array[0];
                array[0] = scambio;

                size--;
                max_heapify(0);
            }

            size = len; //Nell'implementazione fatta serve per stampare il lo heap
        }
    private:
        int* array;
        int size = 0;
};



int main(){
    int array[10] = {4,52,1,26,7,3,9,1,66,21};


    Heap heap(array,10);
    heap.HeapSort();
    heap.printHeap();
    // Heap heap;
    // cout << "\n\n\n";
    // heap.insert(5);
    // heap.insert(1);
    // heap.insert(6);
    // heap.insert(9);
    // heap.printHeap();

    // cout << "\n\n" << heap.extractMax() << endl;

    // heap.printHeap();

    cout << "\n\n\n";
}