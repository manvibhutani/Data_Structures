//Manvi, 12213106
#include<iostream>
using namespace std;
int main()
{int num=10;
    int arr[num];
    int a[]={12,18,13,2,3,23,5,15};
    for(int i=0; i<num; i++)
    {
        arr[i]=-1;
    }
    for(int i=0; i<8; i++)
    {
        int k=a[i]%10;
        if(arr[k]==-1)
        {
            arr[k]=a[i];
        }
        else
        {
            while(arr[k]!=-1)
            {
                k+=1;
            }
            arr[k]=a[i];
        }
    }
    for(int i=0; i<num; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}