#include <stdio.h>
#include <vector>

using namespace std;

///Funcao de ordenaçao de vetores por ordem crescente
vector<int> bubbleSort(vector<int> vetor) {
    for(int i = 0; i < vetor.size()-1; i++) {
        for(int j = i+1; j < vetor.size(); j++){
            if(vetor[i] > vetor[j]){
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }

                /// Trecho que permite visualizar o processo de troca
                /// printf("\n\n[");
                /// for(int i = 0 ; i < vetor.size(); i++) {
                /// printf("%d ", vetor[i]);
                ///    }
                /// printf("]");
        }
    }
    return vetor;
}