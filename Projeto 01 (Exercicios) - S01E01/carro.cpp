#include <iostream>
using namespace std;

class Carro{
    private:
        int nPessoas = 0;
        int maxPessoas = 2;
        float gasolina = 0;
        float maxGasolina = 100;
        int km = 0;
    
    public:
        Carro(){
            cout << "Digite o número máximo de pessoas: ";
            cin >> this->maxPessoas;
            cout << "Digite a quantidade máxima de litros que o tanque do carro comporta: ";
            cin >> this->maxGasolina;
        }

        void mostra_pessoas(){
            cout << "O carro possui " << this->nPessoas << " pessoas\n";
        }

        bool embarcar(){
            if (this->nPessoas < this->maxPessoas){
                this->nPessoas += 1;
                cout << "embarcou\n";
                return true;
            }
            cout << "ta lotado\n";
            return false;
        }

        bool desembarcar(){
            if (this->nPessoas > 0){
                this->nPessoas--;
                cout << "Desembarcou\n";
                return true;
            }
            cout << "Não há ninguém!\n";
            return false;
        }

        void dirigir(int km){
            if(this->nPessoas > 0){
                if(km <= this->gasolina){
                    this->gasolina -= km;
                    this->km += km;
                    cout << "Você chegou ao seu destino!\n";
                }else{
                    cout << "Não há gasolina para dirigir a distância!\n";
                }
            }else{
                cout << "Não há ninguém no carro!\n";
            }
        }

        int mostra_distancia(){
            return this->km;
        }

        void abastecer(float gasolina){
            if(gasolina > this->maxGasolina || (gasolina+this->gasolina) > this->maxGasolina){
                this->gasolina = this->maxGasolina;
            }else{
                this->gasolina += gasolina;
            }
            cout << "Abastecido!\n";
        }

        float mostrar_gasolina(){
            return this->gasolina;
        }

        ~Carro(){
            cout << "Carro destruído! :(" << endl;
        }

};

int main() {
    Carro * carro = new Carro();
    int op = 0;
    do{
        cout << "----MENU----\n1 - Embarcar\n2 - Desembarcar\n3 - Mostrar quantidade de pessoas\n4 - Dirigir\n5 - Abastecer\n6 - Mostrar gasolina\n7 - Mostrar distância percorrida\n8 - Sair\nDigite a opção: ";
        cin >> op;
        switch(op){
            case 1:
                carro->embarcar();
                break;
            case 2:
                carro->desembarcar();
                break;
            case 3:
                carro->mostra_pessoas();
                break; 
            case 4:
                int km;
                cout << "Digite quantas km deseja percorrer: ";
                cin >> km;
                carro->dirigir(km);
                break;
            case 5:
                float gas;
                cout << "Digite quanto deseja abastecer: ";
                cin >> gas;
                carro->abastecer(gas);
                break; 
            case 6:
                cout << "Gasolina: " << carro->mostrar_gasolina() << endl;
                break;
            case 7 :
                cout << "Odometro: " << carro->mostra_distancia() << endl;
                break;            
            case 8:
                cout << "::> Fim da execução" << endl;
                delete carro;
                break;
            default:
                cout << "Por favor informe uma opção correta!\n";
        }
    }while(op != 8);
    return 0;
}

