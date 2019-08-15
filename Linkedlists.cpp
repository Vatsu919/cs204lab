#include<iostream>
#include<bits/stdc++.h>
#include<tuple>
#include<cstdlib>
using namespace std;
struct node{
tuple<int,int> pt;
struct node *ptr;
};
struct node *hd=NULL;
void Addfirst(int x,int y)
{
    struct node *nnode=(struct node*)malloc(sizeof(struct node));
    get<0>(nnode->pt)=x;
    get<1>(nnode->pt)=y;
    nnode->ptr=hd;
    hd=nnode;
}
int Delfirst()
{

    struct node *temp=hd;
    if(temp==NULL)
    {
    return -1;
    }
    hd=temp->ptr;
    free(temp);
}
int Del(int x,int y)
{

    struct node *temp=hd;
    if(temp==NULL)
    {
        return -1;
    }
    struct node *prev=(struct node*)malloc(sizeof(struct node));
    if(get<0>(temp->pt)==x && get<1>(temp->pt)==y)
    {
        hd=temp->ptr;
        free(temp);
        return 0;
    }
    prev=temp;
    temp=temp->ptr;
    while(temp!=NULL)
    {
        if(get<0>(temp->pt)==x && get<1>(temp->pt)==y)
        {
            prev->ptr=temp->ptr;
            free(temp);
            return 0;
        }
        prev=temp;
        temp=temp->ptr;
    }

return -1;
}

int search(int d)
{
 struct node *temp=hd;
 int o=0;
 while(temp!=NULL)
 {

     int f=get<0>(temp->pt);
     int g=get<1>(temp->pt);
     if(f*f+g*g<=d*d)
     {
         o++;
     }
     temp=temp->ptr;
 }
    if(o==0)
    {
        return -1;
    }
    else
        return o;

}
bool search(int x,int y)
{
    struct node *temp=hd;
    int g=0;
    while(temp!=NULL)
    {
     int f=get<0>(temp->pt);
     int h=get<1>(temp->pt);
     if(f==x && h==y)
     {
        return true;
     }
     temp=temp->ptr;
    }
    return false;
}
int length()
{
 struct node *temp=hd;
 int c=0;
 while(temp!=NULL)
 {
     c++;
     temp=temp->ptr;
 }
 return c;

}

int main()
{
long long int k;
cin>>k;
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
            {
                int a,b;
                cin>>a>>b;
                Addfirst(a,b);
                break;
            }
            case 2:
            {
                int q=Delfirst();
                if(q==-1)
                {
                 cout<<"-1";
                }
                break;
            }
            case 3:
            {
                int c,d;
                cin>>c>>d;
                int e=Del(c,d);
                if(e==-1)
                cout<<e<<endl;
                break;
            }
            case 4:
            {
                int f;
                cin>>f;
                int w=search(f);
                if(w==-1)
                    cout<<"-1";
                else
                    cout<<w;
                break;
            }
            case 5:
            {
                int g;
                int h;
                cin>>g>>h;
                int j=search(g,h);
                if(j==1)
                    cout<<"True";
                else
                    cout<<"False";
                break;
            }
            case 6:
            {
                int o=length();
                cout<<o<<endl;
                break;
            }



        }

    }
return 0;
}

