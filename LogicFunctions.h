#pragma once

// функція - драйвер
float CalculateIntegral(Functions Func, Methods Method, const double, const double,
	double, const double, std::vector <MyPoint>&);

// власні (підітегральні) функції
double MySin(const double);

double MyCos(const double);

double MyTan(const double);

double MyCtg(const double);

// функції для обчислення інтеграла вибраним методом
float LeftRectangleMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points);

float CentralRectangleMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points);

float RightRectangleMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points);

float TrapezoidicalMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points);

float SimpsonsMethod(double (*TrigonFunc)(double a), const double a, const double b, const double h, std::vector <MyPoint>& points);