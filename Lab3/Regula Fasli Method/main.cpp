#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
using namespace std;
float f(float x)
{
    return (x*x*x-2*x-5);
}
int main()
{
    float a,b,result=0,itr=0;
    cout<<"Enter the limits"<<endl;
    cin>>a>>b;
    while(f(a)*f(b)>0)
    {
        cout<<"Entered invalid limits enter again."<<endl;
        cin>>a>>b;
    }

      cout<<"Iteration\tX0\tx1\tx2"<<endl;
       cout<<"--------------------------------------------"<<endl;
    do
    {
        itr++;
        cout<<itr<<"\t        "<<a<<"\t"<<b<<"\t"<<result<<"\t\t"<<endl;
        result=a-((b-a)/(f(b)-f(a)))*f(a);
        if(f(a)*f(result)>0)
        {
            a=result;
        }

        else
        {
            b=result;
        }
    }while(fabs(f(result))>0.0001);
    cout<<"--------------------------------------------"<<endl;
    cout<<"Root is="<<setprecision(5)<<result;
}
