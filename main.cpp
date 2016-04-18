#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include "CacheMemory.h"

using namespace std;


void welcome();
bool checkArg(int, char*[]);

int main(int argc, char* argv[]){

	welcome();
	
	if(!checkArg(argc, argv))
		return 1;
	
	int parametros[3];
	parametros[0]= std::stoi(argv[1]);
	parametros[1]= std::stoi(argv[2]);
	parametros[2]= std::stoi(argv[3]);
	CacheMemory memoria(parametros[0], parametros[1], parametros[2]);
	memoria.print();

	cout << "fin del programa" << endl;
	return 0;
}

void welcome(){
	//string mensaje;
	//string integrantes;
	cout << "Bienvenido a este programa!\n"
		 << "Simulador de una memoria cache\n"
		 << "Hecho por Daniel Diaz y Fletso\n"
		 << endl;
	
}

bool checkArg(int argc, char* argv[] ){
	if(argc != 4){
		cerr << "Error de argumentos, uso:\n"
			 << "\t " << argv[0] << " <asociatividad> <tamano del cache> <tamano del bloque>"
			 << endl;
		return false;
	}
	return true;
	
}



#endif
