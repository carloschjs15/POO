#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H
class ListaSequencial{
	private:
		int *v = nullptr;
		int tam;
		int capacidade;
	public:
		ListaSequencial(int);
		~ListaSequencial();
		void inserir(int);
		void remover(int);
		int getElemento(int);
		bool cheia();
		int buscar(int);
		int tamanho();
		void print();
		void limpar();
};
#endif
