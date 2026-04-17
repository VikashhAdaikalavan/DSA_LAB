#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int sum, prefix, suffix,best;
}Node;

int maxi(int a, int b)
{
    return a>b?a:b;
}

Node make(int x)
{
    Node new;
    new.best = new.sum = new.prefix = new.suffix = x;
    return new;
}

Node merge(Node l, Node r)
{
    Node res;
    res.sum = l.sum + r.sum;
    res.prefix = maxi(l.prefix, l.sum+r.prefix);
    res.suffix = maxi(r.suffix,r.sum + l.suffix);
    res.best = maxi(maxi(l.best,r.best),l.suffix+r.prefix);
    return res;
}

Node func(int n, int arr[n],int l, int r)
{
    if(l == r) return make(arr[l]);

    int mid = (l+r)/2;
    Node left = func(n,arr,l,mid);
    Node right = func(n,arr,mid+1,r);
    Node ans = merge(left,right);
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i =0 ; i<n ; i++) scanf("%d",&arr[i]);
    printf("%d\n",(func(n,arr,0,n-1)).best);
    return 0;
}

