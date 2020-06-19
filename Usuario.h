#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Usuario
{
	protected:
		string nombre;
		string nombre_usuario;
		string contrasena;
		vector<Usuario*> usuarios_seguidos;
	public:
		Usuario(string,string,string);
		string getNombre();
		string getNombreUsuario();
		string getContrasena();
		vector<Usuario*> getUsuariosSeguidos();
		void agregarUsuario_Seguido(Usuario*);
	
};

#endif
