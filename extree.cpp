#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

struct tree{
string data;
tree *right;
tree *left;
};
bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^' || c=='(' || c==')' || c==',') 
        return true; 
    return false; 
} 
 tree* node(string h)
{
    tree* temp=new tree;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=h;
    return temp;
}
tree* makkk(string s)
{
  stack<tree *> st;
  tree *t,*t1,*t2;
  int i=0;
  while(i<s.length())
  {
   if(!isOperator(s[i]))
   {
       string j;
       while(s[i]!=',' && s[i]!=NULL)
       {
           j+=s[i];
           
           i++;
       }
       t=node(j);
       st.push(t);
   }
   else if(s[i]==',')
   {
       i++;
       continue;
   }
   else
   {
       string j;
       j+=s[i];
       t=node(j);
       t1=st.top();
       st.pop();
       t2=st.top(); 
       st.pop();
       t->right=t1;
       t->left=t2;
       st.push(t);
       i++;
   }

  }
  t=st.top();
  st.pop();
  return t;


}

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 



string infixToPostfix(string s) 
{ 
    std::stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string ns;
    int i=0; 
    while(i<l)
    { 
  
        if(!isOperator(s[i])) 
        {
            while(!isOperator(s[i]) && s[i]!=NULL)
            {
             ns+=s[i];
             i++;
            }
           ns+=',';
        }
        else if(s[0]=='-')
        {
            st.push('-');
            ns+=',';
            ns+='0';
            ns+=',';
            i++;
        }
        else if((s[i]=='-'&&i>0)&&(s[i-1]==NULL || s[i-1]=='(' || isOperator(s[i-1])))
            {
            st.push('-');
            ns+=',';
            ns+='0';
            ns+=',';
            i++;
        }
 
        else if(s[i] == '(') 
        { 
        st.push('(');
        i++; 
        }  
      
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               ns += c; 
               ns+=',';
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
            i++;
        } 
          
         
        else{ 
            while(!st.empty() && (prec(s[i]) < prec(st.top())||(prec(s[i])==prec(st.top())&&prec(s[i])!=3)) )   
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c;
                ns+=','; 
            } 
            st.push(s[i]);
            i++; 
        } 
        
     
    } 
     
    while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
        ns+=',';
        
    } 
      
   
return ns;  
} 


 void inorder(tree *t) 
{ 
    if(t) 
    { 
        inorder(t->left); 
        cout<<t->data; 
        inorder(t->right); 
    } 
}
int toInt(string s)  
{  
    int num = 0;  
      
     
    if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
   
   
    else
        for (int i=1; i<s.length(); i++)  
        { 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        } 
      
    return num;  
}  
int eval(tree* root)  
{  
      
    if (!root)  
        return 0;  
  
      
    if (!root->left && !root->right)  
        return toInt(root->data);  
  
     
    int l_val = eval(root->left);  
  
     
    int r_val = eval(root->right);  
  
    
    if (root->data=="+")  
        return l_val+r_val; 
         
  
    if (root->data=="-")  
        return l_val-r_val;  
  
    if (root->data=="*")  
        return l_val*r_val;  
    if(root->data=="/")
    return l_val/r_val;  
    if(root->data=="^")
    return pow(l_val,r_val);
}  

int main()
{
    int p;
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        int n;
        cin>>n;
        for(int k=1;k<=n;k++)
        {
        string l;
        cin>>l;
        string j=infixToPostfix(l);
 
        tree* e=makkk(j);
        
        int o=eval(e);
        cout<<o;
        }
    }

}
 
