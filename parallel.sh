#!/bin/bash
echo exec_parallel.sh
./caplow ~/hello_kmod/hello1 100 &
./caplow ~/hello_kmod/hello2 100 &
./caplow ~/hello_kmod/hello3 100 &
./caplow ~/hello_kmod/hello4 100 &
./caplow ~/hello_kmod/hello5 100 &
./caplow ~/hello_kmod/hello6 100 &
./caplow ~/hello_kmod/hello7 100 &
./caplow ~/hello_kmod/hello8 100;
echo finished!!
