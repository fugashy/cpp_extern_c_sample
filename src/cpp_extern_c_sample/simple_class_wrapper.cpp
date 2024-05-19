#include "cpp_extern_c_sample/simple_class.hpp"
#include "cpp_extern_c_sample/simple_class_wrapper.h"


using cpp_extern_c_sample::SimpleClass;


SimpleClassHandler SimpleClass_create(int value)
{
  return new SimpleClass(value);
}

void SimpleClass_destroy(SimpleClassHandler handler)
{
  delete static_cast<SimpleClass*>(handler);
}

int SimpleClass_get_value(SimpleClassHandler handler)
{
  return static_cast<SimpleClass*>(handler)->GetValue();
}
