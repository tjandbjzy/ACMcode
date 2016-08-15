#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1

struct Tr{
    int val;
}tr[N<<2];

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

void pushUp(int rt){
    tr[rt].val=gcd(tr[rt<<1].val, tr[rt<<1|1].val);
}

void build(int l, int r, int rt){
    if(l==r){
        scanf("%d", &tr[rt].val);
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}

int query(int ql, int qr, int l, int r, int rt){
    if(ql==l && qr==r){
        return tr[rt].val;
    }
    int mid=(l+r)>>1;
    if(ql>mid) return query(ql, qr, rson);
    else if(qr<=mid) return query(ql, qr, lson);
    else return gcd(query(ql, mid, lson), query(mid+1, qr, rson));
}

int main(){
    int t, n, q, u, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        build(1, n, 1);
        scanf("%d", &q);
        while(q--){
            scanf("%d %d", &u, &v);
            printf("%d\n", query(u, v, 1, n, 1));
        }
    }
    return 0;
}
