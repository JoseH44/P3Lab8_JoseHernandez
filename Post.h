#ifndef POST_H
#define POST_H

#include <iostream>
using namespace std;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Comentario.h"

class Archivo;

class Post
{
	protected:
		string titulo;
		string contenido;
		int numero_likes;
		int numero_hates;
		vector<Comentario*> lista_comentarios;
		
	public:
		Post(string,string,int,int);
		void setAnadirComentario(Comentario*);
		string getTitulo();
		string getContenido();
		int getNumeroLikes();
		void setNumeroLikes();
		int getNumeroHates();
		void setNumeroHates();
		vector<Comentario*> getComentarios();
		
		~Post();
		
	friend class Archivo;
	
};

#endif
