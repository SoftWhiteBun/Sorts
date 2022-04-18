#pragma once
#include <iostream>
#include <windows.h> // ����� ��������� � �������
#include <ctime> // ��� time
#include <fstream> // �������� ����-�����
#include <vector>
#include <string>
using namespace std;


void CreateBinaryArr(vector<bool>& A, int n);
void BubbleSort(vector<bool>& A);
void ViewInTxt(const string fileName, vector<bool>& A); 
void SelectionSort(vector<bool>& A);
void QuickSort( vector<bool>& A, int last_i, int first_i);
void Quick(vector<bool>& A, int l, int f);
void Heap(vector<bool>& A, int n, int i);
void HeapSort(vector<bool>& A, int n);