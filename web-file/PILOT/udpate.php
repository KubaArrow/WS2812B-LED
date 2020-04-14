<?php 



include_once("db.php");

$val=$_POST['value_opt'];

$name=$_POST['opt'];

$query ="UPDATE `p-ws2812b` SET `value_opt`='{$val}' WHERE `urz`='PC-KUBA' and `opt`='{$name}'";

if ($res = mysqli_query($db, $query)) {

 

    

}