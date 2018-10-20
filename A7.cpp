#include <iostream>
#define MAX 20
#define NUM_MAX_LEN 9
using namespace std;
 
int my_depth;
int N ;
 
struct COW {
    int weight[NUM_MAX_LEN];
    int num_len;
};
 
COW cows[MAX];
COW cows_comb[MAX];
 
int ans = 0;
void pick(int depth, int start){
    if(depth > my_depth){
        //calculate
        for(int i = 0 ; i < NUM_MAX_LEN; i++){
            int tmp_sum = 0;
            for(int j = 0 ; j < my_depth; j++){
                tmp_sum += cows_comb[j].weight[i];
            }
            if(tmp_sum >= 10) return;
        }
         
        ans = my_depth;
        return;
    }
     
    for (int i = start; i < N;) {
        cows_comb[depth-1] = cows[i];
        pick(depth+1, ++i);
    }
}
 
int main(int argc, const char * argv[]) {
    cin >> N;
     
    //init
    for(int i = 0; i < N; i++){
        int cow_weight;
        int tmp_len = 0;
        cin >> cow_weight;
         
        int j = 0;
        while(cow_weight > 0){
            ++tmp_len;
            cows[i].weight[j++] = cow_weight%10;
            cow_weight /= 10;
        }
        //fill with zero
        for(; j < 9; j++){
            cows[i].weight[j] = 0;
        }
        //set num of arr
        cows[i].num_len = tmp_len;
    }
     
    //algorithm
    for(my_depth = 1 ; my_depth <= N; my_depth++){
        pick(1, 0);
    }
    cout << ans << "\n";
    return 0;
}

