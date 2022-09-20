#!/bin/bash

read -p "Ready to compile your code - Press any key to continue"
make

read -p "Your program is going to be ran twice with a sequence of inputs, sit tight"
cat steps1.txt | cmake-build-debug/school > output-part1.txt 2>errors-part1.txt
cat steps2.txt | cmake-build-debug/school > output-part2.txt 2>errors-part2.txt

echo "There should be four new files:"
echo "	output-part1.txt"
echo "	output-part2.txt"
echo "	errors-part1.txt"
echo "	errors-part2.txt"
echo "These files represent the output of your program ran with the sequence of inputs"
echo
echo "You can compare these files with the given files:"
echo "	expected-output-part1.txt"
echo "	expected-output-part2.txt"
echo "	expected-errors-part1.txt"
echo "	expected-errors-part2.txt"
echo
echo "This script is going to do the comparison for you"

read -p "Ready to compare? Hit any key when ready"
echo "Comparing output 1"
diff output-part1.txt expected-output-part1.txt
echo
echo "Comparing the errors 1"
diff errors-part1.txt expected-errors-part1.txt
echo

echo "Comparing output 2"
diff output-part2.txt expected-output-part2.txt
echo
echo "Comparing the errors 1"
diff errors-part2.txt expected-errors-part2.txt
echo

echo "If you did not see any messages it means that your output and the expected output"
echo "are the same"
echo
echo

