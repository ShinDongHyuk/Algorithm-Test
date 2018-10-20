#include <iostream>
#define MAXNUM 10000
 
int departments[MAXNUM];
int max_budget = 0;
 
using namespace std;
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
        if (arr[j] <= pivot)
        {
            i++;
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
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
bool is_valid(int threshold, int N){
    int sum = 0;
    for (int i = 0; i < N ; i++) {
        if(threshold >= departments[i]) sum += departments[i];
        else sum += threshold;
    }
    return (sum <= max_budget);
}
 
int main(int argc, const char * argv[]) {
    int N;
    //read N
    cin >> N;
     
    //read budgets
    for (int i = 0 ; i < N; i++) {
        cin >> departments[i];
    }
     
    //read max budget
    cin >> max_budget;
     
    //sort budgets
    quickSort(departments, 0, N-1);
     
    //algorithm
    int left = 0, right = departments[N-1], mid = 0;
    while(left < right){
        mid = (left + right + 1) / 2;
         
        if(is_valid(mid, N)){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    cout << left << "\n";
    return 0;
}

