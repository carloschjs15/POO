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
    public:
        Pessoa * pessoa {nullptr}; //agregação
        //Pessoa pessoa = null;
        void embarcar(Pessoa * pessoa){
            if(this->pessoa != nullptr)
                cout << "ja tem gente na motinha\n";
            else
                this->pessoa = pessoa;
        }

        Pessoa * desembarcar(){
            if(this->pessoa == nullptr)
                return nullptr;
            Pessoa * temp = this->pessoa;
            this->pessoa = nullptr;
            return temp; 
        }

        void dirigir(){
            if(this->pessoa == nullptr)
                cout << "nao tem ninguem na motinha\n"; 
            else if(this->pessoa->getIdade() >= 4)
                cout << pessoa->getNome() << ": Urruuu, dando uma voltinha\n";
            else
                cout << pessoa->getNome() << "Você não sabe andar ainda\n";
        }

};

int main() {
    Motinha motinha;
    while(true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "embarcar"){//nome idade
            string nome;
            int idade;
            ss >> nome >> idade;
            
            motinha.embarcar(new Pessoa(nome, idade));

        }else if(cmd == "dirigir"){
            motinha.dirigir();
        }else if(cmd == "desembarcar"){
            Pessoa * temp = motinha.desembarcar();
            if(temp != nullptr)
                delete temp;
        }else{
            cout << "comando invalido\n";
        }
    }
}

