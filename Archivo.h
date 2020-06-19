#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "Usuario.h"
#include "Post.h"
#include "Comentario.h"

#include <iostream>
using namespace std;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <sstream>
using std::stringstream;

class Archivo
{	
	protected:	
		string fileName;
		ofstream outputFile;
		ifstream inputFile;
		int modoEscritura;
		vector<Usuario*> lista_usuarios;
	public:
		Archivo(string);
		bool guardarUsuario(Usuario*);
		bool abrirEscritura(int);
		bool cerrarEscritura();
		bool abrirLectura();
		bool cerrarLectura();
		vector<Usuario*> getListaUsuarios();
		void leerUsuarios();
		~Archivo();
	
};

#endif
