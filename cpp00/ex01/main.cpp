#include "PhoneBook.hpp"

int main(void)
{
    std::string input;
    PhoneBook book;

    std::cout << s::YELLOW << "Welcom to PhoneBook!\n";
    while (true)
    {
        std::cout << s::NOCOLOR << "Enter command [ADD | SEARCH | EXIT]: ";
        std::getline(std::cin, input);
        if (input == "ADD")
            book.add();
        else if (input == "SEARCH")
            book.search();
        else if (input == "EXIT")
            return (int)(!(std::cout << s::RED << "Program closed!\n"));
        input = "";
    }
    return 0;
}