// sorting.cpp

#include "sorting.h" // Incluimos su propia cabecera para asegurar que las declaraciones coincidan.

// --- DEFINICIONES ---
// Las funciones auxiliares van aquí. No necesitan estar en el .h si solo se usan dentro de este archivo.
void mergeSplit(std::vector<Pokemon> &A, std::vector<Pokemon> &B, int low, int high);
void mergeArray(std::vector<Pokemon>& A, std::vector<Pokemon>& B, int low, int mid, int high);
void copyArray(std::vector<Pokemon>& A, std::vector<Pokemon>& B, int low, int high);

// Implementación de la función principal
std::vector<Pokemon>& ordenaMerge(std::vector<Pokemon> &v) {
    std::vector<Pokemon> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
    return v;
}

// Implementación de las funciones auxiliares
void mergeSplit(std::vector<Pokemon> &A, std::vector<Pokemon> &B, int low, int high) {
    int mid;
    if (low >= high) { // Condición de paro corregida (era low == high)
        return;
    }
    mid = low + (high - low) / 2; // Forma más segura de calcular el punto medio
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

void mergeArray(std::vector<Pokemon>& A, std::vector<Pokemon> &B, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (A[i].get_npoke() <= A[j].get_npoke()) { // Usar <= para mantener la estabilidad del ordenamiento
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

void copyArray(std::vector<Pokemon>& A, std::vector<Pokemon> &B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}