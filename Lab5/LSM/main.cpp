#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
    float  x[10],y[10]; ///entering the data;
    float sumx=0,sumy=0,sumxy=0,sumxxy=0,sumxx=0,sumxxx=0,sumxxxx=0;
    int n,j,k,i;
    cout<<"How many data you want to enter"<<endl;
    cin>>n;
    cout<<"Enter x and y correspondingly"<<endl;
    ///data input
    for(i=0; i<n; i++)
    {
        cout<<"x"<<i+1<<":";
        cin>>x[i];
        cout<<"y"<<i+1<<":";
        cin>>y[i];
    }

    ///calculating the required variables;
    for(i=0; i<n; i++)
    {
        sumy=sumy+y[i];
        sumx=sumx+x[i];
        sumxy=sumxy+x[i]*y[i];
        sumxx=sumxx+pow(x[i],2);
        sumxxx=sumxxx+pow(x[i],3);
        sumxxxx=sumxxxx+pow(x[i],4);
        sumxxy=sumxxy+pow(x[i],2)*y[i];
    }
    ///assign to matrix;
    float mat[3][4];
    mat[0][0]=sumxx;
    mat[0][1]=sumx;
    mat[0][2]=n;
    mat[0][3]=sumy;
    mat[1][0]=sumxxx;
    mat[1][1]=sumxx;
    mat[1][2]=sumx;
    mat[1][3]=sumxy;
    mat[2][0]=sumxxxx;
    mat[2][1]=sumxxx;
    mat[2][2]=sumxx;
    mat[2][3]=sumxxy;

    ///now solving the equation with elimination.
    float sum,sol[3]= {0},sub=0;


    ///elimination.
    for(j=0; j<3-1; j++)
    {
        for(i=j+1; i<3; i++)
        {
            sub=mat[i][j]/mat[j][j]; ///get subtraction ratio for making lower zero.
            for(k=0; k<3+1; k++)
            {
                mat[i][k]-=mat[j][k]*sub; ///multiply each row with sub.
            }
        }
    }




    ///Back substitution.

    for(i=3; i>=0; i--)
    {
        sum=0;
        for(j=i; j<3; j++)
        {
            sum=sum+mat[i][j]*sol[j];
            sol[i]=(mat[i][3]-sum)/mat[i][i];
        }
    }

    cout<<endl<<"Required Equation is"<<endl;
    cout<<"______________"<<endl;
    cout<<setprecision(1)<<sol[0]<<"x^2+"<<sol[1]<<"x+"<<sol[2]<<endl;
    cout<<"______________"<<endl;
    return 0;
}
