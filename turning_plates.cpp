// POP projekt 1 AIR 1 Code::Blocks 16.01

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

const int MAX_P = 4;  // maksymalny wymiar wierszy i kolumn | max size of rows and columns
char tablica[MAX_P][MAX_P] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80}; // tablica dwuwymiarowa wypelniona znakami w ASCII | table with ascii codes
const int t = 4000; // zmienna do ustawienia czasu uspania funkcji | variable for time sleep function

void wstep()
{
    cout << "Twoim zadaniem jest ulozenie tabliczki zgodnie z kolejnoscia alfabetyczna znakow." << endl;
    cout << "Your task is to arrange the plate in the alphabetical order of the characters." << endl;
    Sleep(t);
    cout << "Ukladanie tabliczki nastepuje poprzez obroty poszczegolnych cwiartek (klawisze od 1 do 4)\noraz poprzez obrot srodka (klawisz 5). \nYou can arrange the plate by rotating the individual quadrants (keys 1 to 4) and then by turning the center (key 5).\n";
    Sleep(2 * t);
    system("CLS");
    cout << "Oto Twoja tabliczka: \nYour plate:\n";
    Sleep(t / 2);
    system("CLS");
}

// functions turning each small plate 90 deg. Each plate has a specific number
void jedynka() // klawisz nr 1 itd.  | key number 1
{
    char buf = tablica[0][0];
    tablica[0][0] = tablica[1][0];
    tablica[1][0] = tablica[1][1];
    tablica[1][1] = tablica[0][1];
    tablica[0][1] = buf;
}

void dwojka() // key number 2
{
    char buf = tablica[0][2];
    tablica[0][2] = tablica[1][2];
    tablica[1][2] = tablica[1][3];
    tablica[1][3] = tablica[0][3];
    tablica[0][3] = buf;
}
void trojka() // key number 3
{
    char buf = tablica[2][0];
    tablica[2][0] = tablica[3][0];
    tablica[3][0] = tablica[3][1];
    tablica[3][1] = tablica[2][1];
    tablica[2][1] = buf;
}
void czworka() // key number 4
{
    char buf = tablica[2][2];
    tablica[2][2] = tablica[3][2];
    tablica[3][2] = tablica[3][3];
    tablica[3][3] = tablica[2][3];
    tablica[2][3] = buf;
}

void piatka() // key number 5
{
    char buf = tablica[1][1];
    tablica[1][1] = tablica[2][1];
    tablica[2][1] = tablica[2][2];
    tablica[2][2] = tablica[1][2];
    tablica[1][2] = buf;
}
// PRINTING LINES
void linia()
{
    cout << "|";
}
void linia_pozioma()
{
    cout << "+-------+-------+-------+-------+";
}
void linia_gorna()
{
    cout << ".-------.-------.-------.-------." << endl;
}
void linia_dolna()
{
    cout << "'-------'-------'-------'-------'" << endl;
}
void linia_sr_12()
{
    cout << "+-------1-------+-------2-------+" << endl;
}
void linia_sr_5()
{
    cout << "+-------+-------5-------+-------+" << endl;
}
void linia_sr_34()
{
    cout << "+-------3-------+-------4-------+" << endl;
}
void pisz_tablice() // print plate
{
    linia_gorna(); // print top line
    for (int i = 0; i < MAX_P; i++)
    {
        cout << "|";
        for (int j = 0; j < MAX_P; j++)
        {
            cout << tablica[i][j];  // print character
            cout << setw(7) << "|"; // set field width
        }

        cout << endl;
        cout << setw(0) << "|";
        for (int j = 0; j < MAX_P; j++)
        {
            cout << setw(7) << tablica[i][j];
            cout << setw(0) << "|";
        }
        cout << endl;

        // print lines in the middle
        if (i == 0)
            linia_sr_12();
        if (i == 1)
            linia_sr_5();
        if (i == 2)
            linia_sr_34();
    }
    linia_dolna(); // print bottom line
}
int porownanie(char tab[MAX_P][MAX_P]) // check the table/plate
{
    int w = 0;         // jezeli ta zmienna przyjmie wartosc "1", to znaczy, ze tablica nie jest jeszcze posortowana | w==1 -> tab not sorted
    int p = MAX_P - 1; // p=3 po to, aby w wierszu tablicy nie byl porownywany element ostatni z nieistniejacym elementem o indeksie [i][4] | so index will not be equal 4 (out of range).
    for (int i = 0; i < MAX_P; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (j == 0 && i != 0)
            {
                if (tab[i - 1][3] > tab[i][j])
                {
                    w = 1;
                    break;
                }
            }
            else if (tab[i][j] > tab[i][j + 1])
            {
                w = 1;
                break;
            }
        }
        if (w == 1)
            break;
    }
    return w;
}
void mieszanie_tablicy() // mix the table
{
    const int ilosc_przekrecen = 3; // number of turns
    srand(time(NULL));
    for (int i = 0; i <= ilosc_przekrecen; i++)
    {
        int s = (1 + rand() % 5);
        switch (s)
        {

        case 1:
            system("CLS");
            jedynka();
            break;
        case 2:
            system("CLS");
            dwojka();
            break;
        case 3:
            system("CLS");
            trojka();
            break;
        case 4:
            system("CLS");
            czworka();
            break;
        case 5:
            system("CLS");
            piatka();
            break;
        }
    }
}
void gra() // game
{
    do
    {
        int n;
        cout << "Wcisnij klawisz 1, 2, 3, 4 lub 5: \nPress the key 1, 2, 3, 4 or 5:";
        cin >> n;
        switch (n)
        {

        case 1:
            system("CLS");
            jedynka();
            pisz_tablice();
            break;
        case 2:
            system("CLS");
            dwojka();
            pisz_tablice();
            break;
        case 3:
            system("CLS");
            trojka();
            pisz_tablice();
            break;
        case 4:
            system("CLS");
            czworka();
            pisz_tablice();
            break;
        case 5:
            system("CLS");
            piatka();
            pisz_tablice();
            break;
        default:
            cout << "Zly klawisz!\nWrong key!\n";
        }
    } while (porownanie(tablica) != 0); // while plate is not sorted
    cout << "Gratulacje! Udalo Ci sie ulozyc tabliczke!/n Congrats! You've arranged the plate!";
    Sleep(2 * t);
}
int main()
{
    wstep(); // print the game instruction
    Sleep(1000);
    mieszanie_tablicy(); // mix the plate
    pisz_tablice();      // print the plate
    gra();
}
