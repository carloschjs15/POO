#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void show(vector<int> v){
    cout << "[ ";
    for(int i = 0; i != (int) v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << "]\n";
}

void rshow(vector<int> v){
    cout << "[ ";
    for(int i = ((int) v.size())-1; i >= 0; i--){
        cout << v.at(i) << " ";
    }
    cout << "]\n";
}

void rma(vector<int> * v, int valor){
    for(int i = ((int) v->size())-1; i >= 0; i--){
        if(v->at(i) == valor){
            v->erase(v->begin()+i);
        }
    }
}

int main(){
    vector<int> vet;
    while(true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "show"){
            show(vet);
        }else if(cmd == "add"){
            int valor;
            while(ss >> valor){
                vet.push_back(valor);
            }
        }else if(cmd == "end"){
            break;
        }else if(cmd == "rshow"){
            rshow(vet);
        }else if(cmd == "find"){
            int valor;
            cout << "[ ";
            while(ss >> valor){
                vector<int>::iterator j = find(vet.begin(), vet.end(), valor);
                if(j == vet.end()){
                    cout <<  "-1 ";
                }else{
                    cout << distance(vet.begin(), j) << " ";
                }
            }
            cout << "]\n";
        }else if(cmd == "ins"){
            int ind;
            int valor;
            ss >> ind >> valor;
            if(ind >= 0 && ind < (int) vet.size())
                vet.insert(vet.begin()+ind, valor);
            else if(ind >= (int) vet.size())
                vet.insert(vet.begin()+vet.size(), valor);
        }else if(cmd == "rmi"){
            int ind;
            ss >> ind;
            if(ind >= (int) vet.size() || ind < 0){
                cout << "fail" << endl;
            }else{
                vet.erase(vet.begin()+ind);
            }
        }else if(cmd == "rma"){
            int v;
            ss >> v;
            rma(&vet, v);
        }else{
            cout << "Comando inválido!\n";
        }
    }
    return 0;
}