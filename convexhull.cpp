#include<bits/stdc++.h>
using namespace std;

struct pt{
    int x;
    int y;
};
pt p0;

int dist(pt a,pt b)
{
return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

pt nexttop(stack<pt> &S)
{
    pt p = S.top();
    S.pop();
    pt res = S.top();
    S.push(p);
    return res;
}

int swap(pt a,pt b)
{
    pt temp=a;
    a=b;
    b=temp;
}

int orie(pt p,pt q,pt r)
{
    int h=(p.y-q.y)*(q.x-r.x)-(p.x-q.x)*(q.y-r.y);
    if(h==0)
    {
        return 0;
    }
    else if(h>0)
    {
        return 1;
    }
    else
    {
        return 2;
    }

}
int cmp(const void *a,const void *b)
{
    pt *g=(pt *)a;
    pt *h=(pt *)b;
    int u=orie(p0,*g,*h);
    if(u==0)
    {
        if(dist(p0,*g)<=dist(p0,*h))
        {
            return -1;
        }
        else
        {
            return 1;
        }

    }
    else if(u==1)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

void convexhull(pt p[],int n)
{
  int min=0;
  int ym=p[0].y;
  for(int i=1;i<n;i++)
  {
      if((p[i].y<ym) || (p[i].y==ym&&p[i].x<=p[min].x))
      {
          ym=p[i].y;
          min=i;
      }
  }
  swap(p[0],p[min]);
  p0=p[0];
  qsort(&p[1], n-1, sizeof(pt), cmp);
  int m=1;
  for(int i=1;i<n;i++)
  {
      while(i<n-1 && orie(p0,p[i],p[i+1])==0)
      {
          i++;
      }
      p[m]=p[i];
      m++;
  }
  if(m<3)return;
  stack<pt> s;

  s.push(p[0]);
  s.push(p[1]);
  s.push(p[2]);
  for(int i=3;i<m;i++)
  {
      while(orie(nexttop(s),s.top(),p[i])!=2)
      {
          s.pop();
      }
      s.push(p[i]);
  }
  int w=s.size();
  cout<<w<<endl;

  while(!s.empty())
  {
      pt e=s.top();
      cout<<"("<<e.x<<","<<e.y<<")"<<endl;
      s.pop();
  }
}
int main()
{
    int n;
    cin>>n;
    pt p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    convexhull(p,n);
}
