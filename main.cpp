#include "ecs36b_Common.h"
#include "Person.h"
#include "JvTime.h"
#include "GPS_DD.h"
#include "Thing.h"
#include "Record.h"

main(){
    // GPS_DD littleRedLocation("Litle Red Riding Hood's home");
    Person dearLittleGirl("Dear Little Girl");
    Person grandma("Grandma");
    Thing cap("Little Cap of Red Velvet");
    dearLittleGirl.setName("Little Red Riding Hood");
    Person mother("Mother");
    Thing cake("piece of cake");
    Thing wine("bottle of wine");
    // make an object for "take them to your grandmother"

    // Setting up Grandma's location:
    GPS_DD grandma_location("Out in the wood","Half a league from the village",true);
    grandma.setLocation(grandma_location);

    // Setting up location of where Little Red Riding hood met the wolf
    GPS_DD meetup_location("Entrance of Woods");
    Person wolf("Wolf");
    wolf.setLocation(meetup_location);
    dearLittleGirl.setLocation(meetup_location);


    Thing tree1("Large Oak Tree 1");
    Thing tree2("Large Oak Tree 2");
    Thing tree3("Large Oak Tree 3");

    Record r1(dearLittleGirl,cap);
    r1.setTime("beginning of story");
    r1.setEventDescription("Little Red Riding Hood wore the cap");

    Record r2(mother,cake,wine);
    r2.setTime("second event");
    r2.setEventDescription("Her mom gave her the cake and wine");

    Record r3(dearLittleGirl,wolf,meetup_location);
    r3.setTime("third event");
    r3.setEventDescription("Little Red met the wolf at a particular spot in the wood");

    Record r4(grandma,grandma_location,tree1,tree2,tree3);
    r4.setTime("last event");
    r3.setEventDescription("Grandma was at her own home right outside of the wood and there were three large oak trees nearby");


     std::cout << r1.dump2JSON();
}