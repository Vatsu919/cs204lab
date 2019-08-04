#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int mast(string s1,string s2)
{
 if(s1.length()>s2.length())
 {
     return 1;
 }
 else if(s2.length()>s1.length())
 {
     return 0;
 }
 else if(s1.length()==s2.length())
 {
     int i=0;
     while(i<s1.length())
     {
         int n1=s1[i]-'0';
         int n2=s2[i]-'0';
         if(n1>n2)
         {
             return 1;
         }         
         if(n2>n1)
         {
             return 0;
         }
         i++;
      }
 }
 return 1;
}
string dif(string s1,string s2)
{
    string h;
 if(mast(s1,s2)==0)
 {
  swap(s1,s2);
 }
 
 int l1=s1.length();
 int l2=s2.length();
  int borrow=0;
  int diff=0;
  int k=l1-l2;
  for(int i=l1-1;i>=k;i--)
  {
   diff=(s1[i]-'0')-(s2[i-k]-'0')-borrow;
   if(diff<0)
   {
       diff+=10;
       borrow=1;
   }
   else
   {
       borrow=0;
   }
   h.push_back(diff+'0');

  }
  for(int i=k-1;i>=0;i--)
  {
   diff=(s1[i]-'0')-borrow;
   if(diff<0)
   {
       diff+=10;
       borrow=1;
   }
   else
   {
       borrow=0;
   }
   h.push_back(diff+'0');

  }

reverse(h.begin(),h.end());
int i=0;
while(i<h.length())
{
    if(h[i]=='0')
    h.erase(h.begin()+i);
    else if(h[i]!='0')
    {
    break;
    }

 
}
if(h.length()==0)
{
    h='0';
}
return h;
}
int main()
{
 long long int k;
 cin>>k;
 for(int i=1;i<=k;i++)
 {
  string s1;
  string s2;
  cin>>s1;
  cin>>s2;
  cout<<dif(s1,s2)<<endl;
  }
return 0;
}
