#include "iteration_method.h"
double Iteration_Function(double x)
{
return sqrt(3-pow(0.5, x));
}
void Iteration_Method_Print(size_t iteration, double argument, double difference,
                            double value, double iteration_value)
{
std::cout<<std::setw(5)<<iteration
<<std::setw(20)<<argument
<<std::setw(20)<<difference
<<std::setw(20)<<value
<<std::setw(20)<<iteration_value<<'\n';
}
std::string Iteration_Method::Name() const
{
return "iteration method";
}
void Iteration_Method::Execute(double accuracy, std::pair<double, double> section,
                               const Function &function) const
{
std::cout<<std::left<<std::setw(5)<<"n"
<<std::setw(20)<<"x[n]"
<<std::setw(20)<<"| x[n] - x[n-1] |"
<<std::setw(20)<<"|f(x[n])|"
<<std::setw(20)<<"q(x[n])"<<'\n';
size_t i=0;
double current_argument=(section.first+section.second)/2,
current_value=std::abs(function.function(current_argument)),
current_iteration_value=Iteration_Function(current_argument);
std::cout<<std::setw(5)<<i
<<std::setw(20)<<current_argument
<<std::setw(20)<<"-"
<<std::setw(20)<<current_value
<<std::setw(20)<<current_iteration_value<<'\n';
double current_difference=100.0;
while (current_difference>=accuracy||current_value>=accuracy)
{
++i;
current_difference=std::abs(current_iteration_value-current_argument);
current_argument=current_iteration_value;
current_value=std::abs(function.function(current_argument));
current_iteration_value=Iteration_Function(current_argument);
Iteration_Method_Print(i, current_argument, current_difference, current_value, current_iteration_value);
}
}