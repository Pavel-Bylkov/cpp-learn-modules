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
	this->_book[this->count++].input_info();
	this->count = this->count % 8;
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

int	PhoneBook::_input_index(void)
{
	int	index = 0;

	while (index == 0)
	{
		std::cout << s::NOCOLOR << "Enter index: ";
		std::cin >> index;
		if (index > 8)
		{
			std::cout << s::RED << "Max index: 8\n" << s::NOCOLOR;
			index = 0;
		}
		else if (index < 1)
		{
			std::cout << s::RED << "Min index: 1\n" << s::NOCOLOR;
			index = 0;
		}
	}
	std::cin.get();
	return (index - 1);
}

void   PhoneBook::search(void)
{
	s::print_line(50, '*');
	std::cout << "SEARCH mode\n";
	this->_print_tabl();
	if (this->_book[0].get_first_name().empty())
		std::cout << s::RED << "Contacts not found!\n" << s::NOCOLOR;
	else
		this->_book[this->_input_index()].print();
}
