#include <stdint.h>
#include <string>
#include <list>
#include <tuple>
#include <memory>
namespace ip_tools
{

class ip4_addr_t
{
    std::string internal;
    std::string origin;

  public:
    static bool less_comp(const ip4_addr_t &l, const ip4_addr_t &r) { return l.internal > r.internal; };
    ip4_addr_t(){};
    ip4_addr_t(const std::string &origin_ip);
    ip4_addr_t(const ip4_addr_t &other) : internal(other.internal), origin(other.origin){};
    const ip4_addr_t &operator=(const ip4_addr_t &o);
    ~ip4_addr_t(){};
    inline bool is_valid() const { return !origin.empty(); };
    const std::string &get_origin() const { return origin; };
    inline bool operator<(const ip4_addr_t &oth) const { return internal < oth.internal; };
    uint8_t find(const std::string &like) const;
};

using ip4_list_t = std::list<ip4_addr_t>;
using ip4_list_ptr = std::shared_ptr<ip4_list_t>;

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

  public:
    ip_filter_t();
    ~ip_filter_t();
    ip_filter_t(const ip_filter_t &oth) : ip_list_size(oth.ip_list_size), ip_list(oth.ip_list){};
    const ip_filter_t &operator=(const ip_filter_t &oth);
    inline uint32_t count() const { return ip_list_size; };
    bool insert(const std::string &ip_string);
    std::tuple<uint32_t /*inserted*/, uint32_t /*not_inserted*/> list_insert(const std::list<std::string> &ip_string_list);
    std::shared_ptr<ip_filter_t> select(const std::string &n1, const std::string &n2, const std::string &n3, const std::string &n4);
    std::shared_ptr<ip_filter_t> select(const std::string &like);
    void sort(order_t order);
    void print();
    void print(order_t order);
};

typedef std::shared_ptr<ip_filter_t> ip_filter_ptr;
} // namespace ip_tools
