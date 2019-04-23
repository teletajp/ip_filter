#include <stdint.h>
#include <string>
#include <list>
#include <tuple>
#include <memory>
#include <array>
namespace ip_tools
{

using ip4_addr_t = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;
using ip4_list_t = std::list<ip4_addr_t>;
using ip4_list_ptr = std::unique_ptr<ip4_list_t>;

enum class order_t : uint8_t
{
    no_order = 0,
    asc_order,
    dsc_order,
    max_value = dsc_order
};

class ip_filter_t
{
    uint32_t ip_list_size;
    ip4_list_t ip_list;
  public:
    ip_filter_t();
    ~ip_filter_t();
    ip_filter_t(const ip_filter_t &oth) : ip_list_size(oth.ip_list_size), ip_list(oth.ip_list){};

    const ip_filter_t &operator=(const ip_filter_t &oth);
    inline uint32_t count() const { return ip_list_size; };
    bool insert(const std::string &ip_string);
    std::tuple<uint32_t /*inserted*/, uint32_t /*not_inserted*/> list_insert(const std::list<std::string> &ip_string_list);
    template<class ... Args>
    std::unique_ptr<ip_filter_t> select(Args...args)
    {
        auto res = std::make_unique<ip_filter_t>();
        for(const auto &ip : ip_list)
        {
            auto ip2 = std::make_tuple(args...);
            if(ip2 == ip)
                res->ip_list.push_back(ip);
        }
        return res;
    };

    template<class tuple_t, std::size_t indx>
    struct tuple_find_dig
    {
        static bool find(const uint8_t &dig, const tuple_t& t)
        {
            if(dig==std::get<indx>(t))
                return true;
            else
                return tuple_find_dig<tuple_t,indx-1>::find(dig, t); 
        };
    };
    template<class tuple_t>
    struct tuple_find_dig<tuple_t,0>
    {
        static bool find(uint8_t dig, const tuple_t& t)
        {
            if(dig==std::get<0>(t))
                return true;
            else
                return false; 
        };
    };

    std::unique_ptr<ip_filter_t> select_by_digit(uint8_t dig);
    
    void sort(order_t order);
    void print();
};

using ip_filter_ptr = std::unique_ptr<ip_filter_t>;
} // namespace ip_tools
