<?php
 $cook_name="akshay";
 $cook_no="106";
 setcookie($cook_name,$cook_no,time()+360000000);
 if(!isset($_COOKIE[$cook_name])){
   echo "cookie not set ".$cook_name;
 }else{
   echo "cookie is ".$cook_name."is set";
   echo "value is".$_COOKIE[$cook_name];
 }
?>