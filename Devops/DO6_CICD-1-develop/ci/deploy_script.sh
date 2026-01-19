#!/bin/bash

HOST="192.10.10.2"
USER="vyacheslav"
TMP_DIR="/home/vyacheslav"
DEST_DIR="/usr/local/bin"


# Копирование артефактов на 192.10.10.2 через scp
scp -r src/cat $USER@$HOST:$TMP_DIR
scp -r src/grep/ $USER@$HOST:$TMP_DIR

# Проверка успешности копирования
if [ $? -eq 0 ]; then
    echo "Артефакты успешно скопированы на 192.10.10.2"
else
    echo "Ошибка при копировании артефактов на 192.10.10.2"
    exit 1
fi


# Перенос файлов в папку назначения через ssh
ssh $USER@$HOST "
				  rm -rf /usr/local/bin/cat; 
				  rm -rf /usr/local/bin/grep;
				  mv $TMP_DIR/cat $DEST_DIR; 
				  mv $TMP_DIR/grep $DEST_DIR
				" 

# Проверка успешности перемещения
if [ $? -eq 0 ]; then
    echo "Файлы успешно перемещены в папку назначения."
else
    echo "Ошибка при перемещении файлов в папку назначения."
    exit 1
fi
