#include <list>
#include <vector>
#include <iostream>
#include "ip_filter.h"

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

int main()
{
    try
    {
        std::list<std::string> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(v.at(0));
        }

        ip_tools::ip_filter_t main_filter;
        //auto res = main_filter.list_insert(ip_pool);
		main_filter.list_insert(ip_pool);
        // std::cout << "inserted " << std::get<0>(res) << " ip, bad ip " << std::get<1>(res) << std::endl;
        auto filter_all = main_filter.select("", "", "", "");
        filter_all->print(ip_tools::order_t::dsc_order);
        auto filter_1 = main_filter.select("001", "", "", "");
        filter_1->print(ip_tools::order_t::dsc_order);
        auto filter_46_70 = main_filter.select("046", "070", "", "");
        filter_46_70->print(ip_tools::order_t::dsc_order);
        auto filter_46 = main_filter.select("046");
        filter_46->print(ip_tools::order_t::dsc_order);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
