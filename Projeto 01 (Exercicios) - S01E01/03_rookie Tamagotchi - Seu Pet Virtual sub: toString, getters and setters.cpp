#include <iostream>
#include <sstream>

using namespace std;

class Pet{
    private:
        int energiaMax, saciedadeMax, limpezaMax; // Máximas
        int energia, saciedade, limpeza; // Níveis
        int diamantes = 0, idade = 0; // Outros atributos
        bool morto;
        void setEnergia(int e){
            if(e >= 0){
                if((this->energia + e) > this->energiaMax){
                    this->energia = this->energiaMax;
                }else
                    this->energia += e;
            }else{
                if((this->energia + e) <= 0){
                    this->energia = 0;
                    morto = true;
                    cout << "fail: pet morreu de fraqueza" << endl;
                }else
                    this->energia += e;
            }
        }
        void setLimpeza(int e){
            if(e >= 0){
                if((this->limpeza + e) > this->limpezaMax){
                    this->limpeza = this->limpezaMax;
                }else
                    this->limpeza += e;
            }else{
                if((this->limpeza + e) <= 0){
                    this->limpeza = 0;
                    morto = true;
                    cout << "fail: pet morreu de sujeira" << endl;
                }else
                    this->limpeza += e;
            }
        }
        void setSaciedade(int e){
            if(e >= 0){
                if((this->saciedade + e) > this->saciedadeMax){
                    this->saciedade = this->saciedadeMax;
                }else
                    this->saciedade += e;
            }else{
                if((this->saciedade + e) <= 0){
                    this->saciedade = 0;
                    morto = true;
                    cout << "fail: pet morreu de fome" << endl;
                }else
                    this->saciedade += e;
            }
        }
    public:
        Pet(int e, int s, int l){
            this->morto = false;
            this->energiaMax = this->energia = e;
            this->saciedadeMax = this->saciedade = s;
            this->limpezaMax = this->limpeza = l;
        }

        void init(int e, int s, int l){
            this->morto = false;
            this->energiaMax = this->energia = e;
            this->saciedadeMax = this->saciedade = s;
            this->limpezaMax = this->limpeza = l;
        }

        bool Morto(){ // Se estiver morto retorna true
            return morto;
        }

        void show(){
            cout << "E:" << this->energia << "/" << this->energiaMax << ", S:" << this->saciedade << "/" << this->saciedadeMax << ", L:" << this->limpeza << "/" << this->limpezaMax << ", D:" << this->diamantes << ", I:" << this->idade << endl; 
        }

        void play(){
            if(Morto()){
                cout << "fail: pet esta morto" << endl;
                return ;
            }
            setEnergia(-2);
            setSaciedade(-1);
            setLimpeza(-3);
            this->diamantes++;
            this->idade++;
        }

        void eat(){
            if(Morto()){
                cout << "fail: pet esta morto" << endl;
                return ;
            }
            setEnergia(-1);
            setSaciedade(4);
            setLimpeza(-2);
            this->idade++;            
        }

        void sleep(){
            if(Morto()){
                cout << "fail: pet esta morto" << endl;
                return ;
            }
            if(this->energiaMax - this->energia >= 5){
                this->idade += this->energiaMax - this->energia;
                setEnergia(this->energiaMax);
            }else
                cout << "fail: nao esta com sono" << endl;
        }

        void clean(){
            if(Morto()){
                cout << "fail: pet esta morto" << endl;
                return ;
            }
            setEnergia(-3);
            setSaciedade(-1);
            setLimpeza(this->limpezaMax);
            this->idade += 2;
        }
};

int main(){
    Pet * p {nullptr};
    while (true){
        string linha;
        getline(cin,linha);
        stringstream ss(linha);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "init"){
            int e, s, l;
            ss >> e >> s >> l;
            if(p == nullptr){
                p = new Pet(e,s,l);
            }else{
                p->init(e,s,l);
            }
        }else if(cmd == "show"){
            if(p == nullptr){
                cout << "Pet não foi criado!\n";
            }else{
                p->show();
            }
        }else if(cmd == "play"){
            if(p == nullptr){
                cout << "Pet não foi criado!\n";
            }else if(p->Morto()){
                cout << "fail: pet esta morto \n";
            }else if(!p->Morto()){
                p->play();
            }
        }else if(cmd == "eat"){
            if(p == nullptr){
                cout << "Pet não foi criado!\n";
            }else if(p->Morto()){
                cout << "fail: pet esta morto \n";
            }else if(!p->Morto()){
                p->eat();
            }
        }else if(cmd == "sleep"){
            if(p == nullptr){
                cout << "Pet não foi criado!\n";
            }else if(p->Morto()){
                cout << "fail: pet esta morto \n";
            }else if(!p->Morto()){
                p->sleep();
            }
        }else if(cmd == "clean"){
            if(p == nullptr){
                cout << "Pet não foi criado!\n";
            }else if(p->Morto()){
                cout << "fail: pet esta morto \n";
            }else if(!p->Morto()){
                p->clean();
            }
        }else{
            cout << "Comando inválido!\n";
        }
    }
    delete p;
    return 0;
}