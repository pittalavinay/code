#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
vector<int> data={4,2,7,1,5,3};
sort(data.begin(),data.begin()+3);
sort(data.begin()+3,data.end());
inplace_merge(data.begin(),data.begin()+3,data.end());
cout<<"After inplace_merge:";
for(int n:data)
{
cout<<n<<" ";
}
cout<<"\n";
vector<int> a={1,4,6,7};
vector<int> b={2,4,5,6};
vector<int> intersect;
set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(intersect));
cout<<"Set intersection: ";
for(int n:intersect)
{
cout<<n<<" ";
}
cout<<"\n";
vector<int> empty={4,2,7,1,5,3};
auto it=min_element(empty.begin(),empty.end());
if(it!=empty.end())
{
cout<<"minimum element"<<" "<<*it<<endl;
}
return 0;
}