#include "assignment_1.h"


void as_1_1(int N, vector<int>& lst) 
{
	// 버블 정렬을 사용
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (lst[j] > lst[j + 1])
			{
				int temp = lst[j];
				lst[j] = lst[j + 1];
				lst[j + 1] = temp;
			}
		}
	}
	return ;
}


void as_1_2(int N, vector<string>& lst) 
{
	sort(lst.begin(), lst.end()); // algorithm 라이브러리 사용
	return ;
}


string as_1_3(int A, int B, const string V) 
{
	string result; // 10진수를 B진수로 변환
	int temp = 0; // A진수를 10진수로 변환
	// A진수를 10진수로 변환하는 과정
	for(int i = 0; i < V.size(); i++)
	{
		temp = temp * A + (V[i] - '0');
	}
	// 10진수를 B진수로 변환하는 과정
	if (temp == 0) 
	{
		result = "0";
	} 
	else 
	{
		while (temp > 0) 
		{
			result = char(temp % B + '0') + result;
			temp /= B;
		}
	}

	return (result);
}


string as_1_4(int A, int B, const string V) 
{
	string result; // 10진수를 B진수로 변환
	long long temp = 0; // A진수를 10진수로 변환, 오버플로우 방지를 위한 long long 자료형 사용
	// A진수를 10진수로 변환하는 과정
	for(int i = 0; i < V.size(); i++)
	{
		if(V[i] >= '0' && V[i] <= '9') 
		{
			temp = temp * A + (V[i] - '0');
		} 
		else if(V[i] >= 'A' && V[i] <= 'Z') 
		{
			temp = temp * A + (V[i] - 'A' + 10);
		}
	}
	// 10진수를 B진수로 변환하는 과정
	if(temp == 0)
	{
		result = "0";
	}
	else
	{
		while(temp > 0)
		{
			int remainder = temp % B;
			if(remainder < 10)
			{
				result = char(remainder + '0') + result;
			}
			else
			{
				result = char(remainder - 10 + 'A') + result;
			}
			temp /= B;
		}
	}
	return (result);
}