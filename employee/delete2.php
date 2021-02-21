<html>
<body bgcolor="red">
<form action="main.html" method="post">
<center>
<?php
include_once 'conn.php';
$rid = $_POST['id'];
$sql = "DELETE FROM employee WHERE eid='$rid'";

if (mysqli_query($conn, $sql)) {
    echo "Record deleted successfully";
} 
else {
    echo "Error deleting record: " . mysqli_error($conn);
}
mysqli_close($conn);
?>
<br>
<br>
<input type="submit" value="Back to home page"name="submit">
</center>
</body>
</html>