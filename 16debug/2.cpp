#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int times;
	cin >>times;
	getchar();
	for(int i =0; i < times; i++)
	{
	    int b =0;
		string vines;
		getline(cin,vines);
		if(vines.length() == 0)
		cout <<i+1<<" "<<1<<endl;
		else
		{
			for(int a = 0; a < (vines.length()-1); a++)
			{
				if(vines[a] =='[' && vines[a+1] != ']')
				b++;
			}
			cout <<i +1 <<" "<<pow(2,(b+1))<<endl;
		}
	}
}
