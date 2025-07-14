//
//  Esempi di implementazione di algoritmi di ordinamento

#include <iostream>
#include <memory.h>
using namespace std;


void print(int array[],size_t n);

void insertionSort(int array[], size_t n);
void selectionSort(int v[], size_t n);
void mergeSort(int v[], size_t n);
void mergeSort(int v[], size_t p, size_t r);
void quickSort(int v[], size_t n);
void quickSort(int v[], size_t p, size_t r);

int main()
{
    int array[] = {10,32,11,34,15};
    size_t n = sizeof(array)/sizeof(array[0]);

    cout << "Array iniziale: "; print(array,n);
    //insertionSort(array,n);
    //selectionSort(array,n);
    //mergeSort(array, n);
    quickSort(array,n);
    cout << "Array finale: "; print(array,n);

    return 0;
}

void print(int array[],size_t n)
{
    for(size_t i=0; i<n; i++)
        cout << array[i] << " ";
    cout << endl;
}

void scambia (int& a, int& b)
{
    int appoggio = a;
    a = b;
    b = appoggio;
}

void insertionSort(int array[], size_t n)
{
    for (size_t i=1; i<n; i++)
    {
        int appoggio = array[i];
        size_t j = i-1;
        while ((array[j] > appoggio) && (j >= 0))
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = appoggio;
    }
}

void selectionSort(int v[], size_t n)
{
    for(int i=0; i<n-1; i++)
    {
        size_t posminimo = i;
        for(int j=i+1; j<n; j++)
        {
            if (v[j] < v[posminimo])
                posminimo = j;
        }
        scambia(v[i], v[posminimo]);
    }
}

void mergeSort(int v[], size_t n)
{
    mergeSort(v, 0, n-1);
}

void merge(int v[], size_t p, size_t q, size_t r)
{
    size_t n = r-p+1;
    int* v2 = new int[n];

    size_t i = p;
    size_t j = q + 1;
    size_t k = 0;
    while ((k < n) && (i <= q) && (j <= r))
    {
        if (v[i]<v[j])
        {
            v2[k] = v[i];
            i++;
        }
        else
        {
            v2[k] = v[j];
            j++;
        }
        k++;
    }
    while(i <= q)
    {
        v2[k] = v[i];
        i++;
        k++;
    }
    while(j <= r)
    {
        v2[k] = v[j];
        j++;
        k++;
    }

    memcpy(v+p, v2, n * sizeof(int));
    delete [] v2;
}

void mergeSort(int v[], size_t p, size_t r)
{
    if (r <= p)
        return;

    size_t q = (p + r) / 2;
    mergeSort(v, p, q);
    mergeSort(v, q+1, r);
    merge(v,p,q,r);
}

void quickSort(int v[], size_t n)
{
    quickSort(v, 0, n-1);
}

void quickSort(int v[], size_t p, size_t r)
{
    if (r <= p)
        return;

    int pivot = v[r];

    size_t i = p-1;
    size_t j = p;

    while (j < r)
    {
        if (v[j] <= pivot)
        {
            i++;
            scambia(v[i], v[j]);
        }
        j++;
    }
    scambia(v[i+1],v[r]);

    quickSort(v,p,i);
    quickSort(v,i+2,r);
}
