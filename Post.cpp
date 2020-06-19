#include "Post.h"

Post::Post(string pTitulo,string pContenido,int pLikes,int pHates)
{
	titulo = pTitulo;
	contenido = pContenido;
	numero_likes = pLikes;
	numero_hates = pHates;
	
}

string Post::getTitulo(){
	return titulo;
}

string Post::getContenido(){
	return contenido;
}

int Post::getNumeroLikes(){
	return numero_likes;
}

void Post::setNumeroLikes(){
	numero_likes++;
}

int Post::getNumeroHates(){
	return numero_hates;
}

void Post::setNumeroHates(){
	numero_hates++;
}

vector<Comentario*> Post::getComentarios(){
	return lista_comentarios;
}

void Post::setAnadirComentario(Comentario* pComentario){
	lista_comentarios.push_back(pComentario);
}

Post::~Post()
{
}
