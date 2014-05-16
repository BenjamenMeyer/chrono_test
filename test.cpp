
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/chrono.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
  boost::posix_time::time_duration posix_duration = boost::posix_time::milliseconds(1000);
  
  boost::chrono::duration<uint64_t, boost::milli> chrono_duration = boost::chrono::duration<uint64_t, boost::milli>(posix_duration.total_milliseconds());

  std::cout<<"Chrono Count: "<<chrono_duration.count()<<std::endl;

  boost::posix_time::time_duration chrono_to_posix = boost::posix_time::milliseconds(chrono_duration.count());

  if (posix_duration == chrono_to_posix)
  {
    std::cout<<"Conversion matches"<<std::endl;
  }
  else
  {
    std::cout<<"Conversion does not match"<<std::endl
             <<"\tOriginal: "<<posix_duration.total_milliseconds()<<std::endl
             <<"\t     New: "<<chrono_to_posix.total_milliseconds()<<std::endl;
  }

  return 0;
}

