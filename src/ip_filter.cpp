#include "ip_filter.h"
#include <cctype>
#include <iostream>

namespace ip_tools
{

ip4_addr_t::ip4_addr_t(const std::string &origin_ip)
{
    internal = "000.000.000.000";
    int ii = 14;
    int oi = (int)origin_ip.length() - 1;
    int c = 0;//количество цифр в компоненте ip c>0 && c<4
    int cc = 0;//количество компонентов ip cc==4
    for(;ii>=0 && oi>=0;--ii)
    {
        char ch = origin_ip[oi];
        if( std::isdigit(ch))
        {
            if(internal[ii] == '.')
                break;
            internal[ii] = ch;
            ++c;
            if(c>3)
                break;
        }
        else if(ch == '.')
        {
            if(c == 0 || c > 3)
                break;
            if(internal[ii] != '.')
                continue;
            c = 0;
            ++cc;
        }
        else
            break;

        --oi;
    }
    if(c)
        ++cc;
    if(cc == 4)
    {
        if(!( 
            (internal[0] > '2' || (internal[0] == '2' && (internal[1] > '5' || (internal[1] == '5' && internal[2] > '5'))))
            ||(internal[4] > '2' || (internal[4] == '2' && (internal[5] > '5' || (internal[5] == '5' && internal[6] > '5'))))
            ||(internal[8] > '2' || (internal[8] == '2' && (internal[9] > '5' || (internal[9] == '5' && internal[10] > '5'))))
            ||(internal[12] > '2' || (internal[12] == '2' && (internal[13] > '5' || (internal[13] == '5' && internal[14] > '5'))))
        ))
        origin = origin_ip;
    }
        
}

const ip4_addr_t& ip4_addr_t::operator=(const ip4_addr_t &o)
{
    origin = o.origin;
    internal = o.internal;
    return *this;
}

uint8_t ip4_addr_t::find(const std::string& like) const
{
    auto pos = internal.find(like);
    if (pos == std::string::npos)
        return 0;
    if (pos < 4)
        return 1;
    if (pos < 8)
        return 2;
    if (pos < 12)
        return 3;
    return 4;
}

ip_filter_t::ip_filter_t():
ip_list_size(0)
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

bool ip_filter_t::insert(const ip4_addr_t& ip_addr)
{
    if(ip_addr.is_valid())
    {
        ip_list.push_back(ip_addr);
        ++ip_list_size;
        return true;
    }
    return false;
}

bool ip_filter_t::insert(const std::string &ip_string)
{
    ip4_addr_t ip(ip_string);
    if(ip.is_valid())
    {
        ip_list.push_back(ip);
        ++ip_list_size;
        return true;
    }
    return false;
}

std::tuple<uint32_t,uint32_t> ip_filter_t::list_insert(const std::list<std::string> &ip_string_list)
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
        std::cout << ip.get_origin() << std::endl;
    }
}

void ip_filter_t::print(order_t order)
{
    sort(order_t::asc_order);
    if(order == order_t::asc_order)
    {
        for(auto ip = ip_list.begin(); ip != ip_list.end(); ++ip)
        {
            std::cout << ip->get_origin() << std::endl;
        }
    }
    else
    {
        for(auto ip = ip_list.rbegin(); ip != ip_list.rend(); ++ip)
        {
            std::cout << ip->get_origin() << std::endl;
        }
    }
    
}

void ip_filter_t::sort(order_t order)
{
    if (order == asc_order)
        ip_list.sort();
    else
        ip_list.sort(ip4_addr_t::less_comp);
}

ip_filter_ptr ip_filter_t::select(const std::string& like)
{
    auto res = std::make_shared<ip_filter_t>();
    for(const auto& ip:ip_list)
    {
        if(ip.find(like))
        res->insert(ip);
    }
    return res;
}

ip_filter_ptr ip_filter_t::select( const std::string& n1, const std::string& n2, const std::string& n3, const std::string& n4)
{
    auto res = std::make_shared<ip_filter_t>();
    for (const auto &ip : ip_list)
    {
        if (!n1.empty() && ip.find(n1) != 1)
            continue;
        if (!n2.empty() && ip.find(n2) != 2)
            continue;
        if (!n3.empty() && ip.find(n3) != 3)
            continue;
        if (!n4.empty() && ip.find(n4) != 4)
            continue;

        res->insert(ip);
    }
    return res;
}

}