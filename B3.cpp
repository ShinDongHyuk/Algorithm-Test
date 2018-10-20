#include<iostream>
 
using namespace std;
int N;
 
int GARO, SERO;
 
int map[102][102];
 
int chk[102][102];
 
typedef struct {
     
    int posY;
     
    int posX;
     
} _pos;
 
_pos POSITION[1000000];
 
int main(int argc, const char * argv[])
 
{
     
    int i, j;
     
    scanf("%d", &N);
     
    scanf("%d %d", &SERO, &GARO);
     
    for (i = 1; i <= N; i++)
         
    {
         
        for (j = 1; j <= N; j++)
             
        {
             
            scanf("%d", &map[i][j]);
             
        }
         
    }
     
     
     
    for (i = 1; i <= N; i++)
         
    {
         
        for (j = 1; j <= N; j++)
             
        {
             
            chk[i][j] = 0x7fffffff;
             
        }
         
    }
     
     
     
    int head = 0, tail = 0;
     
    for (i = 0; i <= N +1; i++)
         
    {
         
        for (j = 0; j <= N +1; j++)
             
        {
             
            if (chk[i][j] == 0)
                 
            {
                 
                POSITION[tail].posY = i;
                 
                POSITION[tail].posX = j;
                 
                tail++;
                 
            }
             
        }
         
    }
     
     
     
    int Dy[] = { -1, 1, 0, 0 };
     
    int Dx[] = { 0, 0, -1, 1 };
     
    int temp;
     
    while (1)
         
    {
         
        if (head == tail) break;
         
        for (int dir = 0; dir < 4; dir++)
             
        {
             
            int tmpY = POSITION[head].posY + Dy[dir];
             
            int tmpX = POSITION[head].posX + Dx[dir];
             
            if (tmpY >= 1 && tmpX >= 1 && tmpY <= N && tmpX <= N)
                 
            {
                 
                temp = map[POSITION[head].posY][POSITION[head].posX] - map[tmpY][tmpX];
                 
                if (temp < 0) temp = temp * temp;
                 
                temp += chk[POSITION[head].posY][POSITION[head].posX];
                 
                if (chk[tmpY][tmpX] > temp)
                     
                {
                     
                    chk[tmpY][tmpX] = temp;
                     
                    POSITION[tail].posY = tmpY;
                     
                    POSITION[tail].posX = tmpX;
                     
                    tail++;
                     
                }
                 
            }
             
        }
         
        head++;
         
    }
    cout << chk[SERO][GARO] << "\n";
}

