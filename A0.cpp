#include <iostream>
#define MAXNUM 1000
using namespace std;
 
int prev_jump = 0;
int leaves[MAXNUM];
int ans = 0;
 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];	// pivot
    int i = (low - 1);  // Index of smaller element
     
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;	// increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high);
         
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
 
bool check(int idx1, int idx2){
    if(leaves[idx2] - leaves[idx1] >= prev_jump && leaves[idx2] - leaves[idx1] <= 2*prev_jump)
        return true;
    else return 0;
}
 
int main(int argc, const char * argv[]) {
    int N;
    // read N
    cin >> N;
    // read leaves
    for(int i = 0 ; i < N; i++) cin >> leaves[i];
     
    //sort leaves
    quickSort(leaves, 0, N-1);
     
    // algorithm
    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            prev_jump = leaves[j] - leaves[i];
            for (int k = j+1; k < N; k++) {
                if(check(j, k)) ++ans;
            }
        }
    }
     
    cout << ans << "\n";
    return 0;
}

