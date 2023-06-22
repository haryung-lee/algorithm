#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dollcount[200001];
int main()
{
	long long N, Q = 0, cnt = 0;
	long long answer = 0;
	cin >> N;
	vector<int> matryoshka(N);
	for (int i = 0; i < N; i++)
	{
		cin >> matryoshka[i];
		dollcount[matryoshka[i]]++;
	}
	sort(matryoshka.begin(), matryoshka.end());

	for (int i = 0; i < N; i++)
	{
		if (dollcount[matryoshka[i]] >= 1)
		{
			dollcount[matryoshka[i]]--;
			Q = matryoshka[i];
			cnt = 1;
			for (int j = matryoshka[i] + 1;; j++)
			{
				if (dollcount[j] >= 1)
				{
					Q = j;
					dollcount[j]--;
					cnt++;
				}
				else
				{
					answer += Q * cnt;
					break;
				}
			}
		}
	}
	
	cout << answer;

	return 0;
}