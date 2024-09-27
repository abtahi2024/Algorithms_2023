#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int r)
{
    int l_s=m-l+1;
    int r_s=r-m;
    int la[l_s],ra[r_s];
    int k=0;
    for(int i=l;i<=m;i++)
    {
        la[k]=a[i];
        k++;
    }
    k=0;
    for(int j=m+1;j<=r;j++)
    {
        ra[k]=a[j];
        k++;
    }
    int i=0,j=0;
    int cur=l;
    while(i<l_s&&j<r_s)
    {
        if(la[i]<=ra[j])
        {
            a[cur]=la[i];
            i++;
        }
        else
        {
            a[cur]=ra[j];
            j++;
        }
        cur++;
    }
    while(i<l_s)
    {
        a[cur]=la[i];
        i++;
        cur++;
    }
    while (j<r_s)
    {
       a[cur]=ra[j];
       j++;
       cur++;

    }
    

}
void divide(int a[], int l, int r)
{
   if(l<r)
   {
    int mid=(l+r)/2;
    divide(a,l,mid);
    divide(a,mid+1,r);
    merge(a,l,mid,r);

   }

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    divide(a,0,n-1);
      for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }


    return 0;
}