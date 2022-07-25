#include <iostream>
#include <string>

#include "Trie.h"
using namespace std;
Trie::Trie(){
  Raiz = createNodo('*');
}
Trie::~Trie(){
  destroyNodo(Raiz); // destruir nodos en preorden
}
void Trie::destroyNodo(Nodo* nodo){
  Nodo* iter=nodo;
  for(int i=0;i<26;i++){
    if(iter->children[i]!=NULL){
      destroyNodo(iter->children[i]);
    }
  }
  free(iter);
}
void Trie::insert(Nodo *raiz, string word,int counter,int frequency){
  if(counter < word.length()){
    int idletter = word[counter] - 'a';
    if(!raiz->children[idletter]){

      raiz->children[idletter] = createNodo(word[counter]);
     // cout << "insertado!"<<raiz->children[idletter]->letter<<'\n' << '\n';

      if(word.length()==counter + 1){
        raiz->children[idletter]->isTheEnd = true;
        raiz->children[idletter]->frequency = frequency;
      }
      counter++;
      insert(raiz->children[idletter],word,counter,frequency);
    } else {
      counter++;
      insert(raiz->children[idletter],word,counter,frequency);
    }
  }
}

void Trie::insert(string word,int frequency){
  insert(Raiz,word,0,frequency);
}
Nodo* Trie::createNodo(char letter){
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->isTheEnd = false;
    nuevoNodo->letter = letter;
    for(int i = 0; i < 26; ++i)nuevoNodo->children[i] = NULL;
    espacio++;
    return nuevoNodo;
}
void Trie::searching(Nodo *nodo,vector<string> *answers,vector<int> *f,string pref){
  if(nodo->isTheEnd==true){
    //GUARDO LA PALABRA EN EL VECTOR DE RESULTADOS
    answers->push_back(pref);
    f->push_back(nodo->frequency);
  }
  //BUSCA TODAS LAS LETRAS QUE HAY DESDE EL PREFIJO EN ADELANTE
  for(int i=0;i<26;i++){
    if(nodo->children[i]!=NULL){
      pref.push_back(nodo->children[i]->letter);
      searching(nodo->children[i],answers,f,pref);
      pref.pop_back();
    }
  }
}

void Trie::search(string pref,vector<string> &answers,vector<int> &f ){
  int counter = 0;
  Nodo* iter = Raiz;
  while(counter < pref.length()){
    int lettercode = pref[counter] -  'a';
    if(!iter->children[lettercode])break;
      else{
      counter++;
      iter = iter->children[lettercode];
    }
  }
  if(counter == pref.length()){
    searching(iter,&answers,&f,pref);
  }
}


void Trie::actualizar(Nodo* nodo,string uptd,int counter){
  int lettercode = uptd[counter] - 'a';
      if(nodo->children[lettercode]->isTheEnd && counter +1 == uptd.length()){
  			nodo->children[lettercode]->frequency++;
  		} else {
        counter++;
  			nodo = nodo->children[lettercode];
  			actualizar(nodo,uptd,counter);
      }
}
void Trie::actualizar(string uptd){
  actualizar(Raiz,uptd,0);
}
double Trie::getEspacio(){
  return espacio=((double)espacio*sizeof(Nodo))/1000000;
}
