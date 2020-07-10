#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Kid{
    private:
        string name;
        int idade;
        int saldo = 0; // O pula pula custa 1 real por cada vez
    public:
        Kid(string name, int idade){
            this->name = name;
            this->idade = idade;
        }
        string toString(){
            return this->name + ":" + to_string(this->idade);
        }

        void pulou(){
            this->saldo++;
        }

        string getName(){
            return this->name;
        }

        int getIdade(){
            return idade;
        }

        int getSaldo(){
            return saldo;
        }
};

class Trampolim{
    private:
        vector<Kid> kidsWaiting;
        vector<Kid> kidsplaying;
        int maxplay;
        int caixa = 0;

    public:
        void init(int max){
            maxplay = max;
        }
        string toString(){
            string linha = "=> ";
            vector<Kid>::reverse_iterator rit = kidsWaiting.rbegin();
            for (; rit!= kidsWaiting.rend(); ++rit){
                linha += rit->toString() + " ";
            }
            linha += "=> [ ";
            vector<Kid>::reverse_iterator rt = kidsplaying.rbegin();
            for (; rt!= kidsplaying.rend(); ++rt){
                linha += rt->toString() + " ";
            }
            linha += "]";

            return linha;
        }

        void chegar(Kid c){
            this->kidsWaiting.push_back(c);
        }

        void show(){
            cout << toString() << endl;
        }

        void Mostracaixa(){
            cout << "Caixa:" << caixa;
        }

        void saldo(string name){
            bool find = false;
            for(Kid c : this->kidsWaiting){
                if(c.getName() == name){
                    cout << "Saldo:" << c.getSaldo() << endl;
                    find = true;
                }
            }
            for(Kid c : this->kidsplaying){
                if(c.getName() == name){
                    cout << "Saldo:" << c.getSaldo() << endl;
                    find = true;
                }
            }
            if(!find){
                cout << "\nNão tem nenhuma criança com este nome!\n";
            }
        }

        void paichegou(string name){
            bool find = false;
            for(vector<Kid>::iterator i = this->kidsWaiting.begin();i != this->kidsWaiting.end();i++){
                if(i->getName() == name){
                    this->kidsWaiting.erase(i);
                    find = true;
                }
            }
            for(vector<Kid>::iterator i = this->kidsplaying.begin();i != this->kidsplaying.end();i++){
                if(i->getName() == name){
                    i->pulou();
                    caixa++;
                    this->kidsplaying.erase(i);
                    find = true;
                }
            }
            if(!find){
                cout << "\nNão tem nenhuma criança com este nome!\n";
            }
        }

        void in(){
            if(maxplay > int(this->kidsplaying.size())){
                vector<Kid>::iterator c = this->kidsWaiting.begin();
                this->kidsplaying.push_back(*c);
                this->kidsWaiting.erase(c);
            }else{
                cout << "Desculpe, o trampolim só suporta " << maxplay << " crianças, por favor aguarde sua vez\n";
            }
        }

        void out(){
            vector<Kid>::iterator c = this->kidsplaying.begin();
            c->pulou();
            caixa++;
            this->kidsWaiting.push_back(*c);
            this->kidsplaying.erase(c);
        }

        void fecha(){
            this->kidsplaying.erase(this->kidsplaying.begin(), this->kidsplaying.end());
            this->kidsWaiting.erase(this->kidsWaiting.begin(), this->kidsWaiting.end());
            cout << "Caixa de hoje:" << caixa << endl;
        }
};

int main(){
    Trampolim t;
    cout << "Defina quantas crianças poderão está no trampolim ao mesmo tempo: " << endl;
    int qtd;
    cin >> qtd;
    t.init(qtd);
    while(true){
        string line;
        getline(cin,line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "fechar"){
            t.fecha();
            break;
        }else if(cmd == "chegou"){
            string name;
            int idade;
            ss >> name >> idade;
            Kid c(name, idade);
            t.chegar(c);
        }else if(cmd == "show"){
            t.show();
        }else if(cmd == "entrar"){
            t.in();
        }else if(cmd == "sair"){
            t.out();
        }else if(cmd == "saldo"){
            string name;
            ss >> name;
            t.saldo(name);
        }else if(cmd == "caixa"){
            t.Mostracaixa();
        }else if(cmd == "papaichegou"){
            string name;
            ss >> name;
            t.paichegou(name);
        }else if(cmd == "init"){
            int max;
            ss >> max;
            t.init(max);
        }
    }
    return 0;
}