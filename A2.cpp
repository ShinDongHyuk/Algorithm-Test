#include <iostream>
#define MAX 500
 
int N;
struct MEETING {
    unsigned int id;
    int start_time;
    int finish_time;
};
 
MEETING MEETINGS[MAX];
 
using namespace std;
 
void swap(MEETING* a, MEETING* b)
{
    MEETING t = *a;
    *a = *b;
    *b = t;
}
 
//quick sort by finish time
int partition (MEETING meetings[], int low, int high)
{
    int pivot_finish_time = meetings[high].finish_time;
    int i = (low - 1);
     
    for (int j = low; j <= high- 1; j++)
    {
        if (meetings[j].finish_time < pivot_finish_time)
        {
            i++;
            swap(&meetings[i], &meetings[j]);
        }
        else if(meetings[j].finish_time == pivot_finish_time){
            if(meetings[j].start_time < meetings[high].start_time){
                i++;
                swap(&meetings[i], &meetings[j]);
            }
        }
    }
    swap(&meetings[i + 1], &meetings[high]);
    return (i + 1);
}
 
void quickSort(MEETING meetings[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(meetings, low, high);
        quickSort(meetings, low, pi - 1);
        quickSort(meetings, pi + 1, high);
    }
}
 
int main(int argc, const char * argv[]) {
     
    //read input
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> MEETINGS[i].id >> MEETINGS[i].start_time >> MEETINGS[i].finish_time;
    }
     
    //algorithm
 
    //sort
    quickSort(MEETINGS, 0, N-1);
     
    //greedy algorithm
    int ans = 1;
    int ans_id_list[MAX];
    ans_id_list[0] = MEETINGS[0].id;
    int prev_finish_time = MEETINGS[0].finish_time;
    for(int i = 1 ; i < N; i++){
        if(prev_finish_time <= MEETINGS[i].start_time){
            ans_id_list[ans++] = MEETINGS[i].id;
            prev_finish_time = MEETINGS[i].finish_time;
        }
    }
     
    //answer
    cout << ans << "\n";
    for(int i = 0 ; i < ans; i++){
        cout << ans_id_list[i] << " ";
    }
    return 0;
}

