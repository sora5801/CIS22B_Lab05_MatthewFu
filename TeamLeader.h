#pragma once
#include "ProductionWorker.h"


//The class TeamLeader is a derived class of ProductionWorker. This demonstrates inheritance.
class TeamLeader : public ProductionWorker
{
private:
   int monthlyBonus; //Money earned extra each month
   int requiredHours; //Required training hours.
   int trainingHours; //Hours put into so far.
public:
   //Default Constructor
   class IncompleteTraining {};
   TeamLeader();
   //Constructor
   TeamLeader(int, int, int, double, int, std::string, int, std::string);

   //Accessors
   int getmonthlyBonus() const;
   int getrequiredHours() const;
   int gettrainingHours() const;

   //Mutators
   void setmonthlyBonus(int);
   void setrequiredHours(int);
   void settrainingHours(int);

   //This function is overriden from the parent class
   double moneyearned();
   void yellout(); //This function has the same name as the parent class, only different output.
};