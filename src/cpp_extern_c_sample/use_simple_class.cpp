#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define DLL_PATH "/usr/local/lib/libcpp_extern_c_sample_wrapper.dylib"

typedef void* SimpleClassHandle;

typedef SimpleClassHandle (*SimpleClass_create_t)(int value);
typedef void (*SimpleClass_destroy_t)(SimpleClassHandle handle);
typedef int (*SimpleClass_getValue_t)(SimpleClassHandle handle);

int main() {
  void* dl_handler = dlopen(DLL_PATH, RTLD_LAZY);
  if (!dl_handler) {
    fprintf(stderr, "Failed to load library: %s\n", dlerror());
    return EXIT_FAILURE;
  }

  SimpleClass_create_t SimpleClass_create = (SimpleClass_create_t)dlsym(
      dl_handler, "SimpleClass_create");
  SimpleClass_destroy_t SimpleClass_destroy = (SimpleClass_destroy_t)dlsym(
      dl_handler, "SimpleClass_destroy");
  SimpleClass_getValue_t SimpleClass_getValue = (SimpleClass_getValue_t)dlsym(
      dl_handler, "SimpleClass_get_value");

  if (!SimpleClass_create || !SimpleClass_destroy || !SimpleClass_getValue) {
      fprintf(stderr, "Failed to load symbols: %s\n", dlerror());
      dlclose(dl_handler);
      return EXIT_FAILURE;
  }

  SimpleClassHandle simple_class_handler = SimpleClass_create(42);
  int value = SimpleClass_getValue(simple_class_handler);
  printf("Value: %d\n", value);
  SimpleClass_destroy(simple_class_handler);

  dlclose(dl_handler);
  return EXIT_SUCCESS;
}
