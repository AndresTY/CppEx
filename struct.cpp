/*
 * =====================================================================================
 *
 *       Filename:  struct.cpp
 *
 *    Description: resumen de estructuras
 *
 *        Version:  1.0
 *        Created:  02/04/2021 11:26:26 AM
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Andres Santiago Ducuara Velasquez (),
 * andres.ducuara01@correo.usa.edu.co Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

stack<int> stack1;

//===========================STACKS=============================
void llenarS() {
  stack1.push(1);
  stack1.push(2);
  stack1.push(3);
  stack1.push(4);
  stack1.push(5);
}

void removeS() {
  if (!stack1.empty()) {
    cout << "sale: " << stack1.top() << endl;
    stack1.pop();
  } else {
    cout << "no hay que sacar" << endl;
  }
}

void showS() {
  stack<int> temp = stack1;
  cout << "STACK: ";
  while (!temp.empty()) {
    cout << temp.top();
    temp.pop();
  }
  cout << endl;
}

string vacio() { return stack1.empty() ? "vacia" : "no vacio"; }

void pila() {
  llenarS();
  showS();
  removeS();
  removeS();
  cout << "estado de la pila: " << vacio() << endl;
}
//=============================QUEUE=============================

queue<int> queue1;

void llenarQ() {
  queue1.push(1);
  queue1.push(2);
  queue1.push(3);
  queue1.push(4);
  queue1.push(5);
}

void showQ() {
  queue<int> temp = queue1;
  cout << "QUEUE: ";
  while (!temp.empty()) {
    cout << temp.front();
    temp.pop();
  }
  cout << endl;
}

void remove() {}

void cola() {
  llenarQ();
  showQ();
}

int main() {
  // pila();
  cola();

  return 0;
}
