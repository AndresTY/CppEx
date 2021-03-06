/*
 * =====================================================================================
 *
 *       Filename:  intro.cpp
 *
 *    Description: introduccion a cpp
 *
 *        Version:  1.0
 *        Created:  02/02/2021 11:21:09 AM
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (),
 * andres.ducuara01@correo.usa.edu.co Organization:
 *
 * =====================================================================================
 */

#include <cctype>
#include <iostream>

using namespace std;

void suma() {
  int a = 0, b = 0, c = 0;
  cout << "ingrese un primer valos" << endl;
  cin >> a;
  cout << "segundo valor" << endl;
  cin >> b;
  c = a + b;
  cout << "resultado es:" << c << endl;
}

void pointers() {
  int a = 234;
  int *p_a;
  cout << "direccion a " << &a << endl;
  cout << "direccion p_a " << &p_a << endl;
  p_a = &a;
  cout << "contenido p_a " << *p_a << endl;
  cin >> *p_a;
  cout << "contenido p_a " << *p_a << endl;
  cout << "contenido a " << a << endl;
}

double temp;
double *temp_;
void converter(char a_, char b_) {
  if (tolower(a_) == 'c' && tolower(b_) == 'f') {
    *temp_ = (temp * 9 / 5) + 32;
  }
  if (tolower(a_) == 'f' && tolower(b_) == 'c') {
    *temp_ = (temp - 32) * 5 / 9;
  }
  if (tolower(a_) == 'c' && tolower(b_) == 'k') {
    *temp_ = temp + 273.15;
  }
  if (tolower(a_) == 'k' && tolower(b_) == 'c') {
    *temp_ = temp - 273.15;
  }
  if (tolower(a_) == 'f' && tolower(b_) == 'k') {
    *temp_ = ((temp - 32) * 5 / 9) + 273.15;
  }
  if (tolower(a_) == 'k' && tolower(b_) == 'f') {
    *temp_ = ((temp - 273.15) * 9 / 5) + 32;
  }
}

int main() {
  char a, b;
  temp_ = &temp;
  // suma();
  // pointers();
  cout << "digite temp to temp" << endl;
  cin >> a >> b;
  cout << "digite la temperatura" << endl;
  cin >> *temp_;
  converter(a, b);
  cout << *temp_ << endl;

  return 0;
}
