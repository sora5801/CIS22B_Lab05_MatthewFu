
#include "Employee.h"
std::string Employee::getName() const
{
   return name;
}

int Employee::getNumber() const
{
   return number;
}

std::string Employee::getDate() const
{
   return date;
}

Employee::Employee()
{
   name = "";
   number = 0;
   date = "";
}

Employee::Employee(std::string n, int i, std::string d)
{
   name = n;
   number = i;
   date = d;
}

void Employee::setDate(std::string d)
{
   date = d;
}

void Employee::setName(std::string n)
{
   name = n;
}

void Employee::setNumber(int n)
{
   if (n >= 0 && n <= 9999)
      number = n;
   else
      throw InvalidEmployeeNumber();
}