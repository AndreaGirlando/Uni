// 10.11
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char numero[10];
	unsigned positivi=0, negativi=0;
	fstream file("numeri.txt", ios::in);
	while(file >> numero) 
		if (*numero == '-') negativi++;
		else positivi++;
	cout << "Positivi: " << positivi << endl;
	cout << "Negativi: " << negativi << endl;
	file.close();
	return 0;
}
