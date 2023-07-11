#include "numeric_engine.h"
#include "iteration_method.h"
#include "newton_method.h"
#include "modified_newton_method.h"
const double ACCURACY=0.00001;
double expression(double x)
{
return pow(x, 2)-3+pow(0.5, x);
}
int main()
{
const std::pair<double, double> SECTION=std::make_pair(1.0, 2.0);
const Function function(expression, "x^2 - 3 + 0.5^x");
std::shared_ptr<Numeric_Method> method=std::make_shared<Iteration_Method>();
Numeric_Engine iteration_engine(ACCURACY, SECTION, function, method);
iteration_engine.Execute();
method=std::make_shared<Newton_Method>();
Numeric_Engine newton_engine(ACCURACY, SECTION, function, method);
newton_engine.Execute();
method=std::make_shared<Modified_Newton_Method>();
Numeric_Engine modified_newton_engine(ACCURACY, SECTION, function, method);
modified_newton_engine.Execute();
return 0;
}