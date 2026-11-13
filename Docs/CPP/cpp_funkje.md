bool czy_parzysta(int liczba) {
    return num % 2 == 0;
}

bool czy_palindrom(string slowo){
	for(int i=0;i<slowo.size()/2;i++)
		if(slowo[i]!=slowo[slowo.size()-i-1])
			return false;
	return true;
}

int suma_cyfr (int liczba){
	int suma=0;
	while(liczba>0){
		suma+=liczba%10;
		liczba/=10;
	}	
	return suma;
}

//funkcja sprawdzajaca, czy napis sklada sie ze znakow w kolejnosci rosnacej
bool czy_rosnaca(string napis){
	for(int i=0;i<napis.size()-1;i++)
		if(napis[i]>=napis[i+1])
			return false;
	return true;
}

bool czy_pierwsza(int liczba){
	if(liczba<2)
		false;
	for(int i=2;i*i<=liczba;i++) 
		if(liczba%i==0)
			return false;
	return true;
}
