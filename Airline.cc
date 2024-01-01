#include "Airline.h"

//constructor
Airline::Airline(string n): name(n){

}
//Destructor
Airline::~Airline(){
    for(int i=0; i<part_array.getSize(); i++){
        delete part_array[i];
    }
    for(int i=0; i<airCraft_array.getSize(); i++){
        delete airCraft_array[i];
    }
}

//functions:

//returns an aircraft with matching registration number
Aircraft* Airline::getAircraft(const string& reg){
    for(int i=0; i<airCraft_array.getSize(); i++){
        if(airCraft_array[i]->getRegistration() == reg){
            return airCraft_array[i];
        }
    }
    return NULL;
}
//returns a part with given name
Part* Airline::getPart(const string& part){
    for(int i=0; i<part_array.getSize(); i++){
        if(part_array[i]->getName() == part){
            return part_array[i];
        }
    }
    return NULL; 
} 
//checks if the airline is full if not then adds an aircraft with given type and registration
void Airline::addAircraft(const string& type, const string& reg){
    Aircraft* newAirCraft = new Aircraft(type, reg);

    if(!airCraft_array.isFull()){
        airCraft_array.add(newAirCraft);
    }

}
//adds part to the array after checking neccesary conditions
void Airline::addPart(const string& part, int fh_inspect, int it_inspect){
    if(!part_array.isFull()){
        if(fh_inspect == 0){
            IT_Part* newIT_Part = new IT_Part(part, it_inspect);
            part_array.add(newIT_Part);
            return;
        }
        if(it_inspect == 0){
            FH_Part* newFH_Part = new FH_Part(part, fh_inspect);
            part_array.add(newFH_Part);
            return;
        }
        else{
            FHIT_Part* newFHIT_Part = new FHIT_Part(part, fh_inspect, it_inspect);
            part_array.add(newFHIT_Part);
            return;
        }
    }

}
//calls the takeflight function of aircraft with given registartion number to update the flighthours
void Airline::takeFlight(string reg, int hours){
    for(int i=0; i<airCraft_array.getSize(); i++){
        if(airCraft_array[i]->getRegistration() == reg){
            airCraft_array[i]->takeFlight(hours);
        }
    }
}

//prints the aircraft in the array 
void Airline::printAircraft(){
    cout<<"Printing the aircrafts of the airline: "<<endl;
    for(int i=0; i<airCraft_array.getSize(); i++){
        cout<<*airCraft_array[i];
    }
}
//prints the parts in the array 
void Airline::printParts(){
    cout<<"Printing the parts of the airline: "<<endl;
    for(int i=0; i<part_array.getSize(); i++){
        cout<<*part_array[i];
    }
}
//prints the inspection report
void Airline::inspectionReport(string reg, Date& d){
    Array<Part*> p; 
    for(int i=0; i<airCraft_array.getSize(); i++){
        if(airCraft_array[i]->getRegistration() == reg){
            airCraft_array[i]->inspectionReport(d, p);
            cout<<endl;
            cout<<"The following parts from "<<airCraft_array[i]->getRegistration()<<" require inspection:"<<endl;
            for(int i=0; i<p.getSize(); i++){
                cout<<*p[i];
            }
            return;
        }
    }
}
//installs a part in the aircreft with given registration number
bool Airline::install(string reg, string name, Date& d){
    for(int i=0; i<airCraft_array.getSize(); i++){
        if(airCraft_array[i]->getRegistration() == reg){
            for(int j=0; j<part_array.getSize(); j++){
                if(part_array[j]->getName() == name){
                    airCraft_array[i]->install(part_array[j], d);
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}