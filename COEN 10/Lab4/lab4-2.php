<!--
	Vani Aggarwal
	T 9:15 to 12 PM
	#35375
	10/12/21
-->
<html>
	<?php
		$number1 = $_POST["number1"]; // receives numbers from second page
		$number2 = $_POST["number2"];
		$number3 = $_POST["number3"];
		$number4 = $_POST["number4"];
		$number5 = $_POST["number5"];

		$a = array(0, 0, 0, 0, 0); // creates array 
		$b = array($number1, $number2, $number3, $number4, $number5); // creates array with numbers from first page

		$count = 0;  // sets counter
		for ($i=0; $i<5; $i++) {   // begins for loop
			$a[$i] = rand(1,20); // inserts random numbers into array
			for ($j = $i-1; $j >=0; $j--) { // second for loop, going backwards
				if($a[$i] == $a[$j]) {  // compares elements in array
					$i--; 
					break; // stops second for loop
				}
			}
		} // end for loop


		for ($k=0; $k<5; $k++) { // for loop
		    for ($l=0; $l<5; $l++) { // start of nested for loop
			if ($a[$k] == $b[$l]) { // compares two arrays
			    $count +=1;
			}
		    } // end nested for loop
		} // end for loop

		echo "<p> Number of Matches: </p>" . $count; // shows number of matches

		echo "<p> Entered Numbers: </p>"; 
		for ($m=0; $m<5; $m++) { // start of for loop
		    echo $b[$m] . " ";  // shows the entered numbers 
		} // end for loop

		echo "<p> Numbers Generated: </p>";
		for ($n=0; $n<5; $n++) {  // start of for loop
		    echo $a[$n] . " ";   // shows the numbers generated
		} // end for loop
		
	?>

		<form method = "POST" action = "lab4.php">  <!-- takes user back to first page -->
			<input type = "submit" value = "Try Again" />
		</form>    
</html>
