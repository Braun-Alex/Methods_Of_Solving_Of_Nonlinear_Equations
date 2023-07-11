#pragma once
#include "resources.h"
#include "numeric_method.h"
#include "function.h"
class Numeric_Engine final
{
public:
explicit Numeric_Engine(double entered_accuracy, std::pair<double, double> entered_section,
                        Function entered_function,
               const std::shared_ptr<Numeric_Method> &entered_method);
void Execute() const;
private:
double accuracy;
std::pair<double, double> section;
Function function;
std::shared_ptr<Numeric_Method> method;
};