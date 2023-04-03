# PROMPT
print "Enter a string: ";
chomp(my $input = <>);

# CASE INSENSITIVE
$rev = lc reverse($input);
$for = lc $input;

# OUTPUT
if ( $for eq $rev )
	{ print "The string is a palindrome!\n"; }
else
	{ print "The string is not a palindrome.\n"; }
