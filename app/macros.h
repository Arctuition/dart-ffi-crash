#ifndef _MACROS_H_
#define _MACROS_H_

#ifdef __cplusplus

  #ifdef WIN32
    #define EXPORT __declspec(dllexport)
  #else
    #define EXPORT __attribute__((visibility("default"))) __attribute__((used))
  #endif

  #define EXTERN extern "C"

#else

  #define EXTERN
  #define EXPORT

#endif

#define API EXTERN EXPORT

#endif /* _MACROS_H_ */
