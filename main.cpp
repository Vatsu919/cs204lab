
#include<bits/stdc++.h>


using namespace std;


class ans{
  public:
    string q;
    string r;
};
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


string dif(string s1,string s2)
{
 string h;
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

h=rezeros(h);
if(h.length()==0)
{
    h='0';
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
ans div(string s1,string s2)
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
    ans a;
    a.q=q;
    a.r=r;
    return a;
}

int main()
{
    long long int y;
    cin>>y;
    for(int i=1;i<=y;i++)
    {
      string s1;
      string s2;
      cin>>s1;
      cin>>s2;
      ans d;
      d=div(s1,s2);
      cout<<"Quotient="<<d.q<<endl;
      cout<<"Remainder="<<d.r<<endl;
    }
    return 0;
}
