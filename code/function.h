#pragma once

#include <iostream>

class Function
{

public:
	Function() = default;
	Function(const Function&) = delete;
	Function& operator=(const Function&) = delete;

	virtual double value(double x) const = 0;
	virtual double prim(double x) const = 0;

	virtual ~Function() { }
};

//---------------------------------------------------
class Const :public Function
{
	double value;
public:
	virtual double value(double x) const override{
		return value;
	}
	virtual double prim(double x) const override {
		return 0;
	}
};


class X :public Function
{
	virtual double value(double x) const override {
		return x;
	}
	virtual double prim(double x) const override {
		return 1;
	}
};


class Plus : public Function
{
	Function* f,* g;
	virtual double value (double x) const override {
		return f->value(x) + g->value(x);
	}
	virtual double prim(double x) const override {
		return f->prim(x) + g->prim(x);
	}
	~Plus() { delete f; delete g; }
};


class Minus : public Function
{
	Function* f, * g;
	virtual double value(double x) const override {
		return f->value(x) - g->value(x);
	}
	virtual double prim(double x) const override {
		return f->prim(x) - g->prim(x);
	}
	~Minus() { delete f; delete g; }


};


class Iloczyn : public Function
{
	//uzupe³nij



};

//--------------------------------------------------------------------------


class Wielomian : public Function
{
	//uzupe³nij




};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


