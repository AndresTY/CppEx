/*
 * =====================================================================================
 *
 *       Filename:  tienda.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/04/2021 12:26:02 PM
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

queue<int> cola;
stack<int> fila1;
stack<int> fila2;
stack<int> fila3;

void fillC() {
  int a;
  cout << "cuantas personas entran\n";
  cin >> a;
  for (int i = 0; i < a; i++) {
    cola.push(1);
  }
}

void fillF() {
  if (!cola.empty()) {
    if (fila1.size() < 3) {
      fila1.push(1);
      cola.pop();
    } else if (fila2.size() < 3) {
      fila2.push(1);
      cola.pop();
    } else if (fila3.size() < 3) {
      fila3.push(1);
      cola.pop();
    } else {
      cout << "estimado, estan llenas las cajas\n";
    }
  } else {
    cout << "la cola esta vacia" << endl;
  }
}

void pay(int n) {
  switch (n) {
  case 1:
    if (!fila1.empty()) {
      fila1.pop();
    } else {
      cout << "esta sola\n";
    }
    break;
  case 2:
    if (!fila2.empty()) {
      fila2.pop();
    } else {
      cout << "esta sola\n";
    }
    break;
  case 3:
    if (!fila3.empty()) {
      fila3.pop();
    } else {
      cout << "esta sola\n";
    }
    break;
  default:
    cout << "esta caja no existe\n";
    break;
  }
}

void start() {
  bool open = true;
  do {
    int a;
    cout << "STATUS\n"
         << " Cola: " << cola.size() << endl;
    cout << " caja 1: " << fila1.size() << endl;
    cout << " caja 2: " << fila2.size() << endl;
    cout << " caja 3: " << fila3.size() << endl;
    cout << " 1. lleanr cola\n 2. lleanr cajas \n 3. Sacar caja\n *. cerrar\n";
    cin >> a;
    switch (a) {
    case 1:
      fillC();
      break;
    case 2:
      fillF();
      break;
    case 3:
      int n;
      cout << "que caja sale?\n";
      cin >> n;
      pay(n);
      break;
    default:
      open = false;
    }
  } while (open);
}

int main() {
  start();
  return 0;
}
