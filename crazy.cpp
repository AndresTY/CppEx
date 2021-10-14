#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int size=0;
vector<int> v;

void push(int x){
	v.push_back(x);	
}

void pop(){
	if(!v.empty()){
		v.pop_back();
	}
}

int top(){
	return v.back();
}
bool esta(int x){
	bool t=false;
	for( auto& a: v){
		if(a==x){
			return t=true;
		}
	}
	return t;
}
void change(){
	int temp,aux;
	vector<int> x;
	cout<<"numero viejo: "<<endl;
	cin>>temp;
	cout<<"numero nuevo: "<<endl;
	cin>>aux;
	if(esta(temp)){
		for(int i=0;i<v.size();i++){
			if(v[i]==temp){
				v[i]=aux;
			}
		}
	}else{
		cout<<"no esta el numero"<<endl;
	}

}

void print(){
	cout<<"=======PILA=========="<<endl;

	for (int i=v.size()-1; i>=0;i--){
    		cout<<v[i]<<"<-";
	}
	cout<<endl;
}

int main(){
	int a;
	bool t = true;
	do{
	cout<<" 1. push \n 2. top \n 3. pop\n 4. size\n 5.change \n 6.print\n * exit"<<endl;
	cin>>a;
	switch(a){
		case 1:
			int temp;
			cout<<"numero: "<<endl;
			cin>>temp;
			push(temp);
			break;
		case 2:
			cout<<"el top es: "<<top()<<endl;
			break;
		case 3: 
			pop();
			break;
		case 4:
			cout<<"size: "<<v.size()<<endl;
			break;
		case 5:
			change();
			break;
		case 6:
			print();
			break;
		default:
			t=false;
			break;
	}
	}while(t);		

	return 0;
}
