#include "std_lib_facilities.h"

/* g++ 15.2_drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o 15.2_drill `fltk-config --ldflags --use-images` */

struct Person {
		Person() : first_nm(""), second_nm(""), age_n(0) { }

		Person(string fn, string sn, int age) : first_nm(fn), second_nm(sn), age_n(age)
			{

			if (age_n<0||age_n>=150) error("Nem letezik ilyen");
		
			const string bad=";:\"'[]*&^%$#@!";

			for (int i=0; i<fn.size(); ++i)
				{
					for (int k=0; k<bad.size(); ++k)
						{
						if (fn[i]==bad[k]) error("bad chars");
						}
				}

			for (int i=0; i<sn.size(); ++i)
				{
					for (int k=0; k<bad.size(); ++k)
						{
						if (sn[i]==bad[k]) error("bad chars");
						}
				}

		
			}

	int age() const { return age_n; }
	string first_name() const { return first_nm; }
	string second_name() const { return second_nm; }

private:
		int age_n;
		string second_nm;
		string first_nm;
};

ostream& operator<<(ostream& o, const Person& p)
{
	return o<<p.first_name()<<" "<<p.second_name() <<" "<< p.age();
}

istream& operator>>(istream& i, Person& p)
{
	int number;
	string f_n; 
	string s_n;
	i >>f_n>>s_n>>number;

	p = Person(f_n,s_n,number);
	return i;
}

int main()
{
	//Person nev{"Goofy","",63};
	//cout<<nev<<endl;
	
	vector<Person> vec;
	Person proba;
	cout<<"Adjon meg 6 db(Vezeteknev Keresznev eletkor)"<<endl;
	for(int i=0; i<6; ++i)
	{
		cin>>proba;
		vec.push_back(proba);
	}

	for(int i=0; i<6; ++i)
	{
		cout<<vec[i]<<endl;
	}
	
}
