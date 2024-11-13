#include "pch.h"
#include "CppUnitTest.h"
#include <sstream> // ��� std::istringstream
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
			// ������� �������� ��� CreateStudents
			istringstream input("Ivanenko\n1\n0\n5\n4\n5\n"); // ��� ��� ������ ��������
			streambuf* cin_backup = cin.rdbuf(input.rdbuf()); // ��������������� ����������� ��� �� input

			// ��������� ���������� ������ ��������
			const int N = 1;
			Student* students = new Student[N];

			CreateStudents(students, N);

			// �������� ���������� ���������� ��������
			Assert::AreEqual(string("Ivanenko"), students[0].prizv, L"������� �������� �����������.");
			Assert::AreEqual(1, students[0].kurs, L"���� �������� ������������.");
			Assert::AreEqual((int)KN, (int)students[0].specialnist, L"������������ �������� �����������.");
			Assert::AreEqual(5, students[0].ocinka_fizyka, L"������ � ������ �����������.");
			Assert::AreEqual(4, students[0].ocinka_matematyka, L"������ � ���������� �����������.");
			Assert::AreEqual(5, students[0].ocinka_programuvannia, L"������ � ������������� �����������.");

			delete[] students;

			// ³��������� ������������ �����
			cin.rdbuf(cin_backup);
		}
	};
}
