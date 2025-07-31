#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
class cabinTemperaturecontrolsystem
{
    /*
    *@breif private declaration of containers
    */
    set<string> s;
    stack<pair<string,float>> st;
    public:
    /* 
    *
    *@brief the zone temperature settings using this method and store and update of current
    */
   void zonetemperature(string key,float temperature)
   {
       map<string,float> m;
       m.insert({key,temperature});
       zonetemperaturedisplay(m);
   }
    /* 
    *
    *@brief  display  zone temperature using this method
    */
   void zonetemperaturedisplay(map<string,float> mm)
   {
      map<string,float> ::iterator it;
      for(it=mm.begin();it!=mm.end();it++)
      {
        cout<< it->first<<" "<<it->second<<endl;
      }
   }
     /* 
    *
    *@brief the valid temperature zones using this method and store and update of current
    */
    
   void temperaturezone(string zones)
   {
    s.insert(zones);
    
   }
     /* 
    *
    *@brief  display  zone temperature using this method
    */
   void temperaturezonedisplay()
   {
    set<string>:: iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" "<<endl;
    }
   }
    /* 
    *
    *@brief  zone mode history using this method and store and update of current
    */
    void zonetomodehistory(string keyzone,string valuemode)
    {
        multimap<string,string> mzm;
        mzm.insert({keyzone,valuemode});
         for(auto zh:mzm)
         {
            cout<<zh.first<<" "<<zh.second<<endl;
         }

    }
    /* 
    *
    *@brief  temperature adjustemt log using this method and store and update of current
    */
   void temperatureadjustmentlog(string zoneadjustment)
   {
    multiset<string> mal;
    mal.insert(zoneadjustment);
       multiset<string> :: iterator it;
       for(it=mal.begin();it!=mal.end();it++)
       {
     int co=count(mal.begin(),mal.end(),*it);
     cout<<*it<<" "<<co<<endl;
       }
   }
      /* 
    *
    *@brief  temperature request queue log this method and store and update of current
    */
   void temperaturerequestqueue(string seq)
   {
    queue<string> qq;
    qq.push(seq);
     while(!qq.empty())
     {
        cout<<qq.front()<<endl;
        qq.pop();
     }
   }
  /* 
    *@brief oRespond to sensor-triggered emergency cooling/heating.
      Automatically override user settings.
    *@brief  emergency override queue this method and store and update of current
    */
   void emergencyq(int priority,string command)
   {
    pair<int,string> pii={priority,command};
    priority_queue<pair<int,string>> pq;
    pq.push(pii);
    cout<<pq.top().first<<" "<<pq.top().second<<endl;
   }
    /* 
    *@brief Respond to sensor-triggered emergency cooling/heating.
     Automatically override user settings.
    *@brief  undolastchange stack this method and store and update of current
    */
  
   void stacka(string zone,float oldtemp)
   {
     pair<string,int> pii={zone,oldtemp};
    
     st.push(pii);
   }
    /* 
    *@brief  On user "Undo", revert to last known temp using top() and pop().
     Helps simulate rollback of recent unintended changes.
    *@brief  undolastchange stack this method and store and update of current
    */
   void undo()
   {
    while(!st.empty())
    {
    cout<< st.top().first<<" "<<st.top().second<<endl;
    st.pop();
   }
}
    
};
int main()
{

    cabinTemperaturecontrolsystem cc;
    cout<<"zone temperature settings"<<endl; 
    cc.zonetemperature("Driver",22.5);
    cc.zonetemperature("Passenger",23.5);
    cc.zonetemperature("Rear",24.5);
    cout<<"valid temperature zones"<<endl;
    cc.temperaturezone("Driver");
    cc.temperaturezone("Passenger");
    cc.temperaturezone("Rear");
     cc.temperaturezone("Driver");
    cc.temperaturezone("Passenger");
    cc.temperaturezone("Rear");
    cc.temperaturezonedisplay();
    cout<<"zone history"<<endl;
    cc.zonetomodehistory("Passenger","Eco");
    cc.zonetomodehistory("Passenger","Auto");
     cc.zonetomodehistory("Passenger","Eco");
    cout<<"Temperature adjustmentLog"<<endl;
    cc.temperatureadjustmentlog("Driver");
    cc.temperatureadjustmentlog("Passenger");
     cc.temperatureadjustmentlog("Rear");
     cout<<"Temperature Request Queue"<<endl;
     cc.temperaturerequestqueue("Increase Driver Temp");
     cc.temperaturerequestqueue("Decrease Rear Temp");
     cout<<"emergency override queue"<<endl;
     cc.emergencyq(20,"Emergency cool down");
     cc.emergencyq(10,"not emergency heating");
     cc.stacka("Passenger",20);
     cc.stacka("Driver",30);
     cc.stacka("Passenger2",40);
     cc.stacka("Passenger3",50);
     cout<<"undo last change"<<endl;
     cc.undo();
    return 0;
}