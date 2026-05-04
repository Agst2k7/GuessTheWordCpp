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
    system("clear");
    cout << "Lifes: " << lifes << endl;
    cout << "--> ";
    for (int i=0; i<word_size; i++) {
        cout << status[i] << " ";
    }
    cout << endl;
}

bool HaveChar(const char& c, const char word[], char status[], const int &word_size) {
    int i = 0;
    bool find = false;
    while(i < word_size) {
        if(c == word[i]) {
            status[i] = c;
            find = true;
        }
        i++;
    }
    return find;
}

int main(int argc, char* argv[]) {

    string palavras[100] = {
    "apple","house","table","chair","water","light","plant","stone","bread","music",
    "river","mountain","cloud","forest","ocean","flower","window","door","floor","ceiling",
    "school","teacher","student","pencil","paper","notebook","computer","keyboard","screen","mouse",
    "phone","camera","picture","movie","actor","artist","writer","reader","driver","pilot",
    "train","plane","boat","car","truck","bicycle","engine","wheel","road","bridge",
    "city","village","country","world","earth","space","star","planet","sun","moon",
    "day","night","morning","evening","hour","minute","second","clock","watch","time",
    "family","mother","father","brother","sister","friend","child","baby","people","person",
    "food","fruit","meat","sugar","salt","coffee","tea","milk","juice","drink",
    "happy","sad","angry","tired","strong","weak","fast","slow","big","small"
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


    draw(status, lifes, word_size);

    while (true) {
        cout << "Digite uma letra:" << endl;

        char input;
        input = getchar();
        getchar();

        if (!HaveChar(input, word, status, word_size)) {
            lifes--;
            cout << "Letra errada!" << endl;
        } else {
            cout << "Acertou a letra!" << endl;
        }

        draw(status, lifes, word_size);
        cout << "PALAVRA: " << palavras[word_index] << endl;
    }



    

    return 0;
}