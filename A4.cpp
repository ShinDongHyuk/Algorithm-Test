#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int cows[80000];
    int N;
    int cn = 0;
    unsigned sum = 0;
     
    cin >> N;
     
    for( int i = 0 ; i < N ; i++ )
    {
        int hi;
        scanf("%d", &hi);
        while( cn > 0 && cows[cn-1] <= hi ) cn--;
        sum += cn;
        cows[cn++] = hi;
    }
    cout << sum;
}

