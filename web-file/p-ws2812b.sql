-- phpMyAdmin SQL Dump
-- version 5.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 14 Kwi 2020, 12:27
-- Wersja serwera: 10.4.11-MariaDB
-- Wersja PHP: 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `test`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `p-ws2812b`
--

CREATE TABLE `p-ws2812b` (
  `id` int(11) NOT NULL,
  `urz` varchar(50) NOT NULL,
  `opt` varchar(50) NOT NULL,
  `value_opt` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin2;

--
-- Zrzut danych tabeli `p-ws2812b`
--

INSERT INTO `p-ws2812b` (`id`, `urz`, `opt`, `value_opt`) VALUES
(1, 'PC-LED', 'opcja', 'music'),
(2, 'PC-LED', 'red', '255'),
(3, 'PC-LED', 'green', '0'),
(4, 'PC-LED', 'blue', '0'),
(5, 'PC-LED', 'time_s', '100');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `p-ws2812b`
--
ALTER TABLE `p-ws2812b`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `p-ws2812b`
--
ALTER TABLE `p-ws2812b`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
