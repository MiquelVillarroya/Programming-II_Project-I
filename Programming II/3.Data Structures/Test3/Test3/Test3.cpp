
#include "Ex1.h"
#include "Ex2.h"
#include "UnitTest.h"

#include <iostream>

using namespace std;

void TestEx1();
void TestEx2();
int main()
{
	TestEx1();
	
	//for(int i = 0; i < 100; ++i)
	TestEx2();
	

	//Test Queue
	/*
	DynamicQueue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.Print();

	q.enqueue(6);
	q.Print();

	q.enqueue(7);
	q.enqueue(8);
	q.Print();

	q.enqueue(9);
	q.enqueue(10);
	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	q.Print();
	*/
	//End
}

void TestEx1() {
#if defined(TEST_EX_1)
	{
		int array[12] = { 1,3,5,7,23,65,23,99,5,34,73,15 };
		DynamicQueue queue;
		for (unsigned int i = 0; i < 12; ++i) {
			queue.enqueue(array[i]);
		}
		const bool capacityOk = queue.capacity() == 15;
		bool valuesOk = true;
		for (unsigned int i = 0; i < 12; ++i) {
			valuesOk = valuesOk && (array[i] == queue.front());
			queue.dequeue();
		}
		TEST("Ex1: DynamicQueue::increaseCapacity()", capacityOk && valuesOk);
	}
#else
	TEST("Ex1: Uncomment #define TEST_EX_1 in Ex1.h to perform the test", false);
#endif
}

void TestEx2() {
#if defined(TEST_EX2)
	srand(time(NULL));
	Waypoint* wp = new Waypoint();
	wp = Insert(wp, 0);


	int val = rand() % 100;
	SetEndPoint(wp, 0, val);

	int key = -1;
	GetAccessKey(wp, key);
	

	bool res1 = val == key;
	TEST(": Exercise 2: Find key recursion ", res1);


#else
	TEST("Ex2: Uncomment #define TEST_EX_2 in Ex2.h to perform the test", false);
#endif
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
