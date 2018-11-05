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
my $currentInfo = "";
my $currentInfo2 = "";
my $booltraite = 0;
my $curLivre = "";


my $fichierrapport = 'rapport.log';
open(my $fr, '>', $fichierrapport) or die "Ne peux pas ouvrir '$fichierrapport' $!";
print $fr "Rapport sur livre traite";

my $filename = 'crossref.xml';
if (open(my $fh, '<:encoding(UTF-8)',$filename) or die "Ne peux pas ouvrir '$filename' $!"){
	while (my $currentLine = <$fh>){
		chomp $currentLine;
		$source = $currentLine;
		#Iteration de l'entete
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
			#print "$livre[1]\n";
			traiterAllLivre();
		}
    }
}
#print Console
print "\nNombre de livre total : ".$nbLivre;
print "\nNombre de livre traite : ".$nbLivreTraite;
#print Fichier
print $fr "\nNombre de livre total : ".$nbLivre;
print $fr "\nNombre de livre traite : ".$nbLivreTraite;
print $fr "\nNombre de livre non traite : ".($nbLivre-$nbLivreTraite);

sub traiterAllLivre{
	my $current = 1;
	#Charge chaque livre individuellement
	until(!defined $livre[$current]){
		$nbLivre = $nbLivre+1;
		$curLivre = $livre[$current];
		traiterLivre();
		$current = $current+1;
	}

}

sub traiterLivre{
	$booltraite = 1;
	#Nom
	($currentInfo) = $curLivre =~ /<given_name>(.*?)<\/given_name>/;
	print $fr "\n"."Nom : ";
	if(defined $currentInfo and !($currentInfo eq "")){
		$currentInfo = uc $currentInfo;
		print $fr $currentInfo." ";
	}
	($currentInfo2) = $curLivre =~ /<surname>(.*?)<\/surname>/;
	if(defined $currentInfo2 and !($currentInfo2 eq "")){
		$currentInfo2 = uc $currentInfo2;
		print $fr $currentInfo2;
	}
	unless (defined $currentInfo or defined $currentInfo2) {
		$booltraite = 0;
	}
	#Titre
	($currentInfo) = $curLivre =~ /<title>(.*?)<\/title>/;
	print $fr "\n"."Titre : ";
	if(defined $currentInfo and !($currentInfo eq "")){
		print $fr $currentInfo;
	}else{
		$booltraite = 0;
	}
	($currentInfo) = $curLivre =~ /<subtitle>(.*?)<\/subtitle>/;	
	if(defined $currentInfo and !($currentInfo eq "")){
		print $fr " : ".$currentInfo;
	}
	#Annee
	($currentInfo) = $curLivre =~ /<year>(.*?)<\/year>/;
	print $fr "\n"."Année de parution : ";
	if(defined $currentInfo and !($currentInfo eq "")){
		print $fr $currentInfo;
	}else{
		$booltraite =0;
	}
	#Editeur
	($currentInfo) = $curLivre =~ /<publisher_name>(.*?)<\/publisher_name>/;
	print $fr "\n"."Editeur : ";
	if(defined $currentInfo and !($currentInfo eq "")){
		print $fr $currentInfo;
	}else{
		$booltraite =0;
	}
	#DOI
	($currentInfo) = $curLivre =~ /<doi>(.*?)<\/doi>/;
	print $fr "\n"."DOI : ";
	if(defined $currentInfo and !($currentInfo eq "")){
		print $fr $currentInfo;
	}else{
		$booltraite =0;
	}
	#Language
	($currentInfo) = $curLivre =~ /<book_metadata language="(.*?)"><contributors>/;
	print $fr "\n"."Langue : ";
	if(defined $currentInfo and !($currentInfo eq "")){
		if($currentInfo eq "fr"){
			print $fr 'Français';
		}
		
	}else{
		$booltraite =0;
	}

	print $fr "\n";
	unless($booltraite==0){
		$nbLivreTraite=$nbLivreTraite+1;
	}
}