#include "replace.hpp"

int read_file(s::str const & fname, s::str& str)
{
    s::str input;
    std::ifstream infile;

    infile.open(fname);
    if (infile.is_open())
    {
        while (!infile.eof())
        {
            std::getline(infile, input);
            str.append(input);
            if (!infile.eof())
                str.append("\n");
            input.clear();
        }
        infile.close();
        return 1;
    }
    std::cerr << "Error: Unable to open file_in\n";
    return 0;
}

void replace(s::str const & s1, s::str const & s2, s::str const & in, s::str& out)
{
    std::size_t start;
    std::size_t found;
    std::size_t len1 = s1.length();
    std::size_t len2 = s2.length();

    found = in.find(s1);
    if (found != std::string::npos)
    {
        out.append(in, 0, found);
        out.append(s2);
    }
    else
        out.append(in);
    while (found != std::string::npos && in.length() > found + len1)
    {
        start = found + len1;
        found = in.find(s1, start);
        if (found != std::string::npos)
        {
            out.append(in, start, found - start);
            out.append(s2);
        }
        else
            out.append(in.begin() + start, in.end());
    }
}

void to_uppercase(s::str& s_out, s::str const & s_in) 
{
    const char *tmp = s_in.c_str();

    while (*tmp)
    {
        s_out += (char)std::toupper(*tmp);
        tmp++;
    }
}

int write(s::str const & fname, s::str& str)
{
    s::str new_name = "";

    to_uppercase(new_name, fname);
    new_name.append(".replace");
    std::ofstream outfile(new_name);
    if (outfile.is_open())
    {
        outfile << str;
        outfile.close();
        return 1;
    }
    std::cerr << "Error: Unable to open file_out\n"; 
    return 0;
}

int replace_infile(s::str const & fname, s::str const & s1, s::str const & s2)
{
    s::str tmp_in = "";
    s::str tmp_out = "";

    if (read_file(fname, tmp_in))
    {
        replace(s1, s2, tmp_in, tmp_out);
        if (write(fname, tmp_out))
            return 0;
    }
    return 1;
}