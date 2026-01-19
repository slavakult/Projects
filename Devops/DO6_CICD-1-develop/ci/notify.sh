#!/bin/bash

# Переменные с токеном и ID пользователя
TELEGRAM_BOT_TOKEN="7839117913:AAG6xpKcDrhIuAykz62Cn3-ownFO0R7o_fY"
TELEGRAM_USER_ID="610917462"

# URL для отправки сообщения через API Telegram
URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"

# Текст сообщения, передаваемый в качестве аргумента
TEXT="$1 %0AПроект: $CI_PROJECT_NAME %0AЭтап: $CI_JOB_STAGE %0AСтатус: $CI_JOB_STATUS"

# Отправка сообщения с помощью curl
curl -s -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
