#ifndef USUARIO_H
#define USUARIO_H

#include "Post.h"

#include <iostream>
using namespace std;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Archivo;

class Usuario
{
	protected:
		string nombre;
		string nombre_usuario;
		string contrasena;
		vector<Usuario*> usuarios_seguidos;
		vector<Post*> lista_posts;
	public:
		Usuario(string,string,string);
		string getNombre();
		string getNombreUsuario();
		string getContrasena();
		vector<Usuario*> getUsuariosSeguidos();
		void agregarUsuario_Seguido(Usuario*);
		void eliminarUsuario(int);
		
		vector<Post*> getPosts();
		void agregarPost(Post*);
		
		
	
	friend class Archivo;
	
};

#endif
