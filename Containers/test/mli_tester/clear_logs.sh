#!/usr/bin/env bash

rm -f a.out
rm -Rf *.dSYM
cd logs; rm -Rf *.log
cd ../deepthought; rm -Rf *.diff