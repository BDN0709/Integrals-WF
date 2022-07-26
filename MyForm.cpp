#include "MyForm.h"
struct MyPoint;  // оголошення структури точки
#include <vector>
struct MyPoint
{  // структура точки
	struct Graphic
	{  // точки, що будуть відображені на графіку
		double x;
		double y;

	}Graphic;

	struct Explanation
	{  // точки, що необхідні для побудови графічного представлення методу інтегрування
		double x;
		double y;

		Explanation()
		{ // конструктор за замовчуванням, що присвоюватиме невизначеність.
			// необхідно для того, щоб фільтрувати пусті точки та не виводити пояснення для методів трапецій та Сімпсона
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