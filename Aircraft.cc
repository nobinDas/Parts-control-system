#include "Aircraft.h"

//constructor
Aircraft::Aircraft(string typ, string reg): type(typ), registration(reg){
    flighthours = 0;
}

//destructor
Aircraft::~Aircraft(){
    for(int i=0; i<part_array.getSize(); i++){
        delete part_array[i];
    }
}

string Aircraft::getRegistration(){
    return registration;
}

//functions:

//installs a part with a date if the array is not full
void Aircraft::install(Part* part, Date& d){
    part->install(d);

    if(!part_array.isFull()){
        part_array.add(part);
    }
}
//updates the flighthours of the aircraft and all the parts in it
void Aircraft::takeFlight(int hours){
    flighthours += hours;

    for(int i=0; i<part_array.getSize(); i++){
        part_array[i]->addFlightHours(hours);
    }
}
//gives a part as a output if it needs inspection
void Aircraft::inspectionReport(Date& d, Array<Part*>& p){
    for(int i=0; i<part_array.getSize(); i++){
        if(part_array[i]->inspection(d)){
            p.add(part_array[i]);
        }
    }
}

ostream& operator<<(ostream& output, Aircraft& arr)
{
    output<<endl;
    
    output<<"Aircraft: "<<arr.type<<endl;
    output<<"Resgistration: "<<arr.registration<<endl;  

    output<<endl;  
    return output;
}
