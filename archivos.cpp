/*
 * =====================================================================================
 *
 *       Filename:  archivos.cpp
 *
 *    Description: manejos de archivos con c y c++
 *
 *        Version:  1.0
 *        Created:  04/13/21 11:22:37
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (), andres.ducuara01@correo.usa.edu.co
 *   Organization:  
 *
 * =====================================================================================
 */

#include <fstream>
#include <iostream>

using namespace std;

int salario;
string name;
string lastname;

string recibe;
//ofstream archivo;
ifstream archivo;

int main(){
	archivo.open("datos.txt");
	
	if(archivo.fail()){
		cout<<"malangas";
		exit(0);
	}else{
		while(!archivo.eof()){
			archivo>>recibe;
			cout<<"data: "<<recibe<<endl;
		}
	}
/***
for(int i=0; i<=3;i++){;
		cout<<"name"<<endl;
		cin>>name;
		cout<<"lastname"<<endl;
		cin>>lastname;
		cout<<"salary"<<endl;
		cin>>salario;

		archivo << name<<"|\t "<<lastname<<"|\t"<<salario<<"|\n";
		cout<<"saved data"<<endl;
	}
**/
}
