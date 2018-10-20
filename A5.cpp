#include <iostream>
#define MAX 100
using namespace std;
 
int MAP[MAX][MAX];
int N;
 
void print_map(){
    for(int i = 0 ; i < MAX; i++){
        for(int j = 0 ; j < MAX; j++){
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}
 
bool is_edge(int r, int c){
    return (r-1 < 0 || c-1 < 0 || r+1 >= MAX || c+1 >= MAX);
}
 
int get_count(int r, int c){
    int total = 4;
    if(is_edge(r, c)){
        //corner
        if( (r-1 < 0 && c-1 < 0) || (r-1 < 0 && c+1 >= MAX) || (r+1 >= MAX && c+1 >= MAX) || (r+1 >= MAX && c-1 < 0)) {
            total -= 2;
        }
        //side edge
        else{
            if(r-1 < 0) total = total - (MAP[r][c-1] + MAP[r+1][c] + MAP[r][c+1]);
            else if(r+1 >=MAX) total = total - (MAP[r][c-1] + MAP[r-1][c] + MAP[r][c+1]);
            else if(c-1 < 0) total = total - (MAP[r-1][c] + MAP[r+1][c] + MAP[r][c+1]);
            else if(c+1 >= MAX) total = total - (MAP[r-1][c] + MAP[r+1][c] + MAP[r][c-1]);
         }
    }
    else{
        //inside
         
        total = total - (MAP[r-1][c] + MAP[r][c-1] + MAP[r+1][c] + MAP[r][c+1]);
    }
    return total;
}
 
int main(int argc, const char * argv[]) {
     
    //initialize MAP
    for(int i = 0 ; i < MAX ; i++){
        for (int j = 0; j < MAX; j++) {
            MAP[i][j] = 0;
        }
    }
     
    //read N;
    cin >> N;
     
    //map coloring
    for(int i = 0 ; i < N; i++){
        int offset_c, offset_r;
        cin >> offset_c >> offset_r;
        for(int c = offset_c; c < offset_c + 10; c++){
            for (int r = offset_r; r < offset_r + 10; r++) {
                MAP[r][c] = 1;
            }
        }
    }
     
     
     
    //algorithm
    int ans = 0;
    for(int i = 0 ; i < MAX; i++){
        for (int j = 0 ; j < MAX; j++) {
            //if the pixel is colored
            if(MAP[i][j] == 1){
                ans += get_count(i, j);
            }
            //else pass
        }
    }
     
    //print_map();
    cout << ans << "\n";
     
     
     
    return 0;
}

