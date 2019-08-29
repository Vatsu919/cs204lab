#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
map<string,long long int> m;
map<string,long long int>::iterator it;

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
long long int eval(tree* root)
{

    if (!root)
        return 0;
    if(eval(root->left)==INT_MIN || eval(root->right)==INT_MIN)
    {
        return INT_MIN;
    }

    if (!root->left && !root->right){
        bool is_number=true;
        for(int i=0;i<root->data.size();i++)
        {
            if(root->data[i]>='0'&&root->data[i]<='9')
                continue;
            else{
                is_number=false;
                break;
            }
        }
        if(is_number)
            return toInt(root->data);
        else
        {
            it=m.find(root->data);
            if(it!=m.end())
            {
            return it->second;
            }
            else
            {
                return INT_MIN;
            }
        }
    }




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
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        for(int k=1;k<=n;k++)
        {
        string l;
        cin>>l;
        int flag=0;
        int c=-1;
        for(int u=0;u<l.length();u++)
        {
            if(l[u]=='=')
            {
                flag=1;
                c=u;
            }
        }
        string h=l.substr(c+1,l.length());
        string y=infixToPostfix(h);

        tree *t=makkk(y);

        long long int q=eval(t);
        if(flag==1)
        {
            m[l.substr(0,c)]=q;
            if(q==INT_MIN)
        {
            cout<<"can't be evaluated"<<endl;
        }
            continue;
        }




        if(q==INT_MIN)
        {
            cout<<"can't be evaluated"<<endl;
        }
        else
        {
            cout<<q<<endl;
        }
        }

  m.clear();
    }


}
