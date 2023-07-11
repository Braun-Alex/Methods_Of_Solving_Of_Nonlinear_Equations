#pragma once
#include "numeric_method.h"
#include "newton_method.h"
void Modified_Newton_Method_Print(size_t iteration, double argument, double difference, double value);
class Modified_Newton_Method: public Numeric_Method
{
std::string Name() const override;
void Execute(double accuracy, std::pair<double, double> section, const Function &function) const override;
};