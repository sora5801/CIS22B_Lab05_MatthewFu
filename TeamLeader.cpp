#include "TeamLeader.h"

TeamLeader::TeamLeader()
{
   name = "";
   number = 0;
   date = "";
   monthlyBonus = 0;
   requiredHours = 0;
   trainingHours = 0;
   hourlypayrate = 0;
   hoursworkedthismonth = 0;
}
TeamLeader::TeamLeader(int mn, int rh, int th, double hr, int hm, std::string n, int num, std::string d)
{
   monthlyBonus = mn;
   requiredHours = rh;
   trainingHours = th;
   hourlypayrate = hr;
   hoursworkedthismonth = hm;
   name = n;
   number = num;
   date = d;
}
int TeamLeader::getmonthlyBonus() const
{
   return monthlyBonus;
}
int TeamLeader::getrequiredHours() const
{
   return requiredHours;
}
int TeamLeader::gettrainingHours() const
{
   return trainingHours;
}

void TeamLeader::setmonthlyBonus(int mn)
{
   monthlyBonus = mn;
}

void TeamLeader::setrequiredHours(int rh)
{
   requiredHours = rh;
}
void TeamLeader::settrainingHours(int th)
{
   if (th >= 8)
      trainingHours = th;
   else
      throw IncompleteTraining();
}

double TeamLeader::moneyearned()
{
   return (hoursworkedthismonth * hourlypayrate) + monthlyBonus;
}

void TeamLeader::yellout()
{
   std::cout << "Get back to work, lazy bum!" << std::endl;
}