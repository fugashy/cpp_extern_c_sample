#include "cpp_extern_c_sample/simple_class.hpp"

#include <iostream>

namespace cpp_extern_c_sample
{

SimpleClass::SimpleClass(int value)
  : value_(value)
{
  std::cout << "SimpleClass: Constructor" << std::endl;
}

SimpleClass::~SimpleClass()
{
  std::cout << "SimpleClass: Destructor" << std::endl;
}

int SimpleClass::GetValue() const
{
  std::cout << "SimpleClass: GetValue" << std::endl;
  return value_;
}


}  // namespace cpp_extern_c_sample
