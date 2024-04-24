#include <stdio.h>
#include <vector>
#include <string>
#include "bubble-sort.h"
#include "insertion-sort.h"
#include "selection-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"

using namespace std;

void Assert(char nomeDoTest[], vector<int> vetor, vector<int> resultadoEsperado) {

    vector<int> ordenado;

    if(nomeDoTest == "bubble"){
        ordenado = bubbleSort(vetor);
    }

    if(nomeDoTest == "insertion"){
        ordenado = insertionSort(vetor);
    }

    if(nomeDoTest == "selection"){
        ordenado = selectionSort(vetor);
    }

    if(nomeDoTest == "merge"){
        ordenado = mergeSort(vetor);
    }

    if(nomeDoTest == "quick"){
        ordenado = quickSort(vetor, 0, vetor.size()-1);
    }

    if(ordenado != resultadoEsperado){
        printf("\n -----  FALHOU! O resultado nao e o esperado.  ----- %s \n", nomeDoTest);
    } else {
        printf("\n -----  SUCESSO! O resultado esta correto.  ----- %s \n", nomeDoTest);
    }

    printf("\n --> obtido:\n[");
    for(int i = 0 ; i < ordenado.size(); i++) {
        printf("%d ", ordenado[i]);
    }
    printf("]\n\n");


    printf(" --> Esperado:\n[");
    for(int i = 0 ; i < resultadoEsperado.size(); i++) {
        printf("%d ", resultadoEsperado[i]);
    }
    printf("]\n\n");
  
}

int main() {

    vector<int> vetor = {7,2,5,2,10,8};
    vector<int> esperado = {2,2,5,7,8,10};

    Assert("bubble", vetor, esperado);

    Assert("insertion", vetor, esperado);

    Assert("selection", vetor, esperado);

    Assert("merge", vetor, esperado);

    Assert("quick", vetor, esperado);
    
    printf("PRESSIONE QUALQUER TECLA E ENTER PARA ENCERRAR\n");
    char a[1];
    scanf("%s", a);

}