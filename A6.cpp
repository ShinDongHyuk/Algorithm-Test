#include <iostream>

using namespace std;

int paper[111][111];
int H[111];
int main()
{
	int max = 1;
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		for (int a = x; a < x + 10; ++a)
			for (int b = y; b < y + 10; ++b)
				paper[a][b] = 1;
	}

	for (int i = 2; i <= 100; ++i)
	{
		for (int j = 2; j <= 100; ++j)
		{
			if (paper[i][j] == 1)
				paper[i][j] += paper[i][j - 1];
		}
	}
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (paper[i][j] != 0)
			{
				int width = 0;
				int height = 1;
				for (int k = 1; k <= 100; ++k)
					H[k] = 0;

				for (int k = j - paper[i][j] + 1; k <= j; ++k)
				{
					H[k] = paper[i][k];
					if (H[k] > 0)
						width++;
				}

				bool flg = true;
				for (int h = i - 1; h > 0; --h)
				{
					for (int k = j - paper[i][j] + 1; k <= j; ++k)
					{
						if (H[k] > 0 && paper[h][k] > 0)
							continue;
						else
						{
							flg = false;
							break;
						}
					}
					if (flg)
						height++;
					else
						break;
				}
				flg = true;
				for (int h = i + 1; h <= 100; ++h)
				{

					for (int k = j - paper[i][j] + 1; k <= j; ++k)
					{
						if (H[k] > 0 && paper[h][k] > 0)
							continue;
						else
						{
							flg = false;
							break;
						}
					}
					if (flg)
						height++;
					else
						break;
				}

				if (max < height * width)
					max = height * width;
			}
		}
	}


	printf("%d\n", max);

	return 0;
}