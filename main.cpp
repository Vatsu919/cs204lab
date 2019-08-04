#include <bits/stdc++.h>

using namespace std;


string rezeros(string s)
 {
       int i=0;
         while(i<s.length())
         {
           if(s[i]=='0')
           s.erase(s.begin()+i);
           else if(s[i]!='0')
         {
           break;
         }
         }
return s;
}

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

string ad(string s1,string s2)
{
    string h;
 if(s1.length()<s2.length())
 {
     swap(s1,s2);
 }
 int su=0;  //su stores sum of two digits of string along with carry
 int ca=0;  //ca is carry variable initialised to 0
 int l1=s1.length();
 int l2=s2.length();
 int k=l1-l2;
         for(int i=l1-1;i>=k;i--)
         {
          su=(s1[i]-'0')+(s2[i-k]-'0')+ca;
          ca=su/10;
          su=su%10;
          h.push_back(su+'0');
         }
         for(int i=k-1;i>=0;i--)
         {
          su=(s1[i]-'0')+ca;
          su=su%10;
          h.push_back(su+'0');

        }
 reverse(h.begin(),h.end());
return h;

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

string mult(string s1,string s2)
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

char getq(string s1,string s2)
{
    char p='0';
            while(mast(s1,s2))
            {
                s1=dif(s1,s2);
                ++p;
            }
            return p;
}
int mulchar(char a,char b)
{
    return (a-'0')*(b-'0');
}
string mul(string s1,char c)
{
    string h;
    reverse(s1.begin(),s1.end());
    int carry=0;
          for(int i=0;i<s1.length();i++)
          {
              int mu=mulchar(s1[i],c)+carry;
              carry=mu/10;
              mu=mu%10;
              h.push_back(mu+'0');
          }
          if(carry!=0)
          {
            h.push_back(carry+'0');
          }
  reverse(h.begin(),h.end());

  return h;
}

string div(string s1,string s2)
{
    string q="";
    string r;
    if(mast(s1,s2)!=1)
    {
        q='0';
        r=s1;
    }
    else
    {
        string y;
        for(int i=0;i<s2.length();i++)
        {
            y.push_back(s1[i]);

        }

        for(int i=s2.length()-1;i<s1.length();i++)
        {

            char qu=getq(y,s2);
            q.push_back(qu);
            string e=mul(s2,qu);
            y=dif(y,e);
            if(i<s1.length()-1)
            {
            y=y+s1[i+1];
            }
        }
     r=y;

    }
    r=rezeros(r);
    q=rezeros(q);
    if(r.length()==0)
        r='0';

    return r;
}

void isprime(string s)
{
    int f=0;
    string i="2",b="1";
    while(!mast(mult(i,i),s))
    {
        if(div(s,i)=="0")
           {
               f=1;
               break;
           }
           i=ad(i,b);
    }
    if(f==1)
    cout<<"Not a Prime"<<endl;
    else
    cout<<"Prime"<<endl;

}

int main()
{
    long long int j;
    cin>>j;
    for(int i=1;i<=j;i++)
    {
    string h;
    cin>>h;
    isprime(h);
    }
    return 0;
}
