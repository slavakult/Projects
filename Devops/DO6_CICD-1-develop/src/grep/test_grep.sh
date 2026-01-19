#!/bin/bash

BUILD=./test/
FILE=t.txt
FILE1=t1.txt
PATTERN=hel
PATTERN1=fla
PATTERN2=Hel
PATTERN3=./test/pattern.txt

# Счетчики тестов
total_tests=0
succes_tests=0
failed_tests=0

# Базовый тест
total_tests=$((total_tests + 1))
./s21_grep $PATTERN $BUILD$FILE $BUILD$FILE1 > $BUILD"grep2.txt"
	grep $PATTERN  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep1.txt"
	diff  $BUILD"grep1.txt" $BUILD"grep2.txt"

if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 1 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 1 failed"
fi

# Остальные тесты (с -e, -i, -v, -c, -l, -n, -h, -f, -o, -iv, -in)
# Тест с -e
total_tests=$((total_tests + 1))
./s21_grep -e $PATTERN -e $PATTERN1 $BUILD$FILE $BUILD$FILE1 > $BUILD"grep4.txt"
grep -e $PATTERN -e $PATTERN1 $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep3.txt"
diff  $BUILD"grep3.txt" $BUILD"grep4.txt"

if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 2 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 2 failed"
fi

# Тест с -i
total_tests=$((total_tests + 1))
./s21_grep -i $PATTERN2 $BUILD$FILE $BUILD$FILE1 > $BUILD"grep6.txt"
grep -i $PATTERN2  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep5.txt"
diff  $BUILD"grep5.txt"  $BUILD"grep6.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 3 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 3 failed"
fi

# Тест с -v
#total_tests=$((total_tests + 1))
#./s21_grep -v $PATTERN $BUILD$FILE $BUILD$FILE1 > $BUILD"grep8.txt"
#grep -v $PATTERN  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep7.txt"
#diff  $BUILD"grep7.txt"  $BUILD"grep8.txt"
#if [ $? -eq 0 ]; then
#  succes_tests=$((succes_tests + 1))
#  echo "Test 4 succes"
#else
#  failed_tests=$((failed_tests + 1))
#  echo "Test 4 failed"
#fi

# Тест с -c
total_tests=$((total_tests + 1))
./s21_grep -c $PATTERN $BUILD$FILE $BUILD$FILE1 > $BUILD"grep10.txt"
grep -c $PATTERN  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep9.txt"
diff  $BUILD"grep9.txt"  $BUILD"grep10.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 5 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 5 failed"
fi

# Тест с -l
total_tests=$((total_tests + 1))
./s21_grep -l $PATTERN $BUILD$FILE $BUILD$FILE1 > $BUILD"grep12.txt"
grep -l $PATTERN  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep11.txt"
diff  $BUILD"grep11.txt"  $BUILD"grep12.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 6 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 6 failed"
fi

# Тест с -n
total_tests=$((total_tests + 1))
./s21_grep -n $PATTERN $BUILD$FILE $BUILD$FILE1 > $BUILD"grep26.txt"
grep -n $PATTERN  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep25.txt"
diff  $BUILD"grep25.txt"  $BUILD"grep26.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 7 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 7 failed"
fi

# Тест с -h
total_tests=$((total_tests + 1))
./s21_grep -h $PATTERN $BUILD$FILE $BUILD$FILE1 > $BUILD"grep14.txt"
grep -h $PATTERN  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep13.txt"
diff  $BUILD"grep13.txt"  $BUILD"grep14.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 8 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 8 failed"
fi

# Тест с -f
#total_tests=$((total_tests + 1))
#./s21_grep -f $PATTERN3 $BUILD$FILE $BUILD$FILE1 > $BUILD"grep18.txt"
#grep -f $PATTERN3  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep17.txt"
#diff  $BUILD"grep17.txt"  $BUILD"grep18.txt"
#if [ $? -eq 0 ]; then
#  succes_tests=$((succes_tests + 1))
#  echo "Test 9 succes"
#else
#  failed_tests=$((failed_tests + 1))
#  echo "Test 9 failed"
#fi
# Тест с -o
total_tests=$((total_tests + 1))
./s21_grep -o $PATTERN $BUILD$FILE $BUILD$FILE1 > $BUILD"grep20.txt"
grep -o $PATTERN  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep19.txt"
diff  $BUILD"grep19.txt"  $BUILD"grep20.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 10 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 10 failed"
fi

# Тест с -iv
#total_tests=$((total_tests + 1))
#./s21_grep -iv $PATTERN2 $BUILD$FILE $BUILD$FILE1 > $BUILD"grep22.txt"
#grep -iv $PATTERN2  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep21.txt"
#diff  $BUILD"grep21.txt"  $BUILD"grep22.txt"
#if [ $? -eq 0 ]; then
#  succes_tests=$((succes_tests + 1))
#  echo "Test 11 succes"
#else
#  failed_tests=$((failed_tests + 1))
#  echo "Test 11 failed"
#fi

# Тест с -in
total_tests=$((total_tests + 1))
./s21_grep -in $PATTERN2 $BUILD$FILE $BUILD$FILE1 > $BUILD"grep24.txt"
grep -in $PATTERN2  $BUILD$FILE $BUILD$FILE1 >  $BUILD"grep23.txt"
diff  $BUILD"grep23.txt"  $BUILD"grep24.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 12 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 12 failed"
fi
# Вывод результатов
echo "Total tests: $total_tests"
echo "Succes: $succes_tests"
echo "Failed: $failed_tests"

if [ $failed_tests -eq 0 ]; then
	echo "All tests succes!"
	exit 0
else
	echo "Some tests failed."
	exit 1
fi	
