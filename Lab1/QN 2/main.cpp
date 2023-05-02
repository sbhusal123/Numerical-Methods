#include<iostream>
#include<math.h>
using namespace std;
class myclass
{
private:
    int n,i;
    float x[100],y[100];
    float sumx,sumxx,sumy,sumxy;
    float a,b;
public:
    myclass()
    {
        sumx=0;
        sumxx=0;
        sumy=0;
        sumxy=0;
    }

    void getdata(int s)
    {
        n=s;
        for(i=0;i<n;i++)
        {
            cout<<"x=";
            cin>>x[i];
            cout<<"y=";
            cin>>y[i];
            y[i]=log(y[i]);
        }
    }

    void getsum()
    {
        for(i=0;i<n;i++)
        {
            sumx=sumx+x[i];
            sumxx=sumxx+x[i]*x[i];
            sumy=sumy+y[i];
            sumxy=sumxy+x[i]*y[i];
        }
    }

    void solve()
    {
        a=(sumxx*sumy-sumx*sumxy)/(n*sumxx-sumx*sumx);
        b=(n*sumxy-sumx*sumy)/(n*sumxx-sumx*sumx);
    }

    void result()
    {
        a=exp(a);
        cout<<"a="<<a<<endl<<"b="<<b;
    }
};
int main()
{
    int n;
    myclass m;
    cout<<"Enter the no of data"<<endl;
    cin>>n;
    m.getdata(n);
    m.getsum();
    m.solve();
    m.result();
}
