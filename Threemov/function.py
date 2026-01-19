from datetime import time, timedelta
from lesson_slot import LessonSlot  # Предположим, что класс сохранён в этом модуле

def main():
    # создаю расписание уроков
    lessons = [
        LessonSlot(time(9, 0), time(10, 30), timedelta(minutes=15)),  # Урок 1
        LessonSlot(time(11, 0), time(12, 15), timedelta(minutes=10)),  # Урок 2
        LessonSlot(time(13, 0), time(14, 45), timedelta(minutes=30))  # Урок 3
    ]

    # Вывожу расписание
    print("Текущее расписание:")
    for i, lesson in enumerate(lessons, 1):
        print(f"{i}. {lesson}")

    # добавляю новый урок с проверкой
    new_lesson = LessonSlot(time(10, 30), time(11, 0), timedelta(minutes=0))
    
    print("\nПопытка добавить урок 10:30-11:00:")
    if LessonSlot.can_add_lesson(lessons, new_lesson):
        lessons.append(new_lesson)
        print("✓ Урок успешно добавлен!")
    else:
        print("Х Нельзя добавить - есть пересечение с существующими уроками")

    # добавляю конфликтующий урок
    conflict_lesson = LessonSlot(time(11, 0), time(12, 30), timedelta(minutes=0))
    
    print("\nПопытка добавить урок 11:00-12:30:")
    if LessonSlot.can_add_lesson(lessons, conflict_lesson):
        lessons.append(conflict_lesson)
        print("✓ Урок добавлен")
    else:
        print(f"Х Конфликт с существующим уроком: {lessons[1]}")

    # нахожу свободные интервалы
    print("\nСвободные промежутки в расписании:")
    free_slots = LessonSlot.find_free_slots(lessons, day_start=time(8, 0), day_end=time(17, 0))
    
    for i, (start, end) in enumerate(free_slots, 1):
        print(f"{i}. С {start.strftime('%H:%M')} до {end.strftime('%H:%M')}")

    # Создаю некорректный урок
    try:
        print("\nПопытка создать урок с некорректным временем:")
        bad_lesson = LessonSlot(time(15, 0), time(14, 0), timedelta(minutes=10))
    except ValueError as e:
        print(f"Х Ошибка: {e}")

if __name__ == "__main__":
    main()