#include "ShiftSupervisor.h"

ShiftSupervisor::ShiftSupervisor()
{
   annualsalary = 0.0;
   annualproductionbonus = 0.0;
   name = "";
   number = 0;
   date = "";
}
ShiftSupervisor::ShiftSupervisor(double as, double ap, std::string n, int num, std::string d)
{
   annualsalary = as;
   annualproductionbonus = ap;
   name = n;
   number = num;
   date = d;
}

double ShiftSupervisor::getannualsalary() const
{
   return annualsalary;
}

double ShiftSupervisor::getannualproductionbonus() const
{
   return annualproductionbonus;
}

void ShiftSupervisor::setannualsalary(double as)
{
   annualsalary = as;
}
void ShiftSupervisor::setannualproductionbonus(double ap)
{
   annualproductionbonus = ap;
}

