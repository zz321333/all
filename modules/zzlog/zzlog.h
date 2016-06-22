#ifndef ZZLOG_H
#define ZZLOG_H

#include "zzdefines.h"

namespace zz {
namespace zzlog {
  enum eErrorLevel {elFatal = 0, elError, elWarn, elInfo, elEnd};
  void print(eErrorLevel, const char *, const char *, ...);
  void print(const char *, ...);
  bool check(bool, eErrorLevel, const char *, const char *, ...);
  bool check(bool, const char *, ...);
}
}

#endif
