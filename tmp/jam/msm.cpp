#include <iostream>
using namespace std;

#define N 6
#define MAXVALUE 1000000

void matrix_chain_order(int *p,int len,int m[N+1][N+1],int s[N+1][N+1]);
void print_optimal_parents(int s[N+1][N+1],int i,int j);

int main()
{
    int p[N+1] = {5, 10, 3, 12, 5, 50, 6};
    int m[N+1][N+1]={0};
    int s[N+1][N+1]={0};
    int i,j;
    matrix_chain_order(p,N+1,m,s);
    cout<<"m value is: "<<endl;
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=N;++j)
            cout<<m[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"s value is: "<<endl;
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=N;++j)
            cout<<s[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"The result is:"<<endl;
    print_optimal_parents(s,1,N);
    puts("");
    return 0;
}

void matrix_chain_order(int *p,int len,int m[N+1][N+1],int s[N+1][N+1])
{
    int i,j,k,t;
    for(i=0;i<=N;++i)
        m[i][i] = 0;
    for(t=2;t<=N;t++) 
    {
        for(i=1;i<=N-t+1;i++)
        {
            j=i+t-1;
            m[i][j] = MAXVALUE;  
            for(k=i;k<=j-1;k++)   
            {
                int temp = m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
                if(temp < m[i][j])
                {
                    m[i][j] = temp;   
                    s[i][j] = k;    
                }
            }
        }
    }
}

void print_optimal_parents(int s[N+1][N+1],int i,int j)
{
    if( i == j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print_optimal_parents(s,i,s[i][j]);
        print_optimal_parents(s,s[i][j]+1,j);
        cout<<")";
    }

}
