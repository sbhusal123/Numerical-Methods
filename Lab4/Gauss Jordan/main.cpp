///gauss jordan  method.
#include<iostream>
using namespace std;
int main()
{
    float mat[5][5],sub,soln[5];
    int i,j,k,n;
    cout<<"Enter the no of equations"<<endl;
    cin>>n;
    ///input
    for(i=0;i<n;i++)
    {
        cout<<"Equation"<<i+1<<endl;
        for(j=0;j<n+1;j++)
        {
            cin>>mat[i][j];
        }
    }

    ///diago
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(i!=j) ///except diagonal element
            {
                sub=mat[i][j]/mat[j][j];
                for(k=0;k<n+1;k++)
                {
                    mat[i][k]-=mat[j][k]*sub;
                }
            }
        }
    }

        cout<<"matrix is"<<endl;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i=0;i<n;i++)
    {
      soln[i]=mat[i][n]/mat[i][i]; ///later diagonal element is divided.
    }

    cout<<"Solution are"<<endl;


    for(i=0;i<n;i++)
    {
      cout<<"x"<<i+1<<"="<<soln[i]<<endl;
    }

}
