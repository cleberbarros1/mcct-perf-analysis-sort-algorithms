#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// Funcao para trocar os elementos
void swap(vector<int>& arr, int a, int b) {
  swap(arr[a], arr[b]);
}

// Funcao de partição
int partition(vector<int>& arr, int low, int high) {
  // Escolha do pivor
  int mid = low + (high - low) / 2;
  int piv = max({arr[low], arr[mid], arr[high]});

  int i = low - 1;
  int j = high + 1;

  while (true) {
    while (++i < high && arr[i] < piv) {}

    while (--j > low && arr[j] > piv) {}

    if (i < j) {
      swap(arr[i], arr[j]);
    } else {
      break;
    }
  }

  return j; // Inidice do pivot
}

// Funcao Recursiva do Quick Sort
vector<int> quickSort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }

  return arr;
}