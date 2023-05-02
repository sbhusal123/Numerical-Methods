#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n;
    float mat[10][10]= {0},sub;
    cout<<"Enter the size of sq matrix";
    cin>>n;
    cout<<"Enter the elements of matrix"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }

    for(i=0; i<n; i++) ///right one is set to unit matrix.
    {
        for(j=n; j<2*n; j++)
        {

            if(j==(i+n))
            {
                mat[i][j]=1;
            }
        }
    }


    cout<<"Augmented Matrix is "<<endl;

    ///display augmented matrix.
    for(i=0; i<n; i++)
    {
        for(j=0; j<n*2; j++)
        {
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }

    ///actual calculation.
    for(i=0; i<n; i++)
    {
        for(j=0; j<n*2; j++)
        {
            if(j!=i) ///perform for element except diagonal element.
            {
                sub=mat[j][i]/mat[i][i]; /// what constant to multiply and subtract.
                for(k=0; k<n*2; k++) ///subtract the elements of row with same.
                {
                    mat[j][k]-=mat[i][k]*sub;
                }
            }
        }
    }

    for(i=0; i<n; i++) ///dividing by diagonal element.
    {
        for(j=0; j<n*2; j++)
        {
            mat[i][j]=mat[i][j]/mat[i][i];
        }
    }


    cout<<"Required Inverse Matrix is: "<<endl;
    for(i=0; i<n; i++)
    {
        for(j=n; j<n*2; j++)
        {
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}
