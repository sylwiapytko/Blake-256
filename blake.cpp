#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <fstream>
//#include <cstdlib>
#include <math.h>
using namespace std;

unsigned long int tabslow[272];//1024*8/32 +512/32 1kBwiadomoœci *8bitów /dl slowa + 16 slow ewentualnego paddingu
unsigned long int DlWiad;
unsigned long int nrslowa;
unsigned long int poczWartosc[8];// pozniej h
unsigned long int stala[16];
int permutacje[14][16];
unsigned long int sol[4];
unsigned long int v[4][4];
unsigned long int licznik;

void przySol()
{
    sol[0]=0;
    sol[1]=0;
    sol[2]=0;
    sol[3]=0;

}
void przypPoczWartosci()
{
    poczWartosc[0]=3238371032;//C1059ED8
    poczWartosc[1]=914150663; //367CD507
    poczWartosc[2]=812702999; //3070DD17
    poczWartosc[3]=4144912697;//F70E5939
    poczWartosc[4]=4290775857;//FFC00B31
    poczWartosc[5]=1750603025;//68581511
    poczWartosc[6]=1694076839;//64F98FA7
    poczWartosc[7]=3204075428;//BEFA4FA4
}
void przypStale()
{
    stala[0]=608135816; //243F6A88
    stala[1]=2242054355;//85A308D3
    stala[2]=320440878; //13198A2E
    stala[3]=57701188;  //03707344
    stala[4]=2752067618;//A4093822
    stala[5]=698298832; //299F31D0
    stala[6]=137296536; //082EFA98
    stala[7]=3964562569;//EC4E6C89
    stala[8]=1160258022;//452821E6
    stala[9]=953160567; //38D01377
    stala[10]=3193202383;//BE5466CF
    stala[11]=887688300; //34E90C6C
    stala[12]=3232508343;//C0AC29B7
    stala[13]=3380367581;//C97C50DD
    stala[14]=1065670069;//3F84D5B5
    stala[15]=3041331479;//B5470917


}
void przypPermutacje()
{
    permutacje[0][0]=0;
    permutacje[0][1]=1;
    permutacje[0][2]=2;
    permutacje[0][3]=3;
    permutacje[0][4]=4;
    permutacje[0][5]=5;
    permutacje[0][6]=6;
    permutacje[0][7]=7;
    permutacje[0][8]=8;
    permutacje[0][9]=9;
    permutacje[0][10]=10;
    permutacje[0][11]=11;
    permutacje[0][12]=12;
    permutacje[0][13]=13;
    permutacje[0][14]=14;
    permutacje[0][15]=15;

    permutacje[1][0]=14;
    permutacje[1][1]=10;
    permutacje[1][2]=4;
    permutacje[1][3]=8;
    permutacje[1][4]=9;
    permutacje[1][5]=15;
    permutacje[1][6]=13;
    permutacje[1][7]=6;
    permutacje[1][8]=1;
    permutacje[1][9]=12;
    permutacje[1][10]=0;
    permutacje[1][11]=2;
    permutacje[1][12]=11;
    permutacje[1][13]=7;
    permutacje[1][14]=5;
    permutacje[1][15]=3;

    permutacje[2][0]=11;
    permutacje[2][1]=8;
    permutacje[2][2]=12;
    permutacje[2][3]=0;
    permutacje[2][4]=5;
    permutacje[2][5]=2;
    permutacje[2][6]=15;
    permutacje[2][7]=13;
    permutacje[2][8]=10;
    permutacje[2][9]=14;
    permutacje[2][10]=3;
    permutacje[2][11]=6;
    permutacje[2][12]=7;
    permutacje[2][13]=1;
    permutacje[2][14]=9;
    permutacje[2][15]=4;

    permutacje[3][0]=7;
    permutacje[3][1]=9;
    permutacje[3][2]=3;
    permutacje[3][3]=1;
    permutacje[3][4]=13;
    permutacje[3][5]=12;
    permutacje[3][6]=11;
    permutacje[3][7]=14;
    permutacje[3][8]=2;
    permutacje[3][9]=6;
    permutacje[3][10]=5;
    permutacje[3][11]=10;
    permutacje[3][12]=4;
    permutacje[3][13]=0;
    permutacje[3][14]=15;
    permutacje[3][15]=8;

    permutacje[4][0]=9;
    permutacje[4][1]=0;
    permutacje[4][2]=5;
    permutacje[4][3]=7;
    permutacje[4][4]=2;
    permutacje[4][5]=4;
    permutacje[4][6]=10;
    permutacje[4][7]=15;
    permutacje[4][8]=14;
    permutacje[4][9]=1;
    permutacje[4][10]=11;
    permutacje[4][11]=12;
    permutacje[4][12]=6;
    permutacje[4][13]=8;
    permutacje[4][14]=3;
    permutacje[4][15]=13;

    permutacje[5][0]=2;
    permutacje[5][1]=12;
    permutacje[5][2]=6;
    permutacje[5][3]=10;
    permutacje[5][4]=0;
    permutacje[5][5]=11;
    permutacje[5][6]=8;
    permutacje[5][7]=3;
    permutacje[5][8]=4;
    permutacje[5][9]=13;
    permutacje[5][10]=7;
    permutacje[5][11]=5;
    permutacje[5][12]=15;
    permutacje[5][13]=14;
    permutacje[5][14]=1;
    permutacje[5][15]=9;

    permutacje[6][0]=12;
    permutacje[6][1]=5;
    permutacje[6][2]=1;
    permutacje[6][3]=15;
    permutacje[6][4]=14;
    permutacje[6][5]=13;
    permutacje[6][6]=4;
    permutacje[6][7]=10;
    permutacje[6][8]=0;
    permutacje[6][9]=7;
    permutacje[6][10]=6;
    permutacje[6][11]=3;
    permutacje[6][12]=9;
    permutacje[6][13]=2;
    permutacje[6][14]=8;
    permutacje[6][15]=11;

    permutacje[7][0]=13;
    permutacje[7][1]=11;
    permutacje[7][2]=7;
    permutacje[7][3]=14;
    permutacje[7][4]=12;
    permutacje[7][5]=1;
    permutacje[7][6]=3;
    permutacje[7][7]=9;
    permutacje[7][8]=5;
    permutacje[7][9]=0;
    permutacje[7][10]=15;
    permutacje[7][11]=4;
    permutacje[7][12]=8;
    permutacje[7][13]=6;
    permutacje[7][14]=2;
    permutacje[7][15]=10;

    permutacje[8][0]=6;
    permutacje[8][1]=15;
    permutacje[8][2]=14;
    permutacje[8][3]=9;
    permutacje[8][4]=11;
    permutacje[8][5]=3;
    permutacje[8][6]=0;
    permutacje[8][7]=8;
    permutacje[8][8]=12;
    permutacje[8][9]=2;
    permutacje[8][10]=13;
    permutacje[8][11]=7;
    permutacje[8][12]=1;
    permutacje[8][13]=4;
    permutacje[8][14]=10;
    permutacje[8][15]=5;

    permutacje[9][0]=10;
    permutacje[9][1]=2;
    permutacje[9][2]=8;
    permutacje[9][3]=4;
    permutacje[9][4]=7;
    permutacje[9][5]=6;
    permutacje[9][6]=1;
    permutacje[9][7]=5;
    permutacje[9][8]=15;
    permutacje[9][9]=11;
    permutacje[9][10]=9;
    permutacje[9][11]=14;
    permutacje[9][12]=3;
    permutacje[9][13]=12;
    permutacje[9][14]=13;
    permutacje[9][15]=0;

    permutacje[10][0]=0;
    permutacje[10][1]=1;
    permutacje[10][2]=2;
    permutacje[10][3]=3;
    permutacje[10][4]=4;
    permutacje[10][5]=5;
    permutacje[10][6]=6;
    permutacje[10][7]=7;
    permutacje[10][8]=8;
    permutacje[10][9]=9;
    permutacje[10][10]=10;
    permutacje[10][11]=11;
    permutacje[10][12]=12;
    permutacje[10][13]=13;
    permutacje[10][14]=14;
    permutacje[10][15]=15;

    permutacje[11][0]=14;
    permutacje[11][1]=10;
    permutacje[11][2]=4;
    permutacje[11][3]=8;
    permutacje[11][4]=9;
    permutacje[11][5]=15;
    permutacje[11][6]=13;
    permutacje[11][7]=6;
    permutacje[11][8]=1;
    permutacje[11][9]=12;
    permutacje[11][10]=0;
    permutacje[11][11]=2;
    permutacje[11][12]=11;
    permutacje[11][13]=7;
    permutacje[11][14]=5;
    permutacje[11][15]=3;

    permutacje[12][0]=11;
    permutacje[12][1]=8;
    permutacje[12][2]=12;
    permutacje[12][3]=0;
    permutacje[12][4]=5;
    permutacje[12][5]=2;
    permutacje[12][6]=15;
    permutacje[12][7]=13;
    permutacje[12][8]=10;
    permutacje[12][9]=14;
    permutacje[12][10]=3;
    permutacje[12][11]=6;
    permutacje[12][12]=7;
    permutacje[12][13]=1;
    permutacje[12][14]=9;
    permutacje[12][15]=4;

    permutacje[13][0]=7;
    permutacje[13][1]=9;
    permutacje[13][2]=3;
    permutacje[13][3]=1;
    permutacje[13][4]=13;
    permutacje[13][5]=12;
    permutacje[13][6]=11;
    permutacje[13][7]=14;
    permutacje[13][8]=2;
    permutacje[13][9]=6;
    permutacje[13][10]=5;
    permutacje[13][11]=10;
    permutacje[13][12]=4;
    permutacje[13][13]=0;
    permutacje[13][14]=15;
    permutacje[13][15]=8;

}

long int naLiczbe(char znak)
{

   // cout<< "jestem w NaLiczbe pobrana znak  to "<< znak<< endl;
    long int liczba;
    switch(znak)
		{
			case '0':{
					liczba=0;
					break;
					}
			case '1':{
					liczba=1;
					break;
					}
			case '2':{
					liczba=2;
					break;
					}
			case '3':{
					liczba=3;
					break;
					}
			case '4':{
					liczba=4;
					break;
					}
			case '5':{
					liczba=5;
					break;
					}
			case '6':{
					liczba=6;
					break;
					}
			case '7':{
					liczba=7;
					break;
					}
			case '8':{
					liczba=8;
					break;
					}
			case '9':{
					liczba=9;
					break;
					}
			case 'A':{
					liczba=10;
					break;
					}
			case 'B':{
					liczba=11;
					break;
					}
			case 'C':{
					liczba=12;
					break;
					}
			case 'D':{
					liczba=13;
					break;
					}
			case 'E':{
					liczba=14;
					break;
					}
			case 'F':{
					liczba=15;
					break;
					}
            case 'a':{
					liczba=10;
					break;
					}
			case 'b':{
					liczba=11;
					break;
					}
			case 'c':{
					liczba=12;
					break;
					}
			case 'd':{
					liczba=13;
					break;
					}
			case 'e':{
					liczba=14;
					break;
					}
			case 'f':{
					liczba=15;
					break;
					}
	}

//cout<< "koncze naLiczbe wyszlo"<< liczba<< endl;
    return liczba;
}
void inicjalizacja(char** argv)
{
    long int nrznaku=0;
    nrslowa=0;
    long int czterobit=0;
    long int potega=0;
    long int pobrana=1;
    long int straznik;
    //cout << "Inicjalizacja pobranej "<< pobrana << endl;
    for(int b=0;b<272;b++)//zeruje tablice
    {
        tabslow[b]=0;
    }
    while(argv[1][nrznaku]!='\0')
    {

        czterobit=nrznaku%8;
        potega= 32-4*(czterobit+1);
       // cout<<"Element nr:"<<nrznaku<<" Czterobit="<< czterobit<<" poega="<< potega<<endl;

       pobrana=naLiczbe(argv[1][nrznaku]);

       // cout <<"Argumentem jest to podane "<< argv[1][nrznaku]<< " to liczba "<< pobrana<< endl;

        tabslow[nrslowa]=tabslow[nrslowa]+(pobrana*pow(2,potega));


        if( czterobit==7 && argv[1][nrznaku+1]!='\0')
        {
         //   cout<< "slowo nr "<<nrslowa<< "  rowna sie "<< tabslow[nrslowa]<< endl<<endl;
         //   cout<< "podbijam slowo z "<< nrslowa<< " na "<< nrslowa+1<< endl<<endl;
            nrslowa+=1;

        }
    nrznaku++;
    }
    DlWiad = nrznaku*4;
    long int DlwOstBloku=DlWiad%512;
   //  cout<< "Dlugosc wiadomosci "<< DlWiad<< " Dlugosc wiadomosci w ostatnim bloku"<< DlwOstBloku<< endl<<endl;

     if(DlwOstBloku==0)
     {
      //   cout <<"Blok idealnie sie skonczyl"<<endl;
         nrslowa+=1;
         tabslow[nrslowa]=pow(2,31);
       //  cout<< "slowo nr bedace 1 w paddingu "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
         nrslowa+=1;
         straznik=nrslowa+12;
       //  cout<< "Uzupelniam zerami od slowa "<< nrslowa<< " do "<< straznik<< endl;
         for(nrslowa; nrslowa<=straznik; nrslowa++)
         {
             tabslow[nrslowa]=0;
        //     cout<< "slowo nr bedace paddingiem "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;

         }
       // nrslowa+=1;//przeostatnie slowwo <---- cos jest nie tak, czy ma byc czy nie
         tabslow[nrslowa]=DlWiad-DlWiad%(long unsigned int)pow(2,31);
       //  cout<< "slowo nr bedace dlwiad "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
         nrslowa+=1;//ostatnie slowo
         tabslow[nrslowa]=DlWiad%(long unsigned int)pow(2,31);
       //  cout<< "slowo nr bedoce dl wiad "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;

     }
     else if(512-DlwOstBloku<65)
     {
      //   cout <<"Zostalo mniej niz 65 w bloku"<<endl;
         czterobit=nrznaku%8;// poprzeddni nrznaku+1
        potega= 31-4*czterobit;
       // cout<<" Czterobit="<< czterobit<<" poega="<< potega<<endl;
        if( czterobit==0 )
        {

        //    cout<< "podbijam slowo z "<< nrslowa<< " na "<< nrslowa+1<< endl<<endl;
            nrslowa+=1;

        }
     //   cout<< "ostatnie slowo  wiadomoscinr "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
        tabslow[nrslowa]=tabslow[nrslowa]+pow(2,potega);
     //   cout<< "ostatnie slowo wiadomosci z dodana 1 nr  "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;

        if (nrslowa%16==13)
        {
            nrslowa+=1;
            tabslow[nrslowa]=0;
       //     cout<< "slowo nr bedace paddingiem "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
            nrslowa+=1;
            tabslow[nrslowa]=0;
        //    cout<< "slowo nr bedace paddingiem "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
        }
        else if(nrslowa%16==14)
        {
            nrslowa+=1;
            tabslow[nrslowa]=0;
        //    cout<< "slowo nr bedace paddingiem "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
        }
        nrslowa+=1;//nowy blok
        straznik=nrslowa+13;

         for(nrslowa; nrslowa<=straznik; nrslowa++)
         {
             tabslow[nrslowa]=0;
       //      cout<< "slowo nr bedace paddingiem "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;

         }

         tabslow[nrslowa]=DlWiad-DlWiad%(long unsigned int)pow(2,31);
       //  cout<< "slowo nr bedace dlwiad"<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
         nrslowa+=1;//ostatnie slowo
         tabslow[nrslowa]=DlWiad%(long unsigned int)pow(2,31);
        // cout<< "slowo nr bedoce dl wiad "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
     }
     else// zostało więcej niż 65
    {
    //    cout <<"Zostalo wiecej niz 65 w bloku"<<endl;
         czterobit=nrznaku%8;// poprzeddni nrznaku+1
        potega= 31-4*czterobit;
     //   cout<<" Czterobit="<< czterobit<<" poega="<< potega<<endl;
        if( czterobit==0 )
        {

      //      cout<< "podbijam slowo z "<< nrslowa<< " na "<< nrslowa+1<< endl<<endl;
            nrslowa+=1;

        }
      //  cout<< "ostatnie slowo  wiadomoscinr "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
        tabslow[nrslowa]=tabslow[nrslowa]+pow(2,potega);
      //  cout<< "ostatnie slowo wiadomosci z dodana 1 nr  "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;

        nrslowa+=1;
        if(nrslowa%16==14)//ktore słowo- juz dl wiadomosci
        {
        tabslow[nrslowa]=DlWiad-DlWiad%(long unsigned int)pow(2,31);
     //    cout<< "slowo nr bedace dlwiad"<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
         nrslowa+=1;//ostatnie slowo
         tabslow[nrslowa]=DlWiad%(long unsigned int)pow(2,31);
     //    cout<< "slowo nr bedoce dl wiad "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
        }
        else
            {
                straznik= nrslowa+ (13-(nrslowa%16));
                for(nrslowa; nrslowa<=straznik; nrslowa++)
                {
                tabslow[nrslowa]=0;
          //      cout<< "slowo nr bedace paddingiem "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;

                }
                tabslow[nrslowa]=DlWiad-DlWiad%(long unsigned int)pow(2,31);
           //      cout<< "slowo nr bedace dlwiad"<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
                 nrslowa+=1;//ostatnie slowo
                 tabslow[nrslowa]=DlWiad%(long unsigned int)pow(2,31);
            //     cout<< "slowo nr bedoce dl wiad "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<< endl<<endl;
            }
     }

}
void wiadPusta()
{
     nrslowa=0;
    DlWiad=0;
    tabslow[nrslowa]=pow(2,31);
   // cout<< "slowo bedące tylko 1 nr "<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<<endl;
    nrslowa+=1;
    for(nrslowa; nrslowa<=15;nrslowa++)
    {
        tabslow[nrslowa]=0;
      //  cout<< "slowo nr"<<nrslowa<< " obecnie rowna sie "<< tabslow[nrslowa]<<endl;
    }
    nrslowa-=1;
   // cout<< "jest tyle slow"<<nrslowa<<endl<<endl;
}

void sprawdzenieWiad()
{
    int c;
    for(c=0; c<=nrslowa; c++)
    {
        cout<< "slowo nr "<<c<< "  rowna sie "<< tabslow[c]<<endl;
    }
}
void oblLicznik(int ktoryBlok)
{
    int a;
    a=DlWiad/((ktoryBlok+1)*512);
    if(a==0)
    {
        if((ktoryBlok+1)*512>=DlWiad+512)
        {
            licznik=0;
        }
        else
        {
            licznik+=(DlWiad%512);
        }
    }
    else
    {
        licznik+=512;
    }
   // cout<< "licznik"<< licznik<< endl;
}
void przypV()
{
    unsigned long int licznik1=0;
    //sol=0;
    //przypisuje vki
    v[0][0]=poczWartosc[0];
    v[0][1]=poczWartosc[1];
    v[0][2]=poczWartosc[2];
    v[0][3]=poczWartosc[3];

    v[1][0]=poczWartosc[4];
    v[1][1]=poczWartosc[5];
    v[1][2]=poczWartosc[6];
    v[1][3]=poczWartosc[7];

    v[2][0]=(sol[0]^stala[0]);
    v[2][1]=(sol[1]^stala[1]);
    v[2][2]=(sol[2]^stala[2]);
    v[2][3]=(sol[3]^stala[3]);

    v[3][0]=(licznik^stala[4]);
    v[3][1]=(licznik^stala[5]);
    v[3][2]=(licznik1^stala[6]);
    v[3][3]=(licznik1^stala[7]);

}
void sprawdzenieV(int ktoryBlok)
{
    cout<<"nr Bloku"<<ktoryBlok<<endl;
    cout<<v[0][0]<<" "<<v[0][1]<<" "<<v[0][2]<<" "<<v[0][3]<<endl;
    cout<<v[1][0]<<" "<<v[1][1]<<" "<<v[1][2]<<" "<<v[1][3]<<endl;
    cout<<v[2][0]<<" "<<v[2][1]<<" "<<v[2][2]<<" "<<v[2][3]<<endl;
    cout<<v[3][0]<<" "<<v[3][1]<<" "<<v[3][2]<<" "<<v[3][3]<<endl;

}
void funkcjaG(int wa, int ka, int wb, int kb, int wc, int kc, int wd, int kd, int nrRundy, int nrG, int ktoryBlok)
{
 //   cout <<"nr rundy "<< nrRundy<<" nr g "<< nrG<<endl;
    int indeks=permutacje[nrRundy][2*nrG];
    int indeks2=permutacje[nrRundy][2*nrG+1];
   // cout <<"indeks "<< indeks<<" indeks2 "<< indeks2<< endl;


    unsigned long int a;
    unsigned long int b;
    unsigned long int c;
    unsigned long int d;
    unsigned long int mc;

    a=v[wa][ka];
    b=v[wb][kb];
    c=v[wc][kc];
    d=v[wd][kd];
   // cout  <<" a "<< a<<" b "<<b<<" c "<< c<<" d "<<d<<endl;
   // cout  <<"slowo "<<tabslow[indeks+(ktoryBlok*16)]<<" slala "<<stala[indeks2]<<endl;
    //cout <<"xor " (tabslow[indeks+(ktoryBlok*16)]^stala[indeks2])<<endl;
    mc=(tabslow[indeks+(ktoryBlok*16)]^stala[indeks2]);
   // cout<<" mc "<<mc;
    a=a+b+mc;
   // cout<<" a "<<a<<endl;

    d=(d^a);
   // cout<<" d "<<d;
    d=d>>16|d<<16;
   // cout<<" d "<<d<<endl;

    c=c+d;
   // cout<<" c "<<c<<endl;

    b=(b^c);
  //  cout<<" b "<<b;
    b=b>>12|b<<20;
   // cout<<" b "<<b<<endl;

    mc=(tabslow[indeks2+(ktoryBlok*16)]^stala[indeks]);
 //   cout<<" mc "<<mc;
    a=a+b+mc;
  //  cout<<" a "<<a<<endl;

    d=(d^a);
  //  cout<<" d "<<d;
    d=d>>8|d<<24;
  //  cout<<" d "<<d<<endl;

    c=c+d;
  //  cout<<" c "<<c<<endl;

    b=(b^c);
  //  cout<<" b "<<b;
    b=b>>7|b<<25;
  //  cout<<" b "<<b<<endl;


    v[wa][ka]=a;
    v[wb][kb]=b;
    v[wc][kc]=c;
    v[wd][kd]=d;










}
void fRundy(int ktoryBlok)
{
    oblLicznik(ktoryBlok);
    przypV();
    //sprawdzenieV(ktoryBlok);
    for(int f=0; f<14;f++)
    {
    funkcjaG(0,0,1,0,2,0,3,0,f,0,ktoryBlok);//4xv nr rundy, nr G, króry blok
    funkcjaG(0,1,1,1,2,1,3,1,f,1,ktoryBlok);
    funkcjaG(0,2,1,2,2,2,3,2,f,2,ktoryBlok);
    funkcjaG(0,3,1,3,2,3,3,3,f,3,ktoryBlok);

    funkcjaG(0,0,1,1,2,2,3,3,f,4,ktoryBlok);
    funkcjaG(0,1,1,2,2,3,3,0,f,5,ktoryBlok);
    funkcjaG(0,2,1,3,2,0,3,1,f,6,ktoryBlok);
    funkcjaG(0,3,1,0,2,1,3,2,f,7,ktoryBlok);

    //sprawdzenieV();

    }

    //sprawdzenieV(ktoryBlok);

    poczWartosc[0]=poczWartosc[0]^sol[0]^v[0][0]^v[2][0];
    poczWartosc[1]=poczWartosc[1]^sol[1]^v[0][1]^v[2][1];
    poczWartosc[2]=poczWartosc[2]^sol[2]^v[0][2]^v[2][2];
    poczWartosc[3]=poczWartosc[3]^sol[3]^v[0][3]^v[2][3];

    poczWartosc[4]=poczWartosc[4]^sol[0]^v[1][0]^v[3][0];
    poczWartosc[5]=poczWartosc[5]^sol[1]^v[1][1]^v[3][1];
    poczWartosc[6]=poczWartosc[6]^sol[2]^v[1][2]^v[3][2];
    poczWartosc[7]=poczWartosc[7]^sol[3]^v[1][3]^v[3][3];

   // cout <<" "<<poczWartosc[0]<<" "<<poczWartosc[1]<<" "<<poczWartosc[2]<<" "<<poczWartosc[3]<<endl;
   // cout <<" "<<poczWartosc[4]<<" "<<poczWartosc[5]<<" "<<poczWartosc[6]<<" "<<poczWartosc[7]<<endl;






}

void szesnas()
{


}
int main(int argc, char** argv)
{

    //cout << "Argumentem jest to podane "<< argv[1] << endl;
if(argv[1]!=NULL)
   inicjalizacja(argv);
else
{
    wiadPusta();
}

//sprawdzenieWiad();

przypPoczWartosci();// początkowe h
przypStale();
przypPermutacje();


licznik=0;
int iloscBlokow=(nrslowa/16);//indeksowanie od 0
//cout<< "iloscBlokow "<< iloscBlokow<< endl;
for(int e=0; e<=iloscBlokow; e++)
{
    fRundy(e);
}


szesnas();
cout.setf( ios::hex, ios::basefield );
cout <<endl<<" "<<poczWartosc[0]<<" "<<poczWartosc[1]<<" "<<poczWartosc[2]<<" "<<poczWartosc[3];
    cout <<" "<<poczWartosc[4]<<" "<<poczWartosc[5]<<" "<<poczWartosc[6]<<endl;

    return 0;
}
