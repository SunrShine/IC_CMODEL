#define BOOST_TEST_MODULE Test_DRAMBuffer
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>

// entry point:
int main(int argc, char *argv[], char *envp[]) {
  return boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}
