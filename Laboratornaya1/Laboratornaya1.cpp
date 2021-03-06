// Laboratornaya1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Complex.h"
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <thread>
#include <chrono>


using namespace std;

void nagruz(int number)
{
	int xx = 0;
	int *arr = new int[number];
	int *arr2 = new int[number];
	int z = 0; 

	for (int i = 0; i < number; i++) {
		arr[i] = rand()% number;
		arr2[i] = rand() % number;
	}

	for (int i = 0; i < number; i++) {
		
		z += arr[i] + arr2[i];
		xx++;
	}
	
	cout << z <<"\n";
}

void nagruz2(int number2)
{
	int xxx = 0;
	int *arr3 = new int[number2];
	int *arr4 = new int[number2];
	int zz = 0;

	for (int i = 0; i < number2; i++) {
		arr3[i] = 1;
		arr4[i] = 2;
	}

	for (int i = 0; i < number2; i++) {

		zz += arr3[i] + arr4[i];
		xxx++;
	}

	cout << zz << "\n";
}



int main()
{

	setlocale(LC_ALL, "Russian");
	

	int n = 10000000;

	// singleproс

	auto begin = std::chrono::steady_clock::now();

	nagruz(n);
	nagruz2(n);
	


	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "Время, затраченное однопоточной реализацией равно : " << elapsed_ms.count() << " ms\n";


// multiproc   

	cout << "\n";

	auto begin2 = std::chrono::steady_clock::now();

	thread t1 = thread(nagruz, n);
	thread t2 = thread(nagruz2, n);


	t1.join();
	t2.join();


	
	auto end2 = std::chrono::steady_clock::now();
	auto elapsed_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2 );
	std::cout << "Время, затраченное многопоточной реализацией равно : " << elapsed_ms2.count() << " ms\n";
	

	cout <<"Время многопоточной реализации быстрее однопоточной приблизительно на: "<< elapsed_ms.count()- elapsed_ms2.count() << "мс" ;


	int x1, x4;
	int x2, x3;
	float aa;
	setlocale(LC_ALL, "Russian");

	cout << "\n";
	cout << "\n" << "Введите параметры для числа А:" << "\n";
	cin >> x1 >> x2;
	cout << "Введите параметры для числа B:" << "\n";
	cin >> x3 >> x4;

    Complex A(x1,x2),B(x3,x4),C,ZZ;

	cout << "Деление на вещественное." << "\n";
	cout << "Результат деления:" << "\n";
	C = A / 5;
	ZZ = B / 5;


	C.OutD();
	ZZ.OutD();
	cout << "Деление двух комплексных." << "\n";
	cout << "Результат деления:" << "\n";
	C = A / B;
	C.OutD();
	cout << "\n";
	cout << "Разность комплексных." << "\n";
	cout << "Результат разности:" << "\n";
	C = A - B;
	C.OutD();
	cout << "Сумма комплексных." << "\n";
	cout << "Результат суммы:" << "\n";
	C = A + B;
	C.OutD();
	cout << "Умножение двух комплексныx." << "\n";
	cout << "Результат умножения:" << "\n";
    C = A * B;
	C.OutD();
	
	cout << "Умножение float на complex."<< "\n";
	cout << "На какое число желаете умножить?" << "\n";
	cin >> aa ;
	cout << "Результат умножения числа А:" << "\n";
	C = A * aa;
	C.OutD();
	cout << "Результат умножения числа В:" << "\n";
	ZZ = B * aa;
	ZZ.OutD();
	system("pause");
}

