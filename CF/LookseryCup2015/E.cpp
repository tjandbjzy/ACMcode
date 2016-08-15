#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cfloat>

using namespace std;
const double PI = acos(-1.0);
struct Point{
	double x,y;
	Point(double x = 0,double y = 0):x(x),y(y){}
};
typedef Point Vec;
Vec operator + (Vec a,Vec b){return Vec(a.x+b.x,a.y+b.y);}
Vec operator - (Point a,Point b){return Vec(a.x-b.x,a.y-b.y);}
Vec operator * (Vec a,double p){return Vec(a.x*p,a.y*p);}
Vec operator / (Vec a,double p){return a*(1/p);}
bool operator < (const Point& a,const Point& b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
const double EPS = 1e-10;
int dcmp(double x){
	if(fabs(x) < EPS) return 0;else return x < 0 ? -1 : 1;
}
bool operator == (const Point& a,const Point& b){
	return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}
double ang(Vec v){return atan2(v.y,v.x);}

double Dot(Vec A,Vec B){return A.x * B.x + A.y * B.y;}
double Length(Vec A){return sqrt(Dot(A,A));}
double Angle(Vec A,Vec B){return acos(Dot(A,B)/Length(A)/Length(B));}

double Cross(Vec A,Vec B){return A.x * B.y - A.y * B.x;}

Point CirCenter(Point a,Point b,Point c){
	double a1 = b.x - a.x,b1 = b.y - a.y,c1 = (a1 * a1 + b1 * b1)/2;
	double a2 = c.x - a.x,b2 = c.y - a.y,c2 = (a2 * a2 + b2 * b2)/2;
	double d = a1 * b2 - a2 * b1;
	return Point(a.x + (c1 * b2 - c2 * b1)/d,a.y + (a1 * c2 - a2 * c1)/d);
}

vector<Point> ConvexHull(vector<Point> p){
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	int n = p.size();
	vector<Point> ch(n+1);
	int m = 0;
	for(int i=0;i<n;i++){
		while(m>1 && dcmp(Cross(ch[m-1] - ch[m-2],p[i]-ch[m-2]))<=0)m--;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i=n-2;i>=0;i--){
		while( m>k && dcmp(Cross(ch[m-1] - ch[m-2],p[i] - ch[m-2])) <= 0)m--;
		ch[m++] = p[i];
	}
	if( n > 1)m--;
	ch.resize(m);
	return ch;
}

bool judge(const vector<Point>& a,const vector<Point>& b,int i,int j){
	double minr = -DBL_MAX,maxr = DBL_MAX;
	int mid = -1;
	int na = a.size(),nb = b.size();
	bool flag = true;
	for(int k=i+1;k<j;k++){
		if(dcmp(Cross(a[k]-a[i],a[k]-a[j]))==0){
			flag = false;
			break;
		}
		Point center = CirCenter(a[i],a[j],a[k]);
		double r = Length(center - (a[i]+a[j])/2.0);
		if(dcmp(Cross(center-a[i],a[j]-a[i]))*dcmp(Cross(a[k]-a[i],a[j]-a[i]))<0)r = -r;
		if(dcmp(r-minr)>0)
			minr = r,mid = k;
	}
	if(flag){
		for(int k=(j+1)%na;;k = (k+1)%na){
			if(k == i)break;
			if(dcmp(Cross(a[k]-a[i],a[k]-a[j]))==0){
				flag = false;
				break;
			}
			Point center = CirCenter(a[i],a[j],a[k]);
			double r = Length(center - (a[i]+a[j])/2.0);
			if(dcmp(Cross(center-a[i],a[j]-a[i]))*dcmp(Cross(a[k]-a[i],a[j]-a[i]))>0)r = -r;
			if( dcmp(r-maxr)<0)maxr = r;
		}
	}
	//printf("maxr: %lf minr: %lf i: %d j:%d\n",maxr,minr,i,j);
	bool ok = true;
	if(flag){
		for(int k=0;k<nb;k++){
			if(dcmp(Cross(b[k]-a[i],a[j]-a[i]))==0 && dcmp(Dot(a[i]-b[k],a[j]-b[k]))<=0 ){
				ok = false;
				break;
			}
			Point center = CirCenter(a[i],a[j],b[k]);
			double r = Length(center - (a[i]+a[j])/2.0);
			if(dcmp(Cross(center-a[i],a[j]-a[i]))*dcmp(Cross(b[k]-a[i],a[j]-a[i]))<0)r = -r;
			//printf("r :%lf x: %lf y:%lf\n",r,b[k].x,b[k].y);
			if(dcmp(Cross(b[k]-a[i],a[j]-a[i]))>0){
				if(dcmp(r-maxr)<0)maxr = r;
			}
			else if(dcmp(Cross(b[k]-a[i],a[j]-a[i]))<0){
				r = -r;
				if(dcmp(minr-r)<0)minr = r;
			}
			if( dcmp(maxr-minr) <= 0){
				ok = false;
				break;
			}
		}
	}
	else ok = false;
	return ok || (mid >=0 && (judge(a,b,i,mid) || judge(a,b,mid,j))); 
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	vector<Point> ina(n),inb(m);
	int x,y;
	for(int i=0;i<n;i++)
		scanf("%d%d",&x,&y),ina[i].x = (double)x,ina[i].y = (double)y;
	for(int i=0;i<m;i++)
		scanf("%d%d",&x,&y),inb[i].x = (double)x,inb[i].y = (double)y;
	vector<Point> a = ConvexHull(ina),b = ConvexHull(inb);
	puts((judge(a,inb,0,a.size()-1) || judge(b,ina,0,b.size()-1)) ? "YES" : "NO");
	return 0;
}
