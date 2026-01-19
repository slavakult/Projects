# Модуль расписания уроков (Lesson Schedule Module)

## Описание
Модуль `lesson_slot` предоставляет инструменты для управления расписанием учебных занятий.  
Он позволяет:
- создавать уроки,
- проверять их на пересечения,
- находить свободные промежутки времени,
- валидировать временные интервалы.

---

## Установка и импорт

```python
from datetime import time, timedelta
from lesson_slot import LessonSlot  # Импортируем основной класс
```

---

## Класс `LessonSlot`

### Конструктор

```python
LessonSlot(start_time: time, end_time: time, break_after: timedelta)
```

**Параметры:**
- `start_time (time)` — время начала урока  
- `end_time (time)` — время окончания урока  
- `break_after (timedelta)` — перерыв после урока  

**Пример:**

```python
lesson = LessonSlot(time(9, 0), time(10, 30), timedelta(minutes=15))
```

---

## Основные методы

### 1. `can_add_lesson(existing_lessons: list, new_lesson: LessonSlot) -> bool`

Проверяет возможность добавления нового урока без конфликтов с существующими.

```python
if LessonSlot.can_add_lesson(lessons, new_lesson):
    lessons.append(new_lesson)
    print("✓ Урок успешно добавлен!")
else:
    print("✗ Нельзя добавить - есть пересечение с существующими уроками")
```

---

### 2. `find_free_slots(lessons: list, day_start: time, day_end: time) -> list`

Находит все свободные промежутки времени между уроками.

**Параметры:**
- `lessons` — список существующих уроков  
- `day_start` — начало рабочего дня (по умолчанию 8:00)  
- `day_end` — окончание рабочего дня (по умолчанию 17:00)  

**Возвращает:**
- список кортежей `(начало_промежутка, конец_промежутка)`

```python
free_slots = LessonSlot.find_free_slots(
    lessons, 
    day_start=time(8, 0), 
    day_end=time(17, 0)
)
```

---

## Примеры использования

### Создание базового расписания

```python
lessons = [
    LessonSlot(time(9, 0), time(10, 30), timedelta(minutes=15)),
    LessonSlot(time(11, 0), time(12, 15), timedelta(minutes=10)),
    LessonSlot(time(13, 0), time(14, 45), timedelta(minutes=30))
]
```

---

### Поиск свободного времени

```python
print("Свободные промежутки в расписании:")
free_slots = LessonSlot.find_free_slots(lessons, day_start=time(8, 0), day_end=time(17, 0))

for i, (start, end) in enumerate(free_slots, 1):
    print(f"{i}. С {start.strftime('%H:%M')} до {end.strftime('%H:%M')}")
```

---

### Проверка на конфликты

```python
new_lesson = LessonSlot(time(10, 30), time(11, 0), timedelta(minutes=0))

if LessonSlot.can_add_lesson(lessons, new_lesson):
    lessons.append(new_lesson)
    print("✓ Урок добавлен в расписание")
else:
    print("✗ Урок не добавлен - обнаружен конфликт")
```

---

## Обработка ошибок

```python
try:
    bad_lesson = LessonSlot(time(15, 0), time(14, 0), timedelta(minutes=10))
except ValueError as e:
    print(f"Ошибка создания урока: {e}")
```

---

## Особенности работы

- Автоматическая сортировка уроков по времени начала  
- Учет перерывов между уроками  
- Гибкая настройка начала и конца рабочего дня  

---

## Преимущества модуля

| Преимущество        | Описание                           |
|--------------------|------------------------------------|
| Простота           | Интуитивно понятный интерфейс      |
| Надежность         | Проверка конфликтов                |
| Гибкость           | Настраиваемые параметры дня        |
| Читаемость         | Понятный и чистый вывод            |
| Производительность | Оптимизированные алгоритмы         |

---

## Примечания

- Используются объекты `datetime.time` и `datetime.timedelta`
- Требуется стандартный модуль `datetime`
