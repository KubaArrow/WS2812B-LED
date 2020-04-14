<?php

$host="localhost";

$user="";//login użytkownika

$pass="";//hasło użytkownika

$name="";//nazwa bazy danych




$db = mysqli_connect($host, $user, $pass, $name);



if (!$db) {

    die('Connect Error (' . mysqli_connect_errno() . ') '

            . mysqli_connect_error());

}











