#include "ip_filter.h"
#include <cctype>
#include <iostream>
#include <algorithm>
namespace ip_tools
{

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
        std::string ip_str = std::to_string(std::get<0>(ip)) + "." + std::to_string((std::get<1>(ip))) 
        + "." + std::to_string(std::get<2>(ip)) + "." + std::to_string(std::get<3>(ip));
        std::cout << ip_str << std::endl;
    }
}

void ip_filter_t::sort(order_t order)
{
    if(order == order_t::dsc_order)
        ip_list.sort(std::greater<ip4_addr_t>());
    else if(order == order_t::asc_order)
        ip_list.sort();
}

ip_filter_ptr ip_filter_t::select_by_digit(uint8_t dig)
{
    auto res = std::make_unique<ip_filter_t>();
    for(const auto &ip : ip_list)
    {
        if(tuple_find_dig<ip4_addr_t,3>::find(dig, ip))
            res->ip_list.push_back(ip);
    }
    return res;
}
} // namespace ip_tools