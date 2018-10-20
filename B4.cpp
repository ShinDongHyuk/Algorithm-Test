#include <iostream>

using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, m;
int chcnt;
int cnt;
int cheese[102][102];
int visit[102][102];

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = 0;
		}
	}
}

void dfs(int a, int b) {
	visit[a][b] = 1;
	for (int i = 0; i<4; i++) {
		if (cheese[a + dx[i]][b + dy[i]] == 1 && !visit[a + dx[i]][b + dy[i]]) {
			cheese[a + dx[i]][b + dy[i]] = 0;
			visit[a + dx[i]][b + dy[i]] = 1;
			chcnt--;
			cnt++;
		}
		else if (cheese[a + dx[i]][b + dy[i]] == 0 && !visit[a + dx[i]][b + dy[i]]) {
			dfs(a + dx[i], b + dy[i]);
		}
	}

}

int main(void) {

	cin >> n >> m;
	for (int i = 0; i < 102; i++) {
		fill(cheese[i], cheese[i] + 102, -1);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) {
				chcnt++;
			}
		}
	}

	int k = 0;
	while (chcnt) {
		k++;
		cnt = 0;
		dfs(1, 1);
		init();
	}
	cout << k << "\n" << cnt;

}