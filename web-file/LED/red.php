<?php
include_once("db.php");
$query = "SELECT value_opt FROM p-ws2812b where opt='red'";
if ($res = mysqli_query($db, $query)) {
   $row = mysqli_fetch_array($res);
        echo $row['value_opt'];

}