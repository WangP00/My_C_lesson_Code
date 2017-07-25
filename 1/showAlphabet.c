#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	//initialize "vigenere"
	char alphabets[26][26];
	int i;
	for ( i = 0; i <= 25; ++i)
	{
		for (int j = 0; j <= 25; ++j)
		{
			int temp;
			if (j + i >= 26) temp = j + i - 26;
			else temp = j + i;
			alphabets[i][j] = 'A' + temp;
		}
	}

	// print the result
	for ( i = 0; i <= 25; ++i)
	{
		for (int j = 0; j <= 25; ++j) printf("%c", alphabets[i][j]);
		printf("\n");
	}

	// get secret_key in upper case
	char input_key[100];
	char secret_key[100];
	i = 0;
	int j = 0;
	
	while (scanf("%c", &input_key[i]) == 1) {
		if (input_key[i] == 32)
		{
			printf("There is Space!!\n");
		} else if (input_key[i] == '\r' || input_key[i] == '\n') {
			break;
		} else if (input_key[i] < 65 || (input_key[i] > 90 && input_key[i] < 97) || input_key[i] > 122) {
			printf("There is punctuation!!\n");
		} else {
			if (input_key[i] >= 97)
			{
				secret_key[j] = input_key[i] - 32;
			} else {
				secret_key[j] = input_key[i];
			}
			j++;
		}
		i++;
	}

	printf("secret_key:%s\n", secret_key);

	// get content text in upper case
	char input_text[100];
	char convert_text[1000];
	i = 0;
	j = 0;
	while (scanf("%c", &input_text[i]) == 1) {
		if (input_text[i] == 32)
		{
			printf("There is Space!!\n");
		} else if (input_text[i] == '\r' || input_text[i] == '\n') {
			break;
		} else if (input_text[i] < 65 || (input_text[i] > 90 && input_text[i] < 97) || input_text[i] > 122) {
			printf("There is punctuation!!\n");
		} else {
			if (input_text[i] >= 97)
			{
				convert_text[j] = input_text[i] - 32;
			} else {
				convert_text[j] = input_text[i];
			}
			j++;
		}
		i++;
	}

	printf("convert_text:%s\n", convert_text);

	// do the encryption
	int len_secret = strlen(secret_key);
	int len_text = strlen(convert_text);
	char encoded_text[1000];
	int count = 0;
	for (int a = 0; a < len_text; ++a)
	{
		// // 带转换的字符
		// convert_text[a]       lie
		// // 相应的密钥
		// secret_key[a%len_secret]   hang
// 明文  T
// 密钥  R
// 在R行代替T的为K
		for (int row = 0; row <= 25; ++row)
		{
			for (int col = 0; col <= 25; ++col)
			{

				if (row == secret_key[a % len_secret] - 'A' && col == convert_text[a] - 'A')
				{
					encoded_text[count] = alphabets[row][col];
					count ++;
				}
			}
		}

	}
	printf("encoded_text:%s\n", encoded_text);

	return 0;
}