#include <stdio.h>
#include <vector>
#include <random>

using namespace std;

/// Funçao que cria vetores, com entradas geradas aleatorias pela funçao rand()
vector<int> criarVetor(int numEntradas) {
    vector<int> nV = {};
    for(int i = 0; i < numEntradas; i++) {
        nV.push_back(rand());
    }
    return nV;
}