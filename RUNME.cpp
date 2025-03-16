#include <bits/stdc++.h>
#define GENERATOR
#include "generator.cpp"
#include "create.h"

using namespace std;

int main ()
{
    int testnum;
    cout << "Nhap so luong test: ";
    cin >> testnum;

    string prob_name;
    cout << "Nhap ma bai: ";
    cin >> prob_name;

    using namespace Create;
    create_root (prob_name);
    compile_solution ();

    cerr << "Bat dau sinh test\n----------\n";

    for (int i = 1; i <= testnum; i ++)
    {
        freopen ((prob_name + ".inp").c_str (), "w", stdout);

        int input_gen_time, solution_exec_time;
        clock_t start_time;

        cerr << "Test #" << i << ":\n";

        start_time = clock ();
        Gen::gen (i);
        input_gen_time = 1000.0 * (clock() - start_time) / CLOCKS_PER_SEC;

        fclose (stdout);

        cerr << "Da sinh xong input. Dang chay file loi giai.\n";

        start_time = clock ();
        system ("solution.exe");
        solution_exec_time = 1000.0 * (clock() - start_time) / CLOCKS_PER_SEC;

        cerr << "Da sinh xong output.\n";

        copy_test (prob_name, subtask, i);

        cerr << "Ket thuc qua trinh sinh test #" << i << ".\n";
        cerr << "Thoi gian sinh input: " << input_gen_time << " ms.\n";
        cerr << "Thoi gian chay loi giai: " << solution_exec_time << " ms.\n";
        cerr << "-----\n";
    }

    cerr << "Ket thuc chuong trinh.\n";

    return 0;
}
