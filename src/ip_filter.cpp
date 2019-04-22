#include "ip_filter.h"
#include <cctype>
#include <iostream>
#include <algorithm>
namespace ip_tools
{

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
        std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << std::endl;
    }
}

void ip_filter_t::sort(order_t order)
{
    if(order == order_t::dsc_order)
        ip_list.sort(std::greater<ip4_addr_t>());
    else if(order == order_t::asc_order)
        ip_list.sort();
}

ip_filter_ptr ip_filter_t::select_by_digit(const std::string &digit)
{
    auto res = std::make_unique<ip_filter_t>();
    for(const auto &ip : ip_list)
    {
        if(find_digit(ip, digit))
            res->ip_list.push_back(ip);
    }
    return res;
}

//ip_filter_ptr ip_filter_t::select(uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4)
//{
//    auto res = std::make_unique<ip_filter_t>();
//    for (const auto &ip : ip_list)
//    {
//        if (!n1.empty() && find_digit(ip, n1) != 1)
//            continue;
//        if (!n2.empty() && find_digit(ip, n2) != 2)
//            continue;
//        if (!n3.empty() && find_digit(ip, n3) != 3)
//            continue;
//        if (!n4.empty() && find_digit(ip, n4) != 4)
//            continue;
//
//        res->insert(ip);
//    }
//    return res;
//}

} // namespace ip_tools