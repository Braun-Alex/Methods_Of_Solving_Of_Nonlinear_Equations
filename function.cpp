#include "function.h"
Function::Function(std::function<double(double)> entered_function,
                   std::string entered_expression):function(std::move(entered_function)),
                   expression(std::move(entered_expression)) {}