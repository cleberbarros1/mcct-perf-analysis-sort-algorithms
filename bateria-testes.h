#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include "calcular-tempos.h"
#include "calcular-medias.h"

using namespace std;


/// Funcao que calcula médias de tempo para conjuntos de execucao de X vezes de Matrizes com N elementos, sendo incrementados com M entradas a cada nova rodada de execucoes dos X testes. Retorna um vetor com as medias de cada rodada de avaliacao.
vector<double> bateriaTestes(int numEntradasInicio, int numEntradasFim, int passo, int qtdDeTestes, string metodo, FILE* pipe) {

    if(metodo != "bubble" && metodo != "insertion" && metodo != "selection" && metodo != "merge" && metodo != "quick") {

        vector<double> x = {0.0};

        printf("\n\nERRO: O nome do metodo inserido esta incorreto com as opcoes disponiveis.\n\n\n");
        return x;
    }

    vector<double> mediasDeTempo = {};

    for(int i = numEntradasInicio; i<= numEntradasFim; i += passo) {
        vector<double> tempos = calcularTempos(qtdDeTestes, i, metodo);

        double media = calcularMedia(tempos, i, metodo, pipe);

        printf("MEDIA DE TEMPOS PARA V[%d] --> %f s \n\n", i, media);

        mediasDeTempo.push_back(media);
    }
    
    return mediasDeTempo;
}