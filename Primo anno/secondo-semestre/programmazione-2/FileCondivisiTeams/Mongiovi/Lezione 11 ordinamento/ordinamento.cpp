//
//  Esempi di implementazione di algoritmi di ordinamento

#include <iostream>

using namespace std;

typedef int el;

void print(el array[],size_t n);

void insertionSort(el array[], size_t n);
void selectionSort(el v[], size_t n);
void mergeSort(el v[], size_t n);
void mergeSort(el v[], size_t p, size_t r);
void quickSort(el v[], size_t n);
void quickSort(el v[], size_t p, size_t r);

int main()
{
    el array[] = {10,32,11,34,15};
    size_t n = sizeof(array)/sizeof(array[0]);
    
    cout << "Array iniziale: "; print(array,n);
    //insertionSort(array,n);
    //selectionSort(array,n);
    //mergeSort(array, n);
    quickSort(array,n);
    cout << "Array finale: "; print(array,n);
    
    return 0;
}

void print(el array[],size_t n)
{
    for(size_t i=0; i<n; i++)
        cout << array[i] << " ";
    cout << endl;
}

void scambia (el& a, el& b)
{
    el appoggio = a;
    a = b;
    b = appoggio;
}

void insertionSort(el array[], size_t n)
{
    for (size_t i=1; i<n; i++)
    {
        el appoggio = array[i];
        size_t j = i-1;
        while ((array[j] > appoggio) && (j >= 0))
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = appoggio;
    }
}

void selectionSort(el v[], size_t n)
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

void mergeSort(el v[], size_t n)
{
    mergeSort(v, 0, n-1);
}

void merge(el v[], size_t p, size_t q, size_t r)
{
    size_t n = r-p+1;
    el* v2 = new el[n];
    
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
            
    memcpy(v+p, v2, n * sizeof(el));
    delete [] v2;
}

void mergeSort(el v[], size_t p, size_t r)
{
    if (r <= p)
        return;
    
    size_t q = (p + r) / 2;
    mergeSort(v, p, q);
    mergeSort(v, q+1, r);
    merge(v,p,q,r);
}

void quickSort(el v[], size_t n)
{
    quickSort(v, 0, n-1);
}

void quickSort(el v[], size_t p, size_t r)
{
    if (r <= p)
        return;
    
    el pivot = v[r];
    
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
