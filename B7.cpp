#include <iostream>
using namespace std;

const int mapSize = 17;
const int queueSize = 60000;

struct queue {
	int redX;
	int redY;
	int blueX;
	int blueY;
	int count;
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

char map[mapSize][mapSize];
bool visitedRed[mapSize][mapSize];
bool visitedBlue[mapSize][mapSize];

queue myQueue[queueSize];

queue currentData;
queue nextData;

int X;
int Y;

int result;

int wp;
int rp;

bool endFlag = false;

bool isNotEmpty() {
	return wp > rp;
}

void push(queue data) {
	myQueue[wp++] = data;
}

queue pop() {
	return myQueue[rp++];
}

void init() {
	wp = 0;
	rp = 0;
	endFlag = false;
	result = -1;

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			visitedBlue[j][i] = false;
			visitedRed[j][i] = false;
		}
	}
}

int main() {

	int input;
	cin >> input;

	while (input--) {
		init();
		result = -1;

		cin >> Y;
		cin >> X;

		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'B') {
					nextData.blueX = j;
					nextData.blueY = i;
				}
				if (map[i][j] == 'R') {
					nextData.redX = j;
					nextData.redY = i;
				}
			}
		}

		/*
		for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
		cout << map[j][i];
		}
		cout << endl;
		}
		*/

		nextData.count = 0;
		push(nextData);
		visitedBlue[nextData.blueY][nextData.blueX] = true;
		visitedRed[nextData.redY][nextData.redX] = true;

		while (isNotEmpty()) {
			if (endFlag == true) break;
			currentData = pop();

			if (currentData.count == 10) break;

			for (int i = 0; i < 4; i++) {
				if (endFlag == true) break;
				nextData.blueX = currentData.blueX + dx[i];
				nextData.blueY = currentData.blueY + dy[i];
				nextData.redX = currentData.redX + dx[i];
				nextData.redY = currentData.redY + dy[i];

				if ((visitedRed[nextData.redY][nextData.redX] == true) &&
					(visitedBlue[nextData.blueY][nextData.blueX] == true)) {
					continue;
				}

				if ((map[nextData.blueY][nextData.blueX] == '#') && (map[nextData.redY][nextData.redX] == '#')) {
					continue;
				}

				if (map[nextData.blueY][nextData.blueX] == '#') {
					nextData.blueY -= dy[i];
					nextData.blueX -= dx[i];
				}
				if (map[nextData.redY][nextData.redX] == '#') {
					nextData.redY -= dy[i];
					nextData.redX -= dx[i];
				}

				if (map[nextData.redY][nextData.redX] == 'H') {
					result = currentData.count + 1;
					endFlag = true;
					break;
				}

				if (map[nextData.blueY][nextData.blueX] == 'H') {
					continue;
				}

				if ((nextData.blueX == nextData.redX) && (nextData.blueY == nextData.redY)) {
					continue;
				}

				nextData.count = currentData.count + 1;
				push(nextData);
				visitedBlue[nextData.blueY][nextData.blueX] = true;
				visitedRed[nextData.redY][nextData.redX] = true;
			}
		}
		cout << result << endl;
	}
}