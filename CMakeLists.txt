cmake_minimum_required(VERSION 3.10)

project(cpp_extern_c_sample LANGUAGES CXX)


include_directories(
  include
)

add_library(${PROJECT_NAME} SHARED
  src/${PROJECT_NAME}/simple_class.cpp
)
add_library(${PROJECT_NAME}_wrapper SHARED
  src/${PROJECT_NAME}/simple_class_wrapper.cpp
)
target_link_libraries(${PROJECT_NAME}_wrapper
  ${PROJECT_NAME}
)
install(
  TARGETS
    ${PROJECT_NAME}
    ${PROJECT_NAME}_wrapper
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

add_executable(${PROJECT_NAME}_use_simple_class
  src/${PROJECT_NAME}/use_simple_class.cpp
)
target_link_libraries(${PROJECT_NAME}_use_simple_class
  ${CMAKE_DL_LIBS}
)
install(
  TARGETS
    ${PROJECT_NAME}_use_simple_class
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
set_target_properties(${PROJECT_NAME}_use_simple_class
  PROPERTIES INSTALL_RPATH "@executable_path/../lib")

install(
  DIRECTORY include/
  DESTINATION include)
