#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int i=1,n;
	cin>>n;
	getchar();
	while(i<n+1)
	{
		string Vines;
		getline(cin, Vines);
		int number=0,y=0;
		for(int m=0;m<Vines.length();m++)
		{
			if (Vines[m]=='[')
			    number++;
			if (Vines[m]==']') 
				number--;
			if (y<number)
			    y=number;
				    
		}
		cout<<i<<" "<<(int)pow(2,y)<<endl;
		i++;
	}
	return 0;
}
