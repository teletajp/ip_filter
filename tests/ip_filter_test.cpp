#include <gtest/gtest.h>
#include "ip_filter.h"

TEST(ip_filter_test, insert)
{
    ip_tools::ip_filter ipf;
	std::string ip_string("127.0.0.1");
	ASSERT_EQ(0, ipf.insert(ip_string));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}