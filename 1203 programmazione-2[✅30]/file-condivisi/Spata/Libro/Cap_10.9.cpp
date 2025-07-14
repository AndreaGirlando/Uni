// 10.9
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	char c;
	char linea[80];
	char nuovo[80];
	cout << "Che numero devo inserire? ";
	cin.getline(nuovo,80);
	fstream file("telefono.txt", ios::in | ios::out);
	fstream temp("appoggio.txt", ios::in | ios::out);
	while(file.getline(linea,80) && (strcmp(linea,nuovo)<0))
		temp << linea << endl;
	temp << nuovo << endl;
	temp << linea << endl;
	while(file.getline(linea,80))
		temp << linea << endl;
	file.close();
	temp.close();
	file.open("telefono.txt", ios::out);
	temp.open("appoggio.txt", ios::in);
	while(temp.get(c)) file.put(c);
	file.close();
	temp.close();
	return 0;
}
