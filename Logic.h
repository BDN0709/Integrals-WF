#pragma once

// тип перерахування для уникання літеральних констант. Працює таким чином, що індексює з 0 усі записані елементи.
enum Functions { sinus, cosinus, tangens, cotangens };

enum Methods { LeftRectangle, CentralRectangle, RightRectangle, Trapezoid, Simpsons };

#include "LogicFunctions.h"  // підключення файла з оголошенням функцій для коректної роботи

// функція-драйвер, що аналізує вхідні дані та викликає необхідну функцію обчислення інтеграла та заповнення списку точок
float CalculateIntegral(Functions Func, Methods Method, const double a, const double b,
	double h, const double accuracy, std::vector <MyPoint>& points)
{
	float Integr = 0, tmpRes = 0;

	while (true)
	{
		points.clear();

		if (Method == LeftRectangle)
		{
			if (Func == sinus)
				Integr = LeftRectangleMethod(MySin, a, b, h, points);
			else if (Func == cosinus)
				Integr = LeftRectangleMethod(MyCos, a, b, h, points);
			else if (Func == tangens)
				Integr = LeftRectangleMethod(MyTan, a, b, h, points);
			else
				Integr = LeftRectangleMethod(MyCtg, a, b, h, points);
		}
		else if (Method == CentralRectangle)
		{
			if (Func == sinus)
				Integr = CentralRectangleMethod(MySin, a, b, h, points);
			else if (Func == cosinus)
				Integr = CentralRectangleMethod(MyCos, a, b, h, points);
			else if (Func == tangens)
				Integr = CentralRectangleMethod(MyTan, a, b, h, points);
			else
				Integr = CentralRectangleMethod(MyCtg, a, b, h, points);

		}
		else if (Method == RightRectangle)
		{
			if (Func == sinus)
				Integr = RightRectangleMethod(MySin, a, b, h, points);
			else if (Func == cosinus)
				Integr = RightRectangleMethod(MyCos, a, b, h, points);
			else if (Func == tangens)
				Integr = RightRectangleMethod(MyTan, a, b, h, points);
			else
				Integr = RightRectangleMethod(MyCtg, a, b, h, points);
		}
		else if (Method == Trapezoid)
		{
			if (Func == sinus)
				Integr = TrapezoidicalMethod(MySin, a, b, h, points);
			else if (Func == cosinus)
				Integr = TrapezoidicalMethod(MyCos, a, b, h, points);
			else if (Func == tangens)
				Integr = TrapezoidicalMethod(MyTan, a, b, h, points);
			else
				Integr = TrapezoidicalMethod(MyCtg, a, b, h, points);
		}
		else
		{
			if (Func == sinus)
				Integr = SimpsonsMethod(MySin, a, b, h, points);
			else if (Func == cosinus)
				Integr = SimpsonsMethod(MyCos, a, b, h, points);
			else if (Func == tangens)
				Integr = SimpsonsMethod(MyTan, a, b, h, points);
			else
				Integr = SimpsonsMethod(MyCtg, a, b, h, points);
		}

		if (fabs(Integr - tmpRes) < accuracy)
			break;

		tmpRes = Integr;
		h /= 2;
	}

	return Integr;
}

double MySin(const double a) { return System::Math::Sin(a); }

double MyCos(const double a) { return System::Math::Cos(a); }

double MyTan(const double a) { return System::Math::Tan(a); }

double MyCtg(const double a) { return (1.0 / System::Math::Tan(a)); }

// функція для обчислення інтеграла методом лівих прямокутників та заповнення списків точок графіка та графічного представлення методу інтегрування
float LeftRectangleMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points)
{
	float Result = 0;  // значення інтеграла

	// обчислення значення інтеграла
	for (double x_i = a; x_i < b; x_i += h)
		Result += TrigonFunc(x_i);

	// занесення точок для побудови графіка:

	MyPoint Point; // точка
	for (double x_i = a; x_i <= b; x_i += h)
	{
		// абсциси у графіків різні, оскільки у методі відбувається зсув
		Point.Graphic.x = x_i;
		Point.Explanation.x = x_i + (h / 2.5);

		// а ордината для обох графіків однакова
		Point.Graphic.y = Point.Explanation.y = TrigonFunc(x_i);

		points.push_back(Point);  // заносимо створену точку у список
	}

	return (Result * h);  // повернення значення інтеграла згідно з формулою
}

// функція для обчислення інтеграла методом центральних прямокутників та заповнення списків точок графіка та графічного представлення методу інтегрування
float CentralRectangleMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points)
{
	float Result = 0;  // значення інтеграла

	// обчислення значення інтеграла
	for (double x_i = a + (h / 2); x_i < b; x_i += h)
		Result += TrigonFunc(x_i + (h / 2));

	// занесення точок для побудови графіка:

	MyPoint Point; // точка
	for (double x_i = a; x_i <= b; x_i += h)
	{		
		// абсциси у графіків різні, оскільки у методі відбувається зсув
		Point.Graphic.x = x_i;
		Point.Explanation.x = x_i;

		// а ордината для обох графіків однакова
		Point.Graphic.y = Point.Explanation.y = TrigonFunc(x_i);

		points.push_back(Point);  // заносимо створену точку у список
	}

	return (Result * h);  // повернення значення інтеграла згідно з формулою
}

// функція для обчислення інтеграла методом правих прямокутників та заповнення списків точок графіка та графічного представлення методу інтегрування
float RightRectangleMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points)
{
	float Result = 0; // значення інтеграла

	// обчислення значення інтеграла
	for (double x_i = a + h; x_i <= b; x_i += h)
		Result += TrigonFunc(x_i);

	// занесення точок для побудови графіка:

	MyPoint Point; // точка
	for (double x_i = a; x_i <= b; x_i += h)
	{
		// абсциси у графіків різні, оскільки у методі відбувається зсув
		Point.Graphic.x = x_i;
		Point.Explanation.x = x_i - (h / 2.5);

		// а ордината для обох графіків однакова
		Point.Graphic.y = Point.Explanation.y = TrigonFunc(x_i);

		points.push_back(Point);  // заносимо створену точку у список
	}

	return (Result * h);  // повернення значення інтеграла згідно з формулою
}

// функція для обчислення інтеграла методом трапецій та заповнення списку точок графіка
float TrapezoidicalMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points)
{
	float Result = 0;  // значенння інтеграла

	// обчислення значення інтеграла
	for (double x_i = a + h; x_i <= b; x_i += h)
		Result += (TrigonFunc(x_i) + TrigonFunc(x_i - h));

	// занесення точок для побудови графіка:

	MyPoint Point; // точка
	for (double x_i = a; x_i <= b; x_i += h)
	{  // створюємо точку
		Point.Graphic.x = x_i;
		Point.Graphic.y = TrigonFunc(x_i);

		points.push_back(Point);  // заносимо створену точку у список
	}

	return (Result * (h / 2.0));  // повернення значення інтеграла згідно з формулою
}

// функція для обчислення інтеграла методом Сімпсона та заповнення списку точок графіка
float SimpsonsMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points)
{
	float Result = 0; // значення інтеграла

	// обчислення значення інтеграла на кінцях проміжка інтегрування
	Result += TrigonFunc(a);
	Result += TrigonFunc(b);

	int i = 1;

	// обчислення значення інтеграла згідно з формулою
	for (double x_i = a + h; x_i < b; x_i += h)
	{
		if (i % 2 == 0)
			Result += (2 * TrigonFunc(x_i));
		else
			Result += (4 * TrigonFunc(x_i));
		i++;
	}

	// занесення точок для побудови графіка:

	MyPoint Point; // точка
	for (double x_i = a; x_i <= b; x_i += h)
	{  // створюємо точку
		Point.Graphic.x = x_i;
		Point.Graphic.y = TrigonFunc(x_i);

		points.push_back(Point);  // заносимо створену точку у список
	}

	return (Result * (h / 3.0));  // повернення значення інтеграла згідно з формулою
}