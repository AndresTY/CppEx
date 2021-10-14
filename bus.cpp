/*
 * =====================================================================================
 *
 *       Filename:  bus.cpp
 *
 *    Description: hacer un sistema que saque las personas de un bus hacia dos torniquetes que solo admiten de a 3 personas.
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

queue<int> bus;
stack<int> torn1;
stack<int> torn2;

void fillB() {
  int a;
  cout << "cuantas personas entran\n";
  cin >> a;
  for (int i = 0; i < a; i++) {
    bus.push(1);
  }
}

void fillT() {
  if (!bus.empty()) {
    if (torn1.size() < 3) {
      torn1.push(1);
      bus.pop();
    } else if (torn2.size() < 3) {
      torn2.push(1);
      bus.pop();
    } else {
      cout << "estimado, estan llenos los torniqetes\n";
    }
  } else {
    cout << "el bus esta vacia" << endl;
  }
}

void pay(int n) {
  switch (n) {
  case 1:
    if (!torn1.empty()) {
      torn1.pop();
    } else {
      cout << "esta sola\n";
    }
    break;
  case 2:
    if (!torn2.empty()) {
      torn2.pop();
    } else {
      cout << "esta sola\n";
    }
    break;
  default:
    cout << "esta torniquete no existe\n";
    break;
  }
}

void start() {
  bool open = true;
  do {
    int a;
    cout << "STATUS\n"
         << " Cola: " << bus.size() <<"\n"
	 << "torn1" << torn1.size()<<"\n"
	 << "torn2" << torn2.size()<<endl;
    cout << " 1. lleanr bus\n 2. lleanr torniquete \n 3. Sacar torniquete\n *. cerrar\n";
    cin >> a;
    switch (a) {
    case 1:
      fillB();
      break;
    case 2:
      fillT();
      break;
    case 3:
      int n;
      cout << "que torniquete sale?\n";
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
