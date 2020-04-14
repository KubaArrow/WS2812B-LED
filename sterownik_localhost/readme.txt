Instrukcja konfiguracji kodu Arduino:
1. Jeżeli już odpowiednio wgrałeś i skonfigurowałeś serwer, 
to możesz przystąpić do konfiguracji kodu arduinio.
2. Potrzebujemy adres IP komputera, na którym jest zainstalowany i skonfigurowany xampp(nasz serwer),
włączamy konsole Windows i wpisujemy polecenie "ipconfig", szukamy karty sieciowej komputera i "IPv4 Address".
Zalecane jest abyś miał na serwerze ustawiony statyczny adres IP, zapewne u nas na stronie znajdziesz jak to zrobić.
Dzięki temu nie będziesz musiał za każdym restartem komputera, poprawiać kody w Arduino;
3.Musisz teraz poprawić kod Arduino, tak aby pasował do twojego serwera, wszystkie konieczne zmiany będą oznaczone w kodzie,
a tutaj zrobię pełną liste co trzeba poprawić.

Lista niezbędnych zmian:
Linia: Co zmienić
15: Pin do którego podpieliśmy nasze ledy
16: Liczba ledów
17: Pin do którego podpieliśmy mikrofon
19: Zmiana adresu do pliku start.php
42: Ustawianie danych do łaczenia z WIFI
392: Zmiana adresu do pliku red.php
406: Zmiana adresu do pliku blue.php
418: Zmiana adresu do pliku green.php
430: Zmiana adresu do pliku time.php

Po wprowdzeniu tych poprawek i wgraniu kodu na Arduino, 
wszystko powinno zacząć działać :)