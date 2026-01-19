#!/bin/bash


rm -f ./test/memory.txt
rm -f ./test/mygrep.txt ./test/grep.txt
# Проверяем наличие программы
if [ ! -f s21_grep ]; then
    echo "Ошибка: программа не скомпилирована"
    exit 1
fi
   k=0
   m=0
# Функция для тестирования программы с определенными флагами
test_grep() {
    args="$1"
 
    echo "Тестирование: ./s21_grep $args"
    output=$(./s21_grep $args)
    echo "$output" > ./test/mygrep.txt

    echo "Тестирование: grep $args" 
    output=$(grep $args)
    echo "$output" > ./test/grep.txt

    diff ./test/grep.txt ./test/mygrep.txt
if [ $? -eq 0 ]; then  
((k++))
else
    echo "Файлы программы и утил grep различаются"
fi
echo "совпадений $k из 19"
echo "~~~~~~~~~~~~~~~********~~~~~~~~~~~~~~~~~"
((m++))
#echo "Тестирование памяти: ./s21_grep $args" >> ./test/memory.txt
 #   if [[ "$OSTYPE" == "linux-gnu"* ]]; then

  #     valgrind_exit_code=$?
 
   #     if [ $valgrind_exit_code -eq 0 ]; then
    #    echo "Valgrind не обнаружил утечек памяти $valgrind_exit_code"
     #   elif [ $valgrind_exit_code -eq 1 ]; then
      #  echo "Valgrind обнаружил утечки памяти $valgrind_exit_code"
       # else
        #echo "Valgrind завершил работу с ошибкой (код возврата: $valgrind_exit_code)"
        #fi
    #elif [[ "$OSTYPE" == "darwin"* ]]; then
    #echo "Mac"
     #  output=$(leaks -atExit -- ./s21_grep $args)
      #  leaks_exit_code=$?
      #  if [ $leaks_exit_code -eq 0 ]; then
      #  echo "Leaks не обнаружил утечек памяти $leaks_exit_code"
      #  elif [$leks_exit_code -eq 1 ]; then
      #  echo "Leaks обнаружил утечки памяти $leaks_exit_code"
      #  else
      #  echo "Leaks завершил работу с ошибкой (код возврата: $valgrind_exit_code)"
      #  fi
   # else
    #    echo "Не удалось определить операционную систему"
     #   exit 1
    #fi
    #echo "проверка $m из 19" >> ./test/memory.txt
    #echo "$output" >> ./test/memory.txt
    #echo "~~~~~~~~~~~~~~~********~~~~~~~~~~~~~~~~~" >> ./test/memory.txt
}


# Тестирование программы с разными комбинациями флагов
test_grep "-s hel ./test/t.txt ./test/t1.txt"  
test_grep "-i hel ./test/t.txt ./test/t1.txt1"  
test_grep "-l hel ./test/t.txt ./test/t1.txt"  
test_grep "-s hel ./test/t.txt1 ./test/t1.txt1"  
test_grep "-n hel ./test/t.txt ./test/t1.txt"
test_grep "-e hel -e flag ./test/t.txt ./test/t1.txt1" 
test_grep "-e hel -e flag ./test/t.txt ./test/t1.txt"
test_grep "-v hel ./test/t.txt ./test/t1.txt1"  
test_grep "-v hel ./test/t.txt ./test/t1.txt"
test_grep "-o hel ./test/t.txt ./test/t1.txt1"  
test_grep "-o hel ./test/t.txt ./test/t1.txt"
test_grep "-f ./test/pat.txt ./test/t.txt ./test/t1.txt1"  
test_grep "-f ./test/pat.txt ./test/t.txt ./test/t1.txt"
test_grep "-c hel ./test/t.txt1 ./test/t1.txt1"  
test_grep "-c hel ./test/t.txt ./test/t1.txt"
test_grep "-h hel ./test/t.txt1 ./test/t1.txt1"  
test_grep "-h hel ./test/t.txt ./test/t1.txt"
test_grep "-in Hel ./test/t.txt ./test/t1.txt1"  
test_grep "-in Hel ./test/t.txt ./test/t1.txt"