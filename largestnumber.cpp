#include<bits/stdc++.h>
using namespace std;
 

int myCompare(string X, string Y) 
{ 
    
    string XY = X.append(Y); 
  
     
    string YX = Y.append(X); 
 
    return XY.compare(YX) > 0 ? 1: 0; 
} 

void printLargest(string arr[],int n) 
{ 

    sort(arr,arr+n,myCompare); 
    
    for (int i=0; i < n ; i++ ) 
    {
        cout << arr[i];
    }
    

} 

 
int main()
{ 
    int t;
    cin>>t;
    while(t>0)
    {
    int h;
    cin>>h;
    string a[h];
    for(int i=0;i<h;i++)
    {
        cin>>a[i];
    }
    cout<<"\n";
    printLargest(a,h);
    t--;
    }
}