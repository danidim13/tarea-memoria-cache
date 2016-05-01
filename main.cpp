#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "CacheMemory.h"
#include "CacheMemory.cpp"
#include "DataHandler.h"
#include "DataHandler.cpp"

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

	ifstream datos("aligned.trace");
	string linea;
	unsigned long dir_dec;
	int x;

//	while ( getline (datos,linea) ) {
	while ( x <= 10) {
		//Obtiene una dirección (una línea del archivo)
		getline(datos, linea);
		//Deja solo la dirección y borra el resto
		linea.erase(linea.begin()+8,linea.end());
		//Convierte la dirección a decimal
		std::istringstream(linea) >> std::hex >> dir_dec;
		memoria.split(dir_dec);
		memoria.print();
		x = x+1;
	}

	//DataHandler datH;
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
	parametros[0]= atoi(argv[1]);
	parametros[1]= atoi(argv[2]);
	parametros[2]= atoi(argv[3]);
	return true;

}



#endif
