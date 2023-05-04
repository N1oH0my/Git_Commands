#include <iostream>
using namespace std;


void calc(int p, char* s, int res)
{
    char c[] = { '+','-',0 };
    for (int i = 0; i < 3; i++)
        if (i || p)
        {
            s[p] = c[i];
            if (p < 16) calc(p + 2, s, res);
            else
            {
                int cf = 1;
                int num, sum;
                num = sum = 0;
                for (int i = 0; i < 18; i++)
                    if (s[i] >= '1' && s[i] <= '9') num = num * 10 + cf * (s[i] - '0');
                    else
                        if (s[i])
                        {
                            sum += num;
                            num = 0;
                            cf = s[i] == '+' ? 1 : -1;
                        }
                sum += num;
                if (sum == res)
                {
                    for (int i = 0; i < 18; i++)
                        if (s[i]) cout << s[i];
                    cout << "=" << res << endl;
                }
            }
        }
}
void main(int argc, char** argv)
{
    char s[] = " 1 2 3 4 5 6 7 8 9";
    int res = 122;
    calc(0, s, res);
    std::cin.get();
}