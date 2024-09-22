#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
using namespace std;

#define MY_ERROR_CODE 42

int number_of_words = 0;

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();

void output_text(char*, int);
void three_sentence(char*);
void output_array(int*);
void sort_words(char**&);
void swap(char*&, char*&);
void output_words(char**);
void bin(int);

int count_words(char*, const int);
int num(char*);
int* word_count(char*);

char** tocenisation(char*);
char* text_input();


int main()
{
	system("chcp 1251");

	int number_of_task;
	cout << "List of tasks" << endl;
	cout << "Task 1" << endl;
	cout << "Task 2" << endl;
	cout << "Task 3" << endl;
	cout << "Task 4" << endl;
	cout << "Task 5" << endl;
	cout << "Task 6" << endl;
	cout << "Enter the job number to run it" << endl;

	cin >> number_of_task;
	system("cls");

	switch (number_of_task)
	{
	case 1:
	{
		task1();
		break;
	}
	case 2:
	{
		task2();
		break;
	}
	case 3:
	{
		task3();
		break;
	}
	case 4:
	{
		task4();
		break;
	}
	case 5:
	{
		task5();
		break;
	}
	case 6:
	{
		task6();
		break;
	}
	default:
	{
		cout << "There is no such task" << endl;
	}
	}
	return 0;
}


void task1()
{
	const int size = 100;
	char* text = new char[size] {' '};

	cout << "Enter text" << endl;
	cin.getline(text, size - 1);
	output_text(text, size);

	delete text;
}

void output_text(char* text, int size)
{
	int num_sen = 0;
	char* pch;
	pch = strtok(text, ".!?");

	while (pch != NULL)
	{
		cout << pch;
		pch = strtok(NULL, ".!?");
		getchar();
		num_sen++;
	}
	cout << "Number of sentences in the text: " << num_sen;
}

void task2()
{
	cout << "Enter text." << endl;
	int SIZE = 500;
	char* text = new char[SIZE];
	cin.getline(text, SIZE);
	cout << endl;

	strtok(text, ".!?");
	cout << "Number of words in first sentence =" << count_words(text, SIZE);


}

int count_words(char* text, const int SIZE)
{
	int num_words = 0;

	text = strtok(text, " .,;");
	while (text != NULL)
	{
		text = strtok(NULL, " .,;");
		num_words++;
	}

	return num_words;
}

void task3()
{
	char* text = text_input();

	text = strtok(text, ".!?");
	if (*(text + strlen(text) + 1) != '\0')
	{
		text = strtok(NULL, ".!?");

		int temp = num(text);
		if (temp == MY_ERROR_CODE) cout << "There are no numbers in the second sentence";
		else
		{
			cout << "The number in the second sentence is =";
			bin(temp);
		}
	}
	else cout << "There is no second sentence in the text.";
}

char* text_input()
{
	cout << "Enter text" << endl;
	const int SIZE = 500;
	char* text = new char[SIZE];
	cin.getline(text, SIZE);
	cout << endl;

	return text;
}

int num(char* text)
{
	char* pnum = strpbrk(text, "0123456789");
	if (pnum == nullptr) return MY_ERROR_CODE;

	if (*(pnum - 1) == '-') pnum = pnum - 1;

	return strtol(pnum, NULL, 0);
}

void bin(int number)
{
	for (int pow = 31; pow >= 0; pow--)
	{
		auto var = number & (1 << pow);
		if (var) printf("1");
		else printf("0");
	}
}

void task4()
{
	char* text = text_input();

	char* sentense1 = strtok(text, ".!?");
	char* sentense2 = strtok(NULL, ".!?");
	char* sentense3 = strtok(NULL, ".!?");

	if (sentense1 == NULL || sentense2 == NULL || sentense3 == NULL) {
		cout << "No three sentences";
	}

	char* p_last = sentense3 + strlen(sentense3);
	int number = 3;
	for (; p_last >= text; p_last--)
	{
		if (*p_last == '\0')
		{
			cout << endl << number << ": ";
			number--;
		}
		cout << *p_last;
	}
	three_sentence(text);
}

void print_reverse(char* buffer)
{
	auto size = strlen(buffer);
	for (char* ptr = buffer + size; ptr >= buffer; ptr--)
	{
		cout << *ptr;
	}
}

void three_sentence(char* text)
{
	char* plust = text;
	int count = 0;

	for (;; plust++)
	{
		if (*plust == '.' || *plust == '?' || *plust == '!') count++;
		if (*plust == '\0')
		{
			break;
		}
		if (count == 3) break;
	}

	int number = 3;

	if (count == 3)
	{
		for (; plust >= text; plust--)
		{
			if (*plust == '.' || *plust == '?' || *plust == '!')
			{
				cout << endl << number << ": ";
				number--;
			}
			cout << *plust;
		}

	}
	else cout << "There are no three sentences in the text";
}

void task5()
{
	char* text = text_input();
	int* words = word_count(text);
	output_array(words);
}

int* word_count(char* text)
{
	int i = 0;
	int* word_count = new int[20] {0};
	char* pch = strtok(text, " .,!?;-:");

	while (pch != nullptr)
	{
		i = strlen(pch);
		word_count[i]++;
		pch = strtok(NULL, " .,!?;-:");
	}

	return word_count;
}

void output_array(int* array)
{
	int size = 20;

	cout << "Number of letters | Word count" << endl;

	for (int i = 1; i < size; i++)
	{
		if (array[i] == 0) continue;
		cout << i << '\t' << array[i] << endl;
	}
}
//�� ����� ��������, ��� ���������
void task6()
{
	char* text = text_input();
}

char** tocenisation(char* text)
{
	int i = 0;
	text = strtok(text, " .,?!;-=");
	char** words = new char* [250] { nullptr };

	while (text != nullptr)
	{
		if ((int)*text < -33) *text += 32;
		words[i++] = text;
		text = strtok(NULL, " .,?!;-=");
		number_of_words++;
	}

	return words;
}

void sort_words(char**& words)
{
	for (int i = 0; i < number_of_words - 1; i++)
	{
		for (int j = 0; j < number_of_words - 1; j++)
		{
			if (strcoll(words[j], words[j + 1]) > 0) swap(words[j], words[j + 1]);
		}
	}
}

void swap(char*& first, char*& second)
{
	char* temp = first;
	first = second;
	second = temp;
}

void output_words(char** words)
{
	auto ptr = words[0];
	while (ptr != nullptr)
	{

		ptr++;
	}
	for (int i = 0; i < number_of_words; i++)
	{
		cout << words[i] << ' ';
	}
}