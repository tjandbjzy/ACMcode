#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int path (int j, int p[8], int dist[8], int m[8][8], int c);

int main() {
	int MAX = 1001;
    int a, b, m[8][8];
    for (a = 0; a <= 7; a++)
    	for (b = 0; b <= 7; b++)
    		m[a][b] = MAX;
    m[1][2] = 1;
    m[1][3] = 4;
    m[1][4] = 6;
    m[2][5] = 7;
    m[2][6] = 6;
    m[3][5] = 1;
    m[3][6] = 5;
    m[4][6] = 8;
    m[5][7] = 2;
    m[6][7] = 1;

    int p[8] = {0};
    int dist[8] = {10001};
    //dist[1] = 0;

	for(int i = 1; i <= 7; ++i){
        cout << dist[i] << endl;
    }
    int i, j, distance = 0;
    for (j = 2; j <= 7; j++) {
        dist[j] = dist[1] + m[1][j];
        
        for (i = 2; i <= 7; i++){
            distance = dist[i] + m[i][j];
            
            if (distance < dist[j])
            {
                dist[j] = distance;
            }
            
        }
    }

    int c = 0;
	//int count = path (7, p, dist, m, c);
	//cout << count;
    cout << "the shortest distance is " << dist[7] << endl;
    cout << "the path is ";
    //for (int d = count; d > 0; d--) cout << p[d] ;
    return 0;
}

int path (int j, int p[], int dist[], int m[8][8], int c) {//逆推找路径 
		int distance;
		dist[j] = dist[1] + m[1][j];
        for (int i = 2; i <= 7; i++){
            distance = dist[i] + m[i][j];
            if (distance < dist[j])
            {
                dist[j] = distance;
                p[c] = i;
            }
        }
        if (p[c] == 1) return c;
        else return path(p[c], p, dist, m, c+1);
} 
