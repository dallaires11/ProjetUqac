use strict;
use warnings;
use XML::Simple;
use Data::Dumper;

my $indice = 0;
my $wanted1 = "";
my $wanted2 = "";
my $source = "";
my @livre;
my $nbLivre = 0;
my $nbLivreTraite = 0;

#traiterAllLivre();
#traiterLivre();

my $fichierrapport = 'rapport.log';
open(my $fr, '>', $fichierrapport) or die "Ne peux pas ouvrir '$fichierrapport' $!";
print $fr "Rapport sur livre traite";

my $filename = 'crossref.xml';
if (open(my $fh, '<:encoding(UTF-8)',$filename) or die "Ne peux pas ouvrir '$filename' $!"){
	while (my $currentLine = <$fh>){
		chomp $currentLine;
		$source = $currentLine;
		($wanted1) = $source =~ /<head>(.*?)<\/head>/;
		if(defined $wanted1){
			($wanted2) = $wanted1 =~ /<doi_batch_id>(.*?)<\/doi_batch_id>/;
			print $fr "\n"."ID					:";
			if(defined $wanted2){
				print $fr $wanted2;
			}
			($wanted2) = $wanted1 =~ /<timestamp>(.*?)<\/timestamp>/;
			print $fr "\n"."Timestamp			:";
			if(defined $wanted2){
				print $fr $wanted2;
			}
			($wanted2) = $wanted1 =~ /<name>(.*?)<\/name>/;
			print $fr "\n"."Nom de l'empoye		:";
			if(defined $wanted2){
				print $fr $wanted2;
			}
			($wanted2) = $wanted1 =~ /<email_address>(.*?)<\/email_address>/;
			print $fr "\n"."Email de l'employe	:";
			if(defined $wanted2){
				print $fr $wanted2;
			}
			($wanted2) = $wanted1 =~ /<registrant>(.*?)<\/registrant>/;
			print $fr "\n"."registrant			:";
			if(defined $wanted2){
				print $fr $wanted2;
			}

			print $fr "\n\n";
		}
		($wanted1) = $source =~ /<body>(.*?)<\/body>/;
		if(defined $wanted1){
			@livre = split(/<book book/, $wanted1);
			
			traiterAllLivre();
		}
		
			
  }
}

sub traiterAllLivre{
	my $test=0;
	print $test;
	unless(defined $livre[$test]){
		print $test;
		print "$livre[0]\n";
		$test = $test+1;
	}
#	if(defined @mesLivreAtraite){
#		print "$mesLivreAtraite[1]\n";
	#}
	
	#print 'a';
}

sub traiterLivre{
	my $livreAtraite = shift;

}