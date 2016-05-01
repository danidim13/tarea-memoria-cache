#include "DataHandler.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

DataHandler::DataHandler()
	: datos ("aligned.trace"){
}

DataHandler::~DataHandler(){
}

unsigned long DataHandler::get_dir(){
	//Obtiene una dirección (una línea del archivo)
	getline(datos, linea);
	//Deja solo la dirección y borra el resto
	linea.erase(linea.begin()+8,linea.end());
	//Convierte la dirección a decimal
	std::istringstream(linea) >> std::hex >> dir_dec;
	return dir_dec;
}

