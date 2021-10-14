/*
 * =====================================================================================
 *
 *       Filename:  encrip.cpp
 *
 *    Description: parcial II 
 *
 *        Version:  1.0
 *        Created:  04/13/21 17:52:03
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (), andres.ducuara01@correo.usa.edu.co
 *   Organization:  Universidad Sergio Arboleda 
 *
 * =====================================================================================
 */

// import libraries
#include <fstream> // open and close files
#include <iostream> // outputs and inputs 
#include <string.h> // strings functions
#include <map>

using namespace std;

void start();
void perfil();
void menuLogin();
string user;
string passwd;
typedef map<char,char> kwy;
string tabc = "abcdefghijklmnopqrstuvwxyz_,/-=+.1234567890[]ABCDEFGHIJKLMNOPQRSTVWXYZ";
string tepp = "ZqweMrtyuiop[]asOBdfg123I45N67h8Lj9kl0AzxCcvGbnm,./<>_J-!@E#YXF?&D*()K";
/**
 * encrip and desencrip with matrixn_aux[k][i]*a[i][j]
 *
void desencrip(string n){
	const int a [3][3]={{2,1,0},{1,1,0},{0,0,1}};
	int count =0;
	int out = 0;
	int x = int(n[n.length()-1])-48;
	int aux[x];
	int n_aux[sizeof(aux)/3][3];
	n[n.length()-1]=' ';
	cout<<x<<endl;
	string str="";
	vector<int> temAx;

	for( int i=0;i<n.length()-1;i++){
		if(isdigit(n[i])){
			str+=to_string(n[i]-48);
		}
		if(n[i]=='.'){
			aux[count]=atoi(str.c_str());
			str="";n_aux[k][i]*a[i][j]
			count++;
		}
		if(count==x){
			break;
		}
	}

	for(auto& re: aux){
		cout<<re<<endl;
	}

	memcpy(&n_aux,&aux,sizeof(int));
	for(int k=0; k<sizeof(aux)/3; k++){
		for(int i=0; i<3;i++){
			out=0;
			for(int j=0; j< 3;j++){
				out+=n_aux[k][i]*a[i][j];
			}
			temAx.push_back(out);
		}
	}
	for( auto& re: temAx){
		cout<<re<<endl;
	}
}

string encrip(string n){
	const int a [3][3]={{1,-1,0},{-1,2,0},{0,0,1}};
	int out=0;
	string retturn = "[";
	int temp[n.length()];
	int n_temp[sizeof(temp)/3][3];

	vector<int> aux;

	for(int i=0; i< n.length();i++){
		temp[i]=int(n[i]);
	}

	memcpy(&n_temp,&temp,sizeof(int)*10);
	for(int k=0; k<sizeof(temp)/3; k++){
		for(int i=0; i<3;i++){
			out=0;
			for(int j=0; j< 3;j++){
				out+=n_temp[k][i]*a[i][j];
			}
			cout<<out;
			aux.push_back(out);
		}
	}

	for(auto& re: aux){
		retturn+=to_string(re)+".";
	}
	retturn+="]"+to_string(n.length());

	return retturn;

}
***/

string desencrip(string n,bool palabras=false){
	string temp;
	bool valid=false;
	kwy m;
	string str="";

	for(int i=0;i<tepp.length();i++){
		m[tabc[i]] = tepp[i];	
	}

	if(!palabras){
		for( auto& t: n){
			if(valid==true){
				str += m[t];
			}
			if(t==','){
				valid=true;
			}
		}
	}else{
		for( auto& t: n){
			str += m[t];
		}

	}
	return str;
}

string encrip(string n){

	kwy m;
	string str="";

	for(int i=0;i<tepp.length();i++){
		m[tepp[i]] = tabc[i];	
	}

	for( auto& t: n){
		str += m[t];
	}
	return str;

}

void _register(){
	string sTemp;
	string kwy;
	ofstream fs;
	string tempp;
	bool valid = false;
	fs.open("Users.txt",fstream::in | fstream::out | fstream::app);
	do{
		cout<<"==============================\n\tREGISTRO\n==============================\n";
		valid=false;
		cout<<"User:\t";
		cin>>user;
		cout<<"Password:\t";
		cin>>passwd;
		tempp = encrip(passwd);
		if(!fs.fail()){
			if(passwd.length()<=12){
				fs<<user<<","<<tempp<<"\n";
				valid=true;
			}else{
				cout<<"passwd no valida, debe ser menor a 12"<<endl;
			}
		}else{
			cout<<"Error No Se Puedo Abrir El Archivo"<<endl;
		}
	}while(valid!=true);
	fs.close();
}
string splitt(string n){
	string str="";
	for(auto& a:n){
		if(a==','){
			break;
		}
		str+=a;
	}
	return str;
}
void captura(){
	string str;
	ofstream archivo;

	archivo.open("Captura.txt");
	cout<<"==============================\n\tCAPTURA\n==============================\n";
	for(int i=0; i<=4;i++){
		cout<<"cadena: \t";
		cin>>str;
		archivo <<encrip(str)<<"\n";
	}
	cout<<"\nsaved data"<<endl;
	archivo.close();
	menuLogin();
}

void show(){
	string str;
	ifstream archivo;
	archivo.open("Captura.txt");
	if(!archivo.fail()){
		while(!archivo.eof()){
			archivo>>str;
			cout<<"==============================\n\tDATA\n==============================\n";
			cout<<"->\t"<<desencrip(str,true)<<endl;
		}
	}
	archivo.close();
	menuLogin();
}

void perfil(){
	fstream archivo;
	string usr;
	string pwd;
	string temp;
	archivo.open("Users.txt");
	if(!archivo.fail()){
		while(!archivo.eof()){
			archivo>>temp;
			usr = splitt(temp);
			pwd = desencrip(temp);
			cout<<"================User=================="<<endl;
			cout<<"User:"<<usr<<"\nPasswd:"<<pwd<<endl;
		}
	}

}

void menuLogin(){
	bool t = false;
	int op;
	do{
	cout<<"==============================\n\tMENU\n==============================\n";
	cout<<"1.capturar o resest datos\n2.mostrar datos guardos\n3.mostar perfil"<<endl;
	cin>>op;
	switch(op){
		case 1:
			captura();
			break;
		case 2:
			show();
			break;
		case 3:
			perfil();
			break;
		case 4:
			start();
			break;
		default: 
			t=true;
			break;
	}
	}while(t==false);
	
}

void login(){

	fstream fst;
	string sTemp;
	string u;
	string tempu;
	string p;
	bool valid = false;
	cout<<"==============================\n\tLOGIN\n==============================\n";
		cout<<"User:\t";
		cin>>u;
		cout<<"Password:\t";
		cin>>p;
		fst.open("Users.txt");
		if(!fst.fail()){
			while(!fst.eof()){
				fst>>sTemp;
				tempu = splitt(sTemp);
				if(u==tempu && p==desencrip(sTemp)){
					cout<<"usuario correcto"<<endl;
					menuLogin();
				}else{
					cout<<u<<" "<<tempu<<"/n"<<p<<" "<<desencrip(sTemp)<<endl;
				}
			}
		}
}

void start(){
	bool t= false;
	do{
	int op;
	cout<<"==============================\n\tINICIO\n==============================\n";
	cout<<"1.register\n2.login\n3.salir"<<endl;
	cin>> op;
	switch(op){
		case 1:
			_register();
			break;
		case 2:
			login();
			break;
		case 3:
			exit(0);
			break;
		default: 
			break;

	}
	}while(t==false);
}
int main(){
	start();
	return 0;

}
