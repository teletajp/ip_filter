#include <gtest/gtest.h>
#include <tuple>
#include "ip_filter.h"

TEST(ip_filter_test, ip4_addr_test)
{
    ip_tools::ip4_addr_t ip("127.0.0.1");
	ASSERT_TRUE(ip.is_valid());

	ip_tools::ip4_addr_t ip1("");
	ASSERT_FALSE(ip1.is_valid());

	ip_tools::ip4_addr_t ip2(".");
	ASSERT_FALSE(ip2.is_valid());

	ip_tools::ip4_addr_t ip3("...");
	ASSERT_FALSE(ip3.is_valid());

	ip_tools::ip4_addr_t ip4("1.1.1.");
	ASSERT_FALSE(ip4.is_valid());

	ip_tools::ip4_addr_t ip5("1.1.1.0000");
	ASSERT_FALSE(ip5.is_valid());

	ip_tools::ip4_addr_t ip6("1.1.1.256");
	ASSERT_FALSE(ip6.is_valid());

	ip_tools::ip4_addr_t ip7("1.1.1.265");
	ASSERT_FALSE(ip7.is_valid());

	ip_tools::ip4_addr_t ip8("1.1.1.265");
	ASSERT_FALSE(ip8.is_valid());

	ip_tools::ip4_addr_t ip9("1.1.1.355");
	ASSERT_FALSE(ip9.is_valid());

	ip_tools::ip4_addr_t ip10(".1.1.255");
	ASSERT_FALSE(ip10.is_valid());

	ip_tools::ip4_addr_t ip11("0..001.255");
	ASSERT_FALSE(ip11.is_valid());

	ip_tools::ip4_addr_t ip12("256.1.1.255");
	ASSERT_FALSE(ip12.is_valid());

	ip_tools::ip4_addr_t ip13("255.255.255.255");
	ASSERT_TRUE(ip13.is_valid());

	ip_tools::ip4_addr_t ip14("01.000.01.255");
	ASSERT_TRUE(ip14.is_valid());

	ip_tools::ip4_addr_t ip15("0.0.0.0");
	ASSERT_TRUE(ip15.is_valid());

	ip_tools::ip4_addr_t ip16("a.255.255.255");
	ASSERT_FALSE(ip16.is_valid());
}

TEST(ip_filter_test, insert)
{
    ip_tools::ip_filter_t ipf;
	ASSERT_EQ(1, ipf.insert("127.0.0.1"));
	ASSERT_EQ(1, ipf.count());
}

TEST(ip_filter_test, list_insert)
{
    ip_tools::ip_filter_t ipf;
	std::list<std::string> ip_list = {std::string("113.162.145.156"),
std::string("157.39.22.224"),
std::string("79.180.73.190"),
std::string("179.210.145.4"),
std::string("219.102.120.135"),
std::string("67.232.81.208"),
std::string("85.254.10.197"),
std::string("23.240.215.189"),
std::string("1.29.168.152"),
std::string("185.69.186.168"),
std::string("110.152.103.161"),
std::string("185.182.81.131"),
std::string("68.45.152.8"),
std::string("114.221.179.117"),
std::string("185.89.100.249"),
std::string("46.70.113.73"),
std::string("188.68.0.38"),
std::string("119.42.115.97"),
std::string("194.106.108.214"),
std::string("24.210.239.177"),
std::string("166.88.193.116"),
std::string("62.205.202.214"),
std::string("188.166.87.191"),
std::string("103.62.147.2"),
std::string("95.181.177.197"),
std::string("95.181.177.197"),
std::string("149.107.0.27"),
std::string("182.186.69.18"),
std::string("73.21.168.251"),
std::string("113.190.198.73"),
std::string("91.15.15.33"),
std::string("188.72.96.184"),
std::string("50.254.198.161"),
std::string("98.219.109.151"),
std::string("123.133.114.213"),
std::string("89.177.68.136"),
std::string("89.177.68.136"),
std::string("65.208.151.112"),
std::string("183.198.27.25"),
std::string("187.189.75.118"),
std::string("188.212.33.157"),
std::string("94.240.192.2"),
std::string("69.160.110.157"),
std::string("81.198.169.232"),
std::string("185.89.100.47"),
std::string("46.182.19.219"),
std::string("183.88.197.193"),
std::string("49.74.228.23"),
std::string("124.224.214.76"),
std::string("107.185.11.105"),
std::string("41.235.16.95"),
std::string("68.37.186.197"),
std::string("188.72.127.199"),
std::string("173.171.247.113"),
std::string("173.171.247.113"),
std::string("49.35.12.51"),
std::string("67.167.96.234"),
std::string("204.11.243.70"),
std::string("182.58.201.28"),
std::string("168.167.95.164"),
std::string("153.151.156.27"),
std::string("79.110.28.59"),
std::string("37.188.189.227"),
std::string("188.69.198.152"),
std::string("98.196.145.69"),
std::string("68.202.216.62"),
std::string("68.202.216.62"),
std::string("68.202.216.62"),
std::string("5.189.203.79"),
std::string("197.42.2.124"),
std::string("95.10.3.43"),
std::string("180.251.148.71"),
std::string("113.144.6.220"),
std::string("89.236.227.204"),
std::string("67.250.31.212"),
std::string("67.250.31.212"),
std::string("177.66.186.82"),
std::string("107.209.121.224"),
std::string("213.103.211.108"),
std::string("27.49.172.153"),
std::string("78.158.5.183"),
std::string("78.158.5.183"),
std::string("27.109.142.224"),
std::string("103.101.109.70"),
std::string("117.241.3.153"),
std::string("86.146.190.166"),
std::string("68.60.148.11"),
std::string("89.146.70.220"),
std::string("171.5.117.72"),
std::string("66.169.196.128"),
std::string("5.8.47.226"),
std::string("165.255.112.201"),
std::string("207.191.252.36"),
std::string("123.231.108.232"),
std::string("185.146.112.69"),
std::string("187.190.255.160"),
std::string("187.190.255.160"),
std::string("191.209.77.60"),
std::string("58.126.159.88"),
std::string("222.42.146.225"),
std::string("193.78.85.148"),
std::string("66.102.6.107"),
std::string("5.189.202.254"),
std::string("188.72.126.149"),
std::string("185.217.68.210"),
std::string("190.62.36.205"),
std::string("190.62.36.205"),
std::string("114.243.13.43"),
std::string("128.199.42.73"),
std::string("5.188.216.44"),
std::string("74.124.159.77"),
std::string("103.74.19.104"),
std::string("183.182.99.139"),
std::string("188.72.126.153"),
std::string("173.211.75.241"),
std::string("163.172.151.47"),
std::string("180.183.42.174"),
std::string("93.237.52.162"),
std::string("60.127.180.251"),
std::string("84.132.45.217"),
std::string("37.9.45.225"),
std::string("82.67.92.27"),
std::string("123.191.149.173"),
std::string("73.90.162.151"),
std::string("178.200.214.178"),
std::string("70.123.153.26"),
std::string("177.81.192.15"),
std::string("47.29.8.38"),
std::string("123.21.121.123"),
std::string("73.11.30.103"),
std::string("73.11.30.103"),
std::string("112.79.133.183"),
std::string("151.251.24.30"),
std::string("47.217.153.6"),
std::string("47.208.114.106"),
std::string("93.179.90.113"),
std::string("149.107.0.31"),
std::string("188.166.66.232"),
std::string("64.89.99.122"),
std::string("116.18.33.248"),
std::string("211.226.114.169"),
std::string("69.76.232.100"),
std::string("69.76.232.100"),
std::string("69.76.232.100"),
std::string("69.76.232.100"),
std::string("193.70.91.227"),
std::string("191.101.165.168"),
std::string("195.205.28.27"),
std::string("177.81.184.55"),
std::string("24.163.91.199"),
std::string("197.48.69.176"),
std::string("45.127.57.74"),
std::string("14.169.83.98"),
std::string("47.11.217.253"),
std::string("222.173.235.246"),
std::string("172.2.146.147"),
std::string("67.183.246.205"),
std::string("218.185.237.250"),
std::string("74.136.5.194"),
std::string("14.187.212.140"),
std::string("149.3.43.228"),
std::string("141.101.132.191"),
std::string("189.216.159.43"),
std::string("5.8.47.84"),
std::string("50.26.133.146"),
std::string("83.221.180.18"),
std::string("117.213.109.57"),
std::string("109.193.71.64"),
std::string("46.70.147.26"),
std::string("188.166.49.134"),
std::string("117.198.224.130"),
std::string("77.179.162.181"),
std::string("27.251.253.58"),
std::string("75.69.188.107"),
std::string("198.48.136.200"),
std::string("186.92.150.52"),
std::string("184.170.28.62"),
std::string("47.44.49.2"),
std::string("24.23.88.218"),
std::string("24.23.88.218"),
std::string("220.180.121.6"),
std::string("99.114.89.48"),
std::string("116.25.102.111"),
std::string("93.183.170.145"),
std::string("47.29.254.116"),
std::string("18.248.2.85"),
std::string("141.101.132.73"),
std::string("47.220.163.51"),
std::string("47.220.163.51"),
std::string("123.20.104.253"),
std::string("184.183.34.140"),
std::string("128.199.99.114"),
std::string("93.179.90.77"),
std::string("5.62.159.66"),
std::string("87.118.92.43"),
std::string("185.14.194.116"),
std::string("161.0.198.138"),
std::string("49.118.223.200"),
std::string("188.72.126.130"),
std::string("42.54.29.150"),
std::string("14.182.208.223"),
std::string("14.182.208.223"),
std::string("73.197.19.19"),
std::string("49.206.125.56"),
std::string("67.165.212.104"),
std::string("71.90.169.184"),
std::string("117.207.33.172"),
std::string("195.234.85.219"),
std::string("5.152.151.166"),
std::string("90.191.74.74"),
std::string("184.58.77.155"),
std::string("104.218.63.75"),
std::string("117.3.82.3"),
std::string("188.211.226.16"),
std::string("107.175.234.130"),
std::string("85.253.112.79"),
std::string("190.213.37.222"),
std::string("70.234.198.76"),
std::string("70.234.198.76"),
std::string("5.188.216.204"),
std::string("69.251.6.155"),
std::string("93.34.197.129"),
std::string("5.8.47.202"),
std::string("14.162.206.233"),
std::string("1.231.69.33"),
std::string("69.23.42.183"),
std::string("63.87.226.66"),
std::string("5.254.65.190"),
std::string("37.33.109.179"),
std::string("1.1.234.8"),
std::string("119.201.4.165"),
std::string("179.218.84.120"),
std::string("5.101.217.139"),
std::string("96.92.198.213"),
std::string("96.92.198.213"),
std::string("117.248.24.152"),
std::string("85.253.148.39"),
std::string("27.70.17.38"),
std::string("211.225.89.44"),
std::string("184.91.78.121"),
std::string("95.181.176.189"),
std::string("178.6.12.226"),
std::string("131.221.56.20"),
std::string("84.108.11.149"),
std::string("164.126.188.157"),
std::string("107.223.148.60"),
std::string("218.7.166.58"),
std::string("177.42.212.125"),
std::string("191.101.54.77"),
std::string("191.101.54.77"),
std::string("94.30.173.135"),
std::string("92.105.136.141"),
std::string("41.159.26.123"),
std::string("24.191.211.63"),
std::string("202.74.243.112"),
std::string("108.73.108.163"),
std::string("67.188.13.100"),
std::string("123.20.181.120"),
std::string("179.211.81.134"),
std::string("64.40.152.168"),
std::string("68.43.142.235"),
std::string("173.211.75.62"),
std::string("50.81.221.73"),
std::string("103.203.133.202"),
std::string("47.74.157.18"),
std::string("84.252.26.213"),
std::string("84.252.26.213"),
std::string("71.234.84.132"),
std::string("186.125.174.10"),
std::string("113.182.239.185"),
std::string("106.67.36.120"),
std::string("189.100.88.211"),
std::string("184.170.35.121"),
std::string("181.215.20.38"),
std::string("185.3.147.64"),
std::string("187.64.27.167"),
std::string("73.55.95.93"),
std::string("45.32.140.209"),
std::string("37.110.213.11"),
std::string("177.32.68.231"),
std::string("203.192.225.115"),
std::string("189.181.251.184"),
std::string("82.199.206.151"),
std::string("73.224.202.251"),
std::string("75.90.211.217"),
std::string("173.211.75.55"),
std::string("115.221.10.154"),
std::string("190.39.83.68"),
std::string("112.124.39.77"),
std::string("5.189.200.175"),
std::string("181.169.25.33"),
std::string("202.166.194.217"),
std::string("108.18.251.109"),
std::string("188.72.127.216"),
std::string("76.94.181.14"),
std::string("141.196.77.153"),
std::string("69.227.160.129"),
std::string("5.101.221.37"),
std::string("59.42.27.180"),
std::string("188.68.0.207"),
std::string("173.24.113.249"),
std::string("173.24.113.249"),
std::string("14.231.56.112"),
std::string("5.62.159.140"),
std::string("141.101.132.179"),
std::string("95.90.191.205"),
std::string("193.93.192.122"),
std::string("75.65.190.40"),
std::string("91.204.190.7"),
std::string("131.129.231.39"),
std::string("186.86.29.56"),
std::string("91.135.176.211"),
std::string("154.160.1.180"),
std::string("83.143.86.155"),
std::string("60.7.107.169"),
std::string("89.249.207.229"),
std::string("95.181.176.155"),
std::string("95.181.176.155"),
std::string("41.199.158.154"),
std::string("36.5.146.30"),
std::string("217.72.94.100"),
std::string("217.72.94.100"),
std::string("217.72.94.100"),
std::string("217.72.94.100"),
std::string("217.72.94.100"),
std::string("14.231.214.53"),
std::string("89.163.155.202"),
std::string("85.187.105.45"),
std::string("77.13.117.195"),
std::string("70.91.13.106"),
std::string("126.241.3.145"),
std::string("114.249.117.72"),
std::string("113.173.67.60"),
std::string("183.87.196.93"),
std::string("49.203.248.26"),
std::string("49.203.248.26"),
std::string("185.89.100.59"),
std::string("95.181.177.241"),
std::string("125.43.69.142"),
std::string("37.186.67.25"),
std::string("185.46.85.204"),
std::string("73.91.213.154"),
std::string("111.61.78.76"),
std::string("75.114.69.42"),
std::string("95.181.177.50"),
std::string("95.90.254.195"),
std::string("109.192.168.38"),
std::string("5.101.217.48"),
std::string("86.34.133.118"),
std::string("46.101.163.119"),
std::string("189.6.128.228"),
std::string("202.9.43.222"),
std::string("202.142.76.12"),
std::string("105.73.25.26"),
std::string("119.184.218.145"),
std::string("179.219.241.71"),
std::string("156.212.169.72"),
std::string("103.66.196.13"),
std::string("68.41.149.247"),
std::string("117.102.78.2"),
std::string("14.186.245.237"),
std::string("93.179.90.24"),
std::string("39.88.253.245"),
std::string("187.3.66.189"),
std::string("24.17.1.75"),
std::string("24.17.1.75"),
std::string("188.72.127.249"),
std::string("46.161.60.92"),
std::string("72.77.71.111"),
std::string("114.47.230.91"),
std::string("177.87.9.192"),
std::string("49.156.211.218"),
std::string("187.65.248.41"),
std::string("73.244.53.54"),
std::string("117.213.254.4"),
std::string("187.39.197.81"),
std::string("78.84.243.190"),
std::string("188.72.126.152"),
std::string("141.101.132.158"),
std::string("178.253.240.126"),
std::string("46.101.127.145"),
std::string("154.16.89.9"),
std::string("139.167.0.12"),
std::string("168.196.9.47"),
std::string("107.77.72.118"),
std::string("72.181.175.235"),
std::string("72.181.175.235"),
std::string("104.222.165.144"),
std::string("98.214.16.13"),
std::string("171.221.113.228"),
std::string("46.55.46.98"),
std::string("47.39.211.31"),
std::string("45.248.186.76"),
std::string("77.234.45.173"),
std::string("185.163.24.76"),
std::string("113.89.239.241"),
std::string("113.206.92.243"),
std::string("107.167.109.164"),
std::string("185.46.86.131"),
std::string("185.46.86.131"),
std::string("75.171.214.8"),
std::string("95.181.176.240"),
std::string("95.181.176.240"),
std::string("217.159.171.6"),
std::string("195.250.178.88"),
std::string("89.236.251.247"),
std::string("68.46.218.208"),
std::string("71.88.10.118"),
std::string("176.90.14.232"),
std::string("99.251.8.64"),
std::string("101.98.164.130"),
std::string("71.52.72.142"),
std::string("84.15.185.66"),
std::string("45.124.191.237"),
std::string("168.195.231.1"),
std::string("73.141.213.207"),
std::string("78.171.131.126"),
std::string("73.166.52.138"),
std::string("73.166.52.138"),
std::string("103.203.241.89"),
std::string("188.68.0.102"),
std::string("108.30.39.3"),
std::string("108.30.39.3"),
std::string("191.207.27.171"),
std::string("123.116.254.111"),
std::string("113.77.173.249"),
std::string("81.151.71.218"),
std::string("191.191.197.98"),
std::string("188.166.49.134"),
std::string("108.180.26.133"),
std::string("108.180.26.133"),
std::string("45.62.234.109"),
std::string("177.43.57.48"),
std::string("95.181.176.136"),
std::string("117.196.197.139"),
std::string("23.240.217.243"),
std::string("70.180.91.246"),
std::string("159.203.13.174"),
std::string("186.46.222.194"),
std::string("141.101.132.93"),
std::string("186.179.100.193"),
std::string("181.215.16.39"),
std::string("114.95.157.203"),
std::string("189.7.220.132"),
std::string("189.251.241.73"),
std::string("172.97.129.82"),
std::string("64.237.226.172"),
std::string("50.32.39.122"),
std::string("37.201.203.88"),
std::string("170.80.252.30"),
std::string("89.170.3.145"),
std::string("156.204.84.209"),
std::string("78.84.60.71"),
std::string("78.84.60.71"),
std::string("78.84.60.71"),
std::string("78.10.207.6"),
std::string("99.169.226.169"),
std::string("99.169.226.169"),
std::string("99.169.226.169"),
std::string("99.169.226.169"),
std::string("73.104.80.103"),
std::string("73.104.80.103"),
std::string("79.206.209.45"),
std::string("103.220.209.173"),
std::string("66.249.92.198"),
std::string("47.16.77.236"),
std::string("89.38.96.66"),
std::string("75.206.129.73"),
std::string("129.56.12.56"),
std::string("5.8.47.44"),
std::string("193.24.92.54"),
std::string("156.222.243.190"),
std::string("176.228.138.151"),
std::string("176.228.138.151"),
std::string("176.228.138.151"),
std::string("181.122.209.200"),
std::string("35.193.144.59"),
std::string("101.24.171.210"),
std::string("188.68.0.185"),
std::string("113.195.165.235"),
std::string("41.242.141.134"),
std::string("146.185.206.53"),
std::string("95.181.177.111"),
std::string("67.174.152.35"),
std::string("78.100.196.199"),
std::string("220.132.196.75"),
std::string("14.167.215.198"),
std::string("66.183.9.162"),
std::string("189.62.20.66"),
std::string("68.172.234.141"),
std::string("1.87.203.225"),
std::string("32.215.162.52"),
std::string("32.215.162.52"),
std::string("32.215.162.52"),
std::string("5.62.159.232"),
std::string("81.213.167.197"),
std::string("180.246.83.253"),
std::string("91.204.14.185"),
std::string("49.213.19.115"),
std::string("74.116.59.8"),
std::string("202.129.0.27"),
std::string("94.141.76.33"),
std::string("37.110.210.153"),
std::string("125.165.131.226"),
std::string("61.74.152.228"),
std::string("61.74.152.228"),
std::string("217.174.230.98"),
std::string("173.225.247.123"),
std::string("77.68.40.185"),
std::string("182.75.81.122"),
std::string("182.75.81.122"),
std::string("79.184.219.107"),
std::string("97.95.65.151"),
std::string("49.213.19.137"),
std::string("118.114.86.199"),
std::string("175.192.51.84"),
std::string("97.82.75.243"),
std::string("72.79.56.37"),
std::string("117.2.125.26"),
std::string("193.194.132.76"),
std::string("119.15.93.202"),
std::string("119.15.93.202"),
std::string("119.15.93.202"),
std::string("107.174.108.194"),
std::string("103.207.242.56"),
std::string("78.109.65.21"),
std::string("171.77.145.44"),
std::string("45.123.220.122"),
std::string("5.189.202.198"),
std::string("88.91.160.177"),
std::string("149.154.167.161"),
std::string("109.75.90.41"),
std::string("188.97.225.180"),
std::string("76.112.220.160"),
std::string("5.101.221.76"),
std::string("114.125.118.9"),
std::string("188.237.136.152"),
std::string("213.225.6.88"),
std::string("14.187.178.209"),
std::string("46.251.197.23"),
std::string("189.121.253.246"),
std::string("109.127.20.122"),
std::string("118.96.117.80"),
std::string("27.97.226.94"),
std::string("96.94.121.25"),
std::string("5.8.47.202"),
std::string("46.161.56.203"),
std::string("193.136.199.50"),
std::string("121.27.48.172"),
std::string("36.67.5.186"),
std::string("89.28.76.171"),
std::string("46.161.56.174"),
std::string("188.2.221.111"),
std::string("85.253.176.102"),
std::string("79.15.208.108"),
std::string("5.62.154.58"),
std::string("85.114.239.251"),
std::string("46.161.56.106"),
std::string("46.161.56.106"),
std::string("67.5.105.174"),
std::string("181.215.0.59"),
std::string("95.181.176.58"),
std::string("72.193.106.165"),
std::string("217.61.224.38"),
std::string("185.89.100.44"),
std::string("188.72.126.41"),
std::string("46.70.225.39"),
std::string("80.133.65.104"),
std::string("82.196.6.103"),
std::string("185.158.116.188"),
std::string("94.30.155.174"),
std::string("5.101.219.107"),
std::string("197.48.89.171"),
std::string("164.132.3.102"),
std::string("79.100.201.157"),
std::string("47.11.7.112"),
std::string("82.32.174.146"),
std::string("189.217.133.144"),
std::string("146.185.177.103"),
std::string("217.25.18.126"),
std::string("5.62.154.52"),
std::string("187.188.129.136"),
std::string("217.82.152.217"),
std::string("106.51.30.215"),
std::string("68.106.156.3"),
std::string("109.185.152.20"),
std::string("45.247.3.119"),
std::string("108.171.129.171"),
std::string("189.102.186.9"),
std::string("189.175.155.108"),
std::string("103.28.36.56"),
std::string("212.56.210.90"),
std::string("204.232.108.181"),
std::string("85.180.234.65"),
std::string("188.166.49.33"),
std::string("188.166.72.33"),
std::string("156.220.35.15"),
std::string("41.227.84.129"),
std::string("188.68.0.30"),
std::string("176.12.58.180"),
std::string("85.118.110.10"),
std::string("162.247.72.217"),
std::string("67.205.174.171"),
std::string("185.89.217.170"),
std::string("176.241.89.82"),
std::string("123.23.148.249"),
std::string("123.23.148.249"),
std::string("183.147.179.187"),
std::string("111.222.25.83"),
std::string("91.204.14.239"),
std::string("60.174.233.154"),
std::string("157.37.38.188"),
std::string("50.80.193.175"),
std::string("37.221.176.236"),
std::string("118.69.205.201"),
std::string("113.173.98.95"),
std::string("5.146.199.53"),
std::string("213.213.103.190"),
std::string("141.101.132.120"),
std::string("171.221.26.73"),
std::string("188.68.0.171"),
std::string("151.53.178.221"),
std::string("146.185.204.136"),
std::string("117.209.246.210"),
std::string("193.40.12.10"),
std::string("77.215.105.50"),
std::string("122.40.163.51"),
std::string("182.69.22.32"),
std::string("95.181.176.30"),
std::string("188.72.96.177"),
std::string("108.49.29.94"),
std::string("108.49.29.94"),
std::string("23.254.17.73"),
std::string("46.161.61.51"),
std::string("73.175.73.131"),
std::string("79.208.172.72"),
std::string("36.102.236.203"),
std::string("95.90.254.195"),
std::string("138.122.123.42"),
std::string("126.218.40.164"),
std::string("5.62.153.169"),
std::string("83.128.50.47"),
std::string("83.128.50.47"),
std::string("78.129.149.3"),
std::string("78.129.149.3"),
std::string("146.255.242.234"),
std::string("14.177.248.167"),
std::string("213.219.115.76"),
std::string("185.46.87.231"),
std::string("188.72.96.77"),
std::string("109.91.38.1"),
std::string("201.219.180.58"),
std::string("85.65.43.232"),
std::string("73.87.94.81"),
std::string("73.87.94.81"),
std::string("5.62.154.49"),
std::string("162.236.216.26"),
std::string("190.198.255.34"),
std::string("183.88.77.2"),
std::string("95.181.177.213"),
std::string("73.76.58.22"),
std::string("47.149.142.171"),
std::string("47.149.142.171"),
std::string("119.55.121.74"),
std::string("188.209.233.110"),
std::string("188.209.233.110"),
std::string("181.215.6.120"),
std::string("181.215.6.120"),
std::string("61.98.171.199"),
std::string("187.187.193.21"),
std::string("165.225.81.66"),
std::string("98.64.84.57"),
std::string("46.161.63.66"),
std::string("67.215.250.146"),
std::string("103.251.226.120"),
std::string("199.249.223.75"),
std::string("47.11.7.240"),
std::string("117.200.96.91"),
std::string("191.101.54.244"),
std::string("95.89.126.115"),
std::string("203.249.55.94"),
std::string("49.34.5.58"),
std::string("14.97.7.246"),
std::string("2.29.170.242"),
std::string("14.17.122.207"),
std::string("185.213.20.252"),
std::string("73.185.49.225"),
std::string("47.11.210.118"),
std::string("14.232.172.139"),
std::string("5.101.222.205"),
std::string("134.48.22.110"),
std::string("93.179.90.237"),
std::string("171.6.156.117"),
std::string("171.6.156.117"),
std::string("185.117.149.113"),
std::string("46.161.58.202"),
std::string("191.101.145.250"),
std::string("191.101.145.250"),
std::string("116.68.105.105"),
std::string("125.163.151.121"),
std::string("81.198.25.242"),
std::string("92.161.182.241"),
std::string("194.208.63.191"),
std::string("90.114.80.144"),
std::string("5.189.200.116"),
std::string("186.182.82.240"),
std::string("122.15.212.146"),
std::string("122.15.212.146"),
std::string("122.15.212.146"),
std::string("137.97.9.40"),
std::string("189.122.18.125"),
std::string("187.188.28.45"),
std::string("190.9.214.105"),
std::string("222.130.177.64"),
std::string("123.136.249.120"),
std::string("178.220.115.243"),
std::string("14.102.246.210"),
std::string("178.119.240.143"),
std::string("98.89.83.30"),
std::string("50.106.25.168"),
std::string("185.89.217.189"),
std::string("5.62.159.38"),
std::string("186.95.24.238"),
std::string("5.189.202.171"),
std::string("71.223.161.63"),
std::string("14.207.158.135"),
std::string("216.239.90.19"),
std::string("176.153.26.5"),
std::string("99.61.192.35"),
std::string("73.48.161.172"),
std::string("73.48.161.172"),
std::string("73.48.161.172"),
std::string("188.166.82.41"),
std::string("117.5.75.127"),
std::string("183.83.78.172"),
std::string("172.243.2.129"),
std::string("84.146.103.72"),
std::string("5.101.217.177"),
std::string("110.167.197.122"),
std::string("5.189.203.43"),
std::string("95.213.218.108"),
std::string("185.46.86.22"),
std::string("191.101.54.127"),
std::string("194.135.166.12"),
std::string("79.237.168.168"),
std::string("45.32.108.44"),
std::string("186.204.34.46"),
std::string("117.5.211.1"),
std::string("69.57.247.218"),
std::string("70.121.9.224"),
std::string("209.107.214.71"),
std::string("189.34.176.93"),
std::string("80.78.237.5"),
std::string("14.186.176.190"),
std::string("84.108.20.44"),
std::string("176.126.83.77"),
std::string("104.174.173.170"),
std::string("219.92.33.137"),
std::string("78.48.70.89"),
std::string("186.37.202.178"),
std::string("71.223.241.223"),
std::string("71.223.241.223"),
std::string("73.140.229.40"),
std::string("188.188.19.204"),
std::string("195.154.232.98"),
std::string("112.28.106.231"),
std::string("62.219.224.250"),
std::string("93.171.216.68"),
std::string("37.26.142.184"),
std::string("87.255.69.86"),
std::string("87.255.69.86"),
std::string("157.48.15.35"),
std::string("50.3.197.73"),
std::string("23.27.228.81"),
std::string("190.56.99.94"),
std::string("76.228.35.48"),
std::string("5.8.47.100"),
std::string("110.77.199.103"),
std::string("54.205.123.87"),
std::string("183.89.22.222"),
std::string("14.139.41.109"),
std::string("186.43.29.31"),
std::string("173.31.96.193"),
std::string("173.31.96.193"),
std::string("77.79.38.5"),
std::string("95.85.80.229"),
std::string("191.101.144.238"),
std::string("50.25.139.252"),
std::string("50.25.139.252"),
std::string("177.82.171.180"),
std::string("113.87.26.63"),
std::string("77.181.225.187"),
std::string("103.89.255.122"),
std::string("107.222.35.45"),
std::string("200.125.116.65"),
std::string("202.5.196.66"),
std::string("158.181.40.154"),
std::string("86.115.0.94"),
std::string("68.108.194.244"),
std::string("68.108.194.244"),
std::string("68.108.194.244"),
std::string("110.87.118.235"),
std::string("105.158.16.153"),
std::string("188.72.96.182"),
std::string("14.187.132.10"),
std::string("85.253.45.35"),
std::string("188.166.36.54"),
std::string("111.37.37.235"),
std::string("111.37.37.235"),
std::string("79.184.223.137"),
std::string("34.214.132.226"),
std::string("74.96.79.23"),
std::string("188.166.41.162"),
std::string("117.5.169.43"),
std::string("76.221.68.186"),
std::string("185.89.100.48"),
std::string("74.132.249.206"),
std::string("91.126.205.238"),
std::string("5.62.159.143"),
std::string("188.146.232.177"),
std::string("188.68.3.92"),
std::string("200.5.83.150"),
std::string("93.179.90.116"),
std::string("94.185.80.235"),
std::string("188.104.116.79"),
std::string("177.232.136.107"),
std::string("123.16.114.132"),
std::string("178.254.168.220"),
std::string("66.249.93.2"),
std::string("96.30.65.207"),
std::string("73.84.200.187"),
std::string("70.35.215.94"),
std::string("139.0.6.42"),
std::string("185.46.86.132"),
std::string("89.177.29.121"),
std::string("118.44.17.181"),
std::string("146.185.204.191"),
std::string("146.185.204.191"),
std::string("190.111.195.137"),
std::string("146.185.206.106"),
std::string("185.2.32.173"),
std::string("96.31.53.251"),
std::string("207.41.189.106"),
std::string("36.63.28.208"),
std::string("31.170.161.42"),
std::string("209.107.196.159"),
std::string("185.46.85.78"),
std::string("183.12.241.137"),
std::string("184.167.219.223"),
std::string("177.34.62.115"),
std::string("5.189.200.201"),
std::string("47.11.5.9"),
std::string("179.218.5.141"),
std::string("5.62.159.25"),
std::string("32.209.238.246"),
std::string("32.209.238.246"),
std::string("32.209.238.246"),
std::string("32.209.238.246"),
std::string("46.70.29.76"),
std::string("104.222.164.236"),
std::string("194.152.37.147"),
std::string("177.80.227.215"),
std::string("5.101.217.197"),
std::string("47.8.5.240"),
std::string("192.40.95.34"),
std::string("103.244.252.242"),
std::string("185.89.100.129"),
std::string("178.82.94.82"),
std::string("202.100.206.36"),
std::string("45.249.48.124"),
std::string("84.42.249.4"),
std::string("62.12.93.76"),
std::string("77.93.192.43"),
std::string("141.101.132.50"),
std::string("89.201.7.164"),
std::string("5.15.220.203"),
std::string("185.69.186.227"),
std::string("24.193.178.168"),
std::string("65.26.31.140"),
std::string("83.99.166.35"),
std::string("103.254.155.74"),
std::string("49.34.2.43"),
std::string("91.142.208.226"),
std::string("193.93.192.134"),
std::string("188.68.0.249"),
std::string("79.110.28.78"),
std::string("71.211.2.230"),
std::string("188.72.127.48"),
std::string("185.217.68.209"),
std::string("99.242.220.241"),
std::string("5.62.159.148"),
std::string("1.70.44.170"),
std::string("191.23.199.126"),
std::string("98.242.127.228"),
std::string("59.99.48.248"),
std::string("67.191.200.150"),
std::string("213.6.149.66"),
std::string("77.109.86.105"),
std::string("123.30.177.138"),
std::string("185.14.194.82"),
std::string("39.46.86.85"),
std::string("220.189.194.162"),
std::string("5.189.200.97"),
std::string("24.91.41.150"),
std::string("209.197.20.206"),
std::string("12.155.92.10"),
std::string("12.155.92.10"),
std::string("205.186.180.34"),
std::string("46.161.60.35"),
std::string("73.115.6.159"),
std::string("222.82.198.61"),
std::string("213.200.15.167"),
std::string("5.101.220.79"),
std::string("98.122.86.197"),
std::string("14.231.215.204"),
std::string("76.94.77.14"),
std::string("73.58.220.10"),
std::string("73.58.220.10"),
std::string("73.58.220.10"),
std::string("193.93.192.165"),
std::string("189.122.214.227"),
std::string("191.101.54.148"),
std::string("84.109.80.89"),
std::string("84.109.80.89"),
std::string("84.109.80.89"),
std::string("70.95.65.80"),
std::string("70.95.65.80"),
std::string("70.95.65.80"),
std::string("113.182.18.30"),
std::string("113.182.18.30"),
std::string("144.217.161.119"),
std::string("46.223.254.56"),
std::string("46.223.254.56"),
std::string("71.90.148.209"),
std::string("156.220.69.153"),
std::string("158.181.19.102"),
std::string("59.84.240.60"),
std::string("95.181.176.106"),
std::string("189.120.152.120"),
std::string("153.136.8.214"),
std::string("101.21.80.126"),
std::string("198.73.50.71"),
std::string("68.227.43.14"),
std::string("172.248.74.10"),
std::string("172.248.74.10"),
std::string("46.161.56.241"),
std::string("66.249.93.49"),
std::string("59.89.245.157"),
std::string("163.172.73.168"),
std::string("5.62.154.110"),
std::string("61.148.243.183"),
std::string("81.171.81.234"),
std::string("81.171.81.234"),
std::string("5.189.203.46"),
std::string("197.48.60.53"),
std::string("46.49.43.85"),
std::string("73.115.17.146"),
std::string("193.93.192.192"),
std::string("193.93.192.192"),
std::string("146.185.206.166"),
std::string("69.245.162.12"),
std::string("69.245.162.12"),
std::string("69.245.162.12"),
std::string("69.245.162.12"),
std::string("189.33.47.50"),
std::string("95.42.141.179"),
std::string("95.42.141.179"),
std::string("180.66.236.162"),
std::string("162.13.152.211"),
std::string("99.109.226.233"),
std::string("217.78.6.205"),
std::string("79.235.120.32"),
std::string("187.37.143.79"),
std::string("158.135.163.135"),
std::string("5.101.219.197"),
std::string("158.140.180.27"),
std::string("142.118.105.137"),
std::string("72.201.118.80"),
std::string("112.215.243.201"),
std::string("187.137.61.82"),
std::string("179.218.101.97"),
std::string("181.215.39.116"),
std::string("82.45.10.45"),
std::string("205.185.209.141"),
std::string("180.241.150.70"),
std::string("5.101.221.20"),
std::string("188.68.0.19"),
std::string("47.183.128.151"),
std::string("47.183.128.151"),
std::string("103.252.169.182"),
std::string("162.237.21.238"),
std::string("103.240.127.33"),
std::string("171.4.234.224"),
std::string("76.118.206.235"),
std::string("37.142.228.191"),
std::string("67.183.105.87"),
std::string("67.183.105.87"),
std::string("67.183.105.87"),
std::string("91.64.189.196"),
std::string("93.179.90.82")};
	std::tuple<uint32_t,uint32_t> res = ipf.list_insert(ip_list);
	ASSERT_EQ(1000, std::get<0>(res));
	ASSERT_EQ(0, std::get<1>(res));
	ASSERT_EQ(1000, ipf.count());
	auto filter_1 = ipf.select("001","","","",ip_tools::order_t::dsc_order);
	filter_1->print();
	auto filter_46_70 = ipf.select("046","070","","",ip_tools::order_t::dsc_order);
	filter_46_70->print();
	auto filter_46 = ipf.select("046", ip_tools::order_t::dsc_order);
	filter_46->print();
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}