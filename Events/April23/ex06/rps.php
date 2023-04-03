<?php
	// MACHINE'S SELECTION
	$machine = (int) rand(0, 2);
	if ( $machine == 0 ) { $machine = "rock"; }
	else if ( $machine == 1 ) { $machine = "paper"; }
	else { $machine = "scissors"; }

	// USER'S SELECTION
	$input = strtolower((string) readline("Choose 'rock', 'paper', or 'scissors': "));
	if ( $input != "rock" && $input != "paper" && $input != "scissors" )
	{
		print("This is not a valid option!\n");
		return;
	}

	// WINNER DECLRATION
	if ( $input == $machine	)
		{ printf("Sorry, this is a tie. The computer chose %s.\n", $machine); }
	else if ( ( $input == "rock" && $machine == "scissors" )
		|| ( $input == "scissors" && $machine == "paper" )
		|| ( $input == "paper" && $machine == "rock" ) )
		{ printf("Congratulations! You won! The computer chose %s.\n", $machine); }
	else
		{ printf("Sorry, you lost. The computer chose %s.\n", $machine); }
?>