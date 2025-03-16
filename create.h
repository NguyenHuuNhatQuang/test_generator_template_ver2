#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

namespace Create
{
    string str (long long a)
    {
        if(a == 0) return "0";
        if(a < 0) return "-" + str(-a);
        string ans = "";
        for(int i = 1; i <= 4; i ++)
        {
            ans = "0" + ans;
            ans[0] = (a % 10) + '0';
            a /= 10;
        }
        return ans;
    }

    void copy_test (string prob_name, string subtask, int iTest)
    {
        cerr << "Dang tao thu muc chua test #" << iTest << ".\n";

        string folder_link = prob_name + "\\" + str(iTest) + "_" + subtask;
        string cmd = "if exist \"" + folder_link + "\\\" (exit /b 1) else (exit /b 0)";

        if (system (cmd.c_str ()))
            system(("rmdir /s /q " + folder_link).c_str());

        system(("mkdir " + folder_link).c_str());

        cerr << "Dang sao chep cac file input va output.\n";

        cmd = "copy \"" + prob_name + ".inp\" \"" + folder_link + "\"";
        system (cmd.c_str ());

        cmd = "copy \"" + prob_name + ".out\" \"" + folder_link + "\"";
        system (cmd.c_str ());

        cerr << "Da sao chep xong.\n";
    }

    void create_root (string prob_name)
    {
        string cmd = "if exist \"" + prob_name + "\\\" (exit /b 1) else (exit /b 0)";
        if (system (cmd.c_str ()))
        {
            cerr << "Xoa bo test cu (y/n): ";
            string _ok;
            cin >> _ok;

            while (_ok != "y" and _ok != "n")
            {
                cerr << "Nhap lai (y/n): ";
                cin >> _ok;
            }

            if (_ok == "y")
            {
                system(("rmdir /s /q " + prob_name).c_str());
                cerr << "Da xoa bo test cu.";
            }
            else
            {
                cerr << "Bo test moi se ghi them vao hoac de len bo test cu.";
            }

            cerr << '\n';
        }

        if (!system (cmd.c_str ())) system(("mkdir " + prob_name).c_str());
    }

    void compile_solution ()
    {
        cerr << "Dang bien dich file loi giai.\n";

        system("g++ -g -pipe -O2 -s -static -lm -DTHEMIS -Wl,--stack,66060288 solution.cpp -o solution.exe");
    }
}
