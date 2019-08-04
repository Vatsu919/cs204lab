#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
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
   ca=su/10;
   su=su%10;
   h.push_back(su+'0');

 }
 reverse(h.begin(),h.end());
return h;

}
int main()
{
    long long int p;
    cin>>p;
    for(int i=1;i<=p;i++)
    {
    string j;
    string k;
    cin>>j;
    cin>>k;
    cout<<ad(j,k)<<endl;
    }
return 0;
}
