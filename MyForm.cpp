#include "MyForm.h"
struct MyPoint;  // ���������� ��������� �����
#include <vector>
struct MyPoint
{  // ��������� �����
	struct Graphic
	{  // �����, �� ������ ��������� �� �������
		double x;
		double y;

	}Graphic;

	struct Explanation
	{  // �����, �� �������� ��� �������� ���������� ������������� ������ ������������
		double x;
		double y;

		Explanation()
		{ // ����������� �� �������������, �� ������������� �������������.
			// ��������� ��� ����, ��� ����������� ���� ����� �� �� �������� ��������� ��� ������ �������� �� ѳ������
			this->x = NULL;
			this->y = NULL;
		}

	}Explanation;
};

#include "Logic.h"
#include "UI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CalculateInter::MyForm form;
	Application::Run(% form);

	return;
}