#ifndef Trie_H
#define Trie_H

typedef struct Nodo {
	Nodo *children[26];
	char letter;
	int frequency;
	bool isTheEnd;
}Nodo;
#include <vector>
class Trie{
	private:
		//Variables
		struct Nodo *Raiz;
		double espacio=0;
		//Funciones
		void destroyNodo(Nodo*);
		void insert(Nodo*,std::string,int,int);
		void searching(Nodo *,std::vector<std::string> *,std::vector<int> *,std::string);
		Nodo* createNodo(char);
		void  actualizar(Nodo*,std::string,int);
	public:
		Trie();
		~Trie();
		void insert(std::string,int);
		void search(std::string,std::vector<std::string> &,std::vector<int> &);
		void actualizar(std::string);
		double getEspacio();
};
#endif
