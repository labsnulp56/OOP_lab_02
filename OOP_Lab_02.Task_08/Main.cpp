#include <iostream>
#include <cmath>
# define M_PI  3.14159265358979323846 

using namespace std;

class Cone
{
private:
	double *radius;
	double *height;

public:
	Cone()
	{
		radius = new double(0);
		height = new double(0); /*конструктор значень за замовчуванням*/
	}
	Cone(double radius, double height) /*конструктор для ініціалізації користувацькими значеннями*/
	{
		this->radius = new double(radius);
		this->height = new double(height);
	}
	Cone(const Cone &obj)
	{
		radius = new double(*obj.radius);
		height = new double(*obj.height);
	}
	~Cone() { delete height; delete radius; }
	double GetX()
	{
		return *radius;
	}
	double GetY()
	{
		return *height;
	}
	void SetX(double a)
	{
		*radius = a;
	}
	void SetY(double b)
	{
		*height = b;
	}
	void Print(void);
	double Volume(Cone &obj);
	double Cone::Area(Cone &obj);
};
double Cone::Volume(Cone &obj)
{
	return (1.0 / 3.0)*M_PI*pow(*radius, 2)*(*height);
}
double Cone::Area(Cone &obj)
{
	return M_PI*(*radius)* ((*(radius)) + (*height)); //height в значенні l за формулою конуса щоб не додавати зайву змінну
}

int main()
{
	int radius;
	int height;
	int *ptr1 = &radius;
	int *ptr2 = &height;
	while (radius < 1) {
		cout << "input radius" << endl;
		cin >> radius;
	}
	while (height < 1)
	{
		cout << "input height" << endl;
		cin >> height;
	}
	Cone obj1(*ptr1, *ptr2);
	Cone *obj2 = new Cone;
	Cone obj3(obj1);
	cout << "Radius = " << obj1.GetX() << ' ' << "Height = " << obj1.GetY() << endl;
	cout << "Volume of con is " << obj1.Volume(*obj2) << endl;
	cout << "Radius = " << obj1.GetX() << ' ' << "Сreating a cone = " << obj1.GetY() << endl;
	cout << "Area of con is " << obj1.Area(*obj2) << endl;
	system("pause");
	return 0;
}
