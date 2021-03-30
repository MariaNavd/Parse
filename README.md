# Parse
Программа, анализирующая текстовый файл, который состоит из набора строк. Каждая строка заканчивается символом перевода строки.
  
Анализ состоит в нахождении строк, которые содержат/не содержат (в зависимости от выбора пользователя) заданных
сочетаний символов (также заданных пользователем) - фильтров. Количество задаваемых фильтров неограниченно.
  
Результат работы программы сохраняется в отдельный файл.
  
  
Программа имеет графический интерфейс. Фильтры задаются в форме MyForm в текстовом поле filters и добавляются путем нажатия кнопки Add filter.
  
По нажатию кнопки Select(res) программа начинает анализ текстового файла:
передает массив фильтров filt и условие выбора строк filters_contain (строки содержат (true)/не содержат (false) фильтров) в функцию select_strings (Functions), которая
считывает по одной строке из исходного файла и передает ее в функцию filter_search.
Эта функция возвращает true, если строка удовлетворяет входным данным, т.е. в
следующих случаях: filters_contain = true и все фильтры содержатся в строке,
filters_contain = false и в строке не содержится ни одного фильтра.
  
Если значение функции filter_search = true, select_strings записывает строку в выходной файл Result.log.
