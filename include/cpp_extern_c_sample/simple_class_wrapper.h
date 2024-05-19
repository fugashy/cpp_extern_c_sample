#ifndef CPP_EXTERN_C_SAMPLE_SIMPLE_CLASS_WRAPPER_H_
#define CPP_EXTERN_C_SAMPLE_SIMPLE_CLASS_WRAPPER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief An alias of SimpleClass pointer
 */
typedef void* SimpleClassHandler;

/**
 * @brief Instantiate SimpleClass
 *
 * @param value A value to be set to SimpleClass
 *
 * @return The handler
 */
SimpleClassHandler SimpleClass_create(int value);

/**
 * @brief Destruct SimpleClass
 *
 * @param handle The handler
 */
void SimpleClass_destroy(SimpleClassHandler handle);

/**
 * @brief 
 *
 * @param handle
 *
 * @return 
 */
int SimpleClass_get_value(SimpleClassHandler handle);

#ifdef __cplusplus
}
#endif

#endif // CPP_EXTERN_C_SAMPLE_SIMPLE_CLASS_WRAPPER_H_

