PROJECT (boost_c-d_test)

CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
IF (UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -g")
ENDIF()

FIND_PACKAGE(Boost 1.49.0 COMPONENTS unit_test_framework chrono date_time system REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )
link_directories( ${Boost_LIBRARY_DIR} )

ADD_EXECUTABLE(chrono test.cpp)
TARGET_LINK_LIBRARIES(chrono ${Boost_LIBRARIES})

ADD_EXECUTABLE(chrono_test test-test.cpp)
TARGET_LINK_LIBRARIES(chrono_test ${Boost_LIBRARIES})

ENABLE_TESTING()
ADD_TEST(chrono_test chrono_test) 
