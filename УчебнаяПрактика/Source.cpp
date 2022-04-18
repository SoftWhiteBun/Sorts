#include "pch.h"
#include "zag11.h"


void CreateBinaryArr(vector<bool>& A, int n)  {
	if (A.size() > 0) {
		cout << "������ ��� ������."<<endl;
		return;
	}
	cout << "������� ������ �������: "<<endl;
	cin >> n;
	while ((cin.fail()) || (n < 1)) { //���� ���������� ���������� ��������� ��������� ��� �����<1
    	cin.clear();    //���������� cin � "�������" ����� ������
		cin.ignore(32767, '\n'); //� ������� �������� ����������� ����� �� �������� ������
		cout << "������������ ������! ������� ������������� �������� ������ 0: ";
		cin >> n;
	}
	A.clear();
	A.resize(n);
	srand(time(NULL));        //���� ������ �� ����������
	for (auto item : A)       //��������� ������
	{
		int elem;
		elem = rand();
		if (elem % 2 == 0) item = true;
		else item = false;
	}
}

void BubbleSort(vector<bool>& A)    //����������� ����������
{
	int t1 = clock();           //�������� ����� � �� � ������
	if (A.size() == 0) {        //���� ������ ������
		cout << "������� ��������� ������!" << endl;
		return;
	}
	if (A.size() == 1) {      //���� ������ ������� �� 1 ��������
		cout << "������ ������� �� 1 ��������. ���������� �� ���������." << endl;
		return;
	}
	bool tmp;

	for (int i = 0; i < A.size() - 1; i++)      //���� ������ �� ����������
		for (int j = 0; j < A.size() - i - 1; j++)
		{
			if (A[j] > A[j + 1])      //���� ������� ������� ������ ����������
			{                         //������ �� �������
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	int t2 = clock();              //�������� ����� � �� � �����
	cout << "���������� ���������!" << endl;
	cout << "����������� ����� � ��: " << (t2 - t1) << endl;//������� �� ��������, 
}                                         //������� ������������� ������� ���������� �������

                                  // ���������� �������
void SelectionSort(vector<bool>& A) // ��� ������������ sort() �� ���������� algorithm
{
	int t1 = clock();
	if (A.size() == 0) {
		cout << "������� ��������� ������!"<<endl;
		return;
	}
	if (A.size() == 1) {
		cout << "������ ������� �� 1 ��������. ���������� �� ���������." << endl;
		return;
	}
	for (int i = 0; i < A.size(); i++)
	{
		int tmp = A[0]; // ��������� ����������
		for (int j = i + 1; j < A.size(); j++)
		{
			if (A[i] > A[j])  //���� i-� ������� ������ j-��, ������ �� �������
			{                      
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
	int t2 = clock();
	cout << "���������� ���������!" << endl;
	cout << "����������� ����� � ��: " << (t2 - t1) << endl;
}


void QuickSort( vector<bool>& A, int l, int f)  //������� ����������
{
	if (A.size() == 0) {           //���� ������ ������
		cout << "������� ��������� ������!" << endl;
		return;
	}
	if (A.size() == 1) {              //���� ������ ������� �� 1 ��������
		cout << "������ ������� �� 1 ��������. ���������� �� ���������." << endl;
		return;
	}
	int x;
	if (l < f) {             
		x = A[(l + f) / 2];   //������� ��������
		int i = l; 
		int j = f;    //i � j ������������� ������ � ������� ������ ������� 
		while (i <= j) {
			while (A[i] < x) i++;    //���� i-� ������� ������ �������� �������� ��������� �� ��������� �������
			while (A[j] > x) j--;    //���� j-� ������� ������ �������� �������� ��������� � ����������� ��������
			if (i <= j) swap(A[i++], A[j--]);   //���� i <= j, �� ������ �����.�������� �������
		}
		QuickSort(A, l, j);     //���������� ���������, ���� ������ �� ����� ������������
		QuickSort(A, i, f);
	}
	
}
void Quick(vector<bool>& A, int l, int f) { 
	int t1=clock();
	QuickSort( A, l, f);
	int t2 = clock();
	cout << "���������� ���������!" << endl;
	cout << "����������� ����� � ��: " << (t2 - t1) << endl;
}


void Heap(vector<bool>& A, int n, int i)   //������ � �����
{
	int max = i;
	int l = 2 * i + 1; // ����� 
	int r = 2 * i + 2; // ������ 

	if (l < n && A[l] > A[max])   // ���� ����� �������� ������� ������ �����
		max = l;
	
	if (r < n && A[r] > A[max])   // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
		max = r;

	if (max != i)  // ���� ����� ������� ������� �� ������
	{
		swap(A[i], A[max]); //���������� ����� ������� ������� 	
		Heap(A, n, max);   // ���������� ����������� � �������� ���� ���������� ���������
	}
}


void HeapSort(vector<bool>& A, int n)   //������������� ����������
{
	int t1 = clock();
	for (int i = n / 2 - 1; i >= 0; i--)    //������ ����
		Heap(A, n, i);

	for (int i = n - 1; i >= 0; i--)     //��������� �������� �� ����
	{
		swap(A[0], A[i]); // ���������� ������� ������ � �����
		Heap(A, i, 0);
	}
	int t2 = clock();
	cout << "���������� ���������!" << endl;
	cout << "����������� ����� � ��: " << (t2 - t1) << endl;
}



void ViewInTxt( const string fileName, vector<bool>& A)     //����� � ����
{
	if (A.size() == 0) {
		cout << "������� ��������� ������!" << endl;
		return;
	}
	ofstream fout;
	fout.open(fileName, ios_base::app);       //�������� �����
	if (!(fout.is_open())) {      
		cout << "�� ������� ������� �������� ����!";
		return ;
	}
	
	for (int i=0; i<A.size();i++)             //������� ������
	{
		fout << A[i] << " ";
	}
	fout << endl;
	cout << "������ ������� � ����." << endl;  //�������������� ��������� �� �������
	fout.close();             //�������� �����
}
