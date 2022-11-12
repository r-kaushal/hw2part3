#include "Person.h"

Person::Person(std::string arg_name, GPS_DD home)
{
  this->name = name;
  this->homeLocation = home;
}



Person::Person()
{
  this->name = "";
}
Person::Person(string Name)
{
  this->name = Name;
}


void Person::setHome (GPS_DD home)
{
  this->homeLocation = home;
}

void Person::setLocation
(GPS_DD arg_location)
{
  this->currentLocation = arg_location;
  // this->since_when = arg_time;
}

void Person::setName(string name){
  this->name = name;
}

GPS_DD
Person::getHome
(void)
{
  return this->homeLocation;
}



std::string
Person::getName()
{
  return this->name;
}

Json::Value Person::dump2JSON ()
{
  Json::Value result {};
  if (this->name != "")
    {
      result["name"] = this->name;
    }

  Json::Value tempResult;
  
  tempResult = (this->homeLocation).dump2JSON();
  result["home"] = tempResult;

  tempResult = (this->currentLocation).dump2JSON();
  result["location"] = tempResult;

  // std::cout << tempResult.toStyledString() << std::endl;

  return result;
};

