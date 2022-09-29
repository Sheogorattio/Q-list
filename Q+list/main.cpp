#include <iostream>
#include "Q.h"
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	Q<int> obj;
	for (int i = 0; i < 4; i++) {
		obj.add(rand() % 15 + 5);
	}
	obj.print();
	Q<int> obj2;
	obj.clone(obj2);
	cout << "\n\n------------------------------------\n";
	obj2.print();
}