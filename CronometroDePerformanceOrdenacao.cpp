#include <stdio.h>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;


/// Funçao que cria vetores, com entradas geradas aleatorias pela funçao rand()
vector<int> criarVetor(int numEntradas) {
    vector<int> nV = {};
    for(int i = 0; i < numEntradas; i++) {
        nV.push_back(rand());
    }
    return nV;
}

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

///Funcao que repete o processo de criaçao e ordenaçao de vetores de E tamanho e M vezes e retorna um vetor com os tempos obtidos em cada execução de ordenação de cada iteracao
vector<double> calcularTempos(int numMedidas, int numElementos) {
    vector<double> tempos = {};


    for(int i = 0; i < numMedidas; i++) {
        vector<int> meuVetor = criarVetor(numElementos);

        auto start = steady_clock::now();
        vector<int> vetorOrdenado = bubbleSort(meuVetor);
        auto finish = steady_clock::now();

        auto resultado = finish - start;
        
        tempos.push_back(duration<double>{resultado}.count());
        printf("Concluido ordenacao %d de %d ... V[%d] -> %f s\n", i+1, numMedidas, numElementos, tempos[i]);
    }

    return tempos;
}

/// Funcao que calcula a média (mean or Average) de um conjunto de vetores
double calcularMedia(vector<double> conjunto){
    
    double soma;

    for(int j = 0; j< conjunto.size(); j++) {
            soma += conjunto[j];
        }

    return soma / conjunto.size();
}


/// Funcao que calcula Medias de tempo para conjuntos de execucao de X vezes de Matrizes com N elementos, sendo incrementados com M entradas a cada nova rodada de execucoes dos X testes. Retorna um vetor com as medias de cada rodada de avaliacao.
vector<double> calcularMediasParaIncrementosDeEntradas(int numEntradasInicio, int numEntradasFim, int passo, int qtdDeTestes) {

    vector<double> mediasDeTempo = {};

    for(int i = numEntradasInicio; i<= numEntradasFim; i += passo) {
        vector<double> tempos = calcularTempos(qtdDeTestes, i);

        double media = calcularMedia(tempos);

        printf("MEDIA DE TEMPOS PARA V[%d] --> %f s \n\n", i, media);

        mediasDeTempo.push_back(media);
    }

    
    return mediasDeTempo;
}



int main() {
   printf("\n ------------------- MESTRADO EM MODELAGEM COMPUTACIONAL - 2024.1 --------------------\n");
   printf("\n --> Estudantes: CLEBER BARROS / ITALO GALLON --- \n");
   printf("\n --> Software para avaliacao de performance de algoritmos de ordenacao --- \n");
   printf("\n --> Professor: Tiago Araujo Neves --- \n");
   printf("\n --> DESAFIO: Avaliar complexidade e desempenho de Algoritmos de Ordenacao\n\n");

   printf("\n ------------------- INICIANDO AVALIACAO DE TEMPOS --------------------\n\n");

///AQUI E A INVOCACAO DO METODO PRINCIPAL. ALTERE NA ORDEM -> valor inicial (500) / Valor Final (5000), Passo (1000) e Repeticoes (30)
   vector<double> meuVetor = calcularMediasParaIncrementosDeEntradas(1000, 2000, 100, 30);

   ofstream file("relatorio.txt");
   fstream relatorio;
   relatorio.open("relatorio.txt");


   printf("\n ------------------- RESULTADO DE MEDIAS --------------------\n\n[");
   for(int i = 0 ; i < meuVetor.size(); i++) {
    printf("%f s ", meuVetor[i]);
    
    relatorio << 1000+i*100;
    relatorio << " ";
    relatorio << meuVetor[i] << std::endl;
   }
   printf("]\n\n");

   printf("PRESSIONE ENTER PARA ENCERRAR");
   char a[1];
   scanf("%s", a);
}