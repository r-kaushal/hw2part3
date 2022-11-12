#include "ecs36b_Common.h"
#include "Person.h"
#include "JvTime.h"
#include "GPS_DD.h"
#include "Thing.h"
#include "Record.h"

    Record::Record(Person person, Thing thing1){
        this->person1 = person;
        this->thing1 = thing1;
    }
    Record::Record(Person person,Thing thing1, Thing thing2){
        this->person1 = person;
        this->thing1 = thing1;
        this->thing2 = thing2;  
    }
    Record::Record(Person person, Person person2, GPS_DD location){
        this->person1 = person;
        this->person2 = person2;
        this->location = location;
        this->thing1 = thing1;
        this->thing2 = thing2;
        this->thing3 = thing3;
    }

    Record::Record(Person person,GPS_DD location, Thing thing1, Thing thing2,Thing thing3){
        this->person1 = person;
        this->location = location;
        this->thing1 = thing1;
        this->thing2 = thing2;
        this->thing3 = thing3;
    }

    void Record::setTime(string time)
    {
    this->time = time;
    }
    void Record::setEventDescription(string event){
        this->eventDescription = event;
    }

    Json::Value Record::dump2JSON(){ // need to edit this

    Json::Value result { };
    Json::Value jv_result;

    jv_result = this->person1.dump2JSON();
    result["person1"] = jv_result;

    jv_result = this->person2.dump2JSON();
    result["person2"] = jv_result;

    jv_result = (this->location).dump2JSON();
    result["location"] = jv_result;

    jv_result = (this->thing1).dump2JSON();
    result["thing 1"] = jv_result;

    jv_result = (this->thing2).dump2JSON();
    result["thing 2"] = jv_result;

    jv_result = (this->thing3).dump2JSON();
    result["thing 3"] = jv_result;

    result["time"] = this->time;
    result["event description"] = this->eventDescription;
    
  return result;
}


