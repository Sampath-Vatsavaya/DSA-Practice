#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans=0;
    int neg=0;
    int i=0;
    if(n<0)
    {
        n= ~n+1;
    }
   
    while(n!=0)
    {
        int bit=n&1;
        ans = (bit*pow(10,i)) + ans;
        i++;
        n=n>>1;

    }
    cout<<ans;
}