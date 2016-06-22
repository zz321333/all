#ifndef ZZDEFINES_H
#define ZZDEFINES_H

#define PURE_PRIVATE(classname) classname();\
  classname(const classname &);\
  const classname & operator=(const classname &);
#define PURE_PRIVATE_2(classname) classname(const classname &);\
  const classname & operator=(const classname &);
#define S_SIZE_NAME 128

typedef unsigned int uint;
typedef unsigned char uchar;


#endif
