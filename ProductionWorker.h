#pragma once
#include <iostream>
#include <cstdlib>
#include "Employee.h"

//The class ProductionWorker is a derived class of Employee. This demonstrates Inheritance
class ProductionWorker : public Employee
{
   //These variables are declared protected so that the classes derived from this one
   //can access it.
protected:
   int shift; // 1 for day time. 2 for night time.
   double hourlypayrate; //Money made in an hour.
   int hoursworkedthismonth; //Hours worked in a month
public:
   class InvalidShift {};
   class InvalidPayRate {};
   
   //Default Constructor
   ProductionWorker();
   //Constructor
   ProductionWorker(int, double, std::string, int, std::string, int);

   //Mutators
   void setshift(int);
   void sethourlypayrate(double);
   void sethoursworkedthismonth(int);

   //Accessors
   int getshift() const;
   double gethourlypayrate() const;
   int gethoursworkedthismonth() const;

   void yellout(); //This function is to display static binding
   virtual double moneyearned();//This function is to display dynamic binding. This function
   //will get overrided in the TeamLeader Class. This displays polymorphism.
};