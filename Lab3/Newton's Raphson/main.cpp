#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
using namespace std;
float f(float x)
{
    return (x*x*x*x-x-10);
}
float fd(float x)
{
    return(4*x*x*x-1);
}
int main()
{
    float a,b,result;
    cout<<"Enter the limits"<<endl;
    cin>>a>>b;
    while(f(a)*f(b)>0)
    {
        cout<<"Entered invalid limits enter again."<<endl;
        cin>>a>>b;
    }
    result=b; ///using initial guess.
    ///different initial guess may differ number of iteration.
    cout<<"Iteration\tX"<<endl;
    cout<<"--------------------------------------------"<<endl;
    int i=1;
    for(i=0;i<110;i++)
    {
        cout<<i<<"        "<<"\t"<<result<<endl;

        if(i>100)
        {
            cout<<"Oscillation between local maxima and zero";
            return 0;
        }

        else if(fd(result)==0)
        {
            cout<<"Division by zero"<<endl;
            return 0;
        }

        if(fabs(f(result))<0.0001)
        {
            cout<<"--------------------------------------------"<<endl;
            cout<<"Root is "<<result<<endl;
            return 0;
        }
        result=result-(f(result)/fd(result));
    }
    cout<<"Root jumping solution doesn't converges."<<endl;
    return 0;
}
