//динамическое выделение памяти
//type * name_value = new type;
//Для испзия свободной памяти ОС (куча heap)
// объявлся дин перем по синтаксису
// 
//работа с дин памятью происходит через указатели
//
//преимущества:
//доступно гораздо больше памяти, нежели в стеке
//размеры массивов и структур данных м опредть и менять во время работы
//особенность: 
// если приложение для длительной работы чтобы не переполнитьь нужно delete 

#include "pch.h"
// Lab_No7_dynamic_mem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Динамическое выделение памяти
//type * name_value = new type;
//Для испзия свободной памяти ОС (куча heap)
// объявлся дин перем по синтаксису
// 
//работа с дин памятью происходит через указатели
//
//преимущества:
//доступно гораздо больше памяти, нежели в стеке
//размеры массивов и структур данных м опредть и менять во время работы
//особенность: 
// если приложение для длительной работы чтобы не переполнитьь нужно delete 




#include "stdafx.h"
#include <iostream>

int main()
{
	int *ptr_int = new int;
	int * matr = new int[11 * 12];
	for (int row = 0; row < 12; row++) {
		for (int col = 0; col < 11; col++) {
			matr[row * l1 + col] = row * l1 + col;
		}
	}
	delete[]matr;
	int** dynamic2Darray = new int*[11];//двумерный массив
	for (int i = 0; i < 11; i++)
	{
		delete[] dynamic2Darray[i];
	}
	delete[] dynamic2Darray;

	return 0;
}



