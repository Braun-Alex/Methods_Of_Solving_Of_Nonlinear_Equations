#pragma once
#include "numeric_method.h"
double Iteration_Function(double x);
double Iteration_Method_Print(double iteration, double difference, double value, double iteration_value);
class Iteration_Method: public Numeric_Method
{
std::string Name() const override;
void Execute(double accuracy, std::pair<double, double> section, const Function &function) const override;
};