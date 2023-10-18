#include<iostream>
using namespace std;

int element_swapper(int a[],int size)
{
    for(int i=0;i<size;i+=2)
    {
        if(i+1<size)
        {
            swap(a[i],a[i+1]);
        }
    }
}
void printer(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int main()
{
    int a[5]={1,2,3,4,5};
    int b[4]={2,4,6,8};

    element_swapper(a,5);
    printer(a,5);

    element_swapper(b,4);
    printer(b,4);

}