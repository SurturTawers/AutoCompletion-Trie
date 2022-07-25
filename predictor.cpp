#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iterator>
#include <algorithm>
#include "predictor.h"
#include "Trie.h"
using namespace std;
predictor::predictor(){
	trie = new Trie();
	srand((unsigned)time(NULL));
}
predictor::~predictor(){
		delete trie;
}
void predictor::guardarDiccionario(string palabraDic){
	trie->insert(palabraDic,rand()%1001);
}
void predictor::guardarDicc(string palabraDic){
	this->guardarDiccionario(palabraDic);
}
void predictor::predict(string pref,int frec,vector<palabraConFrec> &res){
	vector<string> answers;
	string prefMod=pref;
	vector<int> f;
   	trie->search(prefMod,answers,f);

		while(answers.size()<frec){
			if(prefMod.size()==1)break;

			answers.clear();
   		f.clear();
   		prefMod.pop_back();
   		trie->search(prefMod,answers,f);
   	}
	for(int i = 0; i < answers.size(); ++i){
		res.push_back({answers.at(i),f.at(i)});
   	}
    sort(res.begin(), res.end(), [](palabraConFrec a, palabraConFrec b){
    	if(a.frequency!=b.frequency) return a.frequency > b.frequency;
    	else return a.word <  b.word;
    });
    string actualizar;
		// si hay más de las que necesito las saco
    if(res.size()>frec){
    	int cont=res.size()-frec;
    	for(int i=res.size();cont!=0;i--){
    		res.pop_back();
    		cont--;
    	}
    }

    for(int i=0;i<res.size() && i<frec;i++){
    	actualizar=res.at(i).word;
    	trie->actualizar(actualizar);
    }
    answers.clear();
    f.clear();
}
void predictor::predecir(string pref,int frec,vector<palabraConFrec> &res ){
	this->predict(pref,frec,res);
}
double predictor::getEspacio(){
  return trie->getEspacio();
}
