#include <iostream>
#include <algorithm>      // max
using namespace std;

int mintrial = 0;
int minstep = 0;
int trial = 0;
int remain = 0;
int totalstep = 0;
int start = 0;


int triali(int N, int i) {
	int t = 0;
	t = (N%i == 0) ? N / i + i - 1 : N / i + max(N%i, i - 1);
	return t;
}

int besttrial(int N) {
	int bestt = N;
	int temp = 0;
	for (int i = 1; i < N; i++) {
		temp = triali(N, i);
		if (temp < bestt) {
			bestt = temp;
		}
	}
	return bestt;
}

int besti(int N) {
	int bestt = N;
	int besti = 0;
	int temp = 0;
	for (int i = 1; i < N; i++) {
		temp = triali(N, i);
		if (temp <= bestt) {
			bestt = temp;
			besti = i;
		}
	}
	return besti;
}

void travel() {
	while (remain > 1) {
		remain = remain - besti(remain);
		cout << "remain reduced to " << remain << endl;
		totalstep++;
	}
	totalstep++;
	return;
}

int main(void) {
	// Your code here!
	remain = 100;
	for (int i = 1; i <= 100; i++) {
		cout << "i=" << i << ", triali(100,i)=" << triali(100, i) << endl;
	}
	cout << "besttrial=" << besttrial(100) << endl;
	cout << "besti=" << besti(100) << endl;
	travel();
	cout << "totalstep=" << totalstep << endl;

	return 0;
}
