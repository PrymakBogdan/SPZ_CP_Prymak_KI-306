# Додаток для віддаленого запуску програм 
Розробка програми для автоматизації процесів віддаленого керування комп'ютером. Розробка програми, що автоматично виконує дії на комп'ютері, на який надано доступ віддалено.
Ідеєю програми є віддалений запуск певного списку програм (наприклад VS Code + Chrome, Microsoft Word + Chrome + Microsoft PowerPoint) та закриття інших непотрібних програм, доступ до яких буде надано. 
# Функціонал
Програма забезпечує можливість створення "Аккаунта" на комп'ютері, на якому встановлена програма, та конектується з іншим комп'ютером (керуючим), для надсилання команд і керування списками програм, які будуть запускатися на дочірньому комп'ютері. Користувач може створювати, редагувати, видаляти списки програм для запуску на дочірньому комп'ютері, а також виконувати команди зупинки та запуску програм на віддаленому комп'ютері через керуючий.
- Створення "Аккаунта" пк, на якому встановлено програму
- Конект пк, з якого відбуватиметься надсилання команд (далі : керуючий пк), з пк, який виконуватиме команди (далі : дочірний пк)
- Створення списку програм до яких буде доступ керування
- Створення списків запуску програм на дочірньому пк
- Редагування списків запуску програм на дочірньому пк
- Видалення списків запуску програм на дочірньому пк
- Передавання списку запуску програм з дочірнього пк на керуючий
- Передавання команд з керуючого пк до дочірнього
- Зупинка всіх програм з списку програм до яких буде доступ керування на дочірньому пк
- Запуск програм з списку запуску програм, надісланого керуючим пк, на дочірньому пк
