#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <windows.h>

void ClearScreen()
  {
    HANDLE                     hStdOut;
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      DWORD                      count;
      DWORD                      cellCount;
      COORD                      homeCoords = { 0, 0 };

      hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
      if (hStdOut == INVALID_HANDLE_VALUE) return;

      /* Get the number of cells in the current buffer */
      if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
      cellCount = csbi.dwSize.X *csbi.dwSize.Y;

      /* Fill the entire buffer with spaces */
      if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR) ' ',
        cellCount,
        homeCoords,
        &count
        )) return;

      /* Fill the entire buffer with the current colors and attributes */
      if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
        )) return;

      /* Move the cursor home */
      SetConsoleCursorPosition( hStdOut, homeCoords );
}

using namespace std;

void inter(char a[], char b[])
{
    char aux[32];
    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux);
}
void shuffle(char a[][52])
{
    int i, x;
    for(i=1; i<=52; i++)
    {
        x=rand()%52+1;
        inter(a[i], a[x]);
    }
}

int main ()
{
    ifstream f("bac.txt");
    cout<<endl;
    cout<<"  "<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
    cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
    cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
    cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
    cout<<"  "<<char(204)<<char(205)<<" B L A C K J A C K "<<char(205)<<char(185)<<endl;
    cout<<"  "<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
    cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(188);
    ifstream deck("deck.txt");

    int i, bani, id=1, ip=1, j, sd, sp, t=0, q=0, split=0, ss, is, bet;
    char a[53][52], d[20][52], p[20][52], k[3], x[3], h[3], s[20][52];
    f>>bani;
    f.close();
    cout.width(53);
    cout<<right<<" Sold ramas: ";
    cout.width(6);
    cout<<right<<bani<<endl<<endl;
    for(i=1; i<=52; i++)
    {
        deck.get(a[i], 52);
        if(i!=52)
            deck.get();
    }
    shuffle(a);
    deck.close();
    i=52;
    cout<<" ";
    for(j=0;j<3;j++)cout<<char(176);
    for(j=0;j<3;j++)cout<<char(177);
    for(j=0;j<3;j++)cout<<char(178);
    cout<<" Va rog sa raspundeti cu 'da', 'nu' respectiv o valoare intreaga.";
    for(j=0;j<3;j++)cout<<char(178);
    for(j=0;j<3;j++)cout<<char(177);
    for(j=0;j<3;j++)cout<<char(176);
    cout<<endl<<endl;
    cout<<" Joci? ";
    cin.get(k, 3);
    cin.get();
    while(k[0]=='d')
    {
        split=0;
        cout<<" ___________________________________________________________________________________"<<endl;
        cout<<" ___________________________________________________________________________________"<<endl<<endl;
        cout<<" Pe cat? ";
        do{
        cin>>bet;
        if(bet<0)cout<<" O suma pozitiva de bani ";
        }while(bet<0);
        cin.get();
        cout<<endl;
        shuffle(a);
        ip=1;
        id=1;
        sp=0;
        sd=0;
        i=52;
        ss=0;
        is=1;
        strcpy(d[id], a[i]);
        strcpy(d[id+1], a[i-1]);
        id=id+2;
        i=i-2;
        strcpy(p[ip], a[i]);
        strcpy(p[ip+1], a[i-1]);
        //strcpy(p[ip], "A de rosie");
        //strcpy(p[ip+1], "A googea");
        i=i-2;
        ip=ip+2;
        cout<<" Carti dealer: ";
        cout.width(12);
        cout<<left<<d[id-2]<<" || "<<"************"<<endl;
        cout<<" Cartile tale: ";

        for(j=split+1; j<ip-1; j++)
        {
            cout.width(12);
            cout<<left<<p[j]<<" || ";
        }
        cout.width(12);
        cout<<left<<p[ip-1]<<endl;
        if(p[1][0]==p[2][0]&&p[1][1]==p[2][1]&&bani>=2*bet)
        {
            cout<<" Split? ";
            cin.get(x, 3);
            cin.get();
        }
        if(x[0]=='d')
        {
            split=1;
            is=is+2;
            strcpy(s[2], p[2]);
            strcpy(p[3], a[i--]);
            strcpy(s[3], a[i--]);
            is++;
            ip++;
        }
        q=0;
        for(j=split+1; j<ip; j++)
        {
            if(strchr("1234567890", p[j][0]))
                sp=sp+p[j][0]-48;
            else if(!strchr("AAA", p[j][0]))
                sp=sp+10;
            else
            q++;
            if(p[j][1]=='0')
                sp=sp+9;
        }
        for(j=1; j<=q; j++)
        {
        if(sp+11+(q-j)*1<=21)
                sp=sp+11;
            else
                sp=sp+1;
        }
        q=0;
        if(sp>=21){
            cout<<" Prima mana:   ";
            cout.width(12);
            cout<<left<<p[1]<<" || ";
            for(j=3; j<ip-1; j++)
            {
                cout.width(12);
                cout<<left<<p[j]<<" || ";
            }
            cout.width(12);
            cout<<left<<p[ip-1]<<endl;
        }
        while(sp<21)
        {
            if(split==1&&ip<=4)
            {
                cout<<" Prima mana:   ";
                cout.width(12);
                cout<<left<<p[1]<<" || ";
                for(j=3; j<ip-1; j++)
                {
                    cout.width(12);
                    cout<<left<<p[j]<<" || ";
                }
                cout.width(12);
                cout<<left<<p[ip-1]<<endl;
            }
            cout<<" Mai iti dau? ";
            cin.get(x, 3);
            cin.get();
            if(x[0]!='d')
                break;
            strcpy(p[ip], a[i]);
            i--;
            ip++;
            if(split==1)
            {
                cout<<" Prima mana:   ";
                cout.width(12);
                cout<<left<<p[1]<<" || ";
            }
            else{
                cout<<" Cartile tale: ";
                cout.width(12);
                cout<<left<<p[1]<<" || ";
                cout.width(12);
                cout<<left<<p[2]<<" || ";
            }
            for(j=3; j<ip-1; j++)
            {
                cout.width(12);
                cout<<left<<p[j]<<" || ";
            }
            cout.width(12);
            cout<<left<<p[ip-1]<<endl;
            sp=0;
            q=0;
            for(j=split+1; j<ip; j++)
            {
                if(strchr("1234567890", p[j][0]))
                    sp=sp+p[j][0]-48;
                else if(!strchr("AAA", p[j][0]))
                    sp=sp+10;
                else
                    q++;
                if(p[j][1]=='0')
                    sp=sp+9;
            }
            for(j=1; j<=q; j++)
            {
                if(sp+11+(q-j)*1<=21)
                    sp=sp+11;
                else
                    sp=sp+1;
            }
            q=0;
        }
            q=0;
        cout<<endl;
        if(split==1){
            ss=0;
            q=0;
            for(j=2; j<is; j++)
            {
                if(strchr("1234567890", s[j][0]))
                    ss=ss+s[j][0]-48;
                else if(!strchr("AAA", s[j][0]))
                    ss=ss+10;
                else
                    q++;
                if(p[j][1]=='0')
                    ss=ss+9;
            }
            for(j=1; j<=q; j++)
            {
                if(ss+11+(q-j)*1<=21)
                    ss=ss+11;
                else
                    ss=ss+1;
            }
            q=0;
            if(ss>=21){
                cout<<" A doua mana:  ";
                for(j=2; j<is-1; j++)
                {
                    cout.width(12);
                    cout<<left<<s[j]<<" || ";
                }
                cout.width(12);
                cout<<left<<s[is-1]<<endl;
            }
            while(ss<21)
            {
                cout<<" Carti dealer: ";
                cout.width(12);
                cout<<left<<d[id-2]<<" || "<<"************"<<endl;
                cout<<" A doua mana:  ";
                for(j=2; j<is-1; j++)
                {
                    cout.width(12);
                    cout<<left<<s[j]<<" || ";
                }
                cout.width(12);
                cout<<left<<s[is-1]<<endl;
                cout<<" Mai iti dau? ";
                cin.get(x, 3);
                cin.get();
                if(x[0]!='d')
                    break;
                strcpy(s[is], a[i]);
                i--;
                is++;
                q=0;
                ss=0;
                for(j=2; j<is; j++)
                {
                    if(strchr("1234567890", s[j][0]))
                        ss=ss+s[j][0]-48;
                    else if(!strchr("AAA", s[j][0]))
                        ss=ss+10;
                    else
                        q++;
                    if(p[j][1]=='0')
                        ss=ss+9;
                }
                for(j=1; j<=q; j++)
                {
                    if(ss+11+(q-j)*1<=21)
                        ss=ss+11;
                    else
                        ss=ss+1;
                }
                q=0;
            }
        }
        cout<<endl;
        for(j=1; j<id; j++)
        {
            if(strchr("1234567890", d[j][0]))
                sd=sd+d[j][0]-48;
            else if(!strchr("AAA", d[j][0]))
                sd=sd+10;
            else
                q++;
            if(d[j][1]=='0')
                sd=sd+9;
        }
        for(j=1; j<=q; j++)
        {
            if(sd+11+(q-j)*1<=21)
                sd=sd+11;
            else
                sd=sd+1;
        }
        q=0;
        if(strchr("1234567890", a[i][0]))
            t=a[i][0]-48;
        else if(!strchr("AAA", a[i][0]))
            t=10;
        else if(sd+11<=21)
            t=11;
        else
            t=1;
        if(a[i][1]=='0')
            t=t+9;
        while(sd+t<=21||sd<17)
        {
            strcpy(d[id], a[i]);
            i--;
            sd=0;
            for(j=1; j<=id; j++)
            {
                if(strchr("1234567890", d[j][0]))
                    sd=sd+d[j][0]-48;
                else if(!strchr("AAA", d[j][0]))
                    sd=sd+10;
                else
                    q++;
                if(d[j][1]=='0')
                    sd=sd+9;
            }
            for(j=1; j<=q; j++)
            {
                if(sd+11+(q-j)*1<=21)
                    sd=sd+11;
                else
                    sd=sd+1;
            }
            q=0;
            if(strchr("1234567890", a[i][0]))
                t=a[i][0]-48;
            else if(!strchr("AAA", a[i][0]))
                t=10;
            else if(sd+11<=21)
                t=11;
            else
                t=1;
            if(a[i][1]=='0')
                t=t+9;
            id++;
        }
        if(!split)
        {
            cout<<" Carti dealer: ";
            for(j=1; j<id-1; j++)
            {
                cout.width(12);
                cout<<left<<d[j]<<" || ";
            }
            cout.width(12);
            cout<<left<<d[id-1]<<endl;
            cout<<" Cartile tale: ";
            for(j=1; j<ip-1; j++)
            {
                cout.width(12);
                cout<<left<<p[j]<<" || ";
            }
            cout.width(12);
            cout<<left<<p[ip-1]<<endl<<endl;
        }
        else
        {
            cout<<" Carti dealer: ";
            for(j=1; j<id-1; j++)
            {
                cout.width(12);
                cout<<left<<d[j]<<" || ";
            }
            cout.width(12);
            cout<<left<<d[id-1]<<endl;
            cout<<" Prima mana:   ";
            cout.width(12);
            cout<<left<<p[1]<<" || ";
            for(j=3; j<ip-1; j++)
            {
                cout.width(12);
                cout<<left<<p[j]<<" || ";
            }
            cout.width(12);
            cout<<left<<p[ip-1]<<endl;
            cout<<" A doua mana:  ";
            for(j=2; j<is-1; j++)
            {
                cout.width(12);
                cout<<left<<s[j]<<" || ";
            }
            cout.width(12);
            cout<<left<<s[is-1]<<endl<<endl;
        }
        if(split)
            cout<<" Pe prima mana  "<<endl;
        cout<<" -----------------------------------------------------------------------------------"<<endl;
        if(1)
        {
            if(sd>21&&sp>21)
            {
                cout<<" Ai prierdut              bani -"<<bet;
                bani=bani-bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
            else  if(sd>21)
            {
                cout<<" Ai castigat              bani +"<<bet;
                bani=bani+bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
            else if(sp>21)
            {
                cout<<" Ai prierdut              bani -"<<bet;
                bani=bani-bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
            else if(sp==sd)
            {
                cout<<" Egal              bani +0";
            }
            else if(sp>sd)
            {
                cout<<" Ai castigat              bani +"<<bet;
                bani=bani+bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
            else if(sd>sp)
            {
                cout<<" Ai prierdut              bani -"<<bet;
                bani=bani-bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
        }
        //cout<<endl<<"sd="<<sd<<endl<<"sp="<<sp<<endl<<"ss="<<ss;
        if(split)
        {
            cout<<endl<<endl<<" Pe a doua mana  "<<endl;
            if(sd>21&&ss>21)
            {
                cout<<" Ai prierdut              bani -"<<bet;
                bani=bani-bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
            else  if(sd>21)
            {
                cout<<" Ai castigat              bani +"<<bet;
                bani=bani+bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
            else if(ss>21)
            {
                cout<<" Ai prierdut              bani -"<<bet;
                bani=bani-bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
            else if(ss==sd)
            {
                cout<<" Egal              bani +0";
            }
            else if(ss>sd)
            {
                cout<<" Ai castigat              bani +"<<bet;
                bani=bani+bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
            else if(sd>ss)
            {
                cout<<" Ai prierdut              bani -"<<bet;
                bani=bani-bet;
                cout<<endl<<" Sold ramas: "<<bani;
            }
        }
        cout<<endl<<" -----------------------------------------------------------------------------------";
        cout<<endl<<endl;
        cout<<"  |_| Mai Joci? |_| ";
        cin.get(k, 3);
        cin.get();
        ClearScreen();
        ifstream f("bac.txt");
        cout<<endl;
        cout<<"  "<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
        cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
        cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
        cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
        cout<<"  "<<char(204)<<char(205)<<" B L A C K J A C K "<<char(205)<<char(185)<<endl;
        cout<<"  "<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
        cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(188);
        cout.width(54);
        cout<<right<<" Sold ramas: "<<bani<<endl<<endl;
        cout<<" ";
        for(j=0;j<3;j++)cout<<char(176);
        for(j=0;j<3;j++)cout<<char(177);
        for(j=0;j<3;j++)cout<<char(178);
        cout<<" Va rog sa raspundeti cu 'da', 'nu' respectiv o valoare intreaga.";
        for(j=0;j<3;j++)cout<<char(178);
        for(j=0;j<3;j++)cout<<char(177);
        for(j=0;j<3;j++)cout<<char(176);
        cout<<endl<<endl;
    }
    ofstream g("bac.txt");
    g<<bani;
    g.close();
    return bani;
}
