#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string mul(string s1,string s2)
{
    string h;
int l1=s1.length();
int l2=s2.length();
int a[l1+l2]={0};
int mul=0;
int carry=0;
int p1=0;
int p2=0;
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
    for(int i=0;i<l1;i++)
    {
        carry=0;
    p2=0;
    for(int j=0;j<l2;j++)
    {
    mul=(s1[i]-'0')*(s2[j]-'0')+a[p1+p2]+carry;
    carry=mul/10;
    a[p1+p2]=mul%10;
    p2++;
    }
    if(carry!=0)
    {
    a[p1+p2]+=carry;
    }
    p1++;
    }
int i=p1+p2-2;
while(i>=0 && a[i]==0)
{
    i--;
}
if(i==-1)
{
    return "0";
}
while(i>=0)
{
 h.push_back(a[i]+'0');
 i--;
}
return h;
}
int main()
{
    long long int e;
    cin>>e;
    for(int i=1;i<=e;i++)
    {
     string w;
     string h;
     cin>>w;
     cin>>h;
     cout<<mul(w,h)<<endl;
    }
    
 return 0;

}
