#include "ip_filter.h"
#include <cctype>
#include <iostream>
#include <algorithm>
namespace ip_tools
{
bool ip_filter_t::insert(const ip4_addr_t & ip_addr)
{
    ip_list.push_back(ip_addr);
    return true;
}

uint8_t ip_filter_t::find_digit(const ip4_addr_t& ip, const std::string & digit)
{
    uint8_t dig = 0;
    try
    {
        int idig = std::stoi(digit);
        if(idig < 0 || idig > 255)
            return 0;
        dig = (uint8_t)idig;
    }
    catch(...) { return 0; }

    if(std::get<0>(ip) == dig)
        return 1;
    if(std::get<1>(ip) == dig)
        return 2;
    if(std::get<2>(ip) == dig)
        return 3;
    if(std::get<3>(ip) == dig)
        return 4;

    return 0;
}

std::string ip_filter_t::to_string(const ip4_addr_t & ip)
{
    return std::to_string(std::get<0>(ip)) + "." + std::to_string(std::get<1>(ip)) + "." + std::to_string(std::get<2>(ip)) + "." + std::to_string(std::get<3>(ip));
}

ip_filter_t::ip_filter_t() : ip_list_size(0)
{
}

ip_filter_t::~ip_filter_t()
{
}

const ip_filter_t &ip_filter_t::operator=(const ip_filter_t &oth)
{
    ip_list_size = oth.ip_list_size;
    ip_list = oth.ip_list;
    return *this;
}

bool ip_filter_t::insert(const std::string &ip_string)
{
    std::string::size_type beg, end, len;
    beg = end = len = 0;
    int dig = 0;
    uint8_t d1, d2, d3, d4;
    const auto max_len = ip_string.length();

    try
    {
        end = ip_string.find('.', beg);
        if(end == std::string::npos) return false;
        len = end - beg;
        if(len > 3) return false;
        dig = std::stoi(ip_string.substr(beg, len));
        if(dig < 0 || dig > 255) return false;
        d1 = dig;
        beg = end + 1;
        if(beg >= max_len) return false;

        end = ip_string.find('.', beg);
        if(end == std::string::npos) return false;
        len = end - beg;
        if(len > 3) return false;
        dig = std::stoi(ip_string.substr(beg, len));
        if(dig < 0 || dig > 255) return false;
        d2 = dig;
        beg = end + 1;
        if(beg >= max_len) return false;

        end = ip_string.find('.', beg);
        if(end == std::string::npos) return false;
        len = end - beg;
        if(len > 3) return false;
        dig = std::stoi(ip_string.substr(beg, len));
        if(dig < 0 || dig > 255) return false;
        d3 = dig;
        beg = end + 1;
        if(beg >= max_len) return false;

        len = max_len - beg;
        if(len > 3) return false;
        dig = std::stoi(ip_string.substr(beg, len));
        if(dig < 0 || dig > 255) return false;
        d4 = dig;

        ip_list_size++;
        ip_list.emplace_back(std::make_tuple(d1,d2,d3,d4));
        return true;
    }
    catch(...){}
    return false;
}

std::tuple<uint32_t, uint32_t> ip_filter_t::list_insert(const std::list<std::string> &ip_string_list)
{
    uint32_t inserted = 0;
    uint32_t not_inserted = 0;
    for (const auto &ip_string : ip_string_list)
    {
        if (insert(ip_string))
            ++inserted;
        else
            ++not_inserted;
    }
    return std::make_tuple(inserted, not_inserted);
}

void ip_filter_t::print()
{
    for (const auto &ip : ip_list)
    {
        std::cout << to_string(ip) << std::endl;
    }
}

void ip_filter_t::print(order_t order)
{
    sort();
    if (order == order_t::asc_order)
    {
        for (auto ip = ip_list.begin(); ip != ip_list.end(); ++ip)
        {
            std::cout << to_string(*ip) << std::endl;
        }
    }
    else
    {
        for (auto ip = ip_list.rbegin(); ip != ip_list.rend(); ++ip)
        {
            std::cout << to_string(*ip) << std::endl;
        }
    }
}

void ip_filter_t::sort()
{
    ip_list.sort();
}

ip_filter_ptr ip_filter_t::select_by_digit(const std::string &digit)
{
    auto res = std::make_unique<ip_filter_t>();
    for(const auto &ip : ip_list)
    {
        if(find_digit(ip, digit))
            res->insert(ip);
    }
    return res;
}

ip_filter_ptr ip_filter_t::select(const std::string &n1, const std::string &n2, const std::string &n3, const std::string &n4)
{
    auto res = std::make_unique<ip_filter_t>();
    for (const auto &ip : ip_list)
    {
        if (!n1.empty() && find_digit(ip, n1) != 1)
            continue;
        if (!n2.empty() && find_digit(ip, n2) != 2)
            continue;
        if (!n3.empty() && find_digit(ip, n3) != 3)
            continue;
        if (!n4.empty() && find_digit(ip, n4) != 4)
            continue;

        res->insert(ip);
    }
    return res;
}

} // namespace ip_tools