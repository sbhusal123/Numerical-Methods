#include<iostream>
using namespace std;
int main()
{
    float x[100],y[100],xx;
    float yy,p,q;
    int i,j,n;
    yy=0;
    cout<<"Enter the no of data"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"x=";
        cin>>x[i];
        cout<<"y=";
        cin>>y[i];
    }
    cout<<"Enter the value of x"<<endl;
    cin>>xx;

    for(i=0;i<n;i++)
    {
        p=1,q=1;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                p=(xx-x[j])*p;
                q=(x[i]-x[j])*q;
            }
        }
        yy=(p/q)*y[i]+yy;
    }

    cout<<"Value of y="<<yy;
}
