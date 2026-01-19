# DO5_SimpleDocker-1 
## Part 1. Готовый докер

Возьмем официальный докер-образ с `nginx` и выкачаем его при помощи `docker pull`.  
![Part_1](imgs/part1/1_docker_pull.PNG)

Проверим наличие докер-образа через `docker images`.  
![Part_1](imgs/part1/1_docker_images.PNG)

Запустим докер-образ через `docker run -d [image_id|repository]`.  
![Part_1](imgs/part1/1_docker_run.PNG)

Проверим, что образ запустился через `docker ps`.  
![Part_1](imgs/part1/1_docker_ps.PNG)

Посмотрим информацию о контейнере через `docker inspect [container_id|container_name]`.
![Part_1](imgs/part1/1_docker_inspect.PNG)  

По выводу команды определим `размер контейнера, список замапленных портов и ip контейнера`.  
![Part_1](imgs/part1/1_docker_size.PNG)  
![Part_1](imgs/part1/1_docker_ipaddress.PNG)  
![Part_1](imgs/part1/1_docker_ports.PNG)  

Остановим докер образ через `docker stop [container_id|container_name]` и проверим, что образ остановился через 'docker ps'.  
![Part_1](imgs/part1/1_docker_stop.PNG)  

Запустим докер с `портами 80 и 443` в контейнере, замапленными на такие же порты на локальной машине, через команду `run`.  
![Part_1](imgs/part1/1_docker_run_d_p.PNG)  

Проверим, что в браузере по адресу `localhost:80` доступна стартовая страница `nginx`.
![Part_1](imgs/part1/1_localhost_80.PNG)    

Перезапустим докер контейнер через `docker restart [container_id|container_name]`.  

Проверим любым способом, что контейнер запустился.  
![Part_1](imgs/part1/1_docker_restart.PNG)  

## Part 2. Операции с контейнером

Прочтём конфигурационный файл `nginx.conf` внутри докер контейнера через команду `exec`.
![Part_2](imgs/part2/exec_1.png)

![Part_2](imgs/part2/exec_2.png)

Создадим на локальной машине файл `nginx.conf`.  
Настройм в нем по пути `/status` отдачу страницы статуса сервера `nginx`.  
![Part_2](imgs/part2/cat_nginx1.png)

![Part_2](imgs/part2/cat_nginx2.PNG)

Скопируем созданный файл `nginx.conf` внутрь докер-образа через команду `docker cp`.  
![Part_2](imgs/part2/docker_cp_docker_exec.png)  

Перезапустим `nginx` внутри докер-образа через команду `exec`.

![Part_2](imgs/part2/docker_reload.png)  

Проверим, что по адресу `localhost:80/status` отдается страничка со статусом сервера `nginx`.  
![Part_2](imgs/part2/localhost_status.png)  

Экспортируем контейнер в файл `container.tar` через команду `export`.

![Part_2](imgs/part2/container_tar.PNG)

Остановим контейнер.  
![Part_2](imgs/part2/docker_stop.PNG)  

Удалим образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры.
![Part_2](imgs/part2/docker_rmi.PNG)  

Удалим остановленный контейнер.  
![Part_2](imgs/part2/docker_rm.PNG)  

Импортируем контейнер обратно через команду `import`.

![Part_2](imgs/part2/docker_import.PNG)  

Запустим импортированный контейнер.

![Part_2](imgs/part2/docker_run_last.PNG)  

Проверим, что по адресу `localhost:80/status` отдается страничка со статусом сервера `nginx`.  
![Part_2](imgs/part2/localhost_status_last.png)  

## Part 3. Мини веб-сервер

Напишем `мини-сервер на C и FastCgi`, который будет возвращать простейшую страничку с надписью `Hello World!`.  
![Part_3](imgs/part3/docker_server.PNG)  

Напишем свой `nginx.conf`, который будет проксировать все запросы с `81 порта` на `127.0.0.1:8080`.  
![Part_3](imgs/part3/docker_nginx.PNG)  

Качаем образ `nginx`, запускаем контейнер, копируем файл `miniserver.c` и `nginx.conf`.  

Заходим в контейнер командой `docker exec -it [container_id] bash`, обновляемся, устанавливаем `gcc, spawn-fcgi, libfcgi-dev`.
![Part_3](imgs/part3/docker_run.PNG)  
![Part_3](imgs/part3/install_gcc_fcgi.PNG)  
![Part_3](imgs/part3/docker_cp_nginx.PNG)  

Запустим написанный мини-сервер через `spawn-fcgi` на порту `8080`.  
![Part_3](imgs/part3/docker_bash.PNG)  

![Part_3](imgs/part3/gcc_server.PNG)  

Проверим, что в браузере по `localhost:81` отдается написанная нами страничка.   
![Part_3](imgs/part3/hello_world.PNG)  

Положим файл `nginx.conf` по пути `./nginx/nginx.conf` (это понадобится позже).  
![Part_3](imgs/part3/nginx-nginx_conf.PNG)  

## Part 4. Свой докер

Напишем свой докер-образ, который:

1) собирает исходники мини сервера на `FastCgi` из Части 3;
2) запускает его на `8080 порту`;
3) копирует внутрь образа написанный `./nginx/nginx.conf`;
4) запускает `nginx`.
nginx можно установить внутрь докера самостоятельно, а можно воспользоваться готовым образом с nginx'ом, как базовым.  
![Part_4](imgs/part4/dockerfile.PNG)  
![Part_4](imgs/part4/run_sh.PNG)  

Соберем написанный докер-образ через `docker build` при этом указав имя и тег.  
![Part_4](imgs/part4/docker_build_t.PNG)  

Проверим через `docker images`, что все собралось корректно.

![Part_4](imgs/part4/docker_images.PNG)  
Запустим собранный докер-образ `с маппингом 81 порта на 80 на локальной машине` и маппингом папки `./nginx` внутрь контейнера по адресу, где лежат конфигурационные файлы `nginx'а`.

![Part_4](imgs/part4/run_it.PNG)

Проверим, что по `localhost:80` доступна страничка написанного мини сервера.  
![Part_4](imgs/part4/localhost_80.PNG)   
Проверим, что по `localhost:80/status` отдается страничка со статусом `nginx`.  
![Part_4](imgs/part4/localhost_status.PNG)   

## Part 5. Dockle

Сканируем образ из предыдущего задания через `dockle [image_id|repository]`.
![Part_5](imgs/part5/docker_run1.PNG)  
![Part_5](imgs/part5/docker_run2.PNG)  

Перепишем `dockerfile`, чтобы избавиться от ошибок.
С ошибкой `CIS-DI-0010` можно разобраться только сменой образа на `Alpine`.  
![Part_5](imgs/part5/dockerfile.PNG)   

Запустим образ заново и обратим внимание, что ошибки `dockle` устранены.
![Part_5](imgs/part5/docker_run_success.PNG)    

## Part 6. Базовый Docker Compose

Напишем файл `docker-compose.yml`.   
![Part_6](imgs/part6/docker-compose_yaml.PNG)  

Поднимем докер-контейнер с `nginx`, который будет проксировать все запросы с `8080 порта на 81 порт` первого контейнера.  
![Part_6](imgs/part6/nginx.PNG)  

Останови все запущенные контейнеры.

![Part_6](imgs/part6/docker_ps.PNG)


Собери и запусти проект с помощью команд docker-compose build и docker-compose up.  
![Part_6](imgs/part6/compose-up.PNG)  

![Part_6](imgs/part6/docker-compose.PNG)

Проверь, что в браузере по localhost:80 отдается написанная тобой страничка, как и ранее.  
![Part_6](imgs/part6/localhost_80.PNG) 