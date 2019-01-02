#include <iostream>
using namespace std;
void recursive(int, int);

int main() {
	int N , X;
	cin>>N>>X;
	recursive(N,X);
	return 0;
}

void recursive(int N, int X){
	if(N < X){
		if(X > 10) printf("%x",N);
		else printf("%d",N);
		return;
	}
	int d = N%X;
	
	recursive(N/X,X);
	if(X > 10) printf("%x",d);
	else printf("%d",d);
}
