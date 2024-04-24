#include <stdio.h>
#include <vector>

using namespace std;

vector<int> merge(vector<int> vetor, vector<int> v1, vector<int> v2) {

  /// Atualiza o vetor original com base em coparacoes entre os 2 sub vetores criados
  int i = 0, j = 0, k = 0;

  while (i < v1.size() && j < v2.size()) {
    if (v1[i] <= v2[j]) {
      vetor[k] = v1[i];
      i++;
    } else {
      vetor[k] = v2[j];
      j++;
    }
    k++;
  }

  /// Copia os elementos restantes do vetor v1, caso existam, para o vetor original
  while (i < v1.size()) {
    vetor[k] = v1[i];
    i++;
    k++;
  }

  /// Copia os elementos restantes do vetor v2, caso existam, para o vetor original
  while (j < v2.size()) {
    vetor[k] = v2[j];
    j++;
    k++;
  }

  return vetor;
}



vector<int> mergeSort(vector<int> vetor) {

/// Avalia se o vetor a ser ordenado possui tamanho maior do que 1, caso possua tamanho > 1, é iniciado o processo de recursivo
    if (vetor.size() > 1) {

        vector<int> v1, v2;

        for(int i = 0; i < vetor.size()/2; i++){
            v1.push_back(vetor[i]);
        }

        for(int i = vetor.size()/2; i < vetor.size(); i++){
            v2.push_back(vetor[i]);
        }

        // Inicia o processo recursivo para os subvetores criados até que eles retornem elementos únicos
        v1 = mergeSort(v1);
        v2 = mergeSort(v2);

        // Faz a ordenação do vetor original utilizando comparacoes entre os subvetores e o vetor original
        vetor = merge(vetor, v1, v2);
    }

    return vetor;

}