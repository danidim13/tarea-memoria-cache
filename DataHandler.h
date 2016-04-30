#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include <string>
#include <fstream>

class DataHandler{
	public:
		DataHandler();
		~DataHandler();
		unsigned long get_dir();
		std::ifstream datos;
		std::string linea;
		unsigned long dir_dec;
	};

#endif
