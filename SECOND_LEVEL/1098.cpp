#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 110;
int Insert[maxn], Heap[maxn], n, Para[maxn];

void downAdjust(int low, int high)
{
    int i = low, j = i * 2;
    while(j <= high)
    {
        if(j + 1 <= high && Heap[j + 1] > Heap[j])
        {
            j = j + 1;
        }
        if(Heap[j] > Heap[i])
        {
            swap(Heap[j], Heap[i]);
            i = j;
            j = i * 2;
        }
        else
        {
            break;
        }
    }
};

void CreatHeap(int low, int high)
{
    for(int i = n / 2; i >= 1; i--)
    {
        downAdjust(i, n);
    }
};

void InsertSort(int low)
{
    if(Insert[low] < Insert[low - 1])
    {
        Insert[0] = Insert[low];  
        int i;      
        for(i = low - 1; Insert[i] > Insert[0]; i--)
        {
            Insert[i+1] = Insert[i];
        }
        Insert[i+1] = Insert[0];
    }
};

bool Judge(int A[])
{
    for(int i = 1; i < n; i++)
    {
        if(A[i] != Para[i])
        {
            return false;
        }
    }
    return true;
};

void Print(int A[])
{
    for(int i =1; i <= n; i++)
    {
        printf("%d", A[i]);
        if(i != n) printf(" ");
    }
    printf("\n");
};

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &Insert[i]);
        Heap[i] = Insert[i];
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &Para[i]);
    }
    CreatHeap(1, n);
    int j, index = n;
    bool judge;
    // InsertSort(2);
    // swap(Heap[1], Heap[index --]);

    for(j = 1; j < n; j++)
    {
        InsertSort(j+1);
        judge = Judge(Insert);
        if(judge == true)
        {
            printf("Insertion Sort\n");
            InsertSort(j+2);
            Print(Insert);
            break;
        }
        swap(Heap[1], Heap[index --]);
        downAdjust(1, index);
        judge = Judge(Heap);
        if(judge == true)
        {
            printf("Heap Sort\n");
            swap(Heap[1], Heap[index --]);
            downAdjust(1, index);
            Print(Heap);
        }
    }
    system("pause");
    return 0;
}
