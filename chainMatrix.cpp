#include <iostream>
using namespace std;
int minmul(int, int *, int **);

int main() {
	int N = 0;
	cout << "input n : ";
	cin >> N;
	int * input = new int[N + 1];
	cout << "input case : ";
	for (int i = 0; i <= N; i++)
		cin >> input[i];
	int ** matrix = new int *[N + 1];
	for (int i = 0; i <= N; i++) {
		matrix[i] = new int[N + 1];
	}
	cout << "min : " << minmul(N, input, matrix) << endl;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << " " << endl;
	}

	delete[] input;
	delete[] matrix;
	return 0;
}

int minmul(int n , int * input, int ** matrix) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j + i <= n; j++) {
			if (j == j + i)
				matrix[j][j + i] = 0;
			else {
				int min = 0;
				for (int k = j; k < j + i; k++) {
					if (k == j) {
						min = matrix[j][k] + matrix[k + 1][j + i] + (input[j - 1] * input[k] * input[i + j]);
					}
					else {
						int tmp = matrix[j][k] + matrix[k + 1][j + i] + (input[j - 1] * input[k] * input[i + j]);
						if (tmp < min)
							min = tmp;
					}
				}
				matrix[j][j + i] = min;
			}
		}
	}
	return matrix[1][n];
}