#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include "CacheMemory.h"
#include "DataHandler.h"

using namespace std;

void welcome();
bool checkArg(int, char*[], int[]);

int main(int argc, char* argv[]){

	welcome();

	// Revision de argumentos, si hay errores el programa termina y retorna 1
	int parametros[3];
	if(!checkArg(argc, argv, parametros))
		return 1;

	CacheMemory memoria(parametros[0], parametros[1], parametros[2]);
	memoria.print();

	DataHandler datH;
	//datH.get_dir();

	cout << "fin del programa" << endl;
	return 0;
}

void welcome(){
	//string mensaje;
	//string integrantes;
	cout << "Bienvenido a este programa!\n"
		 << "Simulador de una memoria cache\n"
		 << "Hecho por Daniel Diaz y Gabriel Jimenez\n"
		 << endl;

}

bool checkArg(int argc, char* argv[], int parametros[]){
	if(argc != 4){
		cerr << "Error de argumentos, uso:\n"
			 << "\t " << argv[0] << " <asociatividad> <tamano del cache> <tamano del bloque>"
			 << endl;
		return false;
	}
	parametros[0]= std::stoi(argv[1]);
	parametros[1]= std::stoi(argv[2]);
	parametros[2]= std::stoi(argv[3]);
	return true;

}



#endif
