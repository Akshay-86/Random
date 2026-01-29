<?php
 session_start();
 
$conn = mysqli_connect('127.0.0.1','root','1234','php');
if($conn)
 echo "Successfully Connected <br>";
else
 echo "Failure".mysqli_connect_error();
 
 $sql = "INSERT INTO Prac (Name, Email, `Mobile No.`, Collage, City, State, Prefession, Course, Terms) 
   VALUES ('$_SESSION[usr_name]', '$_SESSION[usr_mail]', '$_SESSION[usr_mobile]', 
      '$_POST[usr_clg]', '$_POST[usr_city]', '$_POST[usr_state]', '$_POST[prefession]', '$_POST[cousre]', '$_POST[terms]')";
 
 if(mysqli_query($conn,$sql))
  echo "Insertion Successful" ;
else 
  echo "Insertion failed".mysqli_error();
  
?>