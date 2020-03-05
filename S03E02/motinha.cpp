#include <iostream>
#include <sstream>
using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;

    public:
        Pessoa(string nome = "", int idade = -1){
            this->nome = nome;
            this->idade = idade;
            cout << this->nome << " esta nascendo\n"; 
        }
        int getIdade(){
            return idade;
        }
        string getNome(){
            return nome;
        }
        ~Pessoa(){
            cout << this->nome << " esta morrendo\n";
        }
};

class Motinha{
    private:
        int potencia, tempo_moto;
        Pessoa * pessoa {nullptr};
    
    public:    
        Motinha(int potencia = 1){ // Caso não seja informado a potencia é colocado como potencia 1
            while(potencia <= 0){
                cout << "Fail::> A potência não pode ser igual a 0, por favor informe uma nova potência: ";
                cin >> potencia;
            }
            this->potencia = potencia;
        }

        void embarcar(Pessoa * pessoa){
            if(this->pessoa != nullptr)
                cout << "ja tem gente na motinha\n";
            else{
                this->pessoa = pessoa;
                this->tempo_moto = 0;
            }
        }

        void pagar(int valor){
            this->tempo_moto += valor;
        }

        Pessoa * desembarcar(){
            if(this->pessoa == nullptr)
                return nullptr;
            Pessoa * temp = this->pessoa;
            this->pessoa = nullptr;
            return temp; 
        }

        void dirigir(int min){
            if(this->pessoa == nullptr)
                cout << "nao tem ninguem na motinha\n"; 
            else if(this->pessoa->getIdade() >= 4){
                if(min <= this->tempo_moto){
                    string motor = "";
                    for(int i = 1; i <= this->potencia; i++){
                        motor += "run ";
                    }
                    cout << motor << endl;
                    this->tempo_moto -= min;
                }else{
                    cout << "Você possui " << this->tempo_moto << " de tempo, por favor pague mais!\n";
                }
            }else
                cout << pessoa->getNome() << "Você não sabe andar ainda\n";
        }

};

int main() {
    Motinha * motinha;
    while(true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            delete motinha;
            break;
        }else if(cmd == "init"){
            int potencia;
            ss >> potencia;
            motinha = new Motinha(potencia);
        }else if(cmd == "embarcar"){//nome idade
            string nome;
            int idade;
            ss >> nome >> idade;
            
            motinha->embarcar(new Pessoa(nome, idade));

        }else if(cmd == "pagar"){
            int pag;
            ss >> pag;
            motinha->pagar(pag);
        }else if(cmd == "dirigir"){
            int tempo;
            ss >> tempo;
            motinha->dirigir(tempo);
        }else if(cmd == "desembarcar"){
            Pessoa * temp = motinha->desembarcar();
            if(temp != nullptr)
                delete temp;
        }else{
            cout << "comando invalido\n";
        }
    }
}

