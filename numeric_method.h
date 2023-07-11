#pragma once
#include "resources.h"
#include "function.h"
class Numeric_Method
{
public:
virtual std::string Name() const=0;
virtual void Execute(double accuracy, std::pair<double, double> section, const Function &function) const=0;
};