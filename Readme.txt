An Airline runs a number of Aircraft. Spare Parts for the aircraft are stored in case a part must be changed.
The rules and regulations of the airline industry ensure that parts are inspected and changed at regular intervals.
As such, each Part is carefully tracked. Some parts must be inspected after a certain number of ight hours. Some
parts must be inspected after a certain amount of time being installed in an aircraft. And some parts require both
ight hours and time installed to be tracked. This behaviour is the perfect opportunity to use multiple inheritance!
Parts can be installed on an Aircraft on a given Date. Once installed, every time the aircraft ies the number
of ight hours are recorded on the Part. The airline may choose to do an inspectionReport on a particular aircraft
on a given Date, at which time all the parts that are due for inspection are reported.
