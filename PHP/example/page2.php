<?php
  session_start();
  $_SESSION['usr_name'] = $_POST['usr_name'];
  $_SESSION['usr_mail'] = $_POST['usr_mail'];
  $_SESSION['usr_mobile'] = $_POST['usr_mobile'];
?>

<form method="post" action="page3.php">
  <pre>
    Enter clg name:
    <input type="text" name="usr_clg">
  </pre>
  <pre>
    Enter ur city: 
    <input type="text" name="usr_city">
  </pre>
  <pre>
    Enter ur state: 
    <input type="text" name="usr_state">
  </pre>
  <pre>
    <input type="radio" name="prefession" value="student">Student
    
    <input type="radio" name="prefession" value="teacher">Teacher
  </pre>
  <pre>
    Select course:
    <select name="cousre">
      <option></option>
      <option value="DSnA">Data Stractures</option>
      <option value="AI">Artificial I</option>
      <option value="Ml">Mechine learning</option>
    </select>
  </pre>
  <pre>
    <input type="checkbox" name="terms" value="agreed">Terms & Conditions
  </pre>
  
  <pre>
    <button>Submit</button>
  </pre>
</form>
