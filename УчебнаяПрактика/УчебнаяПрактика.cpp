#include "pch.h"
#include "zag11.h"

int main()
{
	char operation;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string fileName;   //название файла
	int n = 0; // размер массива
	vector<bool> array; // массив
	cout << "Введите имя выходного файла: ";
	cin >> fileName;

	do {
		fseek(stdin, 0, SEEK_END);
		cout << "\nN - создать новый бинарный массив\nV - вывод массива в текстовый файл\nQ - быстрая сортировка\n";
		cout << "H - пирамидальная сортировка\nS - сортировка выбором\nB - пузырьковая сортировка\nE - конец\nВаш выбор?" << endl;
		cin >> operation;
		fflush(stdin);
		operation = toupper(operation);
		switch (operation) {
		case 'N': CreateBinaryArr(array, n); break;
		case 'V': ViewInTxt(fileName, array); break;
		case 'Q': Quick(array, 0, array.size() - 1); break;
		case 'H': HeapSort(array, array.size()); break;
		case 'S': SelectionSort(array); break;
		case 'B': BubbleSort(array); break;
		case 'E': return 0;
		default:
			cout << "Нет такой команды\nPress any key" << endl;
			system("pause");
		}
	} while (operation != 'E');

	return 0;
}