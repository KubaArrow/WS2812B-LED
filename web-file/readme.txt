Instrukcja konfiguracji pilota:
1. Zainstaluj Xampp
2. Uruchom go, włącz Apache oraz Mysql
3. Wrzuć foldery LED i PILOT do katalogu htdocs w głownym folderze xamppa.
3. Uruchom w przeglądarce phpmyadmin (http://localhost/phpmyadmin/)
4. Stwórz nową baze danych oraz użytkownika, który będzie miał do niej dostęp
(Użytkownik musi mieć conajmniej uprawnienia typu Dane)
5. Wgraj do sworzonej bazy danych plik p-ws2812b.sql (zakładka Impotuj)
6. W katalogu LED oraz PILOT znajdują się pliki db.php, 
należy w nich w pustych miejscach wpisać nazwę bazy danych, użytkownika i jego hasło. (koniecznie w obu plikach)
7. Gdy już wszystko zrobiłeś, możesz sprawdzić czy pilot działa.
Wpierw wejdź w przeglądarce pod adres localhost/LED/start.php, jeśli zobaczysz słowo music, to znaczy że wszystko jest okej
8. Następnie wejdz na localhost/PILOT i wciśnij przycisk tęczy, jeśli w pliku start.php zmieni się słowo na rainbow, 
to znaczy że system sterownaia jest poprawnie wgrany 
9. Możesz przejść do kodu Arduino :)