<html>
	<?php 

	$number1 = $_POST["number1"];
	$number2 = $_POST["number2"];
	$number3 = $_POST["number3"];
	
		if (($number1 * $number2) == $number3) {
			echo "<p> Good Job! </p>";
		} else {
			echo " <p> You need practice! </p> "; 
			echo $number1 . " * " . $number2 . "=" . $number1 * $number2; 		
		}
	?> 

	<form method="POST" action ="ex.php">
		<input type="submit" value="Try again" />
	</form>	
</html>
