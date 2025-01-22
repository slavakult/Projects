
# Basic CI/CD

Разработка простого **CI/CD** для проекта *SimpleBashUtils*. Сборка, тестирование, развертывание.

<br>






## [Part 1. Настройка **gitlab-runner**](#содержание)

**== Задание ==**

### Поднять виртуальную машину *Ubuntu Server 22.04 LTS*

0. Версия ОС соответствует требованиям ТЗ <br> ![Установлена виртуальная машина](screenshots/part1/without_desktop.PNG) <br>

Из-за проблем с gitlab-runner (ни один не скачался gitlab-runner - была бесконечная загрузка) и достаточно трудоемким процессом добавления ssh-ключа, было принято решение продолжить работу на Linux с GUI.
### Скачать и установить на виртуальную машину **gitlab-runner**

 Установлен gitlab-runner через неофициальный сайт, используя команду
 `curl -L https://packages.gitlab.com/install/repositories/runner/gitlab-runner/script.deb.sh | sudo bash`

1. Загрузить бинарный файл <br>

![ВМ и установка раннера](screenshots/part1/sudo_curl_L_output.PNG) <br>
2. Дать файлу разрешение на исполнение и создать пользователя Gitlab CI: <br>
![установка раннера](screenshots/part1/sudo_chmod_sudo_useradd.PNG) <br> 
3. Установить как службу и запустить <br>
![Установить как службу](screenshots/part1/sudo_gitlab_runner_install.PNG)
![Запустить](screenshots/part1/sudo_gitlab_runner_start.PNG)
![Отображение статуса](screenshots/part1/systemctl_status_gitlab_runner.PNG) <br> 

### Запустить **gitlab-runner** и зарегистрировать его для использования в текущем проекте (*DO6_CICD*)

Для регистрации понадобятся URL и токен, которые можно получить на страничке задания на платформе



- Зарегистрировать gitlab-runner
```
sudo gitlab-runner register
```
> Для этого необходимо ввести данные при регистрации: <br>
> 1. Cвой URL-адрес GitLab
> 2. Cвой регистрационный токен
> 3. Название раннера
> 4. Теги для заданий, разделенные запятыми
> 5. Тип исполнителя

![регистрация](screenshots/part1/gitlab_register.PNG) 
<br>

## [Part 2. Сборка](#содержание)

### Напиcать этап для CI по сборке приложений из проекта *C2_SimpleBashUtils*

- В корне репозитория создать файл `.gitlab-ci.yml`

- Добавить в файл этап запуска сборки через мейк файл из проекта C2.

> Настроим также этап, чтобы файлы, полученные после сборки (артефакты), сохранялись со сроком хранения 30 дней.

![конфигурация](screenshots/part2/gitlab_ci_yml.PNG)


### Проверка сборки проекта

Сборка была успешно осуществлена, исполняемые файлы были сохранены на 30 дней <br>

![значок сданого pipeline](screenshots/part2/pipeline_passed.PNG)
![отчет по сборке](screenshots/part2/pipeline_passed_more.PNG) <br>
<br>

## [Part 3. Тест кодстайла](#содержание)

### Напиcать этап для CI, который запускает скрипт кодстайла (clang-format)

![3.1](screenshots/part3/gitlab-ci_yml.PNG) <br>

### Проверить зафейлился ли пайплайн, если совершена ошибка в кодстайле

- вывод команды локально

![3.2](screenshots/part3/bad_code_style.PNG)

- пайплайн зафейлился <br>

![3.3](screenshots/part3/bad_achieve_pipeline.PNG)


![3.4](screenshots/part3/bad_code_style_from_cicd.PNG)

### Исправить ошибку в форматировании кода и проверить результат

- Результат работы пайплайна <br>

![3.5](screenshots/part3/good_achieve_pipeline.PNG)

- Теперь проект успешно проходит тест кодстайла

![3.6](screenshots/part3/good_code_style_from_cicd.PNG)
<br>

## [Part 4. Интеграционные тесты](#содержание)

### Написать этап для CI, который запускает интеграционные тесты из того же проекта

![Интеграционные тесты](screenshots/part4/gitlab-ci_yml.PNG) <br>

### Проверить зафейлился ли пайплайн, если обнаруживаются ошибочные рузльтаты интеграционных тестов

- Проверяем, что пайплайн зафейлился <br>

![пайплайн зафейлился](screenshots/part4/achieve_bad_tests_from_cicd.PNG)
![пайплайн зафейлился](screenshots/part4/bad_tests_from_cicd.PNG)


### Исправить ошибку для успешного прохождения тестов и проверить результат

- Результат работы пайплайна

![пайплайн ок](screenshots/part4/achieve_bad_tests_good_cicd.PNG)

- Проект успешно проходит интеграционные тесты

![пайплайн ок](screenshots/part4/good_tests_from_cicd.PNG)
<br>

## [Part 5. Этап деплоя](#содержание)

### Поднять вторую виртуальную машину Ubuntu Server 22.04 LTS

![вторая машина](screenshots/part5/network_manager+pings.PNG)



### Написать bash-скрипт, который при помощи ssh и scp копирует файлы, полученные после сборки (артефакты), в директорию /usr/local/bin второй виртуальной машины

Копируем артефакты через scp. <br>
![скрипт](screenshots/part5/deploy_script.PNG)

### В файле gitlab-ci.yml добавили этап запуска написанного скрипта.
 Данный этап будет запускаться вручную при условии, что все предыдущие этапы прошли успешно

![yml](screenshots/part5/deploy-job.PNG)


### Настройка ssh-агента


- Далее необходимо сохранить отпечаток удаленного сервера. Для этого ключ удаленного сервера необходимо добавить в файл `known_hosts` в домашнем каталоге пользователя gitlab-runner. Т. к. я ранее вводил данную команду, то ОС не отреагировала на команду, введеную повторно. <br>

![настройка](screenshots/part5/keyscan.PNG) <br>


### Проверка этапа деплоя

- После пуша обновленного `gitlab-ci.yml` проверяем состояние пайплайна <br>

![деплой](screenshots/part5/pipeline_good.PNG) <br>
![деплой](screenshots/part5/job_succeeded.PNG) <br>

Убедимся, что файлы cat и grap действительно находятся на второй машине.

![файлы](screenshots/part5/bin_192_10_10_2.png) <br>
<br>

## [Part 6. Дополнительно. Уведомления](#содержание)

Настроим уведомления о успешном/неуспешном выполнении пайплайна через бота в `Telegram`.  
Для этого найдем в `Telegram` бота с именем `@BotFather`.  
Используем команду `/newbot` для создания нового бота.  
Следуя инструкциям, зададим `имя бота` и `username` в `Telegram`.  
После создания бота получаем `TELEGRAM_BOT_TOKEN`.  
 ![alt text](screenshots/part6/botfather.PNG)

Далее, найдем бота `@userinfobot`, напишем ему сообщение `/start` и получим наш `TELEGRAM_USER_ID`.    
 ![alt text](screenshots/part6/userinfobot.PNG)

Далее напишем скрипт `notify.sh`, которые будет отправлять уведомления.  
 ![alt text](screenshots/part6/notify_sh.PNG)

Добавим прав на выполнение этому скрипту

![alt text](screenshots/part6/chmod_notify.PNG)

И добавим выполнение скрипта, в каждый этап в `.gitlab-ci.yml`.

 ![alt text](screenshots/part6/gitlab-ci_yml1.PNG)  
 ![alt text](screenshots/part6/gitlab-ci_yml2.PNG)  

Ниже видим, что при вызове этапа пайплайна бот отправляет уведомление.  

![alt text](screenshots/part6/telegram_otch.PNG)  
