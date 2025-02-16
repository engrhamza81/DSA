#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void bubblesort(int arr[],int size)
{
    
    for (int  i = 0; i <size; i++)
    {
        int swaap=0;
       for (int  j = 1; j< size; j++)
       {
        if(arr[j]<arr[j-1])
        {
            swap(arr[j],arr[j-1]);
            swaap=1;
        }
       }
       size=size-1;
       if (swaap==0)
       {
        break;
       }
       
        
    }
    
}
int main()
{
int size_arr;
cout<<"Enter Size Of Array:";
cin>>size_arr;
int array[size_arr];
for (int  i = 0; i < size_arr; i++)
{
    cout<<"Enter Element :"<<i+1<<" :";
    cin>>array[i];
}
bubblesort(array,size_arr);
cout<<"Sorted Array is :";
for (int  i = 0; i < size_arr; i++)
{
    cout<<array[i]<<"  ";
}




return 0;
}