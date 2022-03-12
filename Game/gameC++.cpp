#include<bits/stdc++.h>
#include"console.cpp"
using namespace std;

int sizeName,dem=0,luotChoi=0;
int score[4] = {100,200,500,1000};
int randomScore;
int size;

bool kt;

char nhap;


string cauHoi;
//"haohao","kokomi","gaudo","omachi","cungdinh"
vector<string> DSmiTom;
string miTom,tuDaDoan="";

void Nhap_Ten_Nguoi_Choi(vector<string> &Name,int &size)
{
	string name;
	cout << "Nhap so luong nguoi choi: ";
	cin >> size;
	cin.ignore();
	for(int i = 0 ; i < size ; i++)
	{
		cout << "Nhap ten nguoi choi thu " << i+1 << ": ";
		getline(cin,name);
		Name.push_back(name);
	}
}

void Doan_Chu_Cai(string &dau_,int &Diem_Nguoi_Choi)
{
	gotoxy(15,20);
	TextColor(9);
	cout<<"-->Doan chu cai: ";
	nhap = getche();
	tuDaDoan = tuDaDoan + " " + nhap;
	
	int xacNhan = 0;
	for(int i = 0 ; i < sizeName ; i++)
	{
		if(nhap == miTom[i] && dau_[i] == '_')
		{
			xacNhan++;
			
			Diem_Nguoi_Choi += randomScore;
			dau_[i] = nhap;
			dem++;
		}
	}
	
	if(xacNhan > 0)
	{
		kt = true;
	}	
	else
	{
		kt = false;
	}
}

void SelectionSort(vector<string> &Name , vector<int> &Score,int size)
{
	int indexMax;
	for(int i = 0 ; i < size-1 ; i++)
	{
		indexMax = i;
		for(int j = i+1 ;  j < size ; j++)
		{
			if(Score[indexMax] < Score[j])
			{
				indexMax = j;
			}
		}
		
		if(i != indexMax)
		{
			swap(Score[i],Score[indexMax]);
			swap(Name[i],Name[indexMax]);
		}
	}
}


void Doc_File(ifstream &filein,int size)
{
	getline(filein,cauHoi);
	
	string dapAn;
	while(!filein.eof())
	{
		filein >> dapAn;
		DSmiTom.push_back(dapAn);
	}
}

void Hien_Thi_1()
{
	TextColor(14);
	cout << "                                GGGGGGGGGGGGG               AAA               MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE" << endl;
	cout << "                             GGG::::::::::::G              A:::A              M:::::::M             M:::::::ME::::::::::::::::::::E" << endl;
	cout << "                           GG:::::::::::::::G             A:::::A             M::::::::M           M::::::::ME::::::::::::::::::::E" << endl;
	cout << "                          G:::::GGGGGGGG::::G            A:::::::A            M:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E" << endl;
	cout << "                         G:::::G       GGGGGG           A:::::::::A           M::::::::::M       M::::::::::M  E:::::E       EEEEEE" << endl;
	cout << "                        G:::::G                        A:::::A:::::A          M:::::::::::M     M:::::::::::M  E:::::E" << endl;             
	cout << "                        G:::::G                       A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE" << endl;   
	cout << "                        G:::::G    GGGGGGGGGG        A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M  E:::::::::::::::E" << endl;   
	cout << "                        G:::::G    G::::::::G       A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M  E:::::::::::::::E" << endl;   
	cout << "                        G:::::G    GGGGG::::G      A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE" << endl;   
	cout << "                        G:::::G        G::::G     A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M  E:::::E" << endl;             
	cout << "                         G:::::G       G::::G    A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M  E:::::E       EEEEEE" << endl;
	cout << "                          G:::::GGGGGGGG::::G   A:::::A             A:::::A   M::::::M               M::::::MEE::::::EEEEEEEE:::::E" << endl;
	cout << "                           GG:::::::::::::::G  A:::::A               A:::::A  M::::::M               M::::::ME::::::::::::::::::::E" << endl;
	cout << "                             GGG::::::GGG:::G A:::::A                 A:::::A M::::::M               M::::::ME::::::::::::::::::::E" << endl;
	cout << "                                GGGGGG   GGGGAAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE" << endl;
	cout << endl;
	TextColor(10); 
	cout << "                                                  ----> If you understand then PRESS ANY KEY TO START.";
	getch();
	system("cls");
}

void Hien_Thi_2()
{
	
	int x = rand()%(15-7+1) + 7;
	
	TextColor(x);
	
	int width= 79;
	int height = 30;
	for(int i = 0 ; i < width ; i++)
	{
		gotoxy(i,0);
		cout << "±";
		gotoxy(i,height-1);
		cout << "±";
	}
	for(int i = 0 ; i <height; i++)
	{
		gotoxy(width,i);
		cout << "±±";
		
	}
	
	for(int i = 1 ; i < height-1 ; i++)
	{
		gotoxy(0,i);
		cout << "±±";
	}
}

void Hien_Thi_Score(vector<string> Name,vector<int> Score)
{
	
	int r = 72;
	int l = 94;
	
	TextColor(9);
	gotoxy(l, r);cout<<"S";
	TextColor(11);
	gotoxy(l+1, r);cout<<"c";
	TextColor(12);
	gotoxy(l+2, r);cout<<"o";
	TextColor(13);
	gotoxy(l+3, r);cout<<"r";
	TextColor(10);
	gotoxy(l+4, r);cout<<"e: ";
	
	
	int gg = 72;
	TextColor(11);
	gotoxy(gg, r);cout<<"B";
	TextColor(12);
	gotoxy(gg+1, r);cout<<"X";
	TextColor(13);
	gotoxy(gg+2, r);cout<<"H";
	
	
	int y = 0;
	for(int i = 0 ; i < size ; i++)
	{
		TextColor(14);
		gotoxy(72,74 + y);
		cout << "Top " << i+1 << " " << Name[i];
		TextColor(11);
		gotoxy(94,74+y);
		cout << Score[i];
		y+=2;
	}
	
	int xx = 70;
	int yy = 70;
	TextColor(10);
	for(int i = 0 ; i< 34 ; i++)
	{
		gotoxy(xx+i , yy);
		cout << "±";
	}
	
	for(int i = 0 ; i< 34 ; i++)
	{
		gotoxy(xx+i , yy+19);
		cout << "±";
	}
	
	for(int i = 0 ; i< 20 ; i++)
	{
		gotoxy(xx-1,yy+i);
		cout << "±±";
	}
	
	for(int i = 0 ; i< 20 ; i++)
	{
		gotoxy(xx+33+1,yy+i);
		cout << "±±";
	}
	
	
}

int main()
{
	srand (time(NULL));
	
	ifstream filein;
	filein.open("CauHoi.txt");
	
	Hien_Thi_1();
	
	vector<string> Name;
	
	Nhap_Ten_Nguoi_Choi(Name,size);
	
	vector<int> Diem_Nguoi_Choi(size,0);
	
	Doc_File(filein,size);
	
	miTom = DSmiTom[rand()%5];
	
	sizeName = miTom.size();
	string dau_ (sizeName, '_');
	
	while(1)
	{
		system("cls");
		
		Hien_Thi_2();
		
		gotoxy(0,0);
		TextColor(11);
		cout<< "\n\n\t\t" << cauHoi << "\n\n\n";
		gotoxy(35,5);
		TextColor(8);
		for(int i=0; i<sizeName; i++)
			cout<<" "<<dau_[i]<<" "; 
		cout<<endl<<endl<<endl;
		
		TextColor(14);
		gotoxy(15,10);
		cout << "-Cac chu cai da doan: " << tuDaDoan;
		
		gotoxy(15,12);
		TextColor(12);
		cout << "--->Diem cua " << Name[luotChoi] << ": " << Diem_Nguoi_Choi[luotChoi];
		cout << endl << endl;
		if( dem == sizeName ){
			
			Diem_Nguoi_Choi[luotChoi] = 999999999;
			SelectionSort(Name,Diem_Nguoi_Choi,size);
			
			Hien_Thi_Score(Name,Diem_Nguoi_Choi);
			
			break;
		}
		gotoxy(15,14);
		TextColor(10);
		cout << "Luot choi cua: " << Name[luotChoi];
		randomScore = score[rand()%4];
		gotoxy(15,16);
		TextColor(13);
		cout << "-->Nhan phim bat ky de duoc diem ngau nhien !!!\n\t\t";
		getch();
		gotoxy(15,18);
		TextColor(7);
		cout << "--->Ban da dc thuong " << randomScore << " diem\n\n";
		
		Doan_Chu_Cai(dau_,Diem_Nguoi_Choi[luotChoi]);
		
		
		// reset Name
		if(!kt)
		{
			luotChoi++;
			if(luotChoi == Name.size())
				luotChoi = 0;
		}
	}
	
	
	
	filein.close();
	gotoxy(99,99);
	return 0;
}

