#ifndef CPP_EXTERN_C_SAMPLE_SIMPLE_CLASS
#define CPP_EXTERN_C_SAMPLE_SIMPLE_CLASS

namespace cpp_extern_c_sample
{

class SimpleClass
{
public:
  /**
   * @brief Constructor
   *
   * @param value
   */
  SimpleClass(int value);

  /**
   * @brief Destructor
   */
  ~SimpleClass();

  /**
   * @brief Get a value in this class
   *
   * @return value
   */
  int GetValue() const;

private:
  /**
   * @brief A simple member variable
   */
  int value_;
};

}  // namespace cpp_extern_c_sample

#endif // CPP_EXTERN_C_SAMPLE_SIMPLE_CLASS

