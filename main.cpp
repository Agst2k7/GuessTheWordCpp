#include <iostream>
#include <random>

using namespace std;

int sortIndex(int WORD_TABLE_SIZE) {

    random_device rd; //  gera uma semente verdadeiramente aleatória
    mt19937 gen(rd()); //  é um gerador de alta qualidade (Mersenne Twister)
    uniform_int_distribution<> dist(0, WORD_TABLE_SIZE-1); // garante distribuição uniforme no intervalo
    return dist(gen);
}

void draw(const char status[], const int &lifes, const int &word_size) {
    cout << "Lifes: " << lifes << endl;
    cout << "--> ";
    for (int i=0; i<word_size; i++) {
        cout << status[i] << " ";
    }
    cout << endl;
}


int main(int argc, char* argv[]) {

    string palavras[100] = {
    "cachorro",
    "golfinho",
    "borboleta",
    "tartaruga",
    "elefante",
    "jacare",
    "papagaio",
    "formiga",
    "cavalo",
    "macaco",
    "baleia",
    "pinguim",
    "aranha",
    "leao",
    "zebra",
    "martelo",
    "tesoura",
    "lápis",
    "espelho",
    "guarda-chuva",
    "mochila",
    "lanterna",
    "bússola",
    "relógio",
    "binóculo",
    "violão",
    "tapete",
    "almofada",
    "chave",
    "garrafa",
    "floresta",
    "cachoeira",
    "montanha",
    "vulcão",
    "deserto",
    "glaciar",
    "pantanal",
    "savana",
    "mangue",
    "penhasco",
    "tornado",
    "arco-iris",
    "geada",
    "tempestade",
    "bruma",
    "abacaxi",
    "maracujá",
    "jiló",
    "canjica",
    "coxinha",
    "paçoca",
    "brigadeiro",
    "tapioca",
    "acarajé",
    "goiaba",
    "quiabo",
    "pitanga",
    "jabuticaba",
    "cupuaçu",
    "caju",
    "farmácia",
    "biblioteca",
    "mercado",
    "aeroporto",
    "estádio",
    "museu",
    "parque",
    "palácio",
    "porto",
    "delegacia",
    "cartório",
    "cemitério",
    "aquário",
    "oficina",
    "galeria",
    "bombeiro",
    "enfermeira",
    "arquiteto",
    "fotógrafo",
    "piloto",
    "padeiro",
    "motorista",
    "barbeiro",
    "pescador",
    "fazendeiro",
    "jornalista",
    "carpinteiro",
    "eletricista",
    "cientista",
    "veterinário",
    "bicicleta",
    "submarino",
    "parafuso",
    "campainha",
    "peruca"
};
    int WORD_TABLE_SIZE = 100;

    int word_index = sortIndex(WORD_TABLE_SIZE);
    int word_size = palavras[word_index].size();

    char word[word_index];
    char status[word_index];

    for(int i=0; i<word_size; i++) {
        word[i] = palavras[word_index][i];
        status[i] = '_';
    }

    int lifes = 5;

    cout << "PALAVRA: " << palavras[word_index] << endl;

    draw(status, lifes, word_size);

    

    return 0;
}