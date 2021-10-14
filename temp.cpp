#include <iostream>
#include <stack>
using namespace std;

string name;
char name2 [20];

void parte1(){
	cout<<"nombre: ";
	cin.getline(name2,20,'\n');
	cout<<name2<<endl;
}

void parent(string parentesis){
	stack<int> pila;

	for(int i=0; i<parentesis.length();i++){
		if(parentesis[i]=='('){
			pila.push(1);
		}else if(parentesis[i]==')' && !pila.empty()){
			pila.pop();
		}else{
			char temp = parentesis[i];
			parentesis[i] = '_';
			cout<<"error: "<<temp<<" of "<<parentesis <<"  systax error"<<endl;
		}
	}
	if(!pila.empty()){
		cout<<"Error "<<parentesis<<"_"<<" sintax error"; 
	}

}

string splitted(string a){
	string temp="";
	for(int i=0;i<a.length();i++){
		if(!isspace(a[i])){
			temp+=a[i];
		}
	}
	return temp;
}

void eq(string eq_pre, string new_eq){
	if(eq_pre.length()==new_eq.length()){
		for(int i=0; i<eq_pre.length();i++){
			if(isalpha(new_eq[i])&&isalpha(eq_pre[i])){
				new_eq[i] = eq_pre[i];
			}
		}
		cout<<eq_pre<<" "<<new_eq<<endl;
		if(eq_pre==new_eq) cout<<"coinciden"<<endl;
		else cout<<"no match"<<endl;
	}else{
		cout<<eq_pre<<" "<<new_eq<<endl;
		cout<<"no match"<<endl;
	}

}

int main(){
	cout<<"cadena: ";
	getline(cin,name);

	//parent(name);
	eq("b=a+1",splitted(name));
	eq("f=c+b+h/2",splitted(name));
	return 0;
}
