// 1) 백트랙킹으로 해결
// #include <iostream>
// #include <vector>

// using namespace std;

// int visited[10];
// vector<int> left_tall_nums;

// bool check_left_tall(vector<int> v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         int cnt = 0;
//         for (int j = 0; j < i; j++)
//         {
//             if (v[j] > v[i])
//                 cnt++;
//         }
//         if (cnt != left_tall_nums[v[i] - 1])
//             return false;
//     }
//     return true;
// }

// void backtracking(int n, vector<int> v)
// {
//     if (v.size() == n)
//     {
//         if (check_left_tall(v))
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 cout << v[i] << " ";
//             }
//             cout << "\n";
//         }
//     }
//     else
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (!visited[i])
//             {
//                 visited[i] = 1;
//                 v.push_back(i + 1);
//                 backtracking(n, v);
//                 v.pop_back();
//                 visited[i] = 0;
//             }
//         }
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         int temp;
//         cin >> temp;
//         left_tall_nums.push_back(temp);
//     }

//     vector<int> v;
//     backtracking(n, v);
// }

// 2) 그리디 하게 해결

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v;
    v.resize(10);

    for (int i = 0; i < N; i++)
    {
        int tall_num;
        cin >> tall_num;

        for (int j = 0; j < N; j++)
        {
            if (tall_num == 0 && v[j] == 0)
            {
                v[j] = i + 1;
                break;
            }
            else if (v[j] == 0)
                tall_num--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
}