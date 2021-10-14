/*
 * =====================================================================================
 *
 *       Filename:  decimal.cpp
 *
 *    Description: binary to decimal 
 *
 *        Version:  1.0
 *        Created:  03/24/21 17:41:26
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (), andres.ducuara01@correo.usa.edu.co
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double decimal(string n){
	double dec = 0;
	for(int i= n.size(); i>=0;i--){
		dec += (n[i]=='1'? 1 : 0 )*(pow(2,i));
	}
	return dec;
}

int main(){
	string a;
	cout<<"digit binary: ";
	cin>>a;
	cout<<decimal(a)<<endl;
	return 0;
}
