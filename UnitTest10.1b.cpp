#include "pch.h"
#include "CppUnitTest.h"
#include <sstream> // для std::istringstream
#include "../lab10.1b/lab10.1b.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCreateStudents)
		{
			// Імітація введення для CreateStudents
			istringstream input("Ivanenko\n1\n0\n5\n4\n5\n"); // Дані для одного студента
			streambuf* cin_backup = cin.rdbuf(input.rdbuf()); // Перенаправляємо стандартний ввід на input

			// Створення динамічного масиву студентів
			const int N = 1;
			Student* students = new Student[N];

			CreateStudents(students, N);

			// Перевірка результатів заповнення студента
			Assert::AreEqual(string("Ivanenko"), students[0].prizv, L"Прізвище студента неправильне.");
			Assert::AreEqual(1, students[0].kurs, L"Курс студента неправильний.");
			Assert::AreEqual((int)KN, (int)students[0].specialnist, L"Спеціальність студента неправильна.");
			Assert::AreEqual(5, students[0].ocinka_fizyka, L"Оцінка з фізики неправильна.");
			Assert::AreEqual(4, students[0].ocinka_matematyka, L"Оцінка з математики неправильна.");
			Assert::AreEqual(5, students[0].ocinka_programuvannia, L"Оцінка з програмування неправильна.");

			delete[] students;

			// Відновлення стандартного вводу
			cin.rdbuf(cin_backup);
		}
	};
}
