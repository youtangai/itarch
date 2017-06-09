#!/bin/bash
echo exec_handred.sh
./caplow ~/hello_kmod/hoge 0 100 &
./caplow ~/hello_kmod/hoge 1 100 &
./caplow ~/hello_kmod/hoge 2 100 &
./caplow ~/hello_kmod/hoge 3 100 &
./caplow ~/hello_kmod/hoge 4 100 & 
./caplow ~/hello_kmod/hoge 5 100 &
./caplow ~/hello_kmod/hoge 6 100 &
./caplow ~/hello_kmod/hoge 7 100;
./caplow ~/hello_kmod/hoge 0 0;
echo finished!!
