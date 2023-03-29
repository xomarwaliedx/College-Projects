<head>
<link rel="stylesheet" href="style.css">
</head>

<?php
$mysqli = mysqli_connect("localhost","root","","registration");

if (!$mysqli) {
    die("Connection failed: " . mysqli_connect_error());
}

$namea = $_POST["user_name"];
$passworda = $_POST["password"];
$emaila = $_POST["email"];
$encryptedpassworda=md5($passworda);

$output = $mysqli->query("SELECT * FROM `user` WHERE `email` LIKE '$emaila'");
if($output->num_rows>0)
{
    echo "<h1>User already exist!</h1>";
} else{
    $query="INSERT INTO `user` (`user_id`, `email`, `name`, `password`, `registration_date`) VALUES (NULL, '$emaila', '$namea', '$encryptedpassworda', current_timestamp())";
 if(mysqli_query($mysqli,$query))
 {
  echo "<h1>Welcome ".$namea."</h1>";
 }
 else
 {
  echo "<h1>Record Not Inserted</h1>";
 }
}
$mysqli->close();

?>