#include <iostream>
#include <sstream>

using namespace std;

class Grafite{
    private:
        float tamanho;
        float espessura;
    public:
        Grafite(float tam = 0, float esp = 0.7){
            this->tamanho = tam;
            this->espessura = esp;
        }
        int getTamanho(){
            return this->tamanho;
        }
        void setTamanho(float t){
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
        float espessura;
    public:
        Lapiseira(float esp = 0.7){
            this->espessura = esp;
            cout << "Você tem uma lapiseira!" << endl;
        }

        void muda(float f){
            this->espessura = f;
        }

        void colocaGra(float tam, float esp){
            if(esp == this->espessura){
                if(tam <= 0){
                    cout << "O grafite deve ter um tamanho maior que 0";
                }else{
                    this->g = new Grafite(tam,esp);
                }
            }else{
                cout << "A lapiseira não pode colocar esse grafite!\n";
            }
        }

        void removeGra(){
            if(g != nullptr){
                delete g;
                g = nullptr;
                cout << "Grafite removido!\n";
            }else{
                cout << "Não há grafite na lapiseira!\n";
            }
        }

        void escreve(int linha){
            if(g != nullptr){
                if((linha*0.05) <= this->g->getTamanho()){
                    this->g->setTamanho(this->g->getTamanho() - (linha*0.05));
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
    float g;
    cout << "Criando uma lapiseira, digite a espessura do grafite: ";
    cin >> g;
    Lapiseira l(g);
    while(true){
        string linha;
        getline(cin, linha);
        stringstream ss(linha);
        string cmd;
        ss >> cmd;
        if(cmd == "init"){ // Gera uma nova lapiseira
            float g;
            ss >> g;
            l.muda(g);
        }else if(cmd == "end"){
            break;
        }else if(cmd == "remove"){
            l.removeGra();
        }else if(cmd == "coloca"){
            float tam;
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