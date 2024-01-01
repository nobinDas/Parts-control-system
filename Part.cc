#include "Part.h"

//constructor
Part::Part(string n){
    name = n;
    flighthours = 0;
}
//destructor
Part::~Part(){

}

//getters
string Part::getName(){
    return name;
}

//member functions:
//adds flight hours to the part
void Part::addFlightHours(int hours){
    flighthours += hours;
}
//updates with the installation date
void Part::install(Date& newDate){
    installationDate =newDate;    
}

ostream& operator<<(ostream& output, Part& arr)
{
    output<<endl;
    output<<"Part: "<<arr.name<<endl;
    output<<"Installation date: "<<arr.installationDate;
    output<<"Flight hours: "<<arr.flighthours;
    output<<endl;

    return output;
}


//FH_Part class...............
FH_Part::FH_Part(string n, int fhInspect):Part(n), fh_inspect(fhInspect){
}
FH_Part::~FH_Part(){

}

//virtual function
bool FH_Part::inspection(const Date& date){
    if(flighthours >= fh_inspect){ return true;}

    return false;
}

//IT_Part class..............
IT_Part::IT_Part(string n, int itInspect):Part(n), it_inspect(itInspect){
}
IT_Part::~IT_Part(){
    
}

//virtual function
//returns true if needs an inspection and false other wise
bool IT_Part::inspection(const Date& date){
    if((date.toDays()-installationDate.toDays()) >= it_inspect){ 
        return true;
    }

    return false;
}

//FHIT_Part class..................
FHIT_Part::FHIT_Part(string n, int fhInspect, int itInspect):Part(n),IT_Part(n, itInspect), FH_Part(n, fhInspect){
}
FHIT_Part::~FHIT_Part(){

}

//virtual function
//returns true if needs an inspection and false other wise
bool FHIT_Part::inspection(const Date& date){
    if(FH_Part::inspection(date) || IT_Part::inspection(date)){
        return true;
    }
    return false;
}




 
