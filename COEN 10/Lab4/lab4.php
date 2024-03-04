<!--
	Vani Aggarwal
	T 9:15 - 12 PM
	#35375
-->
<html>
	<h1> Lottery Game! </h1> <!--  header-->
	<p> Input 5 numbers from 1 to 20: </p> <!-- tells user to input numbers-->

	<form action="lab4-2.php" method = "POST"> <!-- reads 5 numbers from user and sends form to second page--> 
		<input type = "number" name = "number1" value="<php echo $number1; ?>"/>
	        <input type = "number" name = "number2" value="<php echo $number2; ?>"/>	
		<input type = "number" name = "number3" value="<php echo $number3; ?>"/>
	        <input type = "number" name = "number4" value="<php echo $number4; ?>"/>
	        <input type = "number" name = "number5" value="<php echo $number5; ?>"/>	
		<input type = "submit" value="Enter!" /> 
	</form>
</html>
