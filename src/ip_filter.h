#include <stdint.h>
#include <string>
#include <list>
#include <tuple>
#include <memory>
#include <algorithm>
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

    template<class Tuple1, class Tuple2, std::size_t indx>
    struct tuple_el_coparator_t
    {
        
        static bool compare(const Tuple1 &ip1, const Tuple2 &ip2)
        {
            return (std::get<indx>(ip1) == std::get<indx>(ip2)) && tuple_el_coparator_t<Tuple1,Tuple2,indx - 1>::compare(ip1, ip2);
        }
    };

    template<class Tuple1, class Tuple2>
    struct tuple_el_coparator_t<Tuple1, Tuple2, 0>
    {
        static bool compare(const Tuple1 &ip1, const Tuple2 &ip2)
        {
            return std::get<0>(ip1) == std::get<0>(ip2);
        }
    };

    template <class T>
    struct tuple_comparator_t
    {
        static bool match(const ip4_addr_t &ip1, const T &ip2)
        { 
            const std::size_t max_index = std::tuple_size<T>::value;
            if(max_index == 0)
            return true;
            return tuple_el_coparator_t<decltype(ip1),decltype(ip2),max_index - 1>::compare(ip1, ip2);
        }
    };

    template<class...ARGS> 
    std::unique_ptr<ip_filter_t> select(ARGS...args)
    {
        static_assert(sizeof...(args) > 0, "ip filter len <= 0");
        static_assert(sizeof...(args) < 5, "ip filter len > 4");
        auto res = std::make_unique<ip_filter_t>();
        const auto ip2 = std::make_tuple(args...);
        for(const auto &ip1 : ip_list)
        {
            if(tuple_comparator_t<decltype(ip2)>::match(ip1,ip2))
                res->ip_list.push_back(ip1);
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
