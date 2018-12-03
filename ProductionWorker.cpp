#include "ProductionWorker.h"

ProductionWorker::ProductionWorker()
{
   shift = 1;
   hourlypayrate = 0;
   name = "";
   number = 0;
   date = "";
   hoursworkedthismonth = 0;
}

ProductionWorker::ProductionWorker(int s, double p, std::string n, int num, std::string date1, int hw)
{
   shift = s;
   hourlypayrate = p;
   name = n;
   number = num;
   date = date1;
   hoursworkedthismonth = hw;
}
void ProductionWorker::setshift(int s)
{
   //If the number is not 1 or 2, an exception will be thrown
   if (s == 1 || s == 2)
      shift = s;
   else
      throw InvalidShift();
}

void ProductionWorker::sethourlypayrate(double h)
{
   //If the hourly rate is less than 0, an exception will be thrown.
   if (h > 0)
      hourlypayrate = h;
   else
      throw InvalidPayRate();
}

void ProductionWorker::sethoursworkedthismonth(int hs)
{
   hoursworkedthismonth = hs;
}

int ProductionWorker::getshift() const
{
   return shift;
}

double ProductionWorker::gethourlypayrate() const
{
   return hourlypayrate;
}

int ProductionWorker::gethoursworkedthismonth() const
{
   return hoursworkedthismonth;
}

double ProductionWorker::moneyearned()
{
   return hourlypayrate * hoursworkedthismonth;
}

void ProductionWorker::yellout()
{
   std::cout << "I'm working here. I'm working here." << std::endl;
}