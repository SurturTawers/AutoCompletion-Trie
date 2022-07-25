#include "controladora.h"
#include "predictor.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

controladora::controladora(){
	predic= new predictor();
	srand((unsigned)time(NULL));
	//this->leerDiccionario(NomDicc);
	//this->escribirResultados(NomBusq,NomRes,frec);
}
controladora::~controladora(){
	delete predic;
}
int controladora::leerDiccionario(string NomDicc){
	string palabraDic;
	int lineas=0;
	lecDic.open(NomDicc);
	if(!lecDic){
		cerr<<"No se pudo leer el diccionario";
		exit(1);
	}
	//SE ABRE EL ARCHIVO DE DICCIONARIO Y SE LEE
	//ENVIANDO LAS PALABRAS AL PREDICTOR
	while(getline(lecDic,palabraDic)){
		lineas++;
		predic->guardarDicc(palabraDic);
	}
	lecDic.close();
	return lineas;
}
int controladora::leerDicc(string NomDicc){
	return (leerDiccionario(NomDicc));
}
void controladora::escribirResultados(string NomBusq, string NomRes, string frec){
	string pref;
	lecBusq.open(NomBusq);
	if(!lecBusq){
		cerr<<"No se pudo leer el archivo de busqueda";
		exit(1);
	}
	escRes.open(NomRes);

	for(int i=0; i<frec.size(); i++){
		if(frec[i] >'9' || frec[i]<'0'){
			cerr<< "debe ingresar un numero";
			exit(1);
		}
	}
	std::cout << "que paso" << '\n';
	frecuencia = stoi(frec);
	//LEE LOS PREFIJOS, LOS ENVIA AL PREDICTOR
	//LUEGO ESCRIBE LOS RESULTADOS
	while(getline(lecBusq,pref)){
		predic->predecir(pref,frecuencia,resultados);
		escRes<<pref+": ";
		if(resultados.size()==0){
			escRes<<"Ninguna palabra de nuestro diccionario comienza con este prefijo";
		}else{
			for(vector<palabraConFrec>::iterator it=resultados.begin();it != resultados.end() ;it++){
				escRes<<'<'+it->word +' '+ to_string(it->frequency)+'>'+' ';
			}
		}
		escRes<<'\n'<<endl;
		resultados.clear();
	}
	escRes.close();
}
void controladora::escribirRes(string NomBusq, string NomRes, string frec){
	escribirResultados(NomBusq,NomRes,frec);
}
double controladora::getEspacio(){
	return predic->getEspacio();
}
