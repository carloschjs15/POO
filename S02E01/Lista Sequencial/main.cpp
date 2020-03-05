#include  <iostream>
#include "class.h"
using namespace std;

int main(){
	int op,n, tamanho;
	cout << "Digite o tamanho máximo da lista: ";
	cin >> tamanho;
	ListaSequencial lista(tamanho);
	do{
		cout << "\nMENU\n1 - Inserir valor\n2 - Remover valor\n3 - Mostrar a lista\n4 - Limpar a lista\n5 - Sair\nDigite sua opcao: ";
		cin >> op;
		cout << endl;
	switch(op){
		case 1:
			cout << "Digite um valor a ser inserido: ";
			cin >> n;
			lista.inserir(n);
			break;
		case 2:
			cout << "Digite um valor a ser removido: ";
			cin >> n;
			lista.remover(n);
			break;
		case 3:
			lista.print();
			break;
		case 4:
			lista.limpar();
			break;
	}
	}while(op != 5);
	return 0;
}
