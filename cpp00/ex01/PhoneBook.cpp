#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->count = 0;
	for (int i = 0; i < 8; ++i)
		this->_book[i] = Contact();
}

void    PhoneBook::add(void)
{
	s::print_line(50, '*');
	std::cout << "ADD mode\n";
	this->_book[this->count++ % 8].input_info();
}

void	PhoneBook::_print_column(s::str field)
{
	s::str tmp;

	std::cout << s::YELLOW << std::setfill(' ') << std::setw(1) << "|";
	if (field.length() > 10)
	{
		tmp.append(field, 0, 9);
		std::cout << s::CYAN << tmp << ".";
	}
	else
		std::cout << s::CYAN << std::setw(10) << field;
}

void    PhoneBook::_print_contact(int index)
{
	std::cout << s::YELLOW << "|" << s::CYAN;
	std::cout << std::setw(10) << std::right << index + 1;
	this->_print_column(this->_book[index].get_first_name());
	this->_print_column(this->_book[index].get_last_name());
	this->_print_column(this->_book[index].get_nickname());
	std::cout << s::YELLOW << "|" << std::endl;
}

void   PhoneBook::_print_tabl(void)
{
	int	index = 0;

	s::print_line(45, '-', s::YELLOW);
    std::cout << s::YELLOW << "|  Index   |First Name|Last Name | Nickname |\n";
	s::print_line(45, '-', s::YELLOW);
	while (index < 8 && !(this->_book[index].get_first_name().empty()))
	{
		this->_print_contact(index++);
		std::cout << s::YELLOW << "|";
		for (int i = 0; i < 4; ++i)
			std::cout << std::setfill('-') << std::setw(11) << "|";
		std::cout << s::NOCOLOR << std::setfill(' ') << std::endl;
	}
}

void PhoneBook::_info_contact(void)
{
	int	index = 0;

    std::cout << s::NOCOLOR << "Enter index: ";
    if((std::cin >> std::noskipws >> index && index > 0 && index < 9
        && index <= this->count && std::cin.get() == 10 ))
    	this->_book[index - 1].print();
    else
    {
        if(std::cin.eof())
			std::exit(1);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect index" << std::endl;
    }
}

void   PhoneBook::search(void)
{
	s::print_line(50, '*');
	std::cout << "SEARCH mode\n";
	this->_print_tabl();
	if (this->_book[0].get_first_name().empty())
		std::cout << s::RED << "Contacts not found!\n" << s::NOCOLOR;
	else
		this->_info_contact();
}
