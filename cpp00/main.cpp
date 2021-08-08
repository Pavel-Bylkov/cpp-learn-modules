#include <iostream>
#include <iomanip> 
#include <ctime>
#define MAX(a, b, c) {int r1, r2; r1 = (a); r2 = (b); c = (r1 >= r2) ? r1 : r2;}

namespace my_std = std;
namespace foo
{
    int f = 300;
}

void	displayTimestamp( void )
{
	std::time_t now = std::time(0);
	std::tm *ltm = localtime(&now);

	// print [19920104_091532]
	std::cout << "[" << ltm->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1;
	std::cout << std::setw(2) << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << ltm->tm_hour;
	std::cout << std::setw(2) << ltm->tm_min;
	std::cout << std::setw(2) << ltm->tm_sec << std::setfill(' ') << "]";

    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);
	std::cout << "[" << buf << "]";
}

int power(int x, unsigned p) {
    int answer = 1;

    for (long unsigned i = 0; i < p; i++)
    {
        answer *= x;
    }
    return answer;
}

int main(void)
{
	int i = 42;
	double d = 3.14;
	const char *s = "C-style string";
	bool f = false;

	displayTimestamp();
	f = std::cout <<  "\033[0;36m" << "This is an integer " << i << "\033[0m" << "\n";
	std::cout << "This is a bool " << f << "\n";
	std::cout << "This is a double " << d << "\n";
	std::cout << "This is a \"" << s << "\"\n";
	std::cout << "This is power(5, 0) " << power(5, 0) << "\n";
	std::cout << "This is power(-5, 1) " << power(-5, 1) << "\n";
	std::cout << "This is power(5, 1) " << power(5, 1) << "\n";
	std::cout << "This is power(5, 2) " << power(5, 2) << "\n";
	std::cout << "This is power(-5, 2) " << power(-5, 2) << "\n";
	std::cout << "This is power(-5, 3) " << power(-5, 3) << "\n";
	int a = 10;
	int b = 20;
	int c = 0;
	MAX(a, b, c); // теперь c равно 20
	std::cout << "This is c " << c << "\n";
	MAX(a += b, b, c); // теперь a = с = 30
	std::cout << "This is a " << a << "\n";
	std::cout << "This is c " << c << "\n";

	std::cout << "Enter an integer and a double:\n";
	std::cin >> i >> d;
	return (int)(not (std::cout << "Your input is " << i << ", " << d << "\n"));
	/*
	char c = '\0';
	while (std::cin.get(c)) { // на каждой итерации считываем один символ в переменную c
		// здесь можно пользоваться значением прочитанным в переменную c 
		if (c != 'a')
			std::cout << c; // выводим символ, если он не равен 'a'
	}
	*/
}