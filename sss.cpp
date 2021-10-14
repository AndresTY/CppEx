/*
 * =====================================================================================
 *
 *       Filename:  sss.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/11/21 12:53:41
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
#include <regex>
using namespace std;

int main(){
	regex str_expr2 ("\"(.*)|(.*)\"");
    regex str_expr ("([A-Za-z]+|[0-9]+[^.?/&%^$#@!~`,+-<>]?)");
    string a1 = "hola";
    string a2 = "123gola";

    if (regex_match (a1,str_expr2)){
        cout << "matched\n";
    }else{
        cout<<"haf";
    }
}
