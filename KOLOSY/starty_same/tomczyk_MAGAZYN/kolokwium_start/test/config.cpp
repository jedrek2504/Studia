#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

struct Config {
    Config() {
    	unit_test_log.set_threshold_level(log_all_errors);
        tolerance(0.0001);
    }

    ~Config() {
    }
};

BOOST_GLOBAL_FIXTURE(Config);
