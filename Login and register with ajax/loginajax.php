<?php
$mysqli = mysqli_connect("localhost","root","","registration");

if (!$mysqli) {
    die("Connection failed: " . mysqli_connect_error());
}

$passworda = $_POST["password"];
$emaila = $_POST["email"];
$encryptedpassworda=md5($passworda);
$output = $mysqli->query("SELECT * FROM `user` WHERE `email` LIKE '$emaila' AND `password` LIKE '$encryptedpassworda'");
if($output->num_rows>0)
{
    echo "yes";
} else{
    echo "no";
}
$mysqli->close();

?>