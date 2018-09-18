#include <iostream>
#include <stdlib.h>
using namespace std;
void divide(int *, int);
void merge(int *, int *, int *, int, int);
void showAll(int *, int);

int main() {
	cout << "input size : ";
	int size = 0;
	cin >> size;
	cout << "input case" << endl;
	int * list = (int *)malloc(sizeof(int)*size);
	cout << "input >> ";
	for (int i = 0; i < size; i++) {		
		cin >> list[i];
	}
	divide(list, size);
	showAll(list, size);
	free(list);
	return 0;
}

void divide(int * S, int size) {
	if (size > 1) {
		int mid = size / 2;
		int h = size - mid;
		int * U = (int *)malloc(sizeof(int)*(mid));
		for (int i = 0; i < mid; i++) {
			U[i] = S[i];
		}
		int * V = (int *)malloc(sizeof(int)*(h));
		for (int i = mid; i < size; i++) {
			V[i - mid] = S[i];
		}
		divide(U, mid);
		divide(V, h);
		merge(S, U, V, mid, h);
		free(U);
		free(V);
	}	
}

void merge(int * S, int * U, int * V, int mid, int h) {
	int i = 0, j = 0;
	int index = 0;
	while (i < mid && j < h) {
		if (U[i] < V[j]) {
			S[index] = U[i];
			i++;
		}
		else {
			S[index] = V[j];
			j++;
		}
		index++;
	}
	if (i < mid) {
		while (i < mid) {
			S[index] = U[i];
			i++;
			index++;
		}
	}
	if (j < h) {
		while (j < h) {
			S[index] = V[j];
			j++;
			index++;
		}
	}
}

void showAll(int * array, int end) {
	for (int i = 0; i < end; i++) {
		cout << array[i]<<" ";
	}
}