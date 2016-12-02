#include<iostream>
using namespace std;

char field[1001][1001];
void football(int currentrow, int currentcolumn, int row, int column)
{
    bool isloop;
    int a[1000],b[1000];
    int steps=0, i=0;
    while(currentrow>=0 && currentcolumn<row &&currentcolumn>=0 &&currentcolumn<column){
        switch(field[currentrow][currentcolumn]){
            case 'N':currentrow--;
            case 'S':currentrow++;
            case 'W':currentcolumn--;
            case 'E':currentcolumn++;
        }
        steps++;
        a[i]=currentrow;
        b[i]=currentcolumn;
        i++;

        for(int k=0; k<i-1; k++){
            if(currentrow==a[k] && currentcolumn==b[k]){
                if(i>1){
                        if(steps-i>1)
                            cout<<i<<" steps before a loop of "<<steps-i<<" steps"<<endl;
                        else
                            cout<<i<<" steps before a loop of "<<steps-i<<" step"<<endl;
                }
                else{
                    if(steps-i>1)
                            cout<<i<<" step before a loop of "<<steps-i<<" steps"<<endl;
                    else
                            cout<<i<<" step before a loop of "<<steps-i<<" steps"<<endl;
                }
                break;
                isloop=true;
            }
        }
        if(isloop)
                break;
    }
        if(isloop==false){
            if(steps>1)
                cout<<steps-1<<" steps to exit"<<endl;
            else
                cout<<"1 step to exit"<<endl;
        }

}
int main()
{
    int row,column,startplace;
    cin>>row>>column>>startplace;

    while(row!=0 && column!=0 && startplace!=0){
        for(int i=0; i<row; i++){
            for(int k=0; k<column; k++)
                cin>>field[i][k];
        }
        int currentrow=0,currentcolumn=startplace-1;
        football(currentrow, currentcolumn, row, column);
        cin>>row>>column>>startplace;
    }
    return 0;
}
