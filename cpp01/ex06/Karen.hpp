#ifndef _KAREN_H_
# define _KAREN_H_

# include <iostream>
# include <string>
# include <cstring>

namespace s
{
    typedef std::string str;
    unsigned long long hash(const char *s1);
}

class Karen
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    void complain( s::str level );
};

#endif