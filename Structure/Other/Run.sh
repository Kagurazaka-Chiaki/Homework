#!/bin/bash

gcc Table.c -o Table

valgrind -v --leak-check=full --track-origins=yes --log-file="TableLog" ./Table > Output