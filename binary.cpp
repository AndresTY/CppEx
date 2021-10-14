/*
 * =====================================================================================
 *
 *       Filename:  binary.cpp
 *
 *    Description: binary to int  
 *
 *        Version:  1.0
 *        Created:  03/24/21 17:14:03
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (), andres.ducuara01@correo.usa.edu.co
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string r){
	string temp;
	for( int i=r.size(); i>=0;i--){
		temp+=r[i];
	}
	return temp;
}

string binary(int n){
	string r;
	while(n>0){
		r+= (n%2 == 0 ? "0":"1");
		n/=2;
	}
	return reverse(r);
}

int main(){
	double a;
	cout<<"digit number: ";
	cin>>a;
	cout<<"number: "<<a<<" binary: "<<binary(a)<<endl;
	return 0;
}
