<html>
<head>
<title>"View Employee"</title>
</head>
<body bgcolor="Lightpink">
<form action="main.html" method="post">
<center>
	<?php
		include_once 'conn.php';
	$sql = "SELECT * FROM employee";
	$result=mysqli_query($conn,$sql);
		if (mysqli_num_rows($result) > 0) 
		{
	?>
<br><br>
  <table  border="2">
  
  <tr>
    <th>Id</th>	
    <th>Name</th>
    <th>Desig</th>	
   <th>Salary</th>		
    </tr>

	<?php
	$i=0;
	while($row = mysqli_fetch_assoc($result)) {
	?>
<tr>
 <td><?php echo $row["eid"]; ?></td>

    <td><?php echo $row["ename"]; ?></td>
<td><?php echo $row["desig"]; ?></td>
<td><?php echo $row["salary"]; ?></td>

</tr>

	<?php
	$i++;
	}
	?>
</table>
	

 	<?php
	}
	else{
   	 echo "No result found";
	}
	?>
<br>
<br>
<input type="submit" value="Back to home page"name="submit">
</center>
</form>
 </body>
</html>
