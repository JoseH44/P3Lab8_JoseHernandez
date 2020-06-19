#include "Comentario.h"

Comentario::Comentario(string pNombreCreador,string pContenido)
{
	nombreCreador = pNombreCreador;
	contenido1 = pContenido;
}


string Comentario::getNombreCreador(){
	return nombreCreador;
}

string Comentario::getContenido(){
	return contenido1;
}

Comentario::~Comentario()
{
}
