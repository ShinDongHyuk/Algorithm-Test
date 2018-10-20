#include <iostream>
using namespace std;

typedef struct point {
	int x;
	int y;
	int time;
}POINT;

int enqueue(int x, int y, int t);
POINT* dequeue();
int move(int x, int y);

POINT queue[10000000];
int N, M;
char map2[50 + 5][50 + 5];
int map[50 + 5][50 + 5];
int tmp[50 + 5][50 + 5];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int answer;
int rd, wt;
POINT makeNode;

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map2[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map2[i][j] == 'W') {
				map[i][j] = 0;
			}
			if (map2[i][j] == 'L') {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				move(i, j);
			}
		}
	}

	cout << answer;

	return 0;
}

int move(int x, int y) {

	rd = 0; wt = 0;
	int veryFar = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = map[i][j];
		}
	}

	tmp[x][y] = 0;
	enqueue(x, y, 0);
	while (1) {
		POINT * newNode;
		newNode = dequeue();
		if (newNode == NULL) {
			break;
		}
		if (veryFar < newNode->time) {
			veryFar = newNode->time;
		}
		int a = newNode->x;
		int b = newNode->y;
		int t = newNode->time;
		for (int i = 0; i < 4; i++) {
			if (a + dx[i] < 0 || a + dx[i] >= N || b + dy[i] < 0 || b + dy[i] >= M)
				continue;
			if (tmp[a + dx[i]][b + dy[i]] == 1) {
				tmp[a + dx[i]][b + dy[i]] = 0;
				enqueue(a + dx[i], b + dy[i], t + 1);
			}
		}
	}

	if (answer < veryFar) {
		answer = veryFar;
	}

	return 0;
}

int enqueue(int x, int y, int t) {

	makeNode.x = x; makeNode.y = y; makeNode.time = t;
	queue[wt++] = makeNode;

	return 0;
}

POINT* dequeue() {

	if (rd == wt) {
		return NULL;
	}

	return &queue[rd++];
}