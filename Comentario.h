#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>
using namespace std;

#include <string>
using std::string;

class Archivo;

class Comentario
{
	protected:
		string nombreCreador;
		string contenido1;
	public:
		Comentario(string,string);
		string getNombreCreador();
		string getContenido();
		~Comentario();
		
	friend class Archivo;
	
};

#endif
