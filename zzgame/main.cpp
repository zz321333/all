#include "zzlog.h"
#include "zzpool.h"
#include "zzstring.h"
#include <new>

using namespace zz;
const char * tag = "zzgame";

int main()
{
  // Начало работы.
  zzlog::print(zzlog::elInfo, tag, "started.\n");

  // Создаем пулы объектов.
  const int COUNT = 35440;
  zzpool * pools256 = new zzpool(COUNT, sizeof(zzstring<256>));
  zzstring<256> * strings[COUNT];

  zzlog::print(zzlog::elInfo, tag, "%ld.\n", COUNT * sizeof(zzstring<256>));
  
  // Тестовые штуки.
  for(uint i = 0; i < COUNT; ++i)
  {
    //zzlog::print(zzlog::elInfo, tag, "%u.\n", i);
    void * p = pools256->allocate();
    if(!zzlog::check(p, zzlog::elError, tag, "p is NULL.\n"))
      break;
    strings[i] = new (p) zzstring<256>("ololo");
    (*strings[i]) = "rrr";

    //if(i > 990)
    //  pools256->free(s);
  }
  for(uint i = 0; i < COUNT; ++i)
  {
    if(i == 387 || i == 65)
      zzlog::print(zzlog::elInfo, tag, "-  %s.\n", strings[i]);
  }

  // Освобождаем пулы объектов.
  delete pools256;

  // The End.
  return 0;
}
