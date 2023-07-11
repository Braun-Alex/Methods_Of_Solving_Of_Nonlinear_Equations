#pragma once
#include "numeric_method.h"
double Derivative_Function(double x);
void Newton_Method_Print(size_t iteration, double argument, double difference,
                         double value, double derivative_value);
class Newton_Method: public Numeric_Method
{
std::string Name() const override;
void Execute(double accuracy, std::pair<double, double> section, const Function &function) const override;
};