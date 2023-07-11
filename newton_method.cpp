#include "newton_method.h"
double Derivative_Function(double x)
{
return 2*x-log(2)*pow(0.5, x);
}
void Newton_Method_Print(size_t iteration, double argument, double difference,
                         double value, double derivative_value)
{
std::cout<<std::setw(5)<<iteration
<<std::setw(20)<<argument
<<std::setw(20)<<std::abs(difference)
<<std::setw(20)<<std::abs(value)
<<std::setw(20)<<derivative_value<<'\n';
}
std::string Newton_Method::Name() const
{
return "newton method";
}
void Newton_Method::Execute(double accuracy, std::pair<double, double> section,
                               const Function &function) const
{
std::cout<<std::left<<std::setw(5)<<"n"
<<std::setw(20)<<"x[n]"
<<std::setw(20)<<"| x[n] - x[n-1] |"
<<std::setw(20)<<"|f(x[n])|"
<<std::setw(20)<<"f'(x[n])"<<'\n';
size_t i=0;
double current_argument=(section.first+section.second)/2,
current_value=function.function(current_argument),
current_derivative_value=Derivative_Function(current_argument);
std::cout<<std::setw(5)<<i
<<std::setw(20)<<current_argument
<<std::setw(20)<<"-"
<<std::setw(20)<<std::abs(current_value)
<<std::setw(20)<<current_derivative_value<<'\n';
double current_difference=100.0;
while (std::abs(current_difference)>=accuracy||std::abs(current_value)>=accuracy)
{
++i;
current_difference=current_value/current_derivative_value;
current_argument-=current_difference;
current_value=function.function(current_argument);
current_derivative_value=Derivative_Function(current_argument);
Newton_Method_Print(i, current_argument, current_difference, current_value, current_derivative_value);
}
}