#include<iostream>
#include<math.h>
using namespace std;

float f(float x)
{
    float m;
    m=1/(1+x);
    return m;
}
int main()
{
    int n,i;
    float a,b;
    float y[100],h,y1,y2=0,area;
    cout<<"Enter the number of interval"<<endl;
    cin>>n;
    cout<<"Enter the upper and lower limits"<<endl;
    cin>>a;
    cin>>b;
    h=(b-a)/n;

    for(i=0;i<=n;i++)
    {
        y[i]=f(a+i*h);
    }

    y1=y[0]+y[n];

    for(i=1;i<=n-1;i++)
    {
        y2=y2+y[i];
    }

    area=(h*(y1+2*y2))/2;
    cout<<"Area="<<area;
}
