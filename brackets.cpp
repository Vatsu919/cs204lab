#include<bits/stdc++.h>
using namespace std;
void balance(string s)
{
 
 char x;
 
 stack<char> j;
 for(int i=0;i<s.length();i++)
 {
     
    
   if(s[i]=='{' || s[i]=='(' || s[i]=='<' || s[i]=='[')
   {
       j.push(s[i]);
       
       continue;
   }
  
   if(s[i]=='|')
   {
       if(!j.empty() && j.top()=='|')
       {
           j.pop();
       }
       else
       {
           j.push(s[i]);
       }
       
       
       continue;
   }
   if(j.empty())
   {
       cout<<"No";
       return;
   }
   switch(s[i])
   {
       case '}':
       {
           x=j.top();
           j.pop();
           if(x=='[' || x=='(' || x=='<' || x=='|')
           {
               cout<<"No";
               return;
           }
        break;
       }
       case ']':
       {
           x=j.top();
           j.pop();
           if(x=='{' || x=='(' || x=='<' || x=='|')
           {
               cout<<"No";
               return;
           }
           break;
       }
       case ')':
       {
           x=j.top();
           j.pop();
           if(x=='[' || x=='{' || x=='<' || x=='|')
           {
               cout<<"No";
               return;
           }
           break;
       }
       case '>':
       {
           x=j.top();
           j.pop();
           if(x=='[' || x=='(' || x=='{' || x=='|')
           {
               cout<<"No";
               return;
           }
           break;
       }
       
   }
 }


 
 if(j.empty())
 {
     cout<<"Yes";
     return;
 }
else
{
 cout<<"No";
 return;
}
}

int main()
{
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
     string s;
     cin>>s;
     cout<<endl;
     balance(s);
    }

}