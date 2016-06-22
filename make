#!/bin/bash
echo "--- start make libzz."
cd libzz
make --silent
if [ $? -eq 0 ]; then
  make --silent
  if [ $? -eq 0 ]; then
    echo "--- its ok."
    echo "--- start make zzgame."
    cd ../zzgame
    make --silent
    if [ $? -eq 0 ]; then
      echo "--- its ok. maybe."
    else
      echo "--- ERROR!!! in make libzz."
    fi
  else
    echo "--- ERROR!!! in make libzz 2."
  fi
else
  echo "--- ERROR!!! in make libzz 1."
fi
