#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct Karta
{
	string znak;
	string wartosc;	
};

vector<Karta> talia_kart;

struct Gracz
{
	queue<Karta> Reka;
	stack<Karta> Stol;
	bool czy_wojna;
	bool czy_pusta_reka;
};

void nowaTalia()
{
	string znaki[4]={"kier","karo","pik","trefl"};
    string wartosci[13]={"2","3","4","5","6","7","8","9","10","W","D","K","A"};
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<13; j++)
		{
			struct Karta karta_talii;
			karta_talii.znak=znaki[i];
			karta_talii.wartosc=wartosci[j];
			talia_kart.push_back(karta_talii);
		}
	}
}

void Tasuj()
{
	random_shuffle(talia_kart.begin(),talia_kart.end());
}

void Rozdaj(int &liczba_graczy, Gracz Lista[])
{
	struct Karta karta_tymczasowa;
	int ilosc_kart=talia_kart.size();
	while(talia_kart.size()>ilosc_kart%liczba_graczy)
	{
		for(int i=0; i<liczba_graczy; i++)
		{
			karta_tymczasowa=talia_kart.front();
			talia_kart.front()=talia_kart.back();
			talia_kart.pop_back();
			Lista[i].Reka.push(karta_tymczasowa);
		}
	}
}

void Wyswietl(int &liczba_graczy, Gracz Lista[], bool &parzysty_ruch)
{
	for(int i=-1; i <= 9; i++)
	{
		for(int j=0; j<liczba_graczy; j++)
		{
			if(Lista[j].czy_pusta_reka)
			{
				if(i==0 || i==-1)
				{
					if(i==-1)
					{
						cout << "   Gracz " << j+1 << "   ";
					}
					else
					{
						cout << " Nie ma kart.";
					}					
				}
				else
				{
					cout << "             ";
				}
			}
			else
			{
			switch(i)
			{
				case -1:
				{
					cout << "  Gracz " << j+1 << "   ";
					break;
				}
				case 0: 
				{
					cout << " _________  ";
					break;
				}
				case 1: 
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						cout << "|         | ";
					}					
					break;
				}
				case 2: 
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						if(Lista[j].Stol.top().wartosc=="10")
						{
							cout << "|10       | ";
						}
						else
						{
							cout << "|" << Lista[j].Stol.top().wartosc << "        | ";
						}
					}
					break;
				}
				case 3:
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						if(Lista[j].Stol.top().znak == "kier") 
						{
					        cout << "|  #   #  | ";
					    }
					    else
						{
							if(Lista[j].Stol.top().znak == "karo")
							{
								cout << "|    #    | ";
							}
							else
							{
								if(Lista[j].Stol.top().znak == "trefl")
								{
									cout << "|   ###   | ";								
								}
								else
								{
									if(Lista[j].Stol.top().znak == "pik")
									{
										cout << "|    #    | ";
									}
								}
							}
					    }
					}	     
					break;	
				}
				case 4:
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						if(Lista[j].Stol.top().znak == "kier") 
						{
					        cout << "| ### ### | ";
					    }
					    else
						{
							if(Lista[j].Stol.top().znak == "karo")
							{
								cout << "|   ###   | ";
							}
							else
							{
								if(Lista[j].Stol.top().znak == "trefl")
								{
									cout << "| #__#__# | ";							
								}
								else
								{
									if(Lista[j].Stol.top().znak == "pik")
									{
										cout << "|   ###   | ";
									}
								}
							}
					    }
					}	     
					break;	
				}
				case 5:
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						if(Lista[j].Stol.top().znak == "kier") 
						{
					        cout << "|  #####  | ";
					    }
					    else
						{
							if(Lista[j].Stol.top().znak == "karo")
							{
								cout << "|  #####  | ";
							}
							else
							{
								if(Lista[j].Stol.top().znak == "trefl")
								{
									cout << "| #  |  # | ";							
								}
								else
								{
									if(Lista[j].Stol.top().znak == "pik")
									{
										cout << "|  #####  | ";
									}
								}
							}
					    }
					}	     
					break;	
				}
				case 6:
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						if(Lista[j].Stol.top().znak == "kier") 
						{
					        cout << "|   ###   | ";
					    }
					    else
						{
							if(Lista[j].Stol.top().znak == "karo")
							{
								cout << "|   ###   | ";
							}
							else
							{
								if(Lista[j].Stol.top().znak == "trefl")
								{
									cout << "|    |    | ";								
								}
								else
								{
									if(Lista[j].Stol.top().znak == "pik")
									{
										cout << "| ###|### | ";
									}
								}
							}
					    }
					}	     
					break;	
				}
				case 7:
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						if(Lista[j].Stol.top().znak == "kier") 
						{
					        cout << "|    #    | ";
					    }
					    else
						{
							if(Lista[j].Stol.top().znak == "karo")
							{
								cout << "|    #    | ";
							}
							else
							{
								if(Lista[j].Stol.top().znak == "trefl")
								{
									cout << "|  #####  | ";							
								}
								else
								{
									if(Lista[j].Stol.top().znak == "pik")
									{
										cout << "|  #_|_#  | ";
									}
								}
							}
					    }
					}	     
					break;	
				}
				case 8: 
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						if(Lista[j].Stol.top().wartosc=="10")
						{
							cout << "|       10| ";
						}
						else
						{
							cout << "|        " << Lista[j].Stol.top().wartosc << "| ";
						}
					}					
					break;
				}
				case 9:
				{
					if(Lista[j].czy_wojna && !parzysty_ruch)
					{
						cout << "|XXXXXXXXX| ";
					}
					else
					{
						cout << "|_________| ";
					}
					break;
				}
			}
		}
		}
		cout << endl;
	}
}

int zamianaWartosci(Gracz Lista[], int j)
{
	int wartosc_karty;
	if(Lista[j].Stol.top().wartosc=="W")
	{
		wartosc_karty=11;
	}
	else
	{
		if(Lista[j].Stol.top().wartosc=="D")
		{
			wartosc_karty=12;
		}
		else
		{
			if(Lista[j].Stol.top().wartosc=="K")
			{
				wartosc_karty=13;
			}
			else
			{
				if(Lista[j].Stol.top().wartosc=="A")
				{
					wartosc_karty=14;
				}
				else
				{
					wartosc_karty=atoi(Lista[j].Stol.top().wartosc.c_str());
				}
			}
		}
	}
	return wartosc_karty;
}

void Tura(int &liczba_graczy, Gracz Lista[])
{
	bool kolejny_ruch=true;
	bool parzysty_ruch=true;
	int max=0;
	int wygrany;
	while(kolejny_ruch)
	{
		if(parzysty_ruch)
		{
			max=0;
		}
		
		for(int i=0; i<liczba_graczy; i++)
		{
			if(!Lista[i].Reka.empty())
			{
				if(Lista[i].czy_wojna)
				{
					Lista[i].Stol.push(Lista[i].Reka.front());
					Lista[i].Reka.pop();
				}
				if(zamianaWartosci(Lista, i)>max && parzysty_ruch && Lista[i].czy_wojna)
				{
					max=zamianaWartosci(Lista, i);
				}
			}
			else
			{
				if(Lista[i].czy_wojna && parzysty_ruch)
				{
					kolejny_ruch=false;
				}
			}
		}
		
		int jedyny_max=0;
		if(parzysty_ruch)
		{
			for(int i=0; i<liczba_graczy; i++)
			{
				if(!Lista[i].czy_pusta_reka)
				{
					if(zamianaWartosci(Lista, i)==max && Lista[i].czy_wojna)
					{
						jedyny_max++;
					}
				}
			}
			
			for(int i=0; i<liczba_graczy; i++)
			{
				if(!Lista[i].czy_pusta_reka)
				{
					if(zamianaWartosci(Lista, i)==max && jedyny_max>1)
					{
						Lista[i].czy_wojna=true;
						kolejny_ruch=true;
						if(Lista[i].Reka.empty())
						{
							kolejny_ruch=false;
						}
					}
					else
					{
						if(jedyny_max==1 && Lista[i].czy_wojna)
						{
							kolejny_ruch=false;
						}
						else
						{
							Lista[i].czy_wojna=false;
							if(jedyny_max==1)
							{
								kolejny_ruch=false;
							}						
						}
					}
				}
			}
		}
		
		Wyswietl(liczba_graczy, Lista, parzysty_ruch);

		if(kolejny_ruch==false)
		{
			for(int i=0; i<liczba_graczy; i++)
			{
				if(!Lista[i].czy_pusta_reka && zamianaWartosci(Lista, i)==max && Lista[i].czy_wojna)
				{
					cout << endl << "Ture wygral gracz " << i+1 << endl << endl;
					wygrany=i;
				}
			}
		}
		
		if(parzysty_ruch)
		{
			parzysty_ruch=false;
		}
		else
		{
			parzysty_ruch=true;
		}
	}
	
	int kolejnosc=rand()%2;
	if(kolejnosc==1)
	{
		for(int i=0; i<liczba_graczy; i++)
		{
			while(!Lista[i].Stol.empty())
			{
				Lista[wygrany].Reka.push(Lista[i].Stol.top());
				Lista[i].Stol.pop();
			}
		}
	}
	else
	{
		for(int i=liczba_graczy-1; i>=0; i--)
		{
			while(!Lista[i].Stol.empty())
			{
				Lista[wygrany].Reka.push(Lista[i].Stol.top());
				Lista[i].Stol.pop();
			}
		}
	}
}

void start()
{
	int liczba_graczy,liczba_talii, automatyczny;
	int kolejna=1;
	int jest_pusta=0;
	bool czy_dalej=true;
	bool tylko_jeden=false;
	do
	{
		cout << "Podaj ilosc graczy(od 2 do 52): ";
		cin >> liczba_graczy;
		cout << endl << "Ile talii kart chcesz uzyc w grze(od 1 do 10): ";
		cin >> liczba_talii;
		cout << endl << "Tryb automatyczny czy manualny(1 lub 0): ";
		cin >> automatyczny;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore( 1000, '\n' );
		}
		cout << endl;
		if((liczba_talii*52)/liczba_graczy<4)
		{
			cout << "Za malo talii dla tylu graczy(co najmniej 4 karty dla kazdego gracza)" << endl << endl;
		}
	}while( liczba_graczy<2 || liczba_graczy>52 || liczba_talii<1 || liczba_talii>10 || (liczba_talii*52)/liczba_graczy<4 || !(automatyczny==0 || automatyczny==1) || cin.fail());
	
	for(int i=1; i<=liczba_talii; i++)
	{
		nowaTalia();
	}
	Tasuj();
	Gracz Lista[liczba_graczy];
	Rozdaj(liczba_graczy, Lista);
	for(int i=0; i<liczba_graczy; i++)
	{
		Lista[i].czy_pusta_reka=false;
	}
	while(!tylko_jeden && czy_dalej)
	{
		for(int i=0; i<liczba_graczy; i++)
		{
			Lista[i].czy_wojna=true;
		}
		
		Tura(liczba_graczy, Lista);
		
		if(automatyczny==0)
		{
			do
			{
				cin.clear();
				cin.ignore( 1000, '\n' );
				cout << "Czy nastepna tura(1 lub 0): ";
				cin >> kolejna;
				cout << endl;
			}while(!(kolejna==0 || kolejna==1) || cin.fail());
			
			if(kolejna==1)
			{
				czy_dalej=true;
			}
			else
			{
				czy_dalej=false;
			}
		}
		
		for(int i=0; i<liczba_graczy; i++)
		{
			if(Lista[i].Reka.empty() && !Lista[i].czy_pusta_reka)
			{
				jest_pusta++;
				Lista[i].czy_pusta_reka=true;
				if(jest_pusta==liczba_graczy-1)
				{
					cout << "Gracz " << i+1 << " nie ma juz kart!" << endl;
				}
			}
			if(jest_pusta==liczba_graczy-1)
			{
				tylko_jeden=true;
			}
			else
			{
				tylko_jeden=false;
			}	
		}
	}
	
	if(czy_dalej)
	{
		for(int i=0; i<liczba_graczy; i++)
		{
			if(!Lista[i].czy_pusta_reka)
			{
				cout <<  endl << "Wojne wygral gracz " << i+1 << " !" << endl;
			}	
		}
	}
	else
	{
		cout << endl << "Przerwano gre!" << endl;
	}
}

int main()
{
	srand(time(NULL));
	start();
}
