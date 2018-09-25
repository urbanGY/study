#include <iostream>
#include <stdlib.h>
using namespace std;
void mergesort2(int, int);
void merge2(int, int, int);
void showAll();
int * S;
int length;

int main() {
	cout << "input size : ";
	int size = 0;
	cin >> size;
	length = size;
	cout << "input case" << endl;
	S = (int *)malloc(sizeof(int)*size);
	cout << "input >> ";
	for (int i = 0; i < size; i++) {		
		cin >> S[i];
	}
	mergesort2(0, size-1);
	showAll();
	free(S);
	return 0;
}
void mergesort2(int low, int high) {	
	if ( high > low ) {
		int mid = (low + high) / 2;
		mergesort2(low, mid);
		mergesort2(mid+1, high);
		merge2(low, mid, high);
	}
}
void merge2(int low, int mid, int high) {
	int * U = (int *)malloc(sizeof(int)*(high - low + 1));
	int i = low, j = mid+1, k = 0;
	while (i <= mid && j <= high) {
		if (S[i] < S[j]) {
			U[k] = S[i];
			i++;
		}
		else {
			U[k] = S[j];
			j++;
		}
		k++;
	}
	if (i <= mid) {
		while (i <= mid) {
			U[k] = S[i];
			i++;
			k++;
		}
	}
	if (j <= high) {
		while (j <= high) {
			U[k] = S[j];
			j++;
			k++;
		}
	}
	for (int a = 0; a < high - low + 1; a++) {
		S[low + a] = U[a];
	}
	free(U);
}
void showAll() {
	for (int i = 0; i < length; i++) {
		cout << S[i]<<" ";
	}
}
