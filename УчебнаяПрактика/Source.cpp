#include "pch.h"
#include "zag11.h"


void CreateBinaryArr(vector<bool>& A, int n)  {
	if (A.size() > 0) {
		cout << "Массив уже создан."<<endl;
		return;
	}
	cout << "Введите размер массива: "<<endl;
	cin >> n;
	while ((cin.fail()) || (n < 1)) { //пока предыдущее извлечение считается неудачным или число<1
    	cin.clear();    //возвращаем cin в "обычный" режим работы
		cin.ignore(32767, '\n'); //и удаляем значения предыдущего ввода из входного буфера
		cout << "Некорректные данные! Введите целочисленное значение больше 0: ";
		cin >> n;
	}
	A.clear();
	A.resize(n);
	srand(time(NULL));        //чтоб рандом не повторялся
	for (auto item : A)       //заполняем массив
	{
		int elem;
		elem = rand();
		if (elem % 2 == 0) item = true;
		else item = false;
	}
}

void BubbleSort(vector<bool>& A)    //пузырьковая сортировка
{
	int t1 = clock();           //засекаем время в мс в начале
	if (A.size() == 0) {        //если массив пустой
		cout << "Сначала заполните массив!" << endl;
		return;
	}
	if (A.size() == 1) {      //если массив состоит из 1 элемента
		cout << "Массив состоит из 1 элемента. Сортировка не требуется." << endl;
		return;
	}
	bool tmp;

	for (int i = 0; i < A.size() - 1; i++)      //пока массив не закончится
		for (int j = 0; j < A.size() - i - 1; j++)
		{
			if (A[j] > A[j + 1])      //если текущий элемент больше следующего
			{                         //меняем их местами
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	int t2 = clock();              //засекаем время в мс в конце
	cout << "Сортировка выполнена!" << endl;
	cout << "Затраченное время в мс: " << (t2 - t1) << endl;//выводим их разность, 
}                                         //которая соответствует времени выполнения функции

                                  // сортировка выбором
void SelectionSort(vector<bool>& A) // или использовать sort() из библиотеки algorithm
{
	int t1 = clock();
	if (A.size() == 0) {
		cout << "Сначала заполните массив!"<<endl;
		return;
	}
	if (A.size() == 1) {
		cout << "Массив состоит из 1 элемента. Сортировка не требуется." << endl;
		return;
	}
	for (int i = 0; i < A.size(); i++)
	{
		int tmp = A[0]; // временная переменная
		for (int j = i + 1; j < A.size(); j++)
		{
			if (A[i] > A[j])  //если i-й элемент больше j-го, меняем их местами
			{                      
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
	int t2 = clock();
	cout << "Сортировка выполнена!" << endl;
	cout << "Затраченное время в мс: " << (t2 - t1) << endl;
}


void QuickSort( vector<bool>& A, int l, int f)  //быстрая сортировка
{
	if (A.size() == 0) {           //если массив пустой
		cout << "Сначала заполните массив!" << endl;
		return;
	}
	if (A.size() == 1) {              //если массив состоит из 1 элемента
		cout << "Массив состоит из 1 элемента. Сортировка не требуется." << endl;
		return;
	}
	int x;
	if (l < f) {             
		x = A[(l + f) / 2];   //находим середину
		int i = l; 
		int j = f;    //i и j соответствуют левому и правому концам массива 
		while (i <= j) {
			while (A[i] < x) i++;    //пока i-й элемент меньше значения середины переходим на следующий элемент
			while (A[j] > x) j--;    //пока j-й элемент больше значения середины переходим к предыдущему элементу
			if (i <= j) swap(A[i++], A[j--]);   //если i <= j, то меняем соотв.элементы местами
		}
		QuickSort(A, l, j);     //рекурсивно выполняем, пока массив не будет отсортирован
		QuickSort(A, i, f);
	}
	
}
void Quick(vector<bool>& A, int l, int f) { 
	int t1=clock();
	QuickSort( A, l, f);
	int t2 = clock();
	cout << "Сортировка выполнена!" << endl;
	cout << "Затраченное время в мс: " << (t2 - t1) << endl;
}


void Heap(vector<bool>& A, int n, int i)   //работа с кучей
{
	int max = i;
	int l = 2 * i + 1; // левый 
	int r = 2 * i + 2; // правый 

	if (l < n && A[l] > A[max])   // Если левый дочерний элемент больше корня
		max = l;
	
	if (r < n && A[r] > A[max])   // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
		max = r;

	if (max != i)  // Если самый большой элемент не корень
	{
		swap(A[i], A[max]); //перемещаем самый большой элемент 	
		Heap(A, n, max);   // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
	}
}


void HeapSort(vector<bool>& A, int n)   //пирамидальная сортировка
{
	int t1 = clock();
	for (int i = n / 2 - 1; i >= 0; i--)    //делаем кучу
		Heap(A, n, i);

	for (int i = n - 1; i >= 0; i--)     //извлекаем элементы из кучи
	{
		swap(A[0], A[i]); // Перемещаем текущий корень в конец
		Heap(A, i, 0);
	}
	int t2 = clock();
	cout << "Сортировка выполнена!" << endl;
	cout << "Затраченное время в мс: " << (t2 - t1) << endl;
}



void ViewInTxt( const string fileName, vector<bool>& A)     //вывод в файл
{
	if (A.size() == 0) {
		cout << "Сначала заполните массив!" << endl;
		return;
	}
	ofstream fout;
	fout.open(fileName, ios_base::app);       //открытие файла
	if (!(fout.is_open())) {      
		cout << "Не удалось открыть выходной файл!";
		return ;
	}
	
	for (int i=0; i<A.size();i++)             //выводим массив
	{
		fout << A[i] << " ";
	}
	fout << endl;
	cout << "Массив выведен в файл." << endl;  //подтверждающее сообщение на консоль
	fout.close();             //закрытие файла
}
