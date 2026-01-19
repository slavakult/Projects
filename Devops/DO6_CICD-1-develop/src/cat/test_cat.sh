#!/bin/bash


BUILD=./test/
FILE1=test.txt
FILE=t.txt
FILE2=t2.txt


total_tests=0
succes_tests=0
failed_tests=0


total_tests=$((total_tests + 1))
./s21_cat $BUILD$FILE > $BUILD"cat2.txt"
cat $BUILD$FILE > $BUILD"cat1.txt"
diff $BUILD"cat1.txt" $BUILD"cat2.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 1 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 1 failed"
fi

# Тест с ключом -b
total_tests=$((total_tests + 1))
./s21_cat -b $BUILD$FILE > $BUILD"cat4.txt"
cat -b $BUILD$FILE > $BUILD"cat3.txt"
diff $BUILD"cat3.txt" $BUILD"cat4.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 2 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 2 failed"
fi

# Тест с ключом -e
#total_tests=$((total_tests + 1))
#./s21_cat -e $BUILD$FILE1 > $BUILD"cat6.txt"
#cat -ev $BUILD$FILE1 > $BUILD"cat5.txt"
#diff $BUILD"cat5.txt" $BUILD"cat6.txt"
#if [ $? -eq 0 ]; then
#  succes_tests=$((succes_tests + 1))
#  echo "Test 3 succes"
#else
#  failed_tests=$((failed_tests + 1))
#  echo "Test 3 failed"
#fi

# Тест с ключом -E
total_tests=$((total_tests + 1))
./s21_cat -E $BUILD$FILE2 > $BUILD"cat8.txt"
cat -e $BUILD$FILE2 > $BUILD"cat7.txt"
diff $BUILD"cat7.txt" $BUILD"cat8.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 4 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 4 failed"
fi

# Тест с ключом -n
total_tests=$((total_tests + 1))
./s21_cat -n $BUILD$FILE > $BUILD"cat10.txt"
cat -n $BUILD$FILE > $BUILD"cat9.txt"
diff $BUILD"cat9.txt" $BUILD"cat10.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 5 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 5 failed"
fi

# Тест с ключом -s
total_tests=$((total_tests + 1))
./s21_cat -s $BUILD$FILE > $BUILD"cat12.txt"
cat -s $BUILD$FILE > $BUILD"cat11.txt"
diff $BUILD"cat11.txt" $BUILD"cat12.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 6 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 6 failed"
fi

# Тест с ключом -T
total_tests=$((total_tests + 1))
./s21_cat -T $BUILD$FILE2 > $BUILD"cat14.txt"
cat -t $BUILD$FILE2 > $BUILD"cat15.txt"
diff $BUILD"cat14.txt" $BUILD"cat15.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 7 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 7 failed"
fi

# Тест с ключом -t
#total_tests=$((total_tests + 1))
#./s21_cat -t $BUILD$FILE1 > $BUILD"cat16.txt"
#cat -tv $BUILD$FILE1 > $BUILD"cat15.txt"
#diff $BUILD"cat15.txt" $BUILD"cat16.txt"
#if [ $? -eq 0 ]; then
#  succes_tests=$((succes_tests + 1))
#  echo "Test 8 succes"
#else
#  failed_tests=$((failed_tests + 1))
#  echo "Test 8 failed"
#fi

# Тест с ключом --number-nonblank
total_tests=$((total_tests + 1))
./s21_cat --number-nonblank $BUILD$FILE > $BUILD"cat18.txt"
cat -b $BUILD$FILE > $BUILD"cat17.txt"
diff $BUILD"cat17.txt" $BUILD"cat18.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 9 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 9 failed"
fi

# Тест с ключом --squeeze-blank
total_tests=$((total_tests + 1))
./s21_cat --squeeze-blank $BUILD$FILE > $BUILD"cat20.txt"
cat -s $BUILD$FILE > $BUILD"cat19.txt"
diff $BUILD"cat19.txt" $BUILD"cat20.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 10 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 10 failed"
fi

# Тест с ключом --number
total_tests=$((total_tests + 1))
./s21_cat --number $BUILD$FILE > $BUILD"cat22.txt"
cat -n $BUILD$FILE > $BUILD"cat21.txt"
diff $BUILD"cat21.txt" $BUILD"cat22.txt"
if [ $? -eq 0 ]; then
  succes_tests=$((succes_tests + 1))
  echo "Test 11 succes"
else
  failed_tests=$((failed_tests + 1))
  echo "Test 11 failed"
fi


# Вывод результатов
echo "Total tests: $total_tests"
echo "Succes: $succes_tests"
echo "Failed: $failed_tests"

if [ $failed_tests -eq 0 ]; then
  echo "All tests succes!"
 exit 0
esle
  echo "Some tests failed."
 exit 1
fi
