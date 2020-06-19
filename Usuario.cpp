#include "Usuario.h"

Usuario::Usuario(string pNombre,string pNombre_usuario,string pContrasena)
{
	nombre = pNombre;
	nombre_usuario = pNombre_usuario;
	contrasena = pContrasena;
}

string Usuario::getNombre(){
	return nombre;
}

string Usuario::getNombreUsuario(){
	return nombre_usuario;
}

string Usuario::getContrasena(){
	return contrasena;
}

vector<Usuario*> Usuario::getUsuariosSeguidos(){
	return usuarios_seguidos;
}

void Usuario::agregarUsuario_Seguido(Usuario* pUsuario){
	usuarios_seguidos.push_back(pUsuario);
}

vector<Post*> Usuario::getPosts(){
	return lista_posts;
}

void Usuario::agregarPost(Post* pPost){
	lista_posts.push_back(pPost);
}
