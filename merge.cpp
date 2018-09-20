#include <iostream>
#include <stdlib.h>
using namespace std;
void divide(int *, int);
void merge(int *, int *, int *, int, int);

void divide2(int, int);
void merge2(int, int, int);

void showAll(int *, int);
int * list;

int main() {
	cout << "input size : ";
	int size = 0;
	cin >> size;
	cout << "input case" << endl;
	list = (int *)malloc(sizeof(int)*size);
	cout << "input >> ";
	for (int i = 0; i < size; i++) {		
		cin >> list[i];
	}
	//divide(list, size);
	divide2(0, size-1);
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

void divide2(int low, int high) {	
	if ( high > low ) {
		int mid = (low + high) / 2;
		divide2(low, mid);
		divide2(mid+1, high);
		merge2(low, mid, high);
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

void merge2(int low, int mid, int high) {
	int * U = (int *)malloc(sizeof(int)*(high - low + 1));
	int i = low, j = mid+1, index = 0;
	while (i <= mid && j <= high) {
		if (list[i] < list[j]) {
			U[index] = list[i];
			i++;
		}
		else {
			U[index] = list[j];
			j++;
		}
		index++;
	}
	if (i <= mid) {
		while (i <= mid) {
			U[index] = list[i];
			i++;
			index++;
		}
	}
	if (j <= high) {
		while (j <= high) {
			U[index] = list[j];
			j++;
			index++;
		}
	}
	for (int a = 0; a < high - low + 1; a++) {
		list[low + a] = U[a];
	}
	free(U);
}

void showAll(int * array, int end) {
	for (int i = 0; i < end; i++) {
		cout << array[i]<<" ";
	}
}
