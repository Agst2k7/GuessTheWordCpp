#include <iostream>


using namespace std;





void draw(const char status[], const int &lifes, const int &word_size) {
    system("cls");
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
    char status[word_size];

    for(int i=0; i<word_size; i++) {
        word[i] = palavras[word_index][i];
        status[i] = '_';
    }

    int lifes = 5;


    draw(status, lifes, word_size);

    while (true) {
        if(lifes > 0) {
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
            
        } else {
            cout << "Voce Perdeu!" << endl;
            cout << "A PALAVRA ERA: " << palavras[word_index] << endl;
            break;
        }
    }


    return 0;
}