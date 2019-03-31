#include <stdint.h>
#include <string>
namespace ip_tools
{
class ip_filter
{
private:
    /* data */
public:
    ip_filter(/* args */);
    ~ip_filter();
    uint32_t insert(const std::string &ip_string);
};
}
