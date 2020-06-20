#include <iostream>
using namespace std;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Usuario.h"
#include "Post.h"
#include "Comentario.h"
#include "Archivo.h"



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	vector<Usuario*> usuarios;
	int posicionUsuario,posicionUsuario2,posicion_comentario,posicion_like,posicion_hate;
	
	int opcion;
	
	Usuario* usuarioRegistrado = NULL;
	Post* postCreado = NULL;
	Comentario* comentarioCreado = NULL;
	Archivo* archivoUsuarios = new Archivo("usuarios.txt");
	
	archivoUsuarios->abrirLectura();
	archivoUsuarios->leerUsuarios();//carga el vector de archivos con los usuarios del archivo de texto
	//llena el vector global de usuarios con los contenidos en el vector de archivos
	for(int i = 0;i < archivoUsuarios->getListaUsuarios().size();i++){
		usuarios.push_back(archivoUsuarios->getListaUsuarios()[i]);
	}
	archivoUsuarios->cerrarLectura();
	
	cout<<"---BIENVENIDO A MUCGRAM---" <<endl<< "1.Registrarse"<<endl
		<<"2.Ingresar"<<endl<<"3.Salir"<<endl<<"Ingrese la opcion:";
	cin >> opcion;
	
	switch(opcion){
		case 1:{
			int subMenu = 0;
			string name,user,pass;
			cout<<endl<<"Ingrese su Nombre: ";
			cin >> name;
			cout<<endl<<"Ingrese su Nombre de Usuario: ";
			cin >> user;
			cout<<endl<<"Ingrese su Contrasena: ";
			cin >> pass;
			cout<<endl<<"REGISTRADO EXITOSAMENTE";
			
			usuarioRegistrado = new Usuario(name,user,pass);
			usuarios.push_back(usuarioRegistrado);
			
			for(int i = 0;i < usuarios.size();i++){
				if(name == usuarios[i]->getNombre() && pass == usuarios[i]->getContrasena()){
					posicionUsuario = i;
					break;
				}
				
			}
			
			
			
			while(subMenu != 7){
				cout<<endl<<endl<<"1.Crear Post"<<endl<<"2.Comentar Post"<<endl<<"3.Dar Like"<<endl
					<<"4.Dar Hate"<<endl<<"5.Seguir Usuario"<<endl<<"6.Dejar de Seguir a un Usuario"<<endl
					<<"7.Salir de la Aplicacion"<<endl<<"Ingrese la Opcion:";
				cin >> subMenu;
				
				switch(subMenu){
					case 1:{
						string titulo,contenido;
						
						cout <<endl<<"Ingrese el Titulo del Post:";
						cin >> titulo;
						cout <<endl<<"Ingrese el Contenido del Post:";
						cin >> contenido;
						postCreado = new Post(titulo,contenido,0,0);
						
						usuarios[posicionUsuario]->agregarPost(postCreado);
						
						cout<<endl<<"POST CREADO EXITOSAMENTE!"<<endl;
						postCreado = NULL;
						break;
					}
					case 2:{
						string nombreCreador, contenidoComen;
						cout<<endl;
						for(int i = 0;i < usuarios.size();i++){
							cout<<i<<"- Posts de: "<< usuarios[i]->getNombre()<<endl<<endl;//nombre de la persona del comentario
							for(int j = 0;j < usuarios[i]->getPosts().size();i++){
								cout<<"#"<<j<<":"<<endl<<"["<<usuarios[i]->getPosts()[j]->getTitulo()<<"]"<<endl
									<<"/"<<usuarios[i]->getPosts()[j]->getContenido()<<"/"<<endl
									<<"(Likes:"<<usuarios[i]->getPosts()[j]->getNumeroLikes()<<") "<<"(Hates:"<<usuarios[i]->getPosts()[j]->getNumeroHates()<<")"
									<<endl;
								cout<<"COMENTARIOS---->"<<endl<<"# De: "<<j<<endl;
								for(int h = 0;h < usuarios[i]->getPosts()[j]->getComentarios().size();i++){
									cout<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getNombreCreador()<<endl
									<<"|"<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getContenido()<<"|"<<endl;
								}//fin del for de los comentarios
							}//fin del for de los posts
						}//fin del for de los usuarios
						
						cout<<endl<<"Ingrese la Posicion del Usuario al que le comentara:";
						cin >> posicionUsuario2;
						cout<<endl<<"Ingrese la Posicion del Post al que le comentara:";
						cin >> posicion_comentario;
						
						cout<<endl<<"Ingrese el Contenido del Comentario:";
						cin >> contenidoComen;
						
						nombreCreador = usuarios[posicionUsuario]->getNombre();
						comentarioCreado = new Comentario(nombreCreador,contenidoComen);
						
						usuarios[posicionUsuario2]->getPosts()[posicion_comentario]->setAnadirComentario(comentarioCreado);
						
						cout<<endl<<"COMENTARIO REALIZADO EXITOSAMENTE";
						comentarioCreado = NULL;
						
						break;
					}
					case 3:{
						
						cout<<endl;
						for(int i = 0;i < usuarios.size();i++){
							cout<<i<<"- Posts de: "<< usuarios[i]->getNombre()<<endl<<endl;//nombre de la persona del comentario
							for(int j = 0;j < usuarios[i]->getPosts().size();i++){
								cout<<"#"<<j<<":"<<endl<<"["<<usuarios[i]->getPosts()[j]->getTitulo()<<"]"<<endl
									<<"/"<<usuarios[i]->getPosts()[j]->getContenido()<<"/"<<endl
									<<"(Likes:"<<usuarios[i]->getPosts()[j]->getNumeroLikes()<<") "<<"(Hates:"<<usuarios[i]->getPosts()[j]->getNumeroHates()<<")"
									<<endl;
								cout<<"COMENTARIOS---->"<<endl<<"# De: "<<j<<endl;
								for(int h = 0;h < usuarios[i]->getPosts()[j]->getComentarios().size();i++){
									cout<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getNombreCreador()<<endl
									<<"|"<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getContenido()<<"|"<<endl;
								}//fin del for de los comentarios
							}//fin del for de los posts
						}//fin del for de los usuarios
						
						cout<<endl<<"Ingrese la Posicion del Usuario al que le dara Like:";
						cin >> posicionUsuario2;
						cout<<endl<<"Ingrese la Posicion del Post al que le Dara Like:";
						cin >> posicion_like;
						usuarios[posicionUsuario2]->getPosts()[posicion_like]->setNumeroLikes();
						
						cout<<endl<<"LIKE REALIZADO EXITOSAMENTE";
						
						break;
					}
					case 4:{
						cout<<endl;
						for(int i = 0;i < usuarios.size();i++){
							cout<<i<<"- Posts de: "<< usuarios[i]->getNombre()<<endl<<endl;//nombre de la persona del comentario
							for(int j = 0;j < usuarios[i]->getPosts().size();i++){
								cout<<"#"<<j<<":"<<endl<<"["<<usuarios[i]->getPosts()[j]->getTitulo()<<"]"<<endl
									<<"/"<<usuarios[i]->getPosts()[j]->getContenido()<<"/"<<endl
									<<"(Likes:"<<usuarios[i]->getPosts()[j]->getNumeroLikes()<<") "<<"(Hates:"<<usuarios[i]->getPosts()[j]->getNumeroHates()<<")"
									<<endl;
								cout<<"COMENTARIOS---->"<<endl<<"# De: "<<j<<endl;
								for(int h = 0;h < usuarios[i]->getPosts()[j]->getComentarios().size();i++){
									cout<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getNombreCreador()<<endl
									<<"|"<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getContenido()<<"|"<<endl;
								}//fin del for de los comentarios
							}//fin del for de los posts
						}//fin del for de los usuarios
						
						cout<<endl<<"Ingrese la Posicion del Usuario al que le Dara Hate:";
						cin >> posicionUsuario2;
						cout<<endl<<"Ingrese la Posicion del Post al que le Dara Hate:";
						cin >> posicion_hate;
						usuarios[posicionUsuario2]->getPosts()[posicion_hate]->setNumeroHates();
						
						cout<<endl<<"HATE REALIZADO EXITOSAMENTE";
						break;
					}
					case 5:{
						cout<<endl<<"-----USUARIOS-----";
						for(int i = 0;i<usuarios.size();i++){
							if(i == posicionUsuario){
							}else{
								cout<<i<<"-"<<usuarios[i]->getNombre()<<endl;
							}
						}
						
						cout<<endl<<"Ingrese La posicion del usuario al que Seguira:";
						cin >> posicionUsuario2;
						
						usuarios[posicionUsuario]->agregarUsuario_Seguido(usuarios[posicionUsuario2]);
						
						cout<<endl<<"USUARIO SEGUIDO EXITOSAMENTE";
						break;
					}
					case 6:{
						cout<<endl<<"-----USUARIOS-----";
						for(int i = 0;i<usuarios.size();i++){
							if(i == posicionUsuario){
							}else{
								cout<<i<<"-"<<usuarios[i]->getNombre()<<endl;
							}
						}
						
						cout<<endl<<"Ingrese La posicion del usuario al que dejara de Seguir:";
						cin >> posicionUsuario2;
						
						usuarios[posicionUsuario]->eliminarUsuario(posicionUsuario2);
						
						cout<<endl<<"DEJO DE SEGUIR AL USUARIO EXITOSAMENTE";
						break;
						break;
					}
				}//fin del switch de opcion 1 de submenu
			
			
			}//fin del while de opcion 1 de submenu
			
			
			break;
		}
		case 2:{
			int subMenu = 0;
			string user,pass;
			
			cout<<endl<<"Ingrese su Nombre de Usuario: ";
			cin >> user;
			cout<<endl<<"Ingrese su Contrasena: ";
			cin >> pass;
			for(int i = 0;i < usuarios.size();i++){
				if(user == usuarios[i]->getNombreUsuario() && pass == usuarios[i]->getContrasena()){
					posicionUsuario = i;
					break;
				}
				
			}
			cout<<endl<<"LOGIN EXITOSAMENTE";
			
			
			
			for(int i = 0;i < usuarios[posicionUsuario]->getUsuariosSeguidos().size();i++){
				cout<<i<<"- Posts de: "<< usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getNombre()<<endl<<endl;//nombre de la persona del comentario
				for(int j = 0;j < usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getPosts().size();i++){
					cout<<"#"<<j<<":"<<endl<<"["<<usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getPosts()[j]->getTitulo()<<"]"<<endl
						<<"/"<<usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getPosts()[j]->getContenido()<<"/"<<endl
						<<"(Likes:"<<usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getPosts()[j]->getNumeroLikes()<<") "<<"(Hates:"<<usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getPosts()[j]->getNumeroHates()<<")"
						<<endl;
					cout<<"COMENTARIOS---->"<<endl<<"# De: "<<j<<endl;
					for(int h = 0;h < usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getPosts()[j]->getComentarios().size();i++){
						cout<<usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getPosts()[j]->getComentarios()[h]->getNombreCreador()<<endl
							<<"|"<<usuarios[posicionUsuario]->getUsuariosSeguidos()[i]->getPosts()[j]->getComentarios()[h]->getContenido()<<"|"<<endl;
					}//fin del for de los comentarios
				}//fin del for de los posts
			}//fin del for de los usuarios
			
			
			
			while(subMenu != 7){
				cout<<endl<<endl<<"1.Crear Post"<<endl<<"2.Comentar Post"<<endl<<"3.Dar Like"<<endl
					<<"4.Dar Hate"<<endl<<"5.Seguir Usuario"<<endl<<"6.Dejar de Seguir a un Usuario"<<endl
					<<"7.Salir de la Aplicacion"<<endl<<"Ingrese la Opcion:";
				cin >> subMenu;
				
				switch(subMenu){
					case 1:{
						string titulo,contenido;
						
						cout <<endl<<"Ingrese el Titulo del Post:";
						cin >> titulo;
						cout <<endl<<"Ingrese el Contenido del Post:";
						cin >> contenido;
						postCreado = new Post(titulo,contenido,0,0);
						
						usuarios[posicionUsuario]->agregarPost(postCreado);
						
						cout<<endl<<"POST CREADO EXITOSAMENTE!"<<endl;
						postCreado = NULL;
						break;
					}
					case 2:{
						string nombreCreador, contenidoComen;
						cout<<endl;
						for(int i = 0;i < usuarios.size();i++){
							cout<<i<<"- Posts de: "<< usuarios[i]->getNombre()<<endl<<endl;//nombre de la persona del comentario
							for(int j = 0;j < usuarios[i]->getPosts().size();i++){
								cout<<"#"<<j<<":"<<endl<<"["<<usuarios[i]->getPosts()[j]->getTitulo()<<"]"<<endl
									<<"/"<<usuarios[i]->getPosts()[j]->getContenido()<<"/"<<endl
									<<"(Likes:"<<usuarios[i]->getPosts()[j]->getNumeroLikes()<<") "<<"(Hates:"<<usuarios[i]->getPosts()[j]->getNumeroHates()<<")"
									<<endl;
								cout<<"COMENTARIOS---->"<<endl<<"# De: "<<j<<endl;
								for(int h = 0;h < usuarios[i]->getPosts()[j]->getComentarios().size();i++){
									cout<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getNombreCreador()<<endl
									<<"|"<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getContenido()<<"|"<<endl;
								}//fin del for de los comentarios
							}//fin del for de los posts
						}//fin del for de los usuarios
						
						cout<<endl<<"Ingrese la Posicion del Usuario al que le comentara:";
						cin >> posicionUsuario2;
						cout<<endl<<"Ingrese la Posicion del Post al que le comentara:";
						cin >> posicion_comentario;
						
						cout<<endl<<"Ingrese el Contenido del Comentario:";
						cin >> contenidoComen;
						
						nombreCreador = usuarios[posicionUsuario]->getNombre();
						comentarioCreado = new Comentario(nombreCreador,contenidoComen);
						
						usuarios[posicionUsuario2]->getPosts()[posicion_comentario]->setAnadirComentario(comentarioCreado);
						
						cout<<endl<<"COMENTARIO REALIZADO EXITOSAMENTE";
						comentarioCreado = NULL;
						
						break;
					}
					case 3:{
						
						cout<<endl;
						for(int i = 0;i < usuarios.size();i++){
							cout<<i<<"- Posts de: "<< usuarios[i]->getNombre()<<endl<<endl;//nombre de la persona del comentario
							for(int j = 0;j < usuarios[i]->getPosts().size();i++){
								cout<<"#"<<j<<":"<<endl<<"["<<usuarios[i]->getPosts()[j]->getTitulo()<<"]"<<endl
									<<"/"<<usuarios[i]->getPosts()[j]->getContenido()<<"/"<<endl
									<<"(Likes:"<<usuarios[i]->getPosts()[j]->getNumeroLikes()<<") "<<"(Hates:"<<usuarios[i]->getPosts()[j]->getNumeroHates()<<")"
									<<endl;
								cout<<"COMENTARIOS---->"<<endl<<"# De: "<<j<<endl;
								for(int h = 0;h < usuarios[i]->getPosts()[j]->getComentarios().size();i++){
									cout<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getNombreCreador()<<endl
									<<"|"<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getContenido()<<"|"<<endl;
								}//fin del for de los comentarios
							}//fin del for de los posts
						}//fin del for de los usuarios
						
						cout<<endl<<"Ingrese la Posicion del Usuario al que le dara Like:";
						cin >> posicionUsuario2;
						cout<<endl<<"Ingrese la Posicion del Post al que le Dara Like:";
						cin >> posicion_like;
						usuarios[posicionUsuario2]->getPosts()[posicion_like]->setNumeroLikes();
						
						cout<<endl<<"LIKE REALIZADO EXITOSAMENTE";
						
						break;
					}
					case 4:{
						cout<<endl;
						for(int i = 0;i < usuarios.size();i++){
							cout<<i<<"- Posts de: "<< usuarios[i]->getNombre()<<endl<<endl;//nombre de la persona del comentario
							for(int j = 0;j < usuarios[i]->getPosts().size();i++){
								cout<<"#"<<j<<":"<<endl<<"["<<usuarios[i]->getPosts()[j]->getTitulo()<<"]"<<endl
									<<"/"<<usuarios[i]->getPosts()[j]->getContenido()<<"/"<<endl
									<<"(Likes:"<<usuarios[i]->getPosts()[j]->getNumeroLikes()<<") "<<"(Hates:"<<usuarios[i]->getPosts()[j]->getNumeroHates()<<")"
									<<endl;
								cout<<"COMENTARIOS---->"<<endl<<"# De: "<<j<<endl;
								for(int h = 0;h < usuarios[i]->getPosts()[j]->getComentarios().size();i++){
									cout<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getNombreCreador()<<endl
									<<"|"<<usuarios[i]->getPosts()[j]->getComentarios()[h]->getContenido()<<"|"<<endl;
								}//fin del for de los comentarios
							}//fin del for de los posts
						}//fin del for de los usuarios
						
						cout<<endl<<"Ingrese la Posicion del Usuario al que le Dara Hate:";
						cin >> posicionUsuario2;
						cout<<endl<<"Ingrese la Posicion del Post al que le Dara Hate:";
						cin >> posicion_hate;
						usuarios[posicionUsuario2]->getPosts()[posicion_hate]->setNumeroHates();
						
						cout<<endl<<"HATE REALIZADO EXITOSAMENTE";
						break;
					}
					case 5:{
						cout<<endl<<"-----USUARIOS-----";
						for(int i = 0;i<usuarios.size();i++){
							if(i == posicionUsuario){
							}else{
								cout<<i<<"-"<<usuarios[i]->getNombre()<<endl;
							}
						}
						
						cout<<endl<<"Ingrese La posicion del usuario al que Seguira:";
						cin >> posicionUsuario2;
						
						usuarios[posicionUsuario]->agregarUsuario_Seguido(usuarios[posicionUsuario2]);
						
						cout<<endl<<"USUARIO SEGUIDO EXITOSAMENTE";
						break;
					}
					case 6:{
						cout<<endl<<"-----USUARIOS-----";
						for(int i = 0;i<usuarios.size();i++){
							if(i == posicionUsuario){
							}else{
								cout<<i<<"-"<<usuarios[i]->getNombre()<<endl;
							}
						}
						
						cout<<endl<<"Ingrese La posicion del usuario al que dejara de Seguir:";
						cin >> posicionUsuario2;
						
						usuarios[posicionUsuario]->eliminarUsuario(posicionUsuario2);
						
						cout<<endl<<"DEJO DE SEGUIR AL USUARIO EXITOSAMENTE";
						break;
						break;
					}
				}//fin del switch de opcion 1 de submenu
			
			
			}//fin del while de opcion 1 de submenu
			
			break;
		}
		case 3:{
			cout <<endl<<"HASTA LA PROXIMA!";
			break;
		}
	}//fin del switch principal
	
	archivoUsuarios->abrirEscritura(0);
	for(int i = 0;i<usuarios.size();i++){
		archivoUsuarios->guardarUsuario(usuarios[i]);
	}
	archivoUsuarios->cerrarEscritura();
	
	delete archivoUsuarios;
	delete usuarioRegistrado; 
	delete comentarioCreado;
	delete postCreado;
	return 0;
}
