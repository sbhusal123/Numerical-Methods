#include<iostream>
using namespace std;
class myclass
{
private:
    float a=0,b=0;
    int n,i,j;
    float x[100],y[100];
    float sumx,sumxx,sumxy,sumy;
public:

    myclass(int sz)
    {
        n=sz;
        sumx=0;
        sumxx=0;
        sumxy=0;
        sumy=0;
    }


    void getData()
    {
        cout<<"Enter the values of x and y correspondingly"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"x=";
            cin>>x[i];
            cout<<"y=";
            cin>>y[i];
        }
    }

    void calSum()
    {
        for(i=0;i<n;i++)
        {
          sumx=sumx+x[i];
          sumxx=sumxx+x[i]*x[i];
          sumy=sumy+y[i];
          sumxy=sumxy+x[i]*y[i];
        }
    }

    void calab()
    {
        a=(sumy*sumx-n*sumxy)/(sumx*sumx-n*sumxx);
        b=(sumxy*sumx-sumy*sumxx)/(sumx*sumx-n*sumxx);
        cout<<"---------\n"<<"a="<<a<<endl<<"b="<<b<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter the size of n"<<endl;
    cin>>n;
    myclass m(n);
    m.getData();
    m.calSum();
    m.calab();
}
