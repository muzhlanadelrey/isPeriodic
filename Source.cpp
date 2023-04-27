#include <iostream>
#include <string>
using namespace std;

void LPS(string pat, int* lps)
{
    int j = 0;

    lps[0] = 0;

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void IsKPeriodic(int K, const string& str)
{
    if (K < 1)
    {
        cout << "K должно быть больше 0!" << endl;
    }
    else
    {
        string pat; 
        for (int i = 0; i < K; ++i)
            pat.push_back(str[i]);

        int* lps = new int[pat.size()];

        LPS(pat, lps);

        int i = 0;
        int j = 0;
        int value = 0;
        while (i < str.size()) {
            if (pat[j] == str[i])
            {
                j++;
                i++;
            }
            if (j == pat.size()) {
                value++; 
                j = lps[j - 1];
            }

            else if (i < str.size() && pat[j] != str[i]) {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i = i + 1;
                }
            }
        }
        if (K * value == str.size())
            cout << "строка " << str << " кратна " << K << endl;
        else cout << "строка " << str << " не кратна " << K << endl;
        delete[] lps;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    string txt = "ababababbababbabbbbbb"; // проверка
    int K = 4; 
    IsKPeriodic(K, txt);
    return 0;
}