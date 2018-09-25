#include <iostream>
#include <stdlib.h>
using namespace std;
void mergesort(int, int *);
void merge(int, int, int *, int *, int *);
void showAll(int *, int);
int main() {
	cout << "input size : ";
	int size = 0;
	cin >> size;
	cout << "input list" << endl;
	int * list = (int *)malloc(sizeof(int)*size);
	cout << "input >> ";
	for (int i = 0; i < size; i++) {
		cin >> list[i];
	}
	mergesort(size, list);
	showAll(list, size);
	free(list);
	return 0;
}
void mergesort(int n, int * S) {
	if (n > 1) {
		const int h = n / 2;
		const int m = n - h;
		int * U = (int *)malloc(sizeof(int)*(h));
		for (int i = 0; i < h; i++) {
			U[i] = S[i];
		}
		int * V = (int *)malloc(sizeof(int)*(m));
		for (int i = h; i < n; i++) {
			V[i - h] = S[i];
		}
		cout << "***" << endl;
		cout << "h : " << h << endl;
		cout << "m : " << m << endl;
		cout << "U : ";
		for (int i = 0; i < h; i++)
			cout << U[i] << " ";
		cout << " " << endl;
		cout << "V : ";
		for (int i = 0; i < m; i++)
			cout << V[i] << " ";
		cout << " " << endl;
		cout << "S : ";
		for (int i = 0; i < n; i++)
			cout << S[i] << " ";
		cout << " " << endl;
		mergesort(h, U);
		mergesort(m, V);		
		merge(h, m, U, V, S);
		cout << "***" << endl;
		cout << "h : " << h << endl;
		cout << "m : " << m << endl;
		cout << "U : ";
		for (int i = 0; i < h; i++)
			cout << U[i] << " ";
		cout << " " << endl;
		cout << "V : ";
		for (int i = 0; i < m; i++)
			cout << V[i] << " ";
		cout << " " << endl;
		cout << "S : ";
		for (int i = 0; i < n; i++)
			cout << S[i] << " ";
		cout << " " << endl;
		free(U);
		free(V);
	}
}
void merge(int h, int m, int * U, int * V, int * S) {
	int i = 0, j = 0;
	int k = 0;
	while (i < h && j < m) {
		if (U[i] < V[j]) {
			S[k] = U[i];
			i++;
		}
		else {
			S[k] = V[j];
			j++;
		}
		k++;
	}
	if (i < h) {
		while (i < h) {
			S[k] = U[i];
			i++;
			k++;
		}
	}
	if (j < m) {
		while (j < m) {
			S[k] = V[j];
			j++;
			k++;
		}
	}
}
void showAll(int * array, int end) {
	cout << " " << endl;
	cout << "result : ";
	for (int i = 0; i < end; i++) {
		cout << array[i] << " ";
	}
}