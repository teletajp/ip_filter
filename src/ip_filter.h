#include <stdint.h>
#include <string>
#include <list>
#include <tuple>
#include <memory>
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
    bool insert(const ip4_addr_t &ip_addr);
    uint8_t find_digit(const ip4_addr_t& ip, const std::string &digit);
    std::string to_string(const ip4_addr_t& ip);
  public:
    ip_filter_t();
    ~ip_filter_t();
    ip_filter_t(const ip_filter_t &oth) : ip_list_size(oth.ip_list_size), ip_list(oth.ip_list){};

    const ip_filter_t &operator=(const ip_filter_t &oth);
    inline uint32_t count() const { return ip_list_size; };
    bool insert(const std::string &ip_string);
    std::tuple<uint32_t /*inserted*/, uint32_t /*not_inserted*/> list_insert(const std::list<std::string> &ip_string_list);

    std::unique_ptr<ip_filter_t> select(const std::string &n1, const std::string &n2, const std::string &n3, const std::string &n4);
    std::unique_ptr<ip_filter_t> select_by_digit(const std::string &like);
    
    void sort();
    void print();
    void print(order_t order);
};

using ip_filter_ptr = std::unique_ptr<ip_filter_t>;
} // namespace ip_tools
