#include <iostream>

using namespace std;
int l, m, x[100], y[100], r;

int min(int a, int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

int max(int a, int b) {
	if (a <= b) {
		return b;
	}
	else {
		return a;
	}
}

int main(void) {

	scanf("%*d%d%d", &l, &m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			for (int k = 1; k < l / 2; k++) {
				int c = 0, tx = min(x[i], x[j]), ty = min(y[i], y[j]);
				for (int p = 0; p < m; p++) c += x[p] >= tx&&y[p] >= ty&&x[p] <= tx + k&&y[p] <= ty + l / 2 - k;
				r = max(r, c);
			}
		}
	}
	cout << r;
	return 0;
}