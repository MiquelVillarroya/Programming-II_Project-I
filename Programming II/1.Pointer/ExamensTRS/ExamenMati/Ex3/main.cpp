#include <iostream>
using namespace std;

struct Empleat {
	string nom;
	string cognom;
	int edat;
	int salari;
};

void printData(Empleat* empleats, int size) {
	for (int i = 0; i < size; ++i) {
		cout << " -- Empleat " << i + 1<< " -- " << endl;
		cout << "Nom: " << empleats[i].nom << endl;
		cout << "Cognom: " << empleats[i].cognom << endl;
		cout << "Edat: " << empleats[i].edat << endl;
		cout << "Salari: " << empleats[i].salari << endl;
		cout << endl;
	}
	cout << endl;
}

void salariMitja(Empleat* empleats, int size) {
	
	int mitja = 0;
	int i = 0;
	for (i = 0; i < size; ++i) {
		mitja += empleats[i].salari;
	}
	mitja /= i;
	cout << "Salari mitja: " << mitja << endl;
	cout << endl;
}

void printEmpleat(Empleat* empleats, int i) {
	cout << " -- Empleat " << i + 1<< " -- " << endl;
	cout << "Nom: " << empleats[i].nom << endl;
	cout << "Cognom: " << empleats[i].cognom << endl;
	cout << "Edat: " << empleats[i].edat << endl;
	cout << "Salari: " << empleats[i].salari << endl;
	cout << endl;
}

void salariAlt(Empleat* empleats, int size) {

	int idx = 0;
	for (int i = 1; i < size; ++i) {
		if (empleats[i].salari > empleats[idx].salari) idx = i;
	}
	printEmpleat(empleats, idx);
}

void salariDescend(Empleat* empleats, int size) {
	
	int* salaris = new int[size];

	for (int i = 0; i < size; ++i) {
		salaris[i] = empleats[i].salari;
	}

	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (salaris[i] < salaris[j]) {
				int aux = salaris[i];
				salaris[i] = salaris[j];
				salaris[j] = aux;
			}
		}
	}

	for (int i = 0; i < size; ++i) {
		cout << "Salari nre. " << i + 1 << ": ";
		cout << salaris[i] << endl;
	}
	cout << endl;
	delete[] salaris;
}

int main() {
	int size;
	cout << "Introdueixi nre d'empleats: ";
	cin >> size;
	Empleat* empleats = new Empleat[size];
	for (int i = 0; i < size; ++i) {
		cout << "Introdueixi nom d'empleat nre. " << i + 1 << ": ";
		cin >> empleats[i].nom;
		cout << "Introdueixi cognom d'empleat nre. " << i + 1 << ": ";
		cin >> empleats[i].cognom;
		cout << "Introdueixi edat d'empleat nre. " << i + 1 << ": ";
		cin >> empleats[i].edat;
		cout << "Introdueixi salari d'empleat nre. " << i + 1 << ": ";
		cin >> empleats[i].salari;
		cout << endl;
	}

	char funcio = 'Q';
	while (funcio != 'P') {
		cout << "Funcions:" << endl;
		cout << " - A: Mostrar les dades de tots els empleats" << endl;
		cout << " - S: Mostrar el salari mitjà" << endl;
		cout << " - D: Mostrar les dades del empleat més ben pagat" << endl;
		cout << " - F: Mostrar tots els salaris en ordre descendent" << endl;
		cout << " - P: Parar el programa" << endl;
		cin >> funcio;

		switch (funcio) {
		case('A'):
			printData(empleats, size);
			break;

		case('S'):
			salariMitja(empleats, size);
			break;

		case('D'):
			salariAlt(empleats, size);
			break;

		case('F'):
			salariDescend(empleats, size);
			break;
		}
	}

	delete[] empleats;

	return 0;
}