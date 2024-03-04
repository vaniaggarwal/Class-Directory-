<html>

	<?php
		$number = $_POST["number"];
		
		$a = array(0, 0, 0, 0, 0);

		$count = 0;
		for ($i=0; $i<5; $i++) {
			$a[$i] = rand(1,20);
		}
		print_r($a);  
		echo "<p> Entered Number: </p>" . $number;
			
		for ($i=0; $i<5; $i++) {
			if ($a[$i] == $number) {
				$count += 1;
		
		}
		}		
			if ($count >= 1) {
				echo "<p>You got it!</p>";
			} else {
				echo "<p>Wrong!</p>";
                                } 	
	
			
	?>
	
		<form method="POST" action ="lab3.php">
			<input type ="submit" value="Try Again" />
		</form>
</html>
