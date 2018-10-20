char puyo[13][7];
int v[13][7], q[10001], h, t;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool isPossibleFlag;
  
/*=====================
      방문 초기화
=======================*/
void visitInit() { // 0 = 미방문, 1 = 방문
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            v[i][j] = 0;
}
  
  
/*=====================
      뿌요 내리기
=======================*/
void puyoDown() {
    for (int i = 0; i < 6; i++) {
        for (int j = 11; j >= 0; j--) {
            if (puyo[j][i] != '.') { // 뿌요를 만나면 .을 다시 아래에서부터 검색
                for (int k = 11; k > j; k--) {
                    if (puyo[k][i] == '.') { // 가장 처음으로 만나는 .이랑 교체
                        char tmp = puyo[k][i];
                        puyo[k][i] = puyo[j][i];
                        puyo[j][i] = tmp;
                        break; // 더이상 찾지않게
                    }
                }
            }
        }
    }
}
  
  
  
/*=====================
    뿌요 찾아 없애기
=======================*/
void deletePuyo() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (puyo[i][j] != '.') {  // 뿌요를 찾음.
                char curPuyo = puyo[i][j]; // 현재 뿌요 상태값
                h = 0, t = 0;
                q[t++] = i * 100 + j;
                int puyoCnt = 0;
                visitInit();
                while (h != t) {  // BFS로 탐색
                    int pos = q[h++];
                    int x = pos / 100; // 위에서 x번째
                    int y = pos % 100; // 왼쪽에서 y번째
                    for (int dir = 0; dir < 4; dir++) {
                        int xx = x + dx[dir];
                        int yy = y + dy[dir];
                        if (xx < 0 || xx>11 || yy < 0 || yy>5) { continue; }
                        if (v[xx][yy] == 0 && puyo[xx][yy] == curPuyo) {
                            v[xx][yy] = ++puyoCnt;
                            q[t++] = xx * 100 + yy;
                        }
                    }
                }
                // BFS가 끝나고 뿌요 카운트가 4이상이면 큐를 다시 돌면서 해당 뿌요 .으로 변경
                if (puyoCnt >= 4) {
                    h = 0, isPossibleFlag = true;
                    while (h != t) {
                        int pos = q[h++];
                        int x = pos / 100;
                        int y = pos % 100;
                        puyo[x][y] = '.';
                    }
                }
            }
        }
    }
}
  
/*=====================
        메인 함수
=======================*/
int main() {
    int T;
    cin >> T;
    for( int test_case = 1; test_case <= T; test_case++){
        int result = 0;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                cin >> puyo[i][j];
            while (1) {
                isPossibleFlag = false;
                deletePuyo();
                puyoDown();
                if (isPossibleFlag==false) { break; }
                else { result++; }
            }
            cout << result << '\n';	
    }
    return 0;
}

