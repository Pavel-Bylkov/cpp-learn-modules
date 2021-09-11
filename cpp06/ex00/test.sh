#!/bin/bash

echo "----------------- Test integer -------------------------"
echo "./convert 0"
./convert 0
echo "./convert 130"
./convert 130
echo "./convert 78"
./convert 78
echo "./convert 7"
./convert 7
echo "./convert -2147483648"
./convert -2147483648
echo "./convert 2147483647"
./convert 2147483647
echo "./convert 3000000000"
./convert 3000000000
echo "----------------- Test char -------------------------"
echo "./convert a"
./convert a
echo "./convert Z"
./convert Z
echo "./convert '%'"
./convert '%'
echo "----------------- Test float -------------------------"
echo "./convert 42.0f"
./convert 42.0f
echo "./convert .0f"
./convert .0f
echo "./convert 0.0f"
./convert 0.0f
echo "./convert -4.2f"
./convert -4.2f
echo "./convert 4.2f"
./convert 4.2f
echo "./convert -inff"
./convert -inff
echo "./convert +inff"
./convert +inff
echo "./convert nanf"
./convert nanf
echo "./convert 3000000000000000000000000000000000000000000000000000000000000000000000000000.0f"
./convert 3000000000000000000000000000000000000000000000000000000000000000000000000000.0f
echo "----------------- Test double -------------------------"
echo "./convert nan"
./convert nan
echo "./convert -inf"
./convert -inf
echo "./convert +inf"
./convert +inf
echo "./convert .0"
./convert .0
echo "./convert 3000000000000000000000000000000000000000000000000000000000000000000000000000.0"
./convert 3000000000000000000000000000000000000000000000000000000000000000000000000000.0

