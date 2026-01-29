<?php
 $conn=mysqli_connect('127.0.0.1','root','1234','php');
 if($conn)
  echo "Connection Successfull,Database selected <br>";
 else
  echo "Connection Failed".mysqli_connect_error($conn);
  
 $sql = "insert into newt values('$_POST[usr_pinno]','$_POST[usr_name]','$_POST[usr_mail]','$_POST[usr_mobile]','$_POST[usr_dob]')";
 
 if(mysqli_query($conn,$sql))
  echo "Insertion Successfull";
 else
  echo "Insertion Failed".mysqli_error();
  
  
?>


<form method="post" action="page3.php">
  
  <pre>
    Enter ur Pin no.: 
    <input type="text" name="usr_pinno">
  </pre>
  <pre>
    Select What do U want to Update
    <select name="data">
      <option></option>
      <option value="NAME">Name</option>
      <option value="EMAIL">E MAIL</option>
      <option value="MOBILENO">MOBILE NO</option>
    </select>
  </pre>
  <pre>
    Enter ur New Data:
    <input type="text" name="newdata">
  </pre>
  
  <pre>
    <button>Next</button>
  </p>
</form>