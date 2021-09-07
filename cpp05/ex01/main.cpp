#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    Bureaucrat sheff1("Boss1", 148);
    try
    {
        Form form1("Form1", 50, 90);
        std::cout << form1 << " get\n";
        sheff1.signForm(form1);
    }
    catch (std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
    }
    try
    {
        Form form2("Form2", 148, 90);
        std::cout << form2 << " get\n";
        sheff1.decrGrade();
        sheff1.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << " exception caught: " << e.what() << '\n';
    }
    try
    {
        Form form3("Form3", 155, 90);
        std::cout << form3 << " get\n";
        sheff1.signForm(form3);
        std::cout << form3 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << " exception caught: " << e.what() << '\n';
    }
    return 0;
}