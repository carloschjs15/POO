#include <iostream>
#include <sstream>

using namespace std;

class Grafite{
    private:
        int tamanho;
        float espessura;
    public:
        Grafite(int tam = 0, float esp = 0.7){
            this->tamanho = tam;
            this->espessura = esp;
        }
        int getTamanho(){
            return this->tamanho;
        }
        void setTamanho(int t){
            this->tamanho = t;
        }
        void setEspessura(float e){
            this->espessura = e;
        }
        float getEspessura(){
            return this->espessura;
        }
};

class Lapiseira{
    private:
        Grafite * g {nullptr};
    public:
        Lapiseira(){
            cout << "Você tem uma lapiseira!" << endl;
        }

        void colocaGra(int tam, float esp){
            if(tam <= 0){
                cout << "O grafite deve ter um tamanho maior que 0";
            }else{
                this->g = new Grafite(tam,esp);
            }
        }

        void escreve(int linha){
            if(g != nullptr){
                if(linha <= this->g->getTamanho()){
                    this->g->setTamanho(this->g->getTamanho() - linha);
                    cout << "Escrevendooooo!!!\n";
                }else{
                    cout << "::fail> Você não tem grafite suficiente, coloque um novo grafite, ou gaste menos dele!" << endl;
                }
            }else{
                cout << "::fail> Não há como escrever você não tem grafite, por favor coloque um grafite!\n";
            }
            
        }

        ~Lapiseira(){
            cout << "A lapiseira foi destruída!" << endl;
            delete g;
        }
};

int main(){
    Lapiseira l;
    while(true){
        string linha;
        getline(cin, linha);
        stringstream ss(linha);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "coloca"){
            int tam;
            float esp;
            ss >> tam >> esp;
            l.colocaGra(tam,esp);
        }else if(cmd == "escreve"){
            int t;
            ss >> t;
            l.escreve(t);
        }
    }

    return 0;
}