#pragma once
#include "Employee.h"

//The class ShiftSupervisor is a derived class from Employee. This demonstrates inheritance.
class ShiftSupervisor : public Employee
{
//Hiding variables is a part of encapsulation.
private:
   double annualsalary; // The money made in a year.
   double annualproductionbonus; //If things go well, more money is made.
public:
   //Default Constructor
   ShiftSupervisor();

   //Constructor
   ShiftSupervisor(double, double, std::string, int, std::string);

   //Accessors
   double getannualsalary() const;
   double getannualproductionbonus() const;

   //Mutators
   void setannualsalary(double);
   void setannualproductionbonus(double);


};
