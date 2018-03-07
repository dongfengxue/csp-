#include<iostream>
#include<cstdio>
using namespace std;

int main(){
int t;
cin>>t;
int money;
if(t<=3500)
  {
money=t;
  }
else if(t>3500&&t<=4955)
    {money=(t-3500)*100/97+3500;}

else if(t>4955&&t<=7655)
    {money=(t-4955)*100/90+5000;}

else if(t>7655&&t<=11255)
    {money=(t-7655)*100/80+8000;}

else if(t>11255&&t<=30755)
    {money=(t-11255)*100/75+12500;}

else if(t>30755&&t<=44755)
    {money=(t-30755)*100/70+38500;}

else if(t>44755&&t<=61005)
    {money=(t-44755)*100/65+58500;}

else
    {money=(t-61005)*100/55+83500;}

cout<<money;
return 0;
}
