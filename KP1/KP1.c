#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define M 2
#define N 8
#define O 8

int*** vd();/*Выделяем память под трёхмерный массив*/
int** vd1();/*Выделяем память под двумерный массив*/
int txt(int*** A, char my[N]);/*Считываем из файла значения и заполняем 3 массива*/ //
int array_A(int*** A, int*** A1, int*** A2, int*** A3);/*Суммируем 3 массива*/ //
int array_och_0(int** och_win, int** och_loss);/*Присваиваем массиву значение 0*/ //
int sum_och_0(int* sum_och);/*Присваиваем массиву значение 0*/ //
int tabl(int*** A);/*Выводим массив с забитыми и пропущенными мячами*/ //
int points(int** och_win, int** och_loss, int*** A1);/*Расчитываем очки в зависимости от трёх массивов (каждый массив - 1 сыгранная игра) и заносим очки в отдельный массив*/ //
int print_points(int** och_win, int** och_loss);/*Выводим массив с очками*/ //
int sum_och(int* sum_och_, int** och_win);/*Суммируем очки для сортировки*/ //
int sumsort(int* sum_och_win, int number[N]);/*Сортируем очки*/ //
int sum_array(int*** A, int* sum_array_A);/*Суммируем мячи для сортировки*/
int searh(int* sum_array_A);/*Выводим команду с наибольшим кол-вом забитых или пропущенных мячей*/
int dif_array_A(int*** A);/*Выводим разность между суммами забитых и пропущенных мячей*/
int div_array_A(int*** A);/*Выводим отношение суммы забитых мячей к сумме пропущенных*/
int change_array_A(int*** A);/*Измененяем количество забитых и пропущенных мячей за игру в ячейке*/

void main()
{
	setlocale(LC_ALL, "rus");

	int k = 1;

	int number[N] = { 1,2,3,4,5,6,7,8 };//Массив с номерами команд

	char my1[8] = { "my1.txt" };//Массивы с названием .txt файлов для заполнения массивов
	char my2[8] = { "my2.txt" };
	char my3[8] = { "my3.txt" };

	int*** A1 = vd();//Выделение памяти под трёхмерные массивы
	int*** A2 = vd();
	int*** A3 = vd();
	int*** A = vd();

	int** och_win = vd1();//Выделение памяти под двумерные массивы
	int** och_loss = vd1();

	int* sum_och_win = (int**)malloc(N * sizeof(int*));//Выделение памяти под одномерные массивы
	int* sum_och_loss = (int**)malloc(N * sizeof(int*));
	int* sum_array_A = (int**)malloc(N * sizeof(int*));

	txt(A1, my1);//Чтение из файла и заполнение массивов
	txt(A2, my2);
	txt(A3, my3);

	array_A(A, A1, A2, A3);//Объединение значений трёх массивов в один
	array_och_0(och_win, och_loss);//Присваивание массиву значения 0
	sum_och_0(sum_och_win);//Присваивание массиву значения 0
	sum_och_0(sum_och_loss);//Присваивание массиву значения 0
	points(och_win, och_loss, A1);//Подсчёт очков в зависимости от забитых и пропущенных мячей
	points(och_win, och_loss, A2);
	points(och_win, och_loss, A3);
	sum_array(A, sum_array_A);//Сумма мячей каждой команды и занесение этих значений в отдельный массив
	sum_och(sum_och_win, och_win);//Сумма очков каждой команды и занесение этих значений в отдельный массив

	while (1) {
		
		puts("Выберите пункт из предоставленного списка:");
		puts("1)Правила игры в баскетбол");
		puts("2)Количество забитых и пропущенных мячей");
		puts("3)Количество набранных очков каждой команды");
		puts("4)Сортировка команд по количеству набранных очков");
		puts("5)Команда с наибольшим и наименьшим количеством забитых мячей");
		puts("6)Разность между суммами забитых и пропущенных мячей");
		puts("7)Отношение суммы забитых мячей к сумме пропущенных");
		puts("8)Изменение количества забитых и пропущенных мячей за игру в ячейке");
		puts("9)Завершение работы программы");

		scanf_s("%d", &k);
		getchar();
		switch (k) {
		case 1:
			system("cls");
			puts("1) Игра состоит из 3 периодов по 8 минут каждый");
			puts("2) Между периодами предусмотрены перерывы ");
			puts("3) В баскетбол играют две команды");
			puts("4) Спортсмены, владеющие мячом, должны передвигаться по полю, ударяя им в пол");
			puts("5) Заброшенный в корзину мяч может приносить от 1 до 3 очков своей команде");
			puts("6) Если в основное время обе команды набрали одинаковое число очков, то назначается 5 минутный овертайм");
			puts("7) Правило 3 секунд – правило, которое запрещает любому игроку атакующей команды находиться в зоне штрафного броска более трех секунд");
			puts("8) Игроку разрешается сделать только два шага с мячом, после чего он должен либо произвести бросок, либо отдать пас\n");
			break;
		case 2:
			system("cls");
			tabl(A);//Вывод исходной таблицы с забитыми и пропущенными мячами 
			break;

		case 3:
			system("cls");
			print_points(och_win, och_loss);//Вывод очков команд
			break;
		case 4:
			system("cls");
			
			sumsort(sum_och_win, number);//Сортировка команд по количеству набранных очков
			break;
		case 5:
			system("cls");
			searh(sum_array_A);//Вывод наибольшего количества забитых и пропущенных мячей
			break;
		case 6:
			system("cls");
			dif_array_A(A);//Разность между суммами забитых и пропущенных мячей
			break;
		case 7:
			system("cls");
			div_array_A(A);//Отношение суммы забитых мячей к сумме пропущенных
			break;
		case 8:
			system("cls");
			change_array_A(A);//Изменение количества забитых и пропущенных мячей в ячейке
			tabl(A);
			break;
		case 9:
			exit(EXIT_SUCCESS);//Завершение работы программы
			break;
		}
	}
}

int*** vd()
{
	int*** A = (int***)malloc(M * sizeof(int**));
	for (int i = 0; i < M; i++)
	{
		A[i] = (int**)malloc(N * sizeof(int*));
		for (int j = 0; j < N; j++)
		{
			A[i][j] = (int*)malloc(O * sizeof(int));

		}
	}
	return A;
}

int** vd1()
{
	int** och = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < O; i++) {
		och[i] = (int*)malloc(O * sizeof(int));
	}
	return och;
}

int txt(int*** A, char my[N])
{
	FILE* pog;

	pog = fopen(my, "r");

	if (pog == NULL) {
		printf("ERROR");
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < O; k++) {
				fscanf(pog, "%d", &A[i][j][k]);
			}
		}
	}

	return A;

}

int array_A(int*** A, int*** A1, int*** A2, int*** A3)
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int l = 0; l < O; l++) {
				A[i][j][l] = A1[i][j][l] + A2[i][j][l] + A3[i][j][l];
			}
		}
	}
	return A;
}

int array_och_0(int** och_win, int** och_loss)
{
	for (int j = 0; j < N; j++) {
		for (int l = 0; l < O; l++) {
			och_win[j][l] = 0;
			och_loss[j][l] = 0;
		}
	}
}

int sum_och_0(int* sum_och)
{
	for (int j = 0; j < N; j++) {
		sum_och = 0;
	}
}

int tabl(int*** A)
{
	int num = 1;
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("\t      Команда №1|Команда №2|Команда №3|Команда №4|Команда №5|Команда №6|Команда №7|Команда №8\n");
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < N; j++) {
			printf("Команда №%d", num);
			num++;
			for (int l = 0; l < O; l++) {
				printf("%8d:%2d", A[0][j][l], A[1][j][l]);
			}
			printf("\n-----------------------------------------------------------------------------------------------------\n");
		}
	}
}

int points(int** och_win, int** och_loss, int*** A1)
{
	int m = 0, n = 0;

	for (int j = 0; j < N; j++) {
		for (int l = 0; l < O; l++) {
			m = A1[0][j][l];
			n = A1[1][j][l];
			if (m > n) {
				och_win[j][l] += 1;
				och_loss[j][l] += 0;
			}
			if (m < n) {
				och_win[j][l] += 0;
				och_loss[j][l] += 1;
			}
			if (m = n && m == 0) {
				och_win[j][l] += 0;
				och_loss[j][l] += 0;
			}
			m = 0;
			n = 0;
		}
	}

	return och_win, och_loss, A1;
}

int print_points(int** och_win, int** och_loss)
{
	int num = 1;
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("\t      Команда №1|Команда №2|Команда №3|Команда №4|Команда №5|Команда №6|Команда №7|Команда №8\n");
	for (int j = 0; j < N; j++) {
		printf("Команда №%d", num);
		num++;
		for (int l = 0; l < O; l++) {
			printf("%7d:%d  ", och_win[j][l], och_loss[j][l]);
		}
		printf("\n-----------------------------------------------------------------------------------------------------\n");

	}
	printf("\n");
}

int sum_och(int* sum_och_, int** och_win)
{
	int sum = 0;
	for (int j = 0; j < N; j++) {
		for (int l = 0; l < O; l++) {
			sum += och_win[j][l];

		}
		sum_och_[j] = sum;
		sum = 0;
	}
	return sum_och_;
}

int sumsort(int* sum_och_win, int number[N])
{
	printf("Выполнить сортировку команд по:\n1)Возрастанию\n2)Убыванию\n");
	int cs = 0;

	scanf("%d", &cs);
	
	 for (int i = 0; i < N - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < O; j++)
		{
			if (((cs == 1) && (sum_och_win[j] < sum_och_win[max])) || ((cs == 2) && ((sum_och_win[j] > sum_och_win[max]))))

				max = j;
		}
		int k = sum_och_win[i];
		sum_och_win[i] = sum_och_win[max];
		sum_och_win[max] = k;
		int num = number[i];
		number[i] = number[max];
		number[max] = num;
	}
		  for (int i = 0; i < N; i++) {
			  printf(" Команда №%2d %5d\n", number[i], sum_och_win[i]);
		  }
}

int sum_array(int*** A, int* sum_array_A)
{
	int sum = 0;
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < N; j++) {
			for (int l = 0; l < O; l++) {
				sum += A[i][j][l];
			}
			sum_array_A[j] = sum;
			sum = 0;
		}
	}
}

int searh(int* sum_array_A) {
	int с, max = -1, min = 9999, cs = 1;
	printf("Вывести команду:\n1)С наибольшим количеством забитых мячей\n2)С наименьшим количеством забитых мячей\n");
		scanf("%d", &cs);
		switch (cs) {
		case 1: {
			{
				for (int j = 0; j < N; ++j) {
					if (max < sum_array_A[j] && max != sum_array_A[j]) {
						max = sum_array_A[j];
						с = j + 1;
					}
				}
				printf("Команда №%d %d\n\n", с, max);
			}
		}
			  break;
		case 2: {
			for (int j = 1; j < N; ++j) {
				if (min > sum_array_A[j] && min != sum_array_A[j]) {
					min = sum_array_A[j];
					с = j + 1;
				}
			}
			printf("Команда №%d %d\n\n", с, min);

		}
			  break;
		}
	}

int dif_array_A(int*** A) {
	int sum = 0, sum1 = 0, sumob = 0, num = 1;
	for (int i = 0; i < N; i++)
	{
		printf("Команда №%d\t", num);
		num++;
		for (int z = 0; z < M; z++) {
			sum += A[0][i][z];
			sum1 += A[1][i][z];
			sumob = sum - sum1;
		}
		printf("%d", sumob);
		sum = 0;
		sum1 = 0;
		printf("\n");
	}
}

int div_array_A(int*** A) {
	float f = 0, u = 0, h = 0;
	int num = 1;
	for (int i = 0; i < N; i++) {
		printf("Команда №%d\t", num);
		num++;
		for (int z = 0; z < 8; z++) {

			f += A[0][i][z];
			u += A[1][i][z];
		}
		h = f / u;

		printf("%.2f\n", h);
		f = 0;
		u = 0;
	}
}

int change_array_A(int*** A) {

	int x = 0, y = 0; 
	int m, n;

	system("cls"); 
	printf("Команда по горизонтали:");
	scanf("%i", &x); 
	printf("Команда по вертикали:");
	scanf("%i", &y); 
	system("cls"); 
	if (x == y) {
		printf("Команда не может играть сама с собой\n");
		printf("Выберите другую команду по вертикали: ");
		scanf("%i", &y);
	}
	printf("Новое значение ячейки Команда %i VS Команда %i\n", y, x);

	printf("Очки команды %i:", x);
	scanf("%i", &n);

	printf("Очки команды %i:", y);
	scanf("%i", &m);

	y--;  
	x--; 

	A[0][y][x] = m;
	A[1][y][x] = n;

	A[1][x][y] = m;
	A[0][x][y] = n;
}