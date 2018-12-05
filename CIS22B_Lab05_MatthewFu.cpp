/*This program is a new employee's tour of the factory. He or she enters his or her name
and the current date. Then he or she is assigned an ID number, a shift, and an hourly pay rate.
Afterward, he or she meets with his or her ShiftSupervisor and TeamLeader.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> //Need for the rand() function
#include "TeamLeader.h" 
#include "ShiftSupervisor.h"
using namespace std;

//Function prototypes declared here.
double displayMoney(ProductionWorker &);
void vocalCommands(TeamLeader &);
void vocalCommands(ProductionWorker &);
/*
Pseudocode:
Ask user for his or her name.
Ask the user for the current date.
Creates a ProductionWorker object.
Calls mutators to set object's instance variable with required items.
   If the user inputs an incorrect number for the ID, an exception will be thrown
   If the user inputs an invalid shift number, then an exception will be thrown
   If the user puts in an hourlyrate of less than 0 dollars, then an exception will be thrown
Creates another ProductionWorker object, but calls the second constructor.
Creates ShiftSupervisor object.
Creates TeamLeader object.
Introduce user to factory and let's him or her know his or her shift, hourly pay, and monthly rate.
Introduce user to the Shift Supervisor and let's user know annual salary as well as bonus.
Asks for the completed training hours of the Team Leader.
   If it is less than 8 hours, an exception will be thrown.
Call vocal command functions that has a Teamleader object as a parameter
Call vocal command function that has a Production object as a parameter
Introduce user to the TeamLeader. Shows the overriden displayMoney function.
*/
int main()
{
   string name;
   string date;
   int Idnumber;
   int shiftentered;
   double hourlyrateentered;
   bool tryAgain = true;
   srand(time(NULL)); //To seed the time.
   int shift = rand() % 2 + 1; // If 1, then day shift. If 2, the night shift.
   double hourlyrate = 12.00;
   int ID = rand() % 9999; //Pseudo-randomly generate an ID number
   int hoursworkedinamonth = 150;
   ProductionWorker Person;
   cout << "Welcome to the factory. What is your name?" << endl;
   getline(cin, name);
   cout << "What is the current date? Please enter in mm/dd/yyyy format." << endl;
   getline(cin, date);
   cout << "What do you want your ID to be? Please keep it between 0 and 9999." << endl;
   cin >> Idnumber;
   while (tryAgain)
   {
      try {
         Person.setNumber(Idnumber);
         // If no exception was thrown, then the
            // next statement will execute. 
         tryAgain = false;
      }
      catch (ProductionWorker::InvalidEmployeeNumber)
      {
         cout << "Error: A bad number was entered. Please keep it between 0 and 9999" << endl;
         cin >> Idnumber;
      }
   }
   cout << "Our policy is that we allow our worker to choose your shift. What shift would you like? Enter 1 for the day shift or 2 for the night shift. " << endl;
   cin >> shiftentered;
   tryAgain = true;
   while (tryAgain)
   {
      try {
         Person.setshift(shiftentered);
         // If no exception was thrown, then the
         // next statement will execute. 
         tryAgain = false;
      }
      catch (ProductionWorker::InvalidShift)
      {
         cout << "Error: An invalid shift Please type in 1 or 2. " << endl;
         cin >> shiftentered;
      }
   }
   cout << "We are feeling generous and you may even choose your hourly rate. Enter an hourly rate that is greater than 0 dollars an hour. " << endl;
   cin >> hourlyrateentered;

   tryAgain = true;
   while (tryAgain) {
      try {
         Person.sethourlypayrate(hourlyrateentered);
         // If no exception was thrown, then the
         // next statement will execute. 
         tryAgain = false;
      }
      catch (ProductionWorker::InvalidPayRate)
      {
         cout << "Error: Give me more money. Please keep it positive " << endl;
         cin >> hourlyrateentered;
      }
   }
   Person.setName(name);

   Person.setDate(date);
   Person.sethoursworkedthismonth(hoursworkedinamonth);

   //Create a ProductionWorker object and call constructor #2. This demonstrates constructor overload.
   ProductionWorker FourthPerson(shift, hourlyrate, "Megaman", 123456, "08/14/2006", hoursworkedinamonth);
   int requiredtraininghours;
   //Create ShiftSupervisor object and TeamLeader object.
   ShiftSupervisor SecondPerson(100000, 20000, "UltraMan", 234234, "09/18/1997");
   // TeamLeader ThirdPerson(3000, 50, , 65, hoursworkedinamonth, "Bob the Builder", 345345, "05/17/1993");

   cout << "Welcome, " << Person.getName() << endl;
   cout << "The date you joined our company is " << Person.getDate() << endl;
   cout << "Your ID number is " << Person.getNumber() << endl;
   if (Person.getshift() == 1) { cout << "You will be taking the day shift." << endl; }
   if (Person.getshift() == 2) { cout << "You will be taking the night shift." << endl; }
   cout << "Your hourly pay rate will be $" << Person.gethourlypayrate() << endl;
   //The following line calls the displayMoney(ProductionWorker &) function and passes a ProductionWorker object
   //to the function. 
   cout << "This means that you will earn $" << displayMoney(Person) << " each month." << endl;
   cout << "Let's get acquainted with others. " << endl << endl;

   cout << SecondPerson.getName() << " is your supervisor." << endl;
   cout << "He gets $" << SecondPerson.getannualsalary() << " a year as a salary and $" << SecondPerson.getannualproductionbonus()
      << " as a production bonus if his shift meets production goal so work hard for him. Moving on." << endl << endl;

   TeamLeader ThirdPerson;
   ThirdPerson.sethoursworkedthismonth(hoursworkedinamonth);
   ThirdPerson.setDate("05/17/1993");
   ThirdPerson.setrequiredHours(50);
   ThirdPerson.setmonthlyBonus(3000);
   ThirdPerson.setName("Bob the Builder");
   ThirdPerson.setNumber(9001);
   cout << SecondPerson.getName() << ", how many hours of training did " << ThirdPerson.getName() << " complete so far? He did complete at least 8 hours right? " << endl;
   cin >> requiredtraininghours;
   tryAgain = true;
   while (tryAgain) {
   try {
      ThirdPerson.settrainingHours(requiredtraininghours);
      tryAgain = false;
   }
   catch (TeamLeader::IncompleteTraining)
   {
      cout << "What! That can't be! He must have completed at least 8 hours!" << endl;
      cin >> requiredtraininghours;
   }
   }  cout << "Whew. I thought he was an incompetant leader for a second. " << endl << endl;

   vocalCommands(ThirdPerson); //Calls the vocalCommands(TeamLeader &) function.
   vocalCommands(FourthPerson); //Calls the void vocalCommands(ProductionWorker &) function.

   cout << "\nThat's the TeamLeader ," << ThirdPerson.getName() << ", and that's your teammate ," << FourthPerson.getName() << endl;
   //The following line calls the displayMoney(ProductionWorker &) function but this time passes a TeamLeader object
   //to the function. This causes the definition to be overridden.
   cout << "As you can see, they do not get along very well. That's because " << FourthPerson.getName() << " does not think that "
      << ThirdPerson.getName() << " should get $" << displayMoney(ThirdPerson) << " each month." << endl;

   cout << "I think the TeamLeader is just stressed out. In addition to his work, he has to take " << ThirdPerson.getrequiredHours()
      << " hours of training each year and he has only so far completed " << ThirdPerson.gettrainingHours() << endl;

   cout << "That's everyone you need to know. Work hard!" << endl;
   system("pause");
   return 0;
}

//This function passes a ProductionWorker object's reference
//and call the moneyearned() function
double displayMoney(ProductionWorker &person)
{
   //Dynamic binding. The function moneyearned() is defined differently in each class.
   //If a ProductionWorker object is passed, the ProductionWorker::moneyearned() function is called.
   //If a TeamLeader object is passed, the TeamLeader::moneyearned() function is called
   return person.moneyearned();
}

//This function passes a TeamLeader Object's reference
//and call the yellout function
void vocalCommands(TeamLeader &person)
{
   //Static Binding. Same name as another function, except a different object is passed.
   //The output is different than the one in ProductionWorker.
   person.yellout();
}

//This function passes a ProductionWorker Object's reference
//and call the yellout function
void vocalCommands(ProductionWorker &person)
{
   //Static Binding. Same name as another function, except a different object is passed.
   //The output is different than the one in Teamleader.
   person.yellout();
}
