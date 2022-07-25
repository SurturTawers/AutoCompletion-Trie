#ifndef predictor_H
#define predictor_H

#include <vector>
#include <string>
#include "Trie.h"

using namespace std;
typedef struct  {
	  string word;
		int frequency;
}palabraConFrec;

class predictor{
	public:
		predictor();
		~predictor();
		void guardarDicc(string palabraDic);
		void predecir(string pref,int frec,vector<palabraConFrec> &res);
		double getEspacio();
	private:
		Trie* trie;
		void guardarDiccionario(string palabraDic);
		void predict(string pref,int frec,vector<palabraConFrec> &res);
};
#endif
