#include <iostream>

using namespace std;

int solve(int x, int y);

int N;                               
int x, y;                              
int map[100 + 10][100 + 10];            
int answer;

int px[4] = { -1, 0, 1, 0 };           
int py[4] = { 0, -1, 0, 1 };

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		for (int a = 0; a < 10; a++) {
			for (int b = 0; b < 10; b++) {
				map[x + a][y + b] = 1;
			}
		}
	}

	/*
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++){
			cout << map[i][j];
		}
		cout << "\n";
	}
	*/

	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			if (map[i][j] == 1) {
				solve(i, j);
			}
		}
	}

	/*
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++){
			cout << map[i][j];
		}
		cout << "\n";
	}
	*/

	cout << answer;			

	return 0;
}

int solve(int x, int y) {

	int aa, bb;

	for (int k = 0; k < 4; k++) {
		aa = x + px[k]; bb = y + py[k];
		if (aa >= 0 && aa < 105 && bb >= 0 && bb < 105 && map[aa][bb] == 0) {
			answer++;
		}
	}

	map[x][y] = 2;
					
	for (int k = 0; k < 4; k++) {
		aa = x + px[k]; bb = y + py[k];
		if (aa >= 0 && aa < 105 && bb >= 0 && bb < 105 && map[aa][bb] == 1) {
			solve(aa, bb);
		}
	}

	return 0;
}
