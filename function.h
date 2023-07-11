#pragma once
#include "resources.h"
class Function
{
public:
explicit Function(std::function<double(double)> entered_function, std::string entered_expression);
const std::function<double(double)> function;
const std::string expression;
};