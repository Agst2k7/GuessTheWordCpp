#include "sortWord.h"
#include <random>

int sortIndex(int WORD_TABLE_SIZE) { 

    random_device rd; //  gera uma semente verdadeiramente aleatória
    mt19937 gen(rd()); //  é um gerador de alta qualidade (Mersenne Twister)
    uniform_int_distribution<> dist(0, WORD_TABLE_SIZE-1); // garante distribuição uniforme no intervalo
    return dist(gen);
}