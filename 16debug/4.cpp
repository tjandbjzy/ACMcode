#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    while (n != -1){
        if (n == 1){
            std::cin >> m;
            for(int i = 1; i <= m; i++){
                for(int j = 1; 2 * j <= m; j++){
                    cout << " " << endl;
                }
                for(int k = 1; k <= 2 * n - 1; k++){
                    cout << "*" << endl;
                }
            }
         }
    }
    return 0;
}
