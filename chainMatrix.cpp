#include <iostream>
#include <string>
using namespace std;
int minmult(int, int *, int **);
//6 - 5x2 2x3 3x4 4x6 6x7 7x8
//12 - 6x2 2x3 3x7 7x5 5x9 9x7 7x2 2x4 4x3 3x9 9x4 4x6
//18 - 6x5 5x4 4x3 3x2 2x5 5x2 2x5 5x6 6x8 8x3 3x9 9x2 2x5 5x7 7x8 8x4 4x9 9x6
int main() {
	int N = 0;
	cout << "input n : ";
	cin >> N;
	int * d = new int[N + 1];
	cout << "input : ";
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		string read = "";
		for (int n = 0; n < input.size(); n++) {						
			if (input.at(n) == 'x' || input.at(n) == 'X') {				
				int x = atoi(read.c_str());				
				d[i] = x;				
				read = "";
			}
			else {
				read += input.at(n);
			}
		}
		d[i + 1] = atoi(read.c_str());
	}
	int ** P = new int *[N + 1];
	for (int i = 0; i <= N; i++) {
		P[i] = new int[N + 1];
	}
	cout << "minmult : " << minmult(N, d, P) << endl;
	cout << "<P>" << endl;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= N; j++) {
			if (j <= i) {
				printf("     ");
			}
			else {
				printf("%3d  ", P[i][j]);
			}			
		}
		cout << " " << endl;
	}
	delete[] d;
	delete[] P;
	return 0;
}
int minmult(int n, int * d, int ** P) {
	int count = 0;
	int ** M = new int *[n + 1];
	for (int i = 0; i <= n; i++) {
		M[i] = new int[n + 1];
	}
	for (int i = 0; i <= n; i++) {
		M[i][i] = 0;
	}
	for (int diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (int i = 1; i <= n - diagonal; i++) {
			int j = i + diagonal;
			int min = 0;
			for (int k = i; k < j ; k++) {
				count++;
				if (k == i) {
					min = M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j]);
					P[i][j] = k;
				}
				else {
					int tmp = M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j]);
					if (tmp < min) {
						min = tmp;
						P[i][j] = k;
					}						
				}
			}
			M[i][j] = min;
		}
	}
	int answer = M[1][n];
	delete[] M;	
	cout << "count : " << count << endl;
	return answer;
}
