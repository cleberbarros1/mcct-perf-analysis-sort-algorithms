#include <stdio.h>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> vetor) {

    for (int i = 0; i < vetor.size() - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < vetor.size(); j++) {
          if (vetor[j] < vetor[menor]) {
            menor = j;
            }
        }

        if (menor != i) {
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
            }
    }

    return vetor;
}