/*
 * =====================================================================================
 *
 *       Filename:  nodes.cpp
 *
 *    Description: nodos repaso 
 *
 *        Version:  1.0
 *        Created:  03/09/21 11:52:18
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (), andres.ducuara01@correo.usa.edu.co
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

//nodo creation
struct nodo{
	double dato;
	nodo *izq;
	nodo *der;
};

nodo *crearnodos(double d){
	nodo *nnodo = new nodo();
	nnodo->dato=d;
	nnodo->izq=NULL;
	nnodo->der=NULL;
	return nnodo;
}

//varaibles
nodo *arbol = NULL;
int n=0,acc=0, peso=0;
double addss=0;
bool perfectoo=true;


//functions
void insertar(nodo *&arbol, double d){
	if(arbol==NULL){
		nodo *nnodo = crearnodos(d);
		arbol = nnodo;

	}else{
		int d1 = arbol->dato;
		if(d<d1){
			insertar(arbol->der,d);

		}else{
			insertar(arbol->izq,d);
		}
	}
}

void mostrar(nodo *&arbol, double d){
	string temp = "";

	if(arbol==NULL){
		return;
	}
     	mostrar(arbol->der, n+1);
	
     	for(int i=0; i<n; i++){
		temp+="\t";
	}
     	cout<< temp<<arbol->dato <<endl;

     	mostrar(arbol->izq, n+1);
}

void def(nodo *&arbol, double d, char type){
	if(type=='a'){
		if(arbol!=NULL){
     			def(arbol->der, n+1,'a');
			addss+=arbol->dato;
     			acc++;
			def(arbol->izq, n+1,'a');
		}
	}else if (type=='w'){
		if(arbol!=NULL){
     			def(arbol->der, n+1,'w');
     			peso++;
			def(arbol->izq, n+1,'w');
		}
	}
}

void pre(nodo *arbol){
     if(arbol==NULL){
	     return;
     }else{
          cout << arbol->dato <<" ";
          pre(arbol->izq);
          pre(arbol->der);
     }
}

int nivel(nodo *temp){
    int a,b;
    if(temp== NULL){
	    return 0;
    }else{
    	if (temp->izq == NULL && temp->der == NULL){
        	 return 1;
    	}else{
        	a= nivel(temp->izq);
        	b= nivel(temp->der);
        	if (a<b) return b+1;
        	else return a+1;
	}
    }     
}

void perfect(nodo *aux){
	if(aux!=NULL){
		if((aux->izq==NULL && aux->der) || (aux->der==NULL && aux->izq)){
			perfectoo=false;
		}
		perfect(aux->izq);
		perfect(aux->der);

	}
}
void inO(nodo *arbol){
     if(arbol==NULL){
	     return;
     }else{
          inO(arbol->izq);
          cout << arbol->dato << " ";
          inO(arbol->der);
     }
}

void post(nodo *arbol){
     if(arbol==NULL){
	     return;
     }else{
          post(arbol->izq);
          post(arbol->der);
          cout << arbol->dato << " ";
     }
}

void menu(){
	int opt;
	bool t=true;
	do{
		cout<<"============MENU=========="<<endl;
		cout<<" 1.insertar \n 2.mostrar \n 3.postorden \n 4. inorden \n 5.preorden \n 6.sumar \n 7.niveles \n 8.peso \n 9.perfecto \n 10.salir"<<endl;
		cin>>opt;
		switch(opt){
			case 1:
				cout<<"=======Insert======"<<endl;
				double d;
				cout<<"dato a entrar:"<<endl;
				cin>>d;
				insertar(arbol,d);
				break;
			case 2:
				cout<<"=====show======"<<endl;
				mostrar(arbol,0);
				break;
			case 3:
				cout<<"======Post========"<<endl;
				post(arbol);
     				cout<<"\n";
				break;
			case 4: 
				cout<<"======Inorden====="<<endl;
				inO(arbol);
				cout<<"\n";
				break;

			case 5:
				cout<<"======preorden======"<<endl;
				pre(arbol);
     				cout<<"\n";
				break;
			case 6:
				cout<<"====promedio=== \n";
				def(arbol,0,'a');
				cout<<"promedio "<<double(addss/acc)<<endl;
				break;
			case 7:
				cout<<"nivel"<<nivel(arbol)<<endl;
				break;
			case 8:
				def(arbol,0,'w');
				cout<<"peso"<<peso<<endl;
				break;
			case 9:
				perfect(arbol);
				cout<<"1 es si, 0 es no";
				cout<<perfectoo<<endl;
				break;
			case 10:
				t=false;
				break;
			default: 
				cout<<"nada prro"<<endl;
				break;

		}
	}while(t);
}

int main(){
	menu();
	return 0;
}
