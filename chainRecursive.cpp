#include <iostream>
#include <string>
using namespace std;
int time = 0;
int * d;
int ** P;
int M(int, int);
void order(int, int);

int main() {
	int N = 0;
	cout << "input n : ";
	cin >> N;
	d = new int[N + 1];
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
	P = new int *[N + 1];
	for (int i = 0; i <= N; i++) {
		P[i] = new int[N + 1];
	}
	cout << "minmult : " << M(1,N) << endl;
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
	cout << "\norder : ";
	order(1, N);
	cout << "\ntime : " << time << endl;
	delete[] d;
	delete[] P;
	return 0;
}

int M(int i, int j) {
	if (i == j) return 0;
	int min = 0;
	for (int k = i; k < j; k++) {
		time++;
		if (k == i) {
			min = M(i,k) + M(k + 1,j) + (d[i - 1] * d[k] * d[j]);
			P[i][j] = k;
		}
		else {
			int tmp = M(i,k) + M(k + 1,j) + (d[i - 1] * d[k] * d[j]);
			if (tmp < min) {
				min = tmp;
				P[i][j] = k;
			}
		}
	}
	return min;
}

void order(int i, int j) {
	if (i == j) cout << "A" << i;
	else {
		int k = P[i][j];
		cout << " (";
		order(i, k);
		order(k + 1, j);
		cout << ") ";
	}
}