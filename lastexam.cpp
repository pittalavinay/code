#include<iostream>
#include<vector>
#include<thread>
#include<algorithm>
#include<string>
#include<memory>
#include<list>
#include<mutex>
#include<thread>
#include<mutex>
#include<deque>
#include<condition_variable>
using namespace std;
 mutex m;
 /*
 *
 *@brief Display Screens using Inheritance & Polymorphism
 * 
 * 
 */
class DisplayScreen 
{
 public:
 virtual void render()=0;
 virtual void updateData(int val)=0;
};
/*
 *
 *@brief Display Screens using Inheritance & Polymorphism
 * @brief Encapsulation & Data Hiding
 * 
 */
class SpeedometerScreen :public DisplayScreen 
{  
    int speed;
  public:
  /*
 *
 *@brief rendering the speedometerscreen 
 * @brief showing the data
 * 
 */
  void render()
  {
      lock_guard<mutex> g1(m);
    cout<<"["<<"SpeedometerScreen"<<"]"<<"Current Speed: "<<speed<<" "<<"km/h"<<endl;
  }
   /*
 *
 *@brief showing the speedometerscreen data
 * @brief updating the data
 * @param getting the val
 */
  void updateData(int val)
  {
    speed=val;
  }
};
 /*
 *
 *@brief Display Screens using Inheritance & Polymorphism
 * @brief this is the waringAlertScreen
 * 
 */
class WarningAlertScreen :public DisplayScreen 
{
    string check;
  public:
  deque<string> v1={"Engine Check!","Door Open!","Battery Check!","Fuel Check!"};
   /*
 *
 *@brief rendering the WarningAlertScreen
 * @brief showing the data
 * 
 */
  void render()
  {
    lock_guard<mutex> g1(m);
    cout<<"["<<"WarningAlertScreen"<<"]"<<"ALERT: "<<check<<" "<<endl;
  }
   /*
 *
 *@brief showing the WarningAlertScreen data
 * @brief updating the data
 * @param getting the val
 */
  void updateData(int val)
  {
    check=v1[val];
  }
};
/*
 *
 *@brief Display Screens using Inheritance & Polymorphism
 * @brief Encapsulation & Data Hiding
 * @brief NavigationScreen
 */
class NavigationScreen :public DisplayScreen 
{
    string direction;
    int k;
  public:
  list<string> v={"Turn Right","Go Straight"};
  vector<string> d={"in","in","for"};
  vector<int> kk={500,1};
/*
 *
 *@brief rendering the NavigationScreen
 * @brief showing the data
 * 
 */
  void render()
  {
    lock_guard<mutex> g1(m);
       cout<<"["<<"NavigationScreen"<<"]"<<"Next: "<<direction<<" "<<d[k]<<" "<<kk[k]<<"km"<<endl;
  }
 /*
 *
 *@brief showing the NavigationScreen data
 * @brief updating the data
 * @param getting the val
 */
  void updateData(int val)
  {
    direction=v.front();
    if(val==1)
    {
    direction=v.back();
    }
    k=val;
  }
};
/*
 *
 *@brief storing Display Screens using smart pointers
 * 
 * @brief Display Manager Module
 */
class DisplayManager 
{
    public:
    vector<shared_ptr<DisplayScreen>> vd;
/*
 *
 *@brief adding the sreen into the vector of screens
 * @brief updating the data
 * @param getting the smart pointer screen as parameter
 */
    void addScreen(shared_ptr<DisplayScreen> addscreen)
    {
        vd.push_back(addscreen);
    }
    // void removeScreen(const string & screenName)
    // {
    //     vd.erase(remove(vd.begin(),vd.end(),screenName),vd.end());
    // }
    /*
 *
 *@brief this renderall method is used for displaying all the values
 * @brief displaying the data
 *
 */
    void renderAll()
    {
        for(auto k:vd)
        {
            k->render();
        }
    }
};
int main()
{
 /*
 *
 *@brief creating the object to the displaymanager 
 * @brief adding the displayscreens to the addscreen by sending parameters
 *
 */
    DisplayManager ds;
    shared_ptr<DisplayScreen> dm1=make_shared<SpeedometerScreen>();
    dm1->updateData(60);
    ds.addScreen(dm1);
      shared_ptr<DisplayScreen> dm2=make_shared<WarningAlertScreen>();
    dm2->updateData(0);
    ds.addScreen(dm2);
      shared_ptr<DisplayScreen> dm3=make_shared<NavigationScreen>();
    dm3->updateData(0);
    ds.addScreen(dm3);
    shared_ptr<DisplayScreen> dm4=make_shared<SpeedometerScreen>();
    dm4->updateData(80);
      shared_ptr<DisplayScreen> dm5=make_shared<WarningAlertScreen>();
    dm5->updateData(1);
      shared_ptr<DisplayScreen> dm6=make_shared<NavigationScreen>();
    dm6->updateData(1);
 /*
 *
 *@brief creating the threads to each and every screen 
 * @brief handled by the mutexs
 *@brief Multithreading & Synchronization
 *@brief Advanced Thread Management
 */
    thread t1(&DisplayManager::addScreen,&ds,dm4);
        thread t2(&DisplayManager::addScreen,&ds,dm5);
           thread t3(&DisplayManager::addScreen,&ds,dm6);
           t1.join();
           t2.join();
           t3.join();
            ds.renderAll();
    return 0;
}