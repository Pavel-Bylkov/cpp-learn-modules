#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) 
            : AForm("ShrubberyCreationForm", 145, 137, target)
{
    ascii_tree =
        "                                                           \n"
        "                 ----         -====-                       \n"
        "      --==--   -@@@@=-         ==@@@@-    -=====-          \n"
        "     --===@@@=-@@======-         -==@@= -@@@@@@@@@=-       \n"
        "         -===@@@@@@=@=====    --=====@@=@====-=---  -      \n"
        "     -=@@@@@-=@====@@@=-   -@@@@@@@=@@@@@==-=@@@@@=-       \n"
        "    @@@@@-  -@@@-==---@@= -@@@@==  -@-@@-=@@-  =@@@@@-     \n"
        "   === -    -@@@- -@- --= =@@- -  -@  @@@ =@@@-  --=-@=    \n"
        "            -@@@-   @=     @--   -@- -@@@- =@@@-      @-   \n"
        "             @@@-    =@    -    -@-  -=@@- ==@@=       -   \n"
        "             -==-     =@        @=   -@@=   -@@            \n"
        "                       @=      -@    -@-    ==             \n"
        "                       -@-     @=                          \n"
        "                        @@    -@                           \n"
        "                        =@    @=                           \n"
        "                        =@-  =@                            \n"
        "                        -@= -@-                            \n"
        "                        -@@-@@                             \n"
        "                      --=====--                            \n"
        "                                                           \n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & oth) : AForm(oth)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & oth)
{
    return *this;
}

void ShrubberyCreationForm::writeToFile(std::string const & fname, std::string const & str) const
{
    std::ofstream outfile(fname);
    if (outfile.is_open())
    {
        outfile << str;
        outfile.close();
    }
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::checkExec(executor);
    this->writeToFile(this->getTarget() + "_shrubbery", ascii_tree);
}

AForm* ShrubberyCreationForm::clone() const
{
    return (new ShrubberyCreationForm(this->getTarget()));
}