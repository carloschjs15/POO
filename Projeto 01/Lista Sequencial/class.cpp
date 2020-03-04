#include <iostream>
#include "class.h"

using namespace std;

ListaSequencial::ListaSequencial(int n){
	v = new int[n];
	tam = 0;
	capacidade = n;
}
bool ListaSequencial::cheia(){
	return (tam==capacidade);
}
int ListaSequencial::getElemento(int i){
	if(i>=0 && i < tam)
		return v[i];
	return -1;
}
void ListaSequencial::inserir(int valor){
	if(!cheia()){
		v[tam] = valor;
		//cout << tam << endl;
		tam++;
	}else{
		cout << "Falha: Lista cheia" << endl;
	}
}
int ListaSequencial::buscar(int valor){
	for(int i = 0; i < tam; i++)
		if(v[i] == valor)
			return i;
	return -1;
}
void ListaSequencial::remover(int valor){
	int ind = buscar(valor);
	if(ind != -1){
		v[ind] = v[tam-1];
		tam--;
	}else{
		cout << "Elemento inexistente" << endl;
	}
}
int ListaSequencial::tamanho(){
	return tam;
}
void ListaSequencial::print(){
	for(int i = 0; i < tam; i++)
		cout << v[i] << endl;
}
void ListaSequencial::limpar(){
	tam = 0;
}
