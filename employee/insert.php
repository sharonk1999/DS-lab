<html>
<body bgcolor="pink">
<form action="main.html" method="post">
<center>
<br>
<br>
<?php
include_once 'conn.php';
if(isset($_POST['submit']))
{
	 $eid=$_POST['id'];
	 $name = $_POST['name'];
	$desig=$_POST['desig'];
	$salary = $_POST['salary'];
	
	 
	 $sql = "INSERT INTO employee (eid,ename,desig,salary) 
		VALUES ('$eid','$name','$desig','$salary')";

	 if (mysqli_query($conn, $sql)) {
		echo "<br>New Employee added !<br>";
	 } 
	else
	 {
		echo "Error: " . $sql . "" . mysqli_error($conn);
	 }
	 mysqli_close($conn);
}

?>
<br><br><input type="submit" value="Back to home page"name="submit">
</center>
</body>
</html>
