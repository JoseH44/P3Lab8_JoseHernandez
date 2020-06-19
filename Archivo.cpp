#include "Archivo.h"

Archivo::Archivo(string pFileName)
{
	fileName = pFileName;
}

bool Archivo::guardarUsuario(Usuario* pUsuario){
	if(outputFile.is_open()){
		outputFile << pUsuario->getNombre() <<',' << pUsuario->getNombreUsuario()
			<<';'<<pUsuario->getContrasena() <<',';
		for(int i = 0;i < pUsuario->getPosts().size();i++){
			outputFile << pUsuario->getPosts()[i]->getTitulo() << ','
				<<pUsuario->getPosts()[i]->getContenido()<< ',' << pUsuario->getPosts()[i]->getNumeroLikes() << ','
				<<pUsuario->getPosts()[i]->getNumeroHates()<<"\n";
		}
		return true;
	}else
		return false;
}


bool Archivo::abrirEscritura(int pModo){
	modoEscritura = pModo;
	modoEscritura = pModo;
	if(modoEscritura == 1)
		outputFile.open(fileName.c_str(), std::ios::app);
	else
		outputFile.open(fileName.c_str());
		
	return outputFile.is_open();
}

bool Archivo::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}

bool Archivo::abrirLectura(){
	inputFile.open(fileName.c_str(),std::ios::in);
	return true;
}

bool Archivo::cerrarLectura(){
	inputFile.close();
	return !inputFile.is_open();
}

vector<Usuario*> Archivo::getListaUsuarios(){
	return lista_usuarios;
}

void Archivo::leerUsuarios(){
	lista_usuarios.clear();
	while(!inputFile.eof()){
		string nombre, usuario, contrasena,titulo,contenido,numeroLikes,numeroHates;
		int likes,hates;
		
		string buffer;
		getline(inputFile,buffer);
		
		stringstream myStream;
		myStream << buffer;
		
		
		//substring desde la primera coma hasta el final
		getline(myStream,nombre,',');
		buffer = buffer.substr(buffer.find(","),buffer.size());
		myStream << buffer;
		
		getline(myStream,usuario,',');
		buffer = buffer.substr(buffer.find(","),buffer.size());
		myStream << buffer;
		
		getline(myStream,contrasena,',');
		buffer = buffer.substr(buffer.find(","),buffer.size());
		myStream << buffer;
		
		Usuario* usuario_temporal = NULL;
		usuario_temporal = new Usuario(nombre,usuario,contrasena);
		//while de la subcadena restante que solo contiene los posts
		while(!buffer.size() == 0){
			getline(myStream,titulo,',');
			buffer = buffer.substr(buffer.find(","),buffer.size());
			myStream << buffer;
			
			getline(myStream,contenido,',');
			buffer = buffer.substr(buffer.find(","),buffer.size());
			myStream << buffer;
			
			getline(myStream,numeroLikes,',');
			buffer = buffer.substr(buffer.find(","),buffer.size());
			myStream << buffer;
			
			getline(myStream,numeroHates,',');
			buffer = buffer.substr(buffer.find(","),buffer.size());
			myStream << buffer;
			
			stringstream myStream2(numeroLikes);
			myStream2 >> likes;
			
			stringstream myStream3(numeroLikes);
			myStream3 >> hates;
			
			Post* post_temporal = new Post(titulo,contenido,likes,hates);
			usuario_temporal->agregarPost(post_temporal);
			
			
		}//fin del while
		lista_usuarios.push_back(usuario_temporal);
	}
}


Archivo::~Archivo()
{
}
