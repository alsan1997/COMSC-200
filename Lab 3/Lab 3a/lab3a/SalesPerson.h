// Lab 3a, SalesPerson.h
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef SALESPERSON_H_INCLUDED
#define SALESPERSON_H_INCLUDED

class SalesPerson
{
public:
  static const int monthsPerYear = 12; // months in one year
  SalesPerson(); // constructor
  void getSalesFromUser(); // input sales from keyboard
  void setSales(int, double); // set sales for a specific month
  void printAnnualSales(); // summarize and print sales
private:
  double totalAnnualSales(); // prototype for utility function
  double sales[monthsPerYear]; // 12 monthly sales figures
}; // end class SalesPerson

#endif // SALESPERSON_H_INCLUDED
