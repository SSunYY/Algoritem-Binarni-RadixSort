#!/bin/bash

case $1 in
  basic)
    echo "Test 1: Osnovni test..."
    echo "5 3 8 1" > vhod.txt
    ./radix_sort
    if [ "$(cat izhod.txt)" != "1 3 5 8 " ]; then
      echo "Napaka: Test 1 ni uspel."
      exit 1
    fi
    ;;
  edge)
    echo "Test 2: Prazen vnos..."
    echo "" > vhod.txt
    ./radix_sort
    if [ -s izhod.txt ]; then
      echo "Napaka: Test 2 ni uspel."
      exit 1
    fi
    ;;
  stress)
    echo "Test 3: Velik vnos..."
    for i in {1..100}; do echo $RANDOM % 256 | bc; done > vhod.txt
    ./radix_sort
    sort -n vhod.txt > expected.txt
    if ! cmp --silent izhod.txt expected.txt; then
      echo "Napaka: Test 3 ni uspel."
      exit 1
    fi
    ;;
esac

echo "Vsi testi za $1 so uspeli!"