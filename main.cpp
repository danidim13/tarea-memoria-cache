#ifndef MAIN_H
#include <iostream>
#include <string>
#define MAIN_H

using namespace std;


void welcome();
bool checkArg(int, char*[]);

int main(int argc, char* argv[]){

	welcome();
	
	if(!checkArg(argc, argv))
		return 1;
	
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
bool checkArg(int argc, char* argv[] ){
	if(argc != 4){
		cout << "Error de argumentos, uso:\n"
			 << "\t " << argv[0] << " <asociatividad> <tamano del cache> <tamano del bloque>"
			 << endl;
		return false;
	}
	
}



#endif
