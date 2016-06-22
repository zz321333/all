#include "zzlog.h"
#include <assert.h>
#include <stdarg.h>

#ifdef OS_ANDROID
#include <android/log.h>
#elif OS_IOS
#else
#include <stdio.h>
#endif

void zz::zzlog::print(eErrorLevel level, const char * tag, const char * format, ...)
{
#ifdef OS_ANDROID
  va_list args;
  va_start(args, format);
  __android_log_vprint(ANDROID_LOG_INFO, tag, format, args);
  va_end(args);
#elif OS_IOS
#else
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
#endif
  if(level == elFatal || level == elError)
    assert(false);
}

void zz::zzlog::print(const char * format, ...)
{
#ifdef OS_ANDROID
  va_list args;
  va_start(args, format);
  __android_log_vprint(ANDROID_LOG_INFO, "EMPTY TAG TODO", format, args);
  va_end(args);
#elif OS_IOS
#else
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
#endif
}

bool zz::zzlog::check(bool assertion, eErrorLevel level, const char * tag, const char * format, ...)
{
  if(!assertion)
  {
#ifdef OS_ANDROID
    va_list args;
    va_start(args, format);
    __android_log_vprint(ANDROID_LOG_INFO, tag, format, args);
    va_end(args);
#elif OS_IOS
#else
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
#endif
    if(level == elFatal || level == elError)
      assert(false);
  }
  return assertion;
}

bool zz::zzlog::check(bool assertion, const char * format, ...)
{
  if(!assertion)
  {
#ifdef OS_ANDROID
    va_list args;
    va_start(args, format);
    __android_log_vprint(ANDROID_LOG_INFO, "EMPTY TAG TODO", format, args);
    va_end(args);
#elif OS_IOS
#else
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
#endif
  }
  return assertion;
}
