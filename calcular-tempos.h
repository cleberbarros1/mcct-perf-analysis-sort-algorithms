#include <stdio.h>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include "criar-vetor.h"
#include "bubble-sort.h"
#include "insertion-sort.h"
#include "selection-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"

using namespace std;
using namespace std::chrono;

///Funcao que repete o processo de criaçao e ordenaçao de vetores de E tamanho e M vezes e retorna um vetor com os tempos obtidos em cada execução de ordenação de cada iteracao
vector<double> calcularTempos(int numMedidas, int numElementos, string metodo) {
    vector<double> tempos = {};


    for(int i = 0; i < numMedidas; i++) {
        vector<int> meuVetor = criarVetor(numElementos);

        if(metodo == "bubble") {
            auto start = steady_clock::now();
            vector<int> vetorOrdenado = bubbleSort(meuVetor);
            auto finish = steady_clock::now();
            auto resultado = finish - start;
        
            tempos.push_back(duration<double>{resultado}.count());
            printf("Concluido ordenacao %d de %d ... V[%d] -> %f s\n", i+1, numMedidas, numElementos, tempos[i]);
            }

        if(metodo == "insertion") {
            auto start = steady_clock::now();
            vector<int> vetorOrdenado = insertionSort(meuVetor);
            auto finish = steady_clock::now();
            auto resultado = finish - start;
        
            tempos.push_back(duration<double>{resultado}.count());
            printf("Concluido ordenacao %d de %d ... V[%d] -> %f s\n", i+1, numMedidas, numElementos, tempos[i]);
            }

        if(metodo == "selection") {
            auto start = steady_clock::now();
            vector<int> vetorOrdenado = selectionSort(meuVetor);
            auto finish = steady_clock::now();
            auto resultado = finish - start;
        
            tempos.push_back(duration<double>{resultado}.count());
            printf("Concluido ordenacao %d de %d ... V[%d] -> %f s\n", i+1, numMedidas, numElementos, tempos[i]);
            }

        if(metodo == "merge") {
            auto start = steady_clock::now();
            vector<int> vetorOrdenado = mergeSort(meuVetor);
            auto finish = steady_clock::now();
            auto resultado = finish - start;
        
            tempos.push_back(duration<double>{resultado}.count());
            printf("Concluido ordenacao %d de %d ... V[%d] -> %f s\n", i+1, numMedidas, numElementos, tempos[i]);
            }

        if(metodo == "quick") {
            auto start = steady_clock::now();
            vector<int> vetorOrdenado = quickSort(meuVetor, 0, meuVetor.size()-1);
            auto finish = steady_clock::now();
            auto resultado = finish - start;
        
            tempos.push_back(duration<double>{resultado}.count());
            printf("Concluido ordenacao %d de %d ... V[%d] -> %f s\n", i+1, numMedidas, numElementos, tempos[i]);
            }

    }

    return tempos;
}