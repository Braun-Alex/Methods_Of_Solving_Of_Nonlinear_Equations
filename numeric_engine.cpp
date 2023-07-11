#include "numeric_engine.h"
Numeric_Engine::Numeric_Engine(double entered_accuracy, std::pair<double, double> entered_section,
                               Function entered_function,
               const std::shared_ptr<Numeric_Method> &entered_method):function(std::move(
                       entered_function))
{
if (entered_accuracy<=0.0) throw std::invalid_argument("Accuracy must be greater than zero!");
accuracy=entered_accuracy;
section=entered_section;
method=entered_method;
}
void Numeric_Engine::Execute() const
{
std::cout<<std::setprecision(10)<<std::setw(99)<<std::setfill('*')<<'*'<<'\n'
<<"Accuracy: "<<accuracy<<'\n'
<<"Section: ["<<section.first<<"; "<<section.second<<"]"<<'\n'
<<"Function: "<<function.expression<<'\n'
<<"Method: "<<method->Name()<<'\n'
<<"Computing..."<<'\n'<<std::setfill(' ');
method->Execute(accuracy, section, function);
std::cout<<std::setw(99)<<std::setfill('*')<<'*'<<'\n';
}