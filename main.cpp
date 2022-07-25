#include <iostream>
#include <ctime>
#include "controladora.h"
using namespace std;
int main(int argc, char const *argv[]){
	controladora* cont;
	int reps=99,lineas;
	double espacio;
	double tiempo=0;
	if(argc!=5){

		cerr<<"Numero de argumentos incorrecto"<<endl;
		exit(1);
	}else{
		//CALCULO EL TIEMPO QUE SE DEMORA EN HACER TODAS LAS INSERCIONES
		//"REPS" VECES
		clock_t start;
		for(int i=0;i<reps;i++){
			cont=new controladora();
			start=clock();
			lineas = cont->leerDicc(argv[1]);
			tiempo+=((double)clock()-start)/CLOCKS_PER_SEC;
			delete cont;
		}
		cont=new controladora();
		start=clock();
		lineas = cont->leerDicc(argv[1]);
		tiempo+=((double)clock()-start)/CLOCKS_PER_SEC;
		reps+=1;
		//CALCULO EL TIEMPO PROMEDIO DE UNA INSERCION
		tiempo=(tiempo/(double)reps);
		cout<<"Tiempo promedio de insercion para "<<lineas<<" palabras:\n"<<tiempo<<endl;
		tiempo=(tiempo/(double)lineas);
		cout<<"Tiempo promedio de insercion de una palabra para "<<lineas<<" palabras:\n"<<tiempo<<endl;
		//ESCRIBO LOS RESULTADOS DE LAS PREDICCIONES
		cont->escribirRes(argv[2],argv[3],argv[4]);
		espacio=cont->getEspacio();
	  	cout<<"El espacio ocupado por el trie es de: "<<espacio<<" MegaBytes"<<endl;
		delete cont;
	}
	return 0;
}
