#include <stdio.h>
#include <vector>
#include "gerar-relatorios.h"

using namespace std;

/// Funcao que calcula a média (mean or Average) de um conjunto de vetores
double calcularMedia(vector<double> conjunto, int i, string metodo, FILE* pipe){
    
    double soma;

    for(int j = 0; j< conjunto.size(); j++) {
            soma += conjunto[j];
        }

    double media = soma / conjunto.size();
    
    iterarRelatorios(media, i, metodo);

    fprintf(pipe, "replot; \n");
    fprintf(pipe, "set autoscale; \n");
    fflush(pipe);
    
    return media;
}