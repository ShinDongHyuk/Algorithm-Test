#include <iostream>
#define QUEUE_MAX_SIZE 1000000
using namespace std;
 
 
template <typename T>
class Queue{
private:
    T *buffer;
    const int size = QUEUE_MAX_SIZE;
    int front;
    int rear;
    int nums;
     
public:
    Queue();
    Queue(int q_size);
    ~Queue();
    bool Put(T data);
    T Get();
    bool IsFull();
    bool IsEmpty();
    int Get_Nums();
    int Next(int now);
     
};
 
template <typename T>
Queue<T>::Queue(){
    buffer = new T[QUEUE_MAX_SIZE];
    front = rear = 0;
    nums = 0;
}
 
template <typename T>
Queue<T>::Queue(int q_size){
    buffer = new int[q_size];
    front = rear = 0;
    nums = 0;
}
 
 
template <typename T>
Queue<T>::~Queue(){
    delete[] buffer;
    nums = 0;
}
 
template <typename T>
bool Queue<T>::Put(T data){
    if(IsFull())
    {
        return false;
    }
    nums++;
    buffer[rear] = data;
    rear = Next(rear);
    return true;
}
 
template <typename T>
T Queue<T>::Get(){
    nums--;
    T re = buffer[front];
    front = Next(front);
    return re;
}
 
template <typename T>
bool Queue<T>::IsFull(){
    return Next(rear) == front;
}
 
template <typename T>
bool Queue<T>::IsEmpty(){
    return front == rear;
}
 
template <typename T>
int Queue<T>::Get_Nums(){
    return nums;
}
 
template <typename T>
int Queue<T>::Next(int now)
{
    return (now+1)%size;
}
 
int box[1001][1001];
 
int M, N;
 
struct TOMATO{
    int r;
    int c;
};
typedef struct TOMATO TOMATO;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
 
bool is_inside(int r, int c){
    if(r < 0 || r > N-1 || c < 0 || c > M-1){
        return false;
    }
    return true;
}
 
int bfs(Queue<TOMATO> &q){
    int level = -1;
    while(!q.IsEmpty()){
        int size = q.Get_Nums();
        for(int i = 0 ; i < size; i++){
            TOMATO t = q.Get();
             
            TOMATO new_t_list[4];
            int new_t_list_idx = 0;
            for(int j = 0 ; j < 4; j++){
                int new_r = t.r + dx[j];
                int new_c = t.c + dy[j];
                if(is_inside(new_r, new_c) && box[new_r][new_c] == 0){
                    box[new_r][new_c] = 1;
                    TOMATO new_t;
                    new_t.r = new_r;
                    new_t.c = new_c;
                    new_t_list[new_t_list_idx++] = new_t;
                }
            }
            for(int new_i = 0; new_i < new_t_list_idx; new_i++){
                q.Put(new_t_list[new_i]);
            }
        }
        level++;
    }
    return level;
}
 
bool check(){
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(box[i][j] == 0) return false;
        }
    }
    return true;
}
 
 
int main(){
    cin >> M >> N;
    Queue<TOMATO> tomotoes;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            cin >> box[i][j];
             
            if(box[i][j] == 1) {
                TOMATO t;
                t.r = i;
                t.c = j;
                tomotoes.Put(t);
            }
        }
    }
    int days = bfs(tomotoes);
    if(!check()) printf("-1\n");
    else printf("%d\n",days);
    return 0;
}

