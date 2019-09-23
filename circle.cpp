#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int fmed(lli arr[],lli n)
{
    sort(arr,arr+n);
    return arr[n/2];
}

void swap(lli *a, lli *b) 
{ 
    lli temp = *a; 
    *a = *b; 
    *b = temp; 
} 

lli par(lli arr[],lli l,lli r,lli x)
{
    lli i=l;
    for(i=l;i<r;i++)
    {
        if(arr[i]==x)
        break;

    }
    swap(&arr[i],&arr[r]);
    i=l;
    for(int j=l;j<=r-1;j++)
    {
        if(arr[j]<arr[r])
        {
        swap(&arr[i],&arr[j]);
        i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}
lli kthsmall(lli arr[],lli l,lli r,lli k)
{
    if(k>0 && k<=r-l+1)
    {
    lli n;
    n=r-l+1;
    lli med[(n+4)/5];
    lli i;
    for(i=0;i<n/5;i++)
    {
        med[i]=fmed(arr+l+i*5,5);
    }
    if(i*5<n)
    {
        med[i] = fmed(arr+l+i*5, n%5);  
        i++; 
    }
    lli mofm;
    if(i==1)
    {
        mofm=med[i-1];
    }
    else
    {
        mofm=kthsmall(med,0,i-1,i/2);
    }
        lli p=par(arr,l,r,mofm);
        if(p-l==k-1)
        {
            return arr[p];
        }   
        else if(p-l>k-1)
        {
            return kthsmall(arr,l,p-1,k);
        }
        else 
        return kthsmall(arr,p+1,r,k-p+l-1);

    }
    return INT_MAX;
}
lli frad(lli x[],lli y[],long int n)
{
    lli d[n];
    for(int i=0;i<n;i++)
    {
        d[i]=x[i]*x[i]+y[i]*y[i];
    }
    lli r=kthsmall(d,0,n-1,n/2);
    return r; 
}
int main()
{
    int t;
    cin>>t;
    for(int u=1;u<=t;u++)
    {
    long int o;
    cin>>o;
    lli x[o];
    lli y[o];
    for(lli i=0;i<o;i++)
    {
        cin>>x[i]>>y[i];
    }
     
    cout<<sqrtl(frad(x,y,o))<<endl;
    }
}    
