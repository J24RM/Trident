/*
    Este codigo se encarga de ordenar la lista de pokemones, recibe un vector a ordenar lleno de objetos de la clase pokemon,
    el algoritmo es el mergesort.
*/

#include "sorting.h" 

void mergeSplit(std::vector<Pokemon> &A, std::vector<Pokemon> &B, int low, int high);
void mergeArray(std::vector<Pokemon>& A, std::vector<Pokemon>& B, int low, int mid, int high);
void copyArray(std::vector<Pokemon>& A, std::vector<Pokemon>& B, int low, int high);


std::vector<Pokemon>& ordenaMerge(std::vector<Pokemon> &v) {
    std::vector<Pokemon> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
    return v;
}

// Funcion que se encarga de hacer las divisiones para dividir en Chunks
void mergeSplit(std::vector<Pokemon> &A, std::vector<Pokemon> &B, int low, int high) {
    int mid;
    if (low >= high) { 
        return;
    }
    mid = low + (high - low) / 2; // Punto medio.
    mergeSplit(A, B, low, mid); // Ir de forma recursiva a la izquierda.
    mergeSplit(A, B, mid + 1, high); // Ir de forma recursiva a la derecha.
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

// Compara los dos chunks para poner primero el mas chico y luego el mayor y luego los une.
void mergeArray(std::vector<Pokemon>& A, std::vector<Pokemon> &B, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (A[i].get_npoke() <= A[j].get_npoke()) { 
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= high) {
        B[k++] = A[j++];
    }
}


//Funcion que se encarga de copiar el array
void copyArray(std::vector<Pokemon>& A, std::vector<Pokemon> &B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

