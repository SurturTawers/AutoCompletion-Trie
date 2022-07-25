#ifndef controladora_H
#define controladora_H

#include <vector>
#include <string>
#include <fstream>
#include "predictor.h"
using namespace std;
class controladora{
	public:
		controladora();
		~controladora();
		int leerDicc(string NomDicc);
		void escribirRes(string NomBusq, string NomRes, string frec);
		double getEspacio();
	private:
		//LECTORES
		ifstream lecDic,lecBusq;
		//ESCRITOR
		ofstream escRes;
		//Variables
		vector <palabraConFrec> resultados;
		predictor* predic;
		int frecuencia;
		//METODOS

		int leerDiccionario(string NomDicc);
		void escribirResultados(string NomBusq, string NomRes, string frec);
};
#endif
