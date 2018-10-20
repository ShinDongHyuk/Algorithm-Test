#include <iostream>
#define QUEUE_MAX_SIZE 10000
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
 
int MAP[101][101];
int visited[101][101] = {0};
 
int M, N;
 
struct ZERGLING{
    int r;
    int c;
};
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int num_of_zerglings = 0;
 
bool is_inside(int r, int c){
    if(r <= 0 || r > N || c <= 0 || c > M){
        return false;
    }
    return true;
}
 
int bfs(Queue<ZERGLING> &q){
    int level = -1;
    while(!q.IsEmpty()){
        int size = q.Get_Nums();
        for(int i = 0 ; i < size; i++){
            ZERGLING z = q.Get();
             
//        	ZERGLING new_z_list[4];
//        	int new_z_list_idx = 0;
            for(int j = 0 ; j < 4; j++){
                int new_r = z.r + dx[j];
                int new_c = z.c + dy[j];
                if(is_inside(new_r, new_c) && MAP[new_r][new_c] == 1 && !visited[new_r][new_c]){
                    ZERGLING new_z;
                    new_z.r = new_r;
                    new_z.c = new_c;
                    q.Put(new_z);
                    visited[new_r][new_c] = 1;
                    num_of_zerglings--;
                    //new_z_list[new_z_list_idx++] = new_z;
                }
            }
//        	for(int new_i = 0; new_i < new_z_list_idx; new_i++){
//
//        	}
        }
        level++;
    }
    return level;
}
 
int main(){
    cin >> M >> N;
    Queue<ZERGLING> zerglings;
    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= M; j++){
            char tmp;
            cin >> tmp;
            MAP[i][j] = tmp - '0';
            if(MAP[i][j] == 1) {
                ZERGLING z;
                z.r = i;
                z.c = j;
                num_of_zerglings++;
            }
        }
    }
     
    ZERGLING start_z;
    cin >> start_z.c >> start_z.r;
 
    zerglings.Put(start_z);
    visited[start_z.r][start_z.c] = 1;
    num_of_zerglings--;
 
    cout << bfs(zerglings) + 3 << "\n";
    cout << num_of_zerglings << "\n";
     
    return 0;
}

