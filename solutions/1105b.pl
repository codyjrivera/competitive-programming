$_ = <>;
chomp;
@nk = split/ /;
my $k = @nk[1];
my $s = <>;
chomp $s;
my %levels;
for ('a'..'z') {
	$levels{$_} =()= $s =~ /${_}{${k}}/g;
}
my $max = 0;
for (%levels) {
	$max = $_ if $_ > $max;
}
print $max;
