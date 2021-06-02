#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <fcntl.h>
#include <shellapi.h>
#include <wchar.h>

LPSTR classname = "window";
MSG message;
HWND button, tekst, help, about, options, tekst2, bar1, bar2, bar3, bar4, bar5, bcgteskst;
HWND ho, std, pth, dbg, tlo, tlo2, helpT, aboutT;
int opcja = 1, run = 0;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, HINSTANCE hInstance, int nCmdShow);

//procedury budujące plik wyjściowy
void startf(FILE* file)
{    
    fprintf(file, "<REAPER_PROJECT 0.1 \"6.19 / win64\" 1613071903"
        "\n  RIPPLE 0"
        "\n  GROUPOVERRIDE 0 0 0"
        "\n  AUTOXFADE 1"
        "\n  ENVATTACH 1"
        "\n  POOLEDENVATTACH 0"
        "\n  MIXERUIFLAGS 11 48"
        "\n  PEAKGAIN 1"
        "\n  FEEDBACK 0"
        "\n  PANLAW 1"
        "\n  PROJOFFS 0 0 0"
        "\n  MAXPROJLEN 0 600"
        "\n  GRID 3199 8 1 8 1 0 0 0"
        "\n  TIMEMODE 1 5 -1 30 0 0 -1"
        "\n  VIDEO_CONFIG 0 0 256"
        "\n  PANMODE 3"
        "\n  CURSOR 300.83886621315918"
        "\n  ZOOM 11.730295593258 1735 0"
        "\n  VZOOMEX 5 0"
        "\n  USE_REC_CFG 0"
        "\n  RECMODE 1"
        "\n  SMPTESYNC 0 30 100 40 1000 300 0 0 1 0 0"
        "\n  LOOP 1"
        "\n  LOOPGRAN 0 4"
        "\n  RECORD_PATH \"\" \"\""
        "\n  <RECORD_CFG"
        "\n  >"
        "\n  <APPLYFX_CFG"
        "\n  >"
        "\n  RENDER_FILE \"\""
        "\n  RENDER_PATTERN projekt_new_ozone"
        "\n  RENDER_FMT 0 2 48000"
        "\n  RENDER_1X 0"
        "\n  RENDER_RANGE 1 0 0 18 1000"
        "\n  RENDER_RESAMPLE 4 0 1"
        "\n  RENDER_ADDTOPROJ 0"
        "\n  RENDER_STEMS 0"
        "\n  RENDER_DITHER 0"
        "\n  TIMELOCKMODE 1"
        "\n  TEMPOENVLOCKMODE 1"
        "\n  ITEMMIX 0"
        "\n  DEFPITCHMODE 589824 0"
        "\n  TAKELANE 1"
        "\n  SAMPLERATE 44100 0 0"
        "\n  <RENDER_CFG"
        "\n    ZXZhdyEAAA=="
        "\n  >"
        "\n  LOCK 1"
        "\n  <METRONOME 6 2"
        "\n    VOL 0.25 0.125"
        "\n    FREQ 800 1600 1"
        "\n    BEATLEN 4"
        "\n    SAMPLES \"\" \"\""
        "\n    PATTERN 2863311530 2863311529"
        "\n  >"
        "\n  GLOBAL_AUTO -1"
        "\n  COMP 1 \"Comp 1\""
        "\n  TEMPO 120 4 4"
        "\n  PLAYRATE 1 0 0.25 4"
        "\n  SELECTION 591 591"
        "\n  SELECTION2 591 591"
        "\n  MASTERAUTOMODE 0"
        "\n  MASTERTRACKHEIGHT 0 0"
        "\n  MASTERPEAKCOL 16576"
        "\n  MASTERMUTESOLO 0"
        "\n  MASTERTRACKVIEW 0 0 0.5 0.5 0 -1 0 0 0 0 -1 -1 0"
        "\n  MASTERHWOUT 0 0 1 0 0 0 0 -1"
        "\n  MASTER_NCH 2 2"
        "\n  MASTER_VOLUME 1 0 -1 -1 1"
        "\n  MASTER_FX 1"
        "\n  MASTER_SEL 0"
        "\n  <MASTERPLAYSPEEDENV"
        "\n    EGUID{68DCE35B-0011-4304-8CD0-57A630C3327E}"
        "\n    ACT 0 -1"
        "\n    VIS 0 1 1"
        "\n    LANEHEIGHT 0 0"
        "\n    ARM 0"
        "\n    DEFSHAPE 0 -1 -1"
        "\n  >"
        "\n  <TEMPOENVEX"
        "\n    EGUID{A499213B-EA19-4907-9E82-2C80A3E6D486}"
        "\n    ACT 0 -1"
        "\n    VIS 1 0 1"
        "\n    LANEHEIGHT 0 0"
        "\n    ARM 0"
        "\n    DEFSHAPE 1 -1 -1"
        "\n  >"
        "\n  <PROJBAY"
        "\n  >");
}

void track(FILE* file, int n)
{
    fprintf(file,"\n  <TRACK {170DFA72-1AAD-4CE9-90AE-0A5248B019D6}"
        "\n    NAME %d"
        "\n    PEAKCOL 27998740"
        "\n    BEAT -1"
        "\n    AUTOMODE 0"
        "\n    VOLPAN 1 0 -1 -1 1"
        "\n    MUTESOLO 0 0 0"
        "\n    IPHASE 0"
        "\n    PLAYOFFS 0 1"
        "\n    ISBUS 0 0"
        "\n    BUSCOMP 0 0 0 0 0"
        "\n    SHOWINMIX 1 0.6667 0.5 1 0.5 0 -1 0"
        "\n    FREEMODE 0"
        "\n    SEL 0"
        "\n    REC 0 0 0 0 0 0 0"
        "\n    VU 2"
        "\n    TRACKHEIGHT 50 0 0 0 0 0"
        "\n    INQ 0 0 0 0.5 100 0 0 100"
        "\n    NCHAN 2"
        "\n    FX 1"
        "\n    TRACKID{170DFA72-1AAD-4CE9-90AE-0A5248B019D6}"
        "\n    PERF 0"
        "\n    MIDIOUT -1"
        "\n    MAINSEND 1 0", n);
}

void s_end(FILE* file, int n)
{
    if (n)
    {
        fprintf(file, "\n  >");
    }
    else
    {
        fprintf(file, "\n>");
    }
}

void clipf(FILE* file, double pos, double length, char name[], double soffs, char source[])
{
    if (opcja == 3)
    {
        strcpy(source, "C:/___no__file___");
    }
    fprintf(file, "\n    <ITEM"
        "\n      POSITION %.14lf"
        "\n      SNAPOFFS 0"
        "\n      LENGTH %.14lf"
        "\n      LOOP 1"
        "\n      ALLTAKES 0"
        "\n      FADEIN 1 0.01 0 1 0 0 0"
        "\n      FADEOUT 1 0.01 0 1 0 0 0"
        "\n      MUTE 0 0"
        "\n      COLOR 24591499 R"
        "\n      SEL 0"
        "\n      IGUID {B1F4E73F-D44F-45BF-94B9-CDE8C6552AC1}"
        "\n      IID 227"
        "\n      COMP 1 0 0"
        "\n      NAME %s"
        "\n      VOLPAN 1 0 1 -1"
        "\n      SOFFS %.14lf"
        "\n      PLAYRATE 1 1 0 - 1 0 0.0025"
        "\n      CHANMODE 0"
        "\n      GUID {4DAD1F9D-E13A-4C55-ACBF-33FA3123CC3E}"
        "\n      <SOURCE VIDEO"
        "\n        FILE \"%s\""
        "\n      >"
        "\n    >", pos, length, name, soffs, source);
}

//funkcje operujące na stringach
const char* cut(char str[], int n)
{
    char* part = strtok(str, "<");
    for (int i = 1; i < n; i++)
    {
        part = strtok(NULL, "< >");
    }
    return part;
}

const char* cut2(char str[], int n)
{
    char* part = strtok(str, "<");
    for (int i = 1; i < n; i++)
    {
        part = strtok(NULL, "<>");
    }
    return part;
}

long long stoi(char tab[])
{
    LPCTSTR sokno[50];
    long long length, p=1;
    long long l=0, i, temp;
    sprintf(sokno, "wykryto błąd w pliku .xml, utworzny projekt może nie funkcjonować poprawnie\n\noczekiwano liczby, otrzymano \"%s\"", tab);
    length = strlen(tab);
    i = length - 1;
    while (i >= 0)
    {
        temp = (tab[i] - 48);
        if (temp > 9 || temp < 0)
        {

            MessageBoxA(NULL, sokno, "błąd odczytu", MB_ICONERROR);
            return 0;
        }
        l = l + temp * p;
        p *= 10;
        i--;
    }
    return l;
}

double stod(char tab[])
{
    LPCTSTR sokno[50];
    char tab2[30];
    unsigned int length;
    double l = 0, p = 1;
    char* part;
    int i, temp;
    sprintf(sokno, "wykryto błąd w pliku .xml, utworzny projekt może nie funkcjonować poprawnie\n\noczekiwano liczby, otrzymano \"%s\"",tab);

    if (strpbrk(tab, ".") != 0)
    {
        strcpy(tab2, tab);        
        part = strtok(tab2, ".");
        strcpy(tab, part);
        part = strtok(NULL, ".");
        strcpy(tab2, part);

        length = strlen(tab);
        i = length - 1;

        while (i >= 0)
        {
            temp = (tab[i] - 48);
            if (temp > 9 || temp < 0)
            {
                MessageBoxA(NULL, sokno, "błąd odczytu", MB_ICONERROR);
                return 0;
            }
            l = l + temp * p;
            p *= 10;
            i--;
        }

        length = strlen(tab2);
        p = 0.1;
        i = 0;

        while (i < length)
        {
            temp = (tab2[i] - 48);
            if (temp > 9 || temp < 0)
            {
                MessageBoxA(NULL, sokno, "błąd odczytu", MB_ICONERROR);
                return 0;
            }
            l = l + temp * p;
            p *= 0.1;
            i++;
        }

        return l;
    }
    else
    {
        return stoi(tab);
    }
}

//czyszczenie pól tekstowych
void clear()
{
    SetWindowTextA(tekst, "");
    SetWindowTextA(tekst2, ".xml -> .rpp");
}

int errorF(char wiersz[], char a, int kol)
{
    LPCTSTR sokno[50];
    sprintf(sokno, "niedopowieni format pliku .xml, poprawna konwersja niemożliwa\n\nciąg znaków \n\"%s\" \nzawiera błąd", wiersz);
    if (wiersz[kol] != a)
    {
        MessageBoxA(NULL, sokno, "błąd odczytu", MB_ICONERROR);
        return 0;
    }
    return 1;
}

//konwersja - tworzenie pliku wynikowego rpp
int translator(FILE* xml)
{
    LPCTSTR s[50];
    LPCTSTR sokno[250];
    errno_t error;
    FILE* rpp = NULL;
    const int size = 150;
    char line[250], name[250], loc[250], name_old[250];
    int mode = opcja;
    int time, frames, hours, minutes, seconds, sciezki=0, clips, clips_all=0, start, end, temp, p=0, k, bad=0;   
    double duration, position, offset, framerate;
    OPENFILENAME ofn;
    char szFile[250];   
    HANDLE sh2 = NULL;

    run = 1;

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0'; 
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Reaper (.rpp)\0*.rpp\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_OVERWRITEPROMPT;

    if(1)
    {
        for (int i = 0; i < 5; i++)
        {
            fgets(line, 60, xml);
        }     
        if (!errorF(line, 'n', 9))
        {
            p = 0;
        }
        else
        {
            
            p = 1;
            strcpy(line, cut2(line, 3));

            printf("%s", line);
            strcpy(name, line);

            fgets(line, 60, xml);
            strcpy(line, cut(line, 3));

            frames = stoi(line);
            if (frames <= 0)
            {
                sprintf(sokno, "niedopowieni format pliku .xml, poprawna konwersja niemożliwa\n\nciąg znaków \n\"%s\" \nzawiera błąd", line);
                MessageBoxA(NULL, sokno, "błąd odczytu", MB_ICONERROR);
                p = 0;
            }
            else
            {                
                fgets(line, 60, xml);
                fgets(line, 60, xml);
                strcpy(line, cut(line, 3));

                framerate = stod(line);
                if (framerate <= 1)
                {
                    sprintf(sokno, "niedopowieni format pliku .xml, poprawna konwersja niemożliwa\n\nciąg znaków \n\"%s\" \nzawiera błąd", line);
                    MessageBoxA(NULL, "niedopowieni format pliku .xml, poprawna konwersja niemożliwa", "błąd odczytu", MB_ICONERROR);
                    p = 0;
                }
                else
                {                    
                    time = frames / framerate;
                    hours = time / 3600;
                    minutes = (time - hours * 3600) / 60;
                    seconds = time - hours * 3600 - minutes * 60;

                    sprintf(sokno, "%s %d klatek - %d sekund [%dh %dmin %ds] - %.4lf fps\n", name, frames, time, hours, minutes, seconds, framerate);
                    SetWindowTextA(tekst, sokno);                    

                    fgets(line, 250, xml);
                }
            }
        }
        if (p==1) //otwieranie pliku do zapisu, jeśli możliwy jest prawidłowy odczyt
        {
            GetSaveFileNameA(&ofn);
            sh2 = CreateFileA(ofn.lpstrFile, GENERIC_WRITE, 0, (LPSECURITY_ATTRIBUTES)NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, (HANDLE)NULL);
            int fd = _open_osfhandle((long)sh2, _O_RDONLY);
            if (fd != -1)
            {
                sprintf(s, "utworzono plik %s", ofn.lpstrFile);
                SetWindowTextA(tekst, s);
                rpp = _fdopen(fd, "w");

                startf(rpp);

                p = 1;
            }
            else
            {
                MessageBox(NULL, L"nie udało się utworzyć pliku do zapisu", L"error", MB_ICONERROR);
                p = 0;
                clear();
            }
        }
        while(p==1) //konwersja plików
        {
            strcpy(line, cut(line, 2));

            if (strcmp(line, "/sequence") == 0) //warunek konca odczytu
            {
                break;
            }                

            if (strcmp(line, "track")==0) //odczyt sciezki
            {
                
                sciezki++;
                track(rpp, sciezki); 
                
                clips = 0;
                sprintf(sokno, "sciezka %d",sciezki);  
                SetWindowTextA(tekst2, sokno);
                
                while(1)
                {
                    fgets(line, 250, xml);
                    strcpy(line, cut(line, 2));

                    if (strcmp(line, "/track") == 0)
                    {
                        break;
                    }                           
                 
                    if (strcmp(line, "clipitem") == 0) //odczyt klipu
                    {
                        clips++;
                        fgets(line, 250, xml);
                        errorF(line, 'n', 25);
                        strcpy(line, cut2(line, 3));
                        strcpy(name, line);

                        for (int i = 0; i < 6; i++)
                        {
                            fgets(line, 250, xml);
                        }                        
                        strcpy(line, cut(line, 3));
                        start = stoi(line);

                        fgets(line, 250, xml);
                        strcpy(line, cut(line, 3));
                        end = stoi(line);

                        duration = end - start;
                        duration = duration / framerate;

                        position = start;
                        position = position / framerate;

                        fgets(line, 250, xml);
                        fgets(line, 250, xml);
                        strcpy(line, cut(line, 3));

                        offset = stoi(line);
                        offset = offset / framerate;
                        
                        for (int i = 0; i < 9; i++)
                        {
                            fgets(line, 250, xml);
                        }
                        if (line[29] == 'p') //jesli adres jest prawidlowo zapisany to go wczytaj
                        {
                            strcpy(line, cut2(line, 3));
                            temp = strlen(line);

                            for (int i = 0; i < temp; i++)
                            {
                                loc[i] = line[17 + i];
                            }
                            strcpy(line, loc);

                            temp = strlen(line);
                            k = 0;
                            int z = 0;       

                            for (z; z + k < temp; z++) //przywracanie spacji
                            {
                                if (line[z + k] == '%')
                                {
                                    loc[z] = ' ';
                                    k += 2;
                                }
                                else
                                {
                                    loc[z] = line[z + k];
                                }                                
                            }
                            loc[z] = '\0'; //kończenie łańcucha znaków
                        }
                        else if (strcmp(name, name_old) != 0) //jezeli nazwa jest inna niz poprzedniego klipu, to nie uzywaj jego sciezki
                        {
                            strcpy(loc, "C:/___no__file___");
                            bad += 1;
                            if (mode == 2) //jeśli konwersja odbywa się w trybie debug, informuj o każdym błędzie
                            {
                                sprintf(sokno, "błąd nr %d \nnie znaleziono lokazlizacji wystapienia elementu projektu:\n%s", bad, name);
                                MessageBoxA(NULL, sokno, "błąd konwersji", MB_ICONEXCLAMATION);
                            }
                        }
                        sprintf(sokno, "   %s %.4lfs %.4lfs %d %d %.4lfs", loc, position, offset, start, end, duration);
                        SetWindowTextA(tekst2, sokno);

                        if (mode == 2) //jeśli konwersja odbywa się w trybie debug, zwiększ czas na odczytanie informacji przez użytkownika
                        {
                            Sleep(2);
                        }
                        
                        clipf(rpp, position, duration, name, offset, loc);

                        strcpy(name_old, name);
                    }                    
                }
                clips_all += clips;
                sprintf(sokno, "%d filmow", clips);
                SetWindowTextA(tekst2, sokno);
                s_end(rpp, 1);
            }
            fgets(line, 250, xml);
        }
        fclose(xml);
        
        if (p == 1)
        {            
            sprintf(sokno, "%d elementow w projekcie", clips_all);
            SetWindowTextA(tekst2, sokno);
            s_end(rpp, 0);
            fclose(rpp);
        }

    }
    CloseHandle(sh2);
    if (p == 1)
    {
        if (bad > 0)
        {
            sprintf(sokno, "nie znaleziono lokazlizacji %d wystapień elementów projektu", bad);
            MessageBoxA(NULL, sokno, "zakończono przetwarzanie - wystąpiły błędy konwersji", MB_ICONINFORMATION);
        }
        else
        {
            sprintf(sokno, "nie znaleziono żadnych problemów");
            MessageBoxA(NULL, sokno, "zakończono przetwarzanie", MB_ICONINFORMATION);
        }
       
        strcpy(name, ofn.lpstrFile);
        for (int j = 0; j < strlen(name); j++)
        {
            if (name[j] == '\\')
            {
                k = j;
            }
        }     
        strcpy(name, "explorer ");
        strncat(name, ofn.lpstrFile, k+1);

        system(name);
    }
    else
    {
        MessageBoxA(NULL, "spróbuj uzyć innego pliku", "translator", MB_ICONINFORMATION);
    }

    clear();
    run = 0;
	return 0;
}

//otwieranie pliku i inicjacja procesu konwersji
void opensave()
{
    OPENFILENAME ofn, sofn;
    char szFile[250];
    HANDLE h;
    LPWSTR s[50];

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Premiere (.xml)\0*.xml\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameA(&ofn) == TRUE)
    {
        strcpy(s, ofn.lpstrFile);
        SetWindowTextA(tekst, s);        
        
        h = CreateFileA(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, (LPSECURITY_ATTRIBUTES)NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, (HANDLE)NULL);

        int fd = _open_osfhandle((long)h, _O_RDONLY);

        if (fd != -1)
        {
            FILE* fileXML = _fdopen(fd, "rb");

            fd = -1;
            sprintf(s, "otwarto plik %s", ofn.lpstrFile);
            SetWindowTextA(tekst, s);                        
            translator(fileXML);
            CloseHandle(h);
        }
        else
        {
            MessageBox(NULL, L"nie udało się otworzyć pliku", L"error", MB_ICONERROR);
            clear();
        }
    } 
    else
    {
        MessageBox(NULL, L"nie udało się otworzyć pliku", L"error", MB_ICONERROR);
        clear();
    }
}

void opensaveDROP(wchar_t* name)
{
    FILE* fileXML;
    LPWSTR s[50];
    errno_t error;

    if ((error = fopen_s(&fileXML, name, "r")) != 0)
    {
        MessageBox(NULL, L"nie udało się utworzyć pliku do zapisu", L"error", MB_ICONERROR);
        clear();
    }
    else
    {
        sprintf(s, "otwarto plik %s", name);
        SetWindowTextA(tekst, s);

        translator(fileXML);
    }
}

//okno główne
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX main;
    HWND hwnd;
    HFONT hFont = CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, VARIABLE_PITCH, TEXT("Century Gothic"));
    HFONT hFont2 = CreateFont(21, 0, 0, 900, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, VARIABLE_PITCH, TEXT("Century Gothic"));
    HFONT hFont3 = CreateFont(18, 0, 0, 900, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, VARIABLE_PITCH, TEXT("Century Gothic"));
    HBRUSH background = CreateSolidBrush(RGB(245, 245, 245));

    main.cbSize = sizeof(WNDCLASSEX);
    main.style = CS_HREDRAW | CS_VREDRAW;
    main.lpfnWndProc = WndProc;
    main.cbClsExtra = 0;
    main.cbWndExtra = 0;
    main.hInstance = hInstance;
    main.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    main.hCursor = LoadCursor(NULL, IDC_ARROW);
    main.hbrBackground = background;
    main.lpszMenuName = NULL;
    main.lpszClassName = classname;
    main.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&main))
    {
        MessageBox(NULL, L"nie udało się otworzyć okna", L"error", MB_ICONERROR | MB_OK);
        return 1;
    }    

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, classname, L"translator",  WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 620, 300, NULL, NULL, hInstance, NULL);
    
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_SIZEBOX);

    tlo2 = CreateWindow(L"STATIC", L"", WS_VISIBLE | WS_CHILD | SS_LEFT, 90, 55, 420, 160, hwnd, NULL, hInstance, NULL);

    tlo = CreateWindow(L"STATIC", L"\nkliknij, by uruchomić\n\n\n\nlub przesuń plik na okno programu", WS_VISIBLE | WS_CHILD | SS_CENTER, 100, 65, 400, 140, hwnd, NULL, hInstance, NULL);
    SendMessage(tlo, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));

    std = CreateWindowEx(0, L"BUTTON", L"START", WS_CHILD | WS_VISIBLE | BS_FLAT, 250, 120, 100, 40, hwnd, NULL, hInstance, NULL);
    SendMessage(std, WM_SETFONT, (WPARAM)hFont2, MAKELPARAM(TRUE, 0));

    options = CreateWindowEx(0, L"BUTTON", L"więcej opcji", WS_CHILD | WS_VISIBLE | BS_FLAT, 180, 0, 240, 23, hwnd, NULL, hInstance, NULL);    
    SendMessage(options, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));

    help = CreateWindowEx(0, L"BUTTON", L"pomoc", WS_CHILD | WS_VISIBLE | BS_FLAT, 0, 0, 180, 23, hwnd, NULL, hInstance, NULL);
    SendMessage(help, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));
    about = CreateWindowEx(0, L"BUTTON", L"o programie", WS_CHILD | WS_VISIBLE | BS_FLAT, 420, 0, 180, 23, hwnd, NULL, hInstance, NULL);
    SendMessage(about, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));

    bar1 = CreateWindow(L"STATIC", L"", WS_VISIBLE | WS_CHILD | SS_LEFT, 0, 40, 20, 205, hwnd, NULL, hInstance, NULL);
    bar2 = CreateWindow(L"STATIC", L"", WS_VISIBLE | WS_CHILD | SS_LEFT, 580, 40, 20, 205, hwnd, NULL, hInstance, NULL);
    bar4 = CreateWindow(L"STATIC", L"", WS_VISIBLE | WS_CHILD | SS_LEFT, 20, 40, 15, 205, hwnd, NULL, hInstance, NULL);
    bar5 = CreateWindow(L"STATIC", L"", WS_VISIBLE | WS_CHILD | SS_LEFT, 565, 40, 15, 205, hwnd, NULL, hInstance, NULL);
    bar3 = CreateWindow(L"STATIC", L"", WS_VISIBLE | WS_CHILD | SS_LEFT, 0, 233, 600, 30, hwnd, NULL, hInstance, NULL);

    tekst = CreateWindow(L"STATIC", L"", WS_VISIBLE | WS_CHILD | SS_CENTER, 0, 23, 600, 20, hwnd, NULL, hInstance, NULL);
    SendMessage(tekst, WM_SETFONT, (WPARAM)hFont3, MAKELPARAM(FALSE, 0));

    tekst2 = CreateWindow(L"STATIC", L".xml -> .rpp", WS_VISIBLE | WS_CHILD | SS_CENTER, 0, 236, 600, 20, hwnd, NULL, hInstance, NULL);
    SendMessage(tekst2, WM_SETFONT, (WPARAM)hFont3, MAKELPARAM(FALSE, 0));

    if (hwnd == NULL)
    {
        MessageBox(NULL, L"nie udało się otworzyć okna", L"error", MB_ICONERROR);
        return 1;
    }
    if (tekst == NULL)
    {
        MessageBox(NULL, L"nie udało się utworzyć przycisku", L"error", MB_ICONERROR);
        return 1;
    }

    HANDLE hIcon = (HICON)LoadImage(NULL, L"2.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);
    if (hIcon) 
    {
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, hIcon);
        SendMessage(hwnd, WM_SETICON, ICON_BIG, hIcon);

        SendMessage(GetWindow(hwnd, GW_OWNER), WM_SETICON, ICON_SMALL, hIcon);
        SendMessage(GetWindow(hwnd, GW_OWNER), WM_SETICON, ICON_BIG, hIcon);
    }

    DragAcceptFiles(hwnd, TRUE);
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return message.wParam;
}

//obsługa zdarzeń
int i = 1, j = 1, k = 1;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, HINSTANCE hInstance, int nCmdShow)
{

    HBRUSH hBrush3 = CreateSolidBrush(RGB(199, 218, 230));
    HBRUSH hBrush2 = CreateSolidBrush(RGB(228, 230, 228));
    HBRUSH hBrush = CreateSolidBrush(RGB(226, 249, 255)); //ramka
    HBRUSH hBrush4 = CreateSolidBrush(RGB(180, 200, 200));
    HFONT hFont2 = CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, VARIABLE_PITCH, TEXT("Century Gothic"));
    HFONT hFont = CreateFont(18, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, VARIABLE_PITCH, TEXT("Century Gothic"));

    if (!run)
    {
        switch (msg)
        {
        case WM_CLOSE:
            DeleteObject(hBrush);
            DeleteObject(hBrush2);
            DeleteObject(hBrush3);
            DeleteObject(hBrush4);
            DeleteObject(hFont);
            DeleteObject(hFont2);
            DestroyWindow(hwnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_DROPFILES:
        {
            HDROP drop = (HDROP)wParam;
            UINT filePathesCount = DragQueryFileA(drop, 0xFFFFFFFF, NULL, 512);
            wchar_t* fileName = NULL;
            UINT longestFileNameLength = 0;
            char s[250];
            int d;

            for (UINT i = 0; i < filePathesCount; ++i)
            {
                UINT fileNameLength = DragQueryFileA(drop, i, NULL, 512) + 1;

                if (fileNameLength > longestFileNameLength)
                {
                    longestFileNameLength = fileNameLength;
                    fileName = (wchar_t*)realloc(fileName, longestFileNameLength * sizeof(*fileName));
                }
                DragQueryFileA(drop, i, fileName, fileNameLength);
            }

            strcpy(s,fileName);
            SetWindowTextA(tekst, s);
            if (strstr(s, ".xml") != 0)
            {
                opensaveDROP(fileName);
            }
            else
            {
                clear();
                MessageBox(NULL, L"złe rozszerzenie pliku", L"error", MB_ICONERROR);               
            }

            free(fileName);
            DragFinish(drop);
            break;
        }
        case WM_COMMAND: //reakcje programu na działania użytkownika
            if ((HWND)lParam == helpT)
            {
                ShellExecute(0, 0, L"https://github.com/MateuszGawrysiak/translator", 0, 0, SW_SHOW);
                DestroyWindow(helpT);                
                SetWindowTextA(help, "pomoc");
                j *= -1;
                break;
            }
            if ((HWND)lParam == aboutT)
            {
                ShellExecute(0, 0, L"https://linktr.ee/mcgp", 0, 0, SW_SHOW);
                DestroyWindow(aboutT);                
                SetWindowTextA(about, "o programie");
                k *= -1;
                break;
            }
            if ((HWND)lParam == std && j+k==2)
            {
                opcja = 1;
                opensave();
                break;
            }
            if ((HWND)lParam == dbg && j+k==2)
            {
                opcja = 2;
                opensave();
                break;
            }
            if ((HWND)lParam == pth && j+k==2)
            {
                opcja = 3;
                opensave();
                break;
            }
            if ((HWND)lParam == help)
            {
                if (k == -1)
                {
                    DestroyWindow(aboutT);
                    SetWindowTextA(about, "o programie");
                    k *= -1;
                }
                if (i == -1)
                {
                    //SetWindowTextA(options, "więcej opcji");
                }
                if (j == 1)
                {                    
                    helpT = CreateWindow(L"STATIC", L"Program konwertuje pliki .xml w standardzie Adobe Premiere Pro / Final Cut Pro na pliki .rpp programu Reaper."
                        "\n1. Opcja \"standard\" - wybór pliku oraz normalny przebieg translacji."
                        "\n2. Opcja \"debug\" - wybór pliku oraz powiadomienia o każdym błędzie konwersji."
                        "\n3. Opcja \"no path\" - zapis pustej ścieżki dostępu w celu odciążenia wynikowego projektu. Opcja zalecana, gdy do projektu programu Reaper "
                        "importujemy gotowy film - umożliwia podgląd na \"timeline\" i nie wymaga ładowania mnóstwa niepotrzebnych danych."
                        "\nZnane błędy: brak konwersji lokalizacji ponownych wystąpień plików projektu, jeśli nie występują one po sobie."
                        "\n                                     >> kliknij, by przejść do strony projektu <<", WS_VISIBLE | WS_CHILD | SS_LEFT | SS_NOTIFY, 20, 40, 560, 193, hwnd, NULL, hInstance, NULL);
                    SendMessage(helpT, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(FALSE, 0));
                    SetWindowTextA(help, "zamknij");
                }
                else
                {
                    DestroyWindow(helpT);
                    SetWindowTextA(help, "pomoc");
                }
                j *= -1;
                break;
            }
            if ((HWND)lParam == about)
            {                
                if (j == -1)
                {
                    DestroyWindow(helpT);
                    SetWindowTextA(help, "pomoc");
                    j *= -1;
                }
                if (i == -1)
                {
                    //SetWindowTextA(options, "więcej opcji");
                }
                if (k == 1)
                {
                    SetWindowTextA(about, "zamknij");
                    aboutT = CreateWindow(L"STATIC", L"<< translator wersja 1.0 - 19.05.2021 >>" //BRING TO FRONT
                    "\nkonwersja plików projektów .xml na .rpp"
                    "\nopracowany dla wersji Reaper 6.19 i kolejnych\n"
                    "\nMateusz Gawrysiak"
                    "\n\nkorzystanie z programu oznacza świadomość ryzyk"
                    "\n>> kliknij, by otworzyć stronę autora <<", WS_VISIBLE | WS_CHILD | SS_CENTER | SS_NOTIFY, 100, 65, 400, 140, hwnd, NULL, hInstance, NULL);
                    SendMessage(aboutT, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(FALSE, 0));
                }
                else
                {
                    DestroyWindow(aboutT);
                    SetWindowTextA(about, "o programie");
                }
                k *= -1;

                break;
            }
            if ((HWND)lParam == options)
            {
                int flaga = 0;
                if (j+k==0)
                {
                    //i *= -1;
                }
                if (j == -1)
                {
                    DestroyWindow(helpT);
                    SetWindowTextA(help, "pomoc");
                    j *= -1;
                    i=-1;
                    flaga++;
                }
                if (k == -1)
                {
                    DestroyWindow(aboutT);
                    SetWindowTextA(about, "o programie");
                    k *= -1;
                    i=-1;
                    flaga++;
                }
                if (i == 1)
                {      
                    SetWindowTextA(tlo, "\nkliknij, by uruchomić w wybranym trybie");
                    SetWindowTextA(options, "mniej opcji");
                    SetWindowTextA(std, "standard");

                    dbg = CreateWindowEx(0, L"BUTTON", L"debug", WS_CHILD | WS_VISIBLE | BS_FLAT, 130, 120, 100, 40, hwnd, NULL, hInstance, NULL);
                    SendMessage(dbg, WM_SETFONT, (WPARAM)hFont2, MAKELPARAM(TRUE, 0));

                    pth = CreateWindowEx(0, L"BUTTON", L"no path", WS_CHILD | WS_VISIBLE | BS_FLAT, 370, 120, 100, 40, hwnd, NULL, hInstance, NULL);
                    SendMessage(pth, WM_SETFONT, (WPARAM)hFont2, MAKELPARAM(TRUE, 0));
                }
                else if (flaga == 0)
                {                  
                    SetWindowTextA(tlo, "\nkliknij, by uruchomić\n\n\n\nlub przesuń plik na okno programu");
                    SetWindowTextA(options, "więcej opcji");
                    SetWindowTextA(std, "START");
                    DestroyWindow(dbg);
                    DestroyWindow(pth);

                }
                else
                {
                    i *= -1;
                }
                
                i *= -1;
                break;
            }
        case WM_CTLCOLORSTATIC: //zmiana kolorów interfejsu
        {
            if (tlo == (HWND)lParam)
            {
                HDC hdcStatic = (HDC)wParam;
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                SetBkColor(hdcStatic, RGB(199, 218, 230));
                UpdateWindow(tlo);
                
                return (INT_PTR)hBrush3;
                break;
            }
            if (tlo2 == (HWND)lParam)
            {
                HDC hdcStatic = (HDC)wParam;
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                SetBkColor(hdcStatic, RGB(199, 218, 230));

                return (INT_PTR)hBrush;
                break;
            }
            if (bar4 == (HWND)lParam)
            {
                HDC hdcStatic = (HDC)wParam;
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                SetBkColor(hdcStatic, RGB(230, 230, 230));

                return (INT_PTR)hBrush2;
                break;
            }
            if (bar5 == (HWND)lParam)
            {
                HDC hdcStatic = (HDC)wParam;
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                SetBkColor(hdcStatic, RGB(230, 230, 230));

                return (INT_PTR)hBrush2;
                break;
            }
            DeleteObject(hBrush);
            DeleteObject(hBrush2);
            DeleteObject(hBrush3);
            DeleteObject(hBrush4);
            DeleteObject(hFont);
            DeleteObject(hFont2);

            break;
        }
        default:
            DeleteObject(hBrush);
            DeleteObject(hBrush2);
            DeleteObject(hBrush3);
            DeleteObject(hBrush4);
            DeleteObject(hFont);
            DeleteObject(hFont2);

            return DefWindowProc(hwnd, msg, wParam, lParam);
        }        
    }
    else
    {
        DeleteObject(hBrush);
        DeleteObject(hBrush2);
        DeleteObject(hBrush3);
        DeleteObject(hBrush4);
        DeleteObject(hFont);
        DeleteObject(hFont2);

        return DefWindowProc(hwnd, msg, wParam, lParam);
    }  

    return 0;
}
