#include <iostream>

using namespace std;

typedef struct ultraviolet {
	int x;
	int y;
}ULTRA;

int rd, wt;
ULTRA queue[1000000];
int N;
int o[100 + 10][100 + 10];
int m[100 + 10][100 + 10];
ULTRA input_node;

int px[4] = { -1, 1, 0, 0 };
int py[4] = { 0, 0, -1, 1 };

int inqueue(int x, int y);
ULTRA* dequeue();

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &o[i][j]);
		}
	}

	inqueue(0, 0);
	while (1) {
		ULTRA* a = dequeue();
		if (a == NULL) {
			break;
		}
		int x = a->x;
		int y = a->y;
		for (int i = 0; i < 4; i++) {
			if (x + px[i] < 0 || x + px[i] >= N || y + py[i] < 0 || y + py[i] >= N) {
				continue;
			}
			if (m[x + px[i]][y + py[i]] == 0) {
				m[x + px[i]][y + py[i]] = m[x][y] + o[x + px[i]][y + py[i]];
				inqueue(x + px[i], y + py[i]);
			}
			else if (m[x][y] + o[x + px[i]][y + py[i]] < m[x + px[i]][y + py[i]]) {
				m[x + px[i]][y + py[i]] = m[x][y] + o[x + px[i]][y + py[i]];
				inqueue(x + px[i], y + py[i]);
			}
		}
	}

	cout << m[N - 1][N - 1];

	return 0;
}

int inqueue(int x, int y) {

	input_node.x = x; input_node.y = y;
	queue[wt++] = input_node;

	return 0;
}

ULTRA* dequeue() {

	if (rd == wt) {
		return NULL;
	}

	return &queue[rd++];
}