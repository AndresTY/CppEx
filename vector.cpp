/*
 * =====================================================================================
 *
 *       Filename:  vector.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/02/2021 12:40:58 PM
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (),
 * andres.ducuara01@correo.usa.edu.co Organization:
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int a[10] = {};
int *a_;

void fill() {
  int arrSize = *(&a + 1) - a;
  for (int i = 0; i < arrSize; i++) {
    cout << "digit number" << endl;
    cin >> *a_++;
  }
  a_ = &a[0];
}

void show() {
  for (int i = 0; i < 10; i++) {
    cout << *a_++ << endl;
  }
}

int main() {
  a_ = &a[0];
  fill();
  show();
  return 0;
}
