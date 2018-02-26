#include <list>
#include <iostream>
#include <math.h>
using namespace std;

// 노드
struct term
{
	int coef; //  계수
	int expo; // 지수(차수)
};

struct ListSort
{
	bool operator() ( const term pTerm1, const  term pTerm2)
	{
		if (pTerm1.expo > pTerm2.expo)
			return true;
		return false;
	}
};

class Polynomial
{
	char name;
	int Size;

	list<term> List;

public:
	Polynomial(char name)
		:name(name)
	{
		Size = 0;
	}

	// 새로운 항 추가
	void Add_Term(int coef, int expo)
	{
		for (auto iter = List.begin(); iter != List.end(); ++iter)
		{
			if (iter->expo == expo)
			{
				iter->coef += coef;
				return;
			}
		}

		term Term = { coef, expo };
		List.push_back(Term);

		// expo 정렬
		List.sort(ListSort());
	}

	int eval(int x)
	{
		int Summary = 0;

		for (auto iter = List.begin(); iter != List.end(); ++iter)
		{
			Summary += pow((iter->coef * x), iter->expo);
		}

		return Summary;
	}

	void print_Poly()
	{
		cout << name << "= ";
		for (auto iter = List.begin(); iter != List.end(); ++iter)
		{
			if (iter != List.begin())
			{
				if (iter->coef > 0)
					cout << "+";
			}

			cout << iter->coef;
			
			if (iter->expo != 0)
			{
				cout << "x^" << iter->expo;;
			}
		}

		cout << endl;
	}

	Polynomial operator+(const Polynomial& Poly2)
	{
		// 같은항과 계수만 더한다.
		Polynomial ResultPoly('f');

		for (auto iter = List.begin(); iter != List.end(); ++iter)
		{
			ResultPoly.Add_Term(iter->coef, iter->expo);
		}

		for (auto iter = Poly2.List.begin(); iter != Poly2.List.end(); ++iter)
		{
			ResultPoly.Add_Term(iter->coef, iter->expo);
		}

		ResultPoly.List.sort(ListSort());
		return ResultPoly;
	}
};

int main()
{
	Polynomial Poly('h');
	Polynomial Poly2('g');

	Poly.Add_Term(3, 2);
	Poly.Add_Term(5, 1);
	Poly.Add_Term(7, 0);

	Poly.print_Poly();

	Poly2.Add_Term(4, 2);
	Poly2.Add_Term(5, 1);
	Poly2.Add_Term(9, 0);

	Poly2.print_Poly();

	Polynomial Poly3 = Poly + Poly2;
	Poly3.print_Poly();


	return 0;
}