#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cards;

bool is_in_cards(int num)
{
    int left = 0, right = cards.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (cards[mid] == num)
            return true;
        else if (cards[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int card;
        cin >> card;
        cards.push_back(card);
    }
    sort(cards.begin(), cards.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        if (is_in_cards(num))
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
}