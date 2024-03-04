<html>
	<p> 
		This is a multiplication table!
	</p>
	<?php
		$number1=rand (0,12);
                $number2=rand (0,12);
		echo $number1 . "x" . $number2 . "="; 
	?>
		
		<form action="ex2.php" method = "POST">
			<input type= "hidden" name="number1" value="<?php echo $number1; ?>"/>
			<input type= "hidden" name ="number2" value="<?php echo $number2;?>"/>
			<input type= "number" name ="number3"/>
			<input type= "submit" value="Calculate!" />
		</form> 
		
</html>
