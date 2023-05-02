#include<iostream>
using namespace std;
int main()
{
    float mat[5][5],eigen_vector[5]= {0},mul[5]= {0},eigen_value=0,prev=0,sum;
    float prev_eigen_vector[5];
    int i,j,n,itr=1;
    bool repeat=true;
    cout<<"Enter the size of sq matrix"<<endl;
    cin>>n;
    cout<<"Enter the elements of matrix"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<"Enter the initial guess"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>eigen_vector[i];
    }


    do
    {

        cout<<"_____________________________"<<endl;
        cout<<"Iteration "<<itr<<endl;
        eigen_value=0;

        for(i=0; i<n; i++) ///matrix multiplication.
        {
            sum=0;
            for(j=0; j<n; j++)
            {
                sum=sum+mat[i][j]*eigen_vector[j];
                mul[i]=sum;
            }
        }
        itr++;

        for(i=0; i<n; i++) ///finding the largest for eigen value;
        {
            if(eigen_value<mul[i])
            {
                eigen_value=mul[i];
            }
        }

        if(prev==eigen_value) ///check if previous two corresponding are equal or not.
        {
            for(i=0;i<n;i++)
            {
                if(prev_eigen_vector[i]==eigen_vector[i])
                {
                 repeat=false;
                }

            }
        }

        cout<<endl<<"Eigen value="<<eigen_value<<endl;
        cout<<"Eigen vector is:"<<endl;

        for(i=0; i<n; i++) ///dividing by largest to find eigen vector.
        {
            eigen_vector[i]=mul[i]/eigen_value;
            cout<<eigen_vector[i]<<endl;
            prev_eigen_vector[i]=eigen_vector[i]; ///to check if last two result are same or not.
        }

        prev=eigen_value;
    }
    while(repeat);

    cout<<"_______________________________"<<endl;
    cout<<"So required eigenvalue="<<eigen_value<<endl;
    cout<<"Corresponding eigen vector is::"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<eigen_vector[i]<<endl;
    }

    return 0;
}
