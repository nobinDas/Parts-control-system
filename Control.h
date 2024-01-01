
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <iomanip>

#include "View.h"
#include "Airline.h"

#define AC_NUM 3
#define PART_NUM 10

using namespace std;

class Control {
		
	public:
		
		void launch();
	
	private:
		View view;
		void initAirline(Airline&);
		void takeFlights(Airline&);
		void inspectionReport(Airline&);

		const static string ac_reg[AC_NUM];
		const static string ac_type[AC_NUM];
		const static string parts[PART_NUM];
		const static int fh[PART_NUM];
		const static int it[PART_NUM];
	
};
#endif