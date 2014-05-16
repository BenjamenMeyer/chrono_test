#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE ChronoTest
#include <boost/test/unit_test.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/chrono.hpp>

BOOST_AUTO_TEST_SUITE( ChronoTest );

BOOST_AUTO_TEST_CASE( chrono_test )
{

  boost::posix_time::time_duration posix_duration = boost::posix_time::milliseconds(1000);
  
  boost::chrono::duration<uint64_t, boost::milli> chrono_duration = boost::chrono::duration<uint64_t, boost::milli>(posix_duration.total_milliseconds());

  boost::posix_time::time_duration chrono_to_posix = boost::posix_time::milliseconds(chrono_duration.count());


  BOOST_MESSAGE("Chrono Count: " << chrono_duration.count());
  BOOST_CHECK( posix_duration == chrono_to_posix );
  BOOST_CHECK_MESSAGE( posix_duration == chrono_to_posix, "Failed : Count " << chrono_to_posix.total_milliseconds() <<  " != " << posix_duration.total_milliseconds() );
}

BOOST_AUTO_TEST_SUITE_END();
