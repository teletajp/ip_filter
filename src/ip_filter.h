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
    uint8_t find_digit(const ip4_addr_t& ip, const std::string &digit);
  public:
    ip_filter_t();
    ~ip_filter_t();
    ip_filter_t(const ip_filter_t &oth) : ip_list_size(oth.ip_list_size), ip_list(oth.ip_list){};

    const ip_filter_t &operator=(const ip_filter_t &oth);
    inline uint32_t count() const { return ip_list_size; };
    bool insert(const std::string &ip_string);
    std::tuple<uint32_t /*inserted*/, uint32_t /*not_inserted*/> list_insert(const std::list<std::string> &ip_string_list);

    template <uint8_t Indx>
    bool ta_el_cmp(uint8_t Indx)
    {
        return std::get<Indx>(ip) == values[Indx];
    }

    template<int ... ns>
    bool is_filtered(ip4_addr_t ip, int...)
    {
        static const count = sizeof...(ns) - 1;
        static_assert(count > 0 && count < 5, "invalid count arguments");
        int values[count] = {ns...};
        for(int i = 0; i < count; i++)
        {
            if(ta_el_cmp<i>(i))
        }
        if(count == 1)
        {
            if(std::get<0>(ip) == values[0])
            {
                if(count == 1)
                    return true;
            }
            else
                return false;
        }
    }

    std::unique_ptr<ip_filter_t> select(int...)
    {
        std::array<uint8_t, sizeof...(ns)> filtr = {(uint8_t)ns...};
        uint8_t max_ind = std::min(sizeof...(ns), std::tuple_size<ip4_addr_t>::value);
        auto res = std::make_unique<ip_filter_t>();
        for(const auto &ip : ip_list)
        {
             if(std::get<0>(ip) != filtr[i])
                 break;

            if(i == max_ind)
                res->ip_list.push_back(ip);
        }
        return res;
    };
    //std::unique_ptr<ip_filter_t> select(uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4);
    std::unique_ptr<ip_filter_t> select_by_digit(const std::string &like);
    
    void sort(order_t order);
    void print();
};

using ip_filter_ptr = std::unique_ptr<ip_filter_t>;
} // namespace ip_tools
