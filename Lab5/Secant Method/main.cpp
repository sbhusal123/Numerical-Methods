#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
float f(float x)
{
    return (x*x+5*x+1);
}
int main()
{
    float a=0,b=0,c=0,itr=0;
    cout<<"Enter the initial guess"<<endl;
    cin>>a>>b;
    cout<<"Itr\ta\tb\tc"<<endl;
    cout<<"--------------------------------------------"<<endl;
    do
    {
        cout<<itr<<"\t"<<a<<"\t"<<b<<"\t"<<c<<endl;
        itr++;
        c=b-((b-a)/(f(b)-f(a)))*f(b);
        a=b;
        b=c;
        if(itr>100)
        {
            cout<<"Root jumping"<<endl;
            return 0;
        }
        else if(f(a)==f(b))
        {
            cout<<"Root doesn't converges"<<endl;
            return 0;
        }
    }while(fabs(f(c)>0.00001));
    cout<<"--------------------------------------------"<<endl;
    cout<<"Root of the equation is:"<<c;
    return 0;
}
