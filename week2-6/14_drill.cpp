#include "std_lib_facilities.h"

class B1
{
public:
	virtual void vf() {cout<<"B1::vf()"<<endl;};
	void f() {cout<<"B1::f()"<<endl;};
	virtual void pvf()=0;
};

class D1 : public B1
{
public:
	void vf() override {cout<<"D1::vf()"<<endl;};
	void f() {cout<<"D1::f()"<<endl;};
	void pvf() override {cout<<"D1::pvf()"<<endl;};
};

class D2 : public D1
{
public:
	void pvf() override {cout<<"D2::pvf()"<<endl;};
};

class B2
{
public:
	virtual void pvf()=0;

};

class D21 :public B2
{
public:
	string data="qwe";
	void pvf() override {cout<<data<<endl;};
};

class D22 : public B2
{
public:
	int number=22;
	void pvf() override {cout<<number<<endl;};
};

void f(B2& b2)
{
	b2.pvf();
};

int main()
{
	//B1 b1_object;
		//b1_object.vf();
		//b1_object.f();
		//b1_object.pvf();

	D1 d1_object;
		d1_object.vf();
		d1_object.f();
		d1_object.pvf();

	B1 &b_ref_object=d1_object;
		b_ref_object.vf();
		b_ref_object.f();
		b_ref_object.pvf();

	D2 d2_object;
		d2_object.vf();
		d2_object.f();
		d2_object.pvf();

	D21 d21_object;
	D22 d22_object;
	f(d21_object);
	f(d22_object);


	return 0;
}