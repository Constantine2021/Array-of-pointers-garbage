#include <iostream>
#include <istream>
#include <iomanip>
#include <fstream>

#include "..\\..\\myfunctions.h"

using namespace std;
int main() {
	setlocale(LC_CTYPE, "rus");
	{cout << "===Задание 1=========" << endl;
	const int nrows = 5, ncols = 10;
	int M[nrows][ncols];
	myrnd(M[0], nrows*ncols, -99, 99);
	int k1, k2;
	cout << "Номера переставляемых строк (1..5):" << setw(2) << (k1 = 2) << setw(2) << (k2 = 5) << endl<<"Исходная матрица:"<<endl;
	k1--; k2--;
	/*int *p; p = M[k1]; 
	M[k1] = M[k2];
	M[k2] = p;*/ //Ошибка!
	int *P[nrows];
	for (int i = 0; i < nrows; i++)
		P[i] = M[i];
	int *p;
	p = P[k1];
	P[k1] = P[k2];
	P[k2] = p;
	cout << "Исходная матрица:\n";
	for (int i = 0; i < nrows; i++) myout(M[i], ncols);
	cout << "Изменненая матрица:\n";
	for (int i = 0; i < nrows; i++) myout(P[i], ncols);
	}
	cout << endl;
	{cout << "===Задание 2b=========" << endl;
	const int nrows = 8, ncols = 8;
	int M[nrows][ncols];
	myrnd(M[0], nrows*ncols, 200, 999);
	int *P[nrows];
	for (int i = 0; i < nrows; i++) P[i] = M[i];
	int D[nrows]; 
	for (int i = 0; i < nrows; i++) D[i] = M[i][i];
	cout << "Исходная матрица:" << endl;
	for (int i = 0; i < nrows; i++) myout(M[i], ncols);
	cout << "Диагональные элемнты матрицы:" << endl;
	myout(D, ncols);
	mysrt(D, nrows, false, P);
	cout << "Измененная матрица:" << endl;
	for (int i = 0; i < nrows; i++) myout(M[i], ncols);
	cout << "Диагональные элемнты матрицы:" << endl;
	myout(D, ncols);
	}
	cout << endl;
	{cout << "===Задание 3=========" << endl; 
	const int ncols = 10, nrows = 5;
	int M[nrows][ncols];
	myrnd(M[0], nrows*ncols, -99, 99);
	cout << "Матрица M:" << endl;
	myout(M[0], ncols*nrows,nrows,5);
	int *sizeA; sizeA = new int[nrows];
	int *sizeB; sizeB = new int[nrows];
	for (int i = 0; i < nrows; i++) {
		 sizeA[i] = 0, sizeB[i] = 0;
		for (int *p = M[i], *end = p + ncols; p < end; p++) {
			if (*p > 0) sizeA[i]++;
			else if (*p < 0) sizeB[i]++;
		}
	}
	int *A[nrows], *B[nrows];
	for (int i = 0; i < nrows; i++) {
		A[i] = new int[sizeA[i]]; B[i] = new int[sizeB[i]];
		for (int *p = M[i], *a = A[i], *b = B[i], *end = p+ncols; p < end; p++) 
			if (*p > 0) *a++ = *p;
			else if (*p < 0) *b++ = *p;
			myord(A[i], sizeA[i]);
			myord(B[i], sizeB[i], 0);
	}
	cout << "Положительные элементы М:" << endl;
	for (int i = 0; i < nrows; i++) myout(A[i], sizeA[i]);
	cout << "Отрицательные элементы М:" << endl;
	for (int i = 0; i < nrows; i++) myout(B[i], sizeB[i]);
	delete[] sizeA;
	delete[] sizeB;
	for (int i = 0; i < nrows; i++) { delete[] A[i]; delete[] B[i]; }
	}
	cout << endl;
	{cout << "===Задание 4a=========" << endl; 
	const int nrows = 40;
	char *S[nrows], *V[nrows];
	cout << "Введите список студентов:\n";
	int n = myinput(S,"11.4s.txt",true);
	cout << endl;
	cout << "Введите список оценок:\n";
	n = myinput(V, "11.4v.txt", true);
	cout << endl;
	cout << "Единый список:\n";
	for (int i = 0; i < n; i++)
		cout <<left << setw(25) << S[i] << V[i] << endl;
	}
	cout << endl;
	{cout << "===Задание 4b=========" << endl; 
	const int nrows = 40;
	char *S[nrows];
	int ns= myinput(S, "11.4b.txt", true);
	char *T[nrows];
	int nt = ns;
	for (int i = 0, j = 0; i < ns; i++) {
		if (strstr(S[i], "3") || strstr(S[i], "2") || strstr(S[i], "1 ") || S[i][mylen(S[i])-1] == '1') nt--;
		else T[j++] = S[i];
	}
	cout << endl;
	cout << "Обновленный список студентов:\n";
	for (int i = 0; i < nt; i++)
		cout << T[i] << endl;
	}
	cout << endl;
	{cout << "===Задание 5=========" << endl; 
	float x = 2.2;
	float *p1 = &x;
	float **p2 = &p1;
	cout << "Ячейка x  " << "имеет адрес " << *p2 << " и содержит значение " << **p2 << endl;
	cout << "Ячейка p1 " << "имеет адрес " << p2 << " и содержит значение " << *p2 << endl;
	cout << "Ячейка p2 " << "имеет адрес " << &p2 << " и содержит значение " << p2 << endl;
	}
	cout << endl;
	{cout << "===Задание 6b=========" << endl; 
	int nrows = strcount("11.6b.txt");
	int **X = new int*[nrows];
	char **S= new char*[nrows];
	int*size = new int[nrows];
	cout << "Структура графа:" << endl;
	myinput(S, "11.6b.txt",  1);
	for (int i = 0; i < nrows; i++) {
		size[i] = wordcount(S[i]," ");
		X[i] = new int[size[i]];
		str2num(X[i], S[i]);
	}
	cout << "Ребра графа с концами в вершине 3:" << endl;
	for(int i=0;i<nrows;i++)
		for(int j=0;j<size[i] ;j++)
			if (X[i][j] == 3) { cout << "(" << i+1 << "-->3)"; break; }
	cout << endl;
	for (int i = 0; i < nrows; i++) {
		delete[] X[i];
		delete[] S[i];
	}
	delete[] size;
	delete[] X;
	delete[] S;
	}
	cout << endl;
	{cout << "===Задание 7b=========" << endl;
	int nrows = strcount("11.7c.txt");
	char **S = new char*[nrows];
	char **T = new char*[nrows];
	char sep[] = "_ ";
	cout << "Исходный список:\n";
	myinput(S, "11.7c.txt", 1);
	cout << endl;
	for (int i = 0; i < nrows; i++) {
		T[i] = S[i];
		T[i] += myspn(S[i], sep);
		for (int j = 0; j < 2; j++) {
			T[i] += mycspn(T[i], sep);
			T[i] += myspn(T[i], sep);
		}
	}
	mysrt(T, nrows, 1, S);
	cout << "Упорядоченный список:\n";
	for (int i = 0; i < nrows; i++)
		cout << S[i] << endl;
	delete[] S;
	delete[] T;
	}




	system("pause");
	return 0;
}