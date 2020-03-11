#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void show(vector<int> v){
    cout << "[ ";
    for(vector<int>::iterator i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }
    cout << "]\n";
}

void rshow(vector<int> v){
    cout << "[ ";
    for(vector<int>::iterator i = v.end(); i != v.begin(); i--){
        cout << *i << " ";
    }
    cout << "]\n";
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
            while(ss >> valor){
                cout << *find(vet.begin(), vet.end(), valor);
            }
        }else if(cmd == "ins"){

        }
    }
    return 0;
}