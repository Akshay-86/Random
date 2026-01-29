<?php
 $conn=mysqli_connect('127.0.0.1','root','1234','php');
 if($conn)
  echo "Connection Successfull,Database selected <br>";
 else
  echo "Connection Failed".mysqli_connect_error().mysqli_error();
  
  $sql = "update newt set $_POST[data] = '$_POST[newdata]' where PINNO = '$_POST[usr_pinno]' ";
  
  if(mysqli_query($conn,$sql))
  echo "updation Successfull";
 else
  echo "updation Failed".mysqli_error($conn);
  
?>