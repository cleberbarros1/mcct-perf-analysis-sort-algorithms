#include <stdio.h>
#include <vector>

using namespace std;


vector<int> insertionSort(vector<int> vetor) {

    int aux, j;
    
    for(int i = 1; i < vetor.size(); i++) {
        j = i - 1;
        aux = vetor[i];

        while(j >= 0 && vetor[j] > aux) {
                vetor[j + 1] = vetor[j];
                j--;
                }
            vetor[j+1] = aux;
        }
    return vetor;
    }