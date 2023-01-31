#include <iostream>
#include <vector>
using namespace std;

struct job
{
	int start;
	int finish;
	string title;
};

void insertion_sort(job* arr, int n)
{
	int i, j;
	job key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j].finish > key.finish)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

vector<job> maximize_productivity(job  a[], int n)
{
	vector<job> result;
	insertion_sort(a, n);
	result.push_back(a[0]);
	int i = 0;
	int j = 1;
	while (i<n && j <= n)
	{
		if (a[i].finish < a[j].start)
		{
			result.push_back(a[j]);
			i++;
		}
		j++;
	}
	return result;
}

int main()
{
	cout << "First example:\n\n";
	job a[3];
	a[0].start = 22; a[0].finish = 30; a[0].title = "Job 1";
	a[1].start = 10; a[1].finish = 20; a[1].title = "Job 2";
	a[2].start = 12; a[2].finish = 25; a[2].title = "Job 3";

	vector<job> result1;
	result1 = maximize_productivity(a, 3);

	cout << "Number of jobs to be taken: " << result1.size() << endl << endl;
	cout << "Jobs to be taken are: " << endl;
	for (int i = 0; i < result1.size(); i++)
	{
		cout << result1[i].title << ", and it starts from: " << result1[i].start << ", and it finishs at: " << result1[i].finish << endl;
	}

	cout << "\n________________________________________________________________\n";

	cout << "\nSecond example:\n\n";
	job b[6];
	b[0].start = 1; b[0].finish = 2; b[0].title = "Job 1";
	b[1].start = 3; b[1].finish = 4; b[1].title = "Job 2";
	b[2].start = 0; b[2].finish = 6; b[2].title = "Job 3";
	b[3].start = 5; b[3].finish = 7; b[3].title = "Job 4";
	b[4].start = 8; b[4].finish = 9; b[4].title = "Job 5";
	b[5].start = 5; b[5].finish = 9; b[5].title = "Job 6";

	vector<job> result2;
	result2 = maximize_productivity(b, 6);

	cout << "Number of jobs to be taken: " << result2.size() << endl << endl;
	cout << "Jobs to be taken are: " << endl;
	for (int i = 0; i < result2.size(); i++)
	{
		cout << result2[i].title << ", and it starts from: " << result2[i].start << ", and it finishs at: " << result2[i].finish << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}