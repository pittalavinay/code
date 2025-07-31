#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<mutex>
#include<thread>
using namespace std;
/*
*@brief ClimateZoneLogger class is singleton class
*@brief Singleton Design Pattern to ensure only one logger instance exists
*@brief Made the constructor private.
*@brief Delete the copy constructor and assignment operator to prevent duplication.
*/
class ClimateZoneLogger 
{
    static ClimateZoneLogger * instance;
    ClimateZoneLogger(){}
    ClimateZoneLogger(const ClimateZoneLogger &)=delete;
    ClimateZoneLogger& operator=(const ClimateZoneLogger&)=delete;
    public:
    mutex m;
    /*
    *@brief getInstance method which is access through the global scope
    */
    static ClimateZoneLogger* getInstance()
    {
        if(instance==nullptr)
        {
            return new ClimateZoneLogger();
        }
        return instance;

    }
    /*
    *@brief Loginfo method to log the information
    *@param zone to declare the zone subsytem to give the subsytem of the info.
    *@param message to print the message or log the message what happend.
    */
    void logInfo(string zone, string subsystem,string message)
    {
        cout<<"[INFO]"<<"   "<<"["<<zone<<"]"<<"["<<subsystem<<"]"<<" "<<message<<endl;
    }
    /*
    *@brief LogWarning method to log the information
    *@param zone to declare the zone subsytem to give the subsytem of the info.
    *@param message to print the message or log the message what happend.
    */
    void logWarning(string zone, string subsystem,string message)
    {
        cout<<"[WARNING]"<<"   "<<"["<<zone<<"]"<<"["<<subsystem<<"]"<<" "<<message<<endl;
    }
     /*
    *@brief LogError method to log the information
    *@param zone to declare the zone subsytem to give the subsytem of the info.
    *@param message to print the message or log the message what happend.
    */
    void logError(string zone, string subsystem,string message)
    {
        cout<<"[Error]"<<"   "<<"["<<zone<<"]"<<"["<<subsystem<<"]"<<" "<<message<<endl;
    }
    /*
    *@brief frontzonemodule method to call method of logs and the information is sent to it
    *@param information to declare the what type of zone.
    *@param zone to give the type of zone .
    *@param subsystem to give the info to the log system.
    *@param message to print the message and send  log the message to log methods.
    */
    void frontZoneModule(string information,string zone, string subsystem,string message)
    {  if(information=="info")
        {
          logInfo(zone,subsystem,message);
        }
        if(information=="warning")
        {
       logWarning(zone,subsystem,message);
        }
        if(information=="error")
        {
       logError(zone,subsystem,message);
        }
    }
       /*
    *@brief rearzonemodule method to call method of logs and the information is sent to it
    *@param information to declare the what type of zone.
    *@param zone to give the type of zone .
    *@param subsystem to give the info to the log system.
    *@param message to print the message and send  log the message to log methods.
    */
     void rearZoneModule(string information,string zone, string subsystem,string message)
    {
       // m.lock();
       if(information=="info")
        {
          logInfo(zone,subsystem,message);
        }
        if(information=="warning")
        {
       logWarning(zone,subsystem,message);
        }
        if(information=="error")
        {
       logError(zone,subsystem,message);
        }
       // m.unlock();
      
    }
       /*
    *@brief driverzonemodule method to call method of logs and the information is sent to it
    *@param information to declare the what type of zone.
    *@param zone to give the type of zone .
    *@param subsystem to give the info to the log system.
    *@param message to print the message and send  log the message to log methods.
    */
     void driverZoneModule(string information,string zone, string subsystem,string message)
    {
       if(information=="info")
        {
          logInfo(zone,subsystem,message);
        }
        if(information=="warning")
        {
       logWarning(zone,subsystem,message);
        }
        if(information=="error")
        {
       logError(zone,subsystem,message);
        }
    }
};
ClimateZoneLogger * ClimateZoneLogger::instance=nullptr;
int main()
{
    ClimateZoneLogger * Logger=ClimateZoneLogger::getInstance();
      string zonef1="Front";
      string zoned1="Driver";
      string zoner1="Rear";
      string subsystemf1="TemperatureControl";
      string subsystemd1="SeatClimate";
      string subsystemr1="AirflowControl";
      string messagef1="Temperature set to 22Tc";
      string messaged1="Driver Seat heater activated";
      string messager1="Rear vents adjusted";
      //thread t1(Logger);
      Logger->frontZoneModule("info",zonef1,subsystemf1,messagef1);
      Logger->driverZoneModule("info",zoned1,subsystemd1,messaged1);
      Logger->rearZoneModule("info",zoner1,subsystemr1,messager1);
       // t1.join();
       string zonef2="Front";
      string zoned2="Driver";
      string zoner2="Rear";
      string subsystemf2="HumiditySensor";
      string subsystemd2="TemperatureControl";
      string subsystemr2="TemperatureSensor";
      string messagef2="Humidity rising above normal";
      string messaged2="Fluctuating temperature readings";
      string messager2="Temperature sensor slightly off";
     // thread t2(Logger);
      Logger->frontZoneModule("warning",zonef2,subsystemf2,messagef2);
      Logger->driverZoneModule("warning",zoned2,subsystemd2,messaged2);
      Logger->rearZoneModule("warning",zoner2,subsystemr2,messager2);
       //t2.join();
       string zonef3="Front";
      string zoned3="Driver";
      string zoner3="Rear";
      string subsystemf3="FanController";
      string subsystemd3="VentControl";
      string subsystemr3="Defroster";
      string messagef3="Front fan malfunction detected";
      string messaged3="Driver side vent stuck";
      string messager3="Rear defroster not responding";
      //thread t3(Logger);
      Logger->frontZoneModule("error",zonef3,subsystemf3,messagef3);
      Logger->driverZoneModule("error",zoned3,subsystemd3,messaged3);
      Logger->rearZoneModule("error",zoner3,subsystemr3,messager3);
      cout<<"All climate zone logs completed";
     // t3.join();
    return 0;
}



