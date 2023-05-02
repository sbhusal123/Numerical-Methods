#include<iostream>
using namespace std;
int main()
{
    ///solves upto 4 equation.
    float mat[5][5],sum,sol[5]={0},sub;
    int i,j,k,n;
    cout<<"Enter the no of eqn::";
    cin>>n;
    cout<<"Now enter the coefficients::"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Equation"<<i+1<<endl;
        for(j=0;j<n+1;j++)
        {
            cin>>mat[i][j];
        }
    }

    ///displaying augmented matrix.

    cout<<endl<<"Augmented Matrix"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }


    ///elimination.
    for(j=0;j<n-1;j++)
    {
        for(i=j+1;i<n;i++)
        {
            sub=mat[i][j]/mat[j][j]; ///get subtraction ratio for making lower zero.
            for(k=0;k<n+1;k++) ///multiply the row with same ratio.
            {
                mat[i][k]-=mat[j][k]*sub; ///multiply each row with sub.
            }
        }
    }


    cout<<endl<<"Upper Triangular Matrix is::"<<endl;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    ///Back substitution.

    for(i=n;i>=0;i--)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum=sum+mat[i][j]*sol[j];
            sol[i]=(mat[i][n]-sum)/mat[i][i];
        }
    }

    cout<<endl<<"Solutions are"<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"x"<<i+1<<"="<<sol[i]<<endl;
    }

    return 0;
}
