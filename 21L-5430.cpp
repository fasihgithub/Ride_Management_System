#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class name {
protected:
	char fname;
	char lname;
public:
	name();
	name(char, char);
	virtual void setdata(char, char);
	//char getdata();
	friend ostream& operator<<(ostream& out, const name& n);
};
name::name()
{
	fname = NULL;
	lname = NULL;
}
name::name(char p, char q)
{
	fname = p;
	lname = q;

}
void name::setdata(char f, char w)
{
	fname = f;
	lname = w;
}
ostream& operator<<(ostream& out, const name& n)
{
	out << "first name:" << n.fname << endl;
	out << "last name:" << n.lname << endl;
	return out;
}
class date {
	int day;
	int month;
	int year;
public:
	date();
	date(int, int, int);
	friend ostream& operator<<(ostream& out, const date& p);
	void setdata(int, int, int);
};
date::date()
{
	day = 0;
	month = 0;
	year = 0;
}
date::date(int p, int q, int r)
{
	day = p;
	month = q;
	year = r;
}
void date::setdata(int p, int q, int r)
{
	day = p;
	month = q;
	year = r;
}
ostream& operator<<(ostream& out, const date& p)
{
	out << "Date:" << p.day << "/" << p.month << "/" << p.year << endl;
	return out;
}
class person
{
protected:
	name pname;
	date dob;
	int age;
	int nid;
public:
	person(char, char, int, int, int, int, int);
	person();
	friend ostream& operator<<(ostream& out, const person&);
};
person::person()
{
	age = 0;
	nid = 0;
}
person::person(char a, char b, int c, int d, int e, int f, int g)
{
	pname.setdata(a, b);
	dob.setdata(c, d, e);
	age = f;
	nid = g;
}
ostream& operator<<(ostream& out, const person& p)
{
	out << p.pname;
	out << p.dob;
	out << "age of person:" << p.age << endl;
	out << "id of person:" << p.nid << endl;
	return out;
}
class mtime {
	int hour;
	int min;
	int second;
public:
	mtime();
	mtime(int, int, int);
	void setdata(int, int, int);
	friend ostream& operator<<(ostream& out, const mtime&);
};
mtime::mtime()
{
	hour = 0;
	min = 0;
	second = 0;
}
mtime::mtime(int a, int b, int c)
{
	hour = a;
	min = b;
	second = c;
}
void mtime::setdata(int a, int b, int c)
{
	hour = a;
	min = b;
	second = c;
}
ostream& operator<<(ostream& out, const mtime& p)
{
	out << "time:" << p.hour << ":" << p.min << ":" << p.second << endl;
	return out;
}

class service {
	char* source;
	char* destination;
	float distance;
	date bookingdate;
	mtime bookingtime;
	bool status;
	float fuelrate;
	int cid;
	int did;
	int vid;
public:
	service()
	{}
	service(char*, char*, float, int, int, int, int, int, int, bool, float, int, int, int);
	friend ostream& operator<<(ostream& out, const service& p);
};
service::service(char* a, char* b, float c, int d, int e, int f, int g, int  h, int i, bool k, float l, int o, int p, int q)
{
	source = new char[10];
	source = a;
	destination = new char[10];
	destination = b;
	distance = c;
	bookingdate.setdata(d, e, f);
	bookingtime.setdata(g, h, i);
	status = k;
	fuelrate = l;
	cid = o;
	did = p;
	vid = q;
}
ostream& operator<<(ostream& out, const service& p)
{
	out << p.source << endl;
	out << p.destination << endl;
	out << p.distance << endl;
	out << p.bookingdate;
	out << p.bookingtime;
	out << p.status << endl;
	out << p.fuelrate << endl;
	out << p.cid << endl;
	out << p.did << endl;
	out << p.vid << endl;
	return out;

}

class customer :public person {

	int cid;
public:
	customer()
	{
		cid = 0;
	}
	customer(int, char, char, int, int, int, int, int);
	friend ostream& operator<<(ostream& out, const customer& p);
};
customer::customer(int a, char x, char b, int c, int d, int e, int f, int g) :person(x, b, c, d, e, f, g)
{
	cid = a;

}
ostream& operator<<(ostream& out, const customer& p)
{
	out << p.pname;
	out << p.dob;
	out << p.nid << endl;
	out << p.age << endl;
	out << p.cid << endl;
	return out;
}

class driver :public person
{
	int dld;
	char** licenselist;
	int nolicence;
	float overranking;
	float salary;
	int expensive;
	int status;
public:
	driver()
	{

	}
	driver(int, int, float, float, int, int, char, char, int, int, int, int, int);

	friend ostream& operator<<(ostream& out, const driver& p);
};
driver::driver(int a, int b, float c, float d, int e, int f, char g, char h, int i, int k, int l, int o, int p) :person(g, h, i, k, l, o, p)
{
	dld = a;
	nolicence = b;
	overranking = c;
	salary = d;
	expensive = e;
	status = f;
}
ostream& operator<<(ostream& out, const driver& p)
{
	out << p.pname;
	out << p.dob;
	out << p.dld << endl;
	out << p.nolicence << endl;
	out << p.overranking << endl;
	out << p.salary << endl;
	out << p.expensive << endl;
	out << p.status << endl;
	return out;
}
class feature {
protected:
	int fid;
	char* description;
	float cost;
public:
	feature() {
	}
	virtual void setdata(int a, char* r, float b);
	friend ostream& operator<<(ostream& out, const feature f);
};
void feature::setdata(int a, char* r, float b)
{
	fid = a;
	description = new char[10];
	description = r;
	cost = b;
}
ostream& operator<<(ostream& out, const feature f)
{
	out << "fid" << f.fid << endl;
	for (int i = 0; f.description[i] != '\0'; i++)
	{
		out << f.description;
	}
	cout << endl;
	out << "cost" << f.cost << endl;
	return out;
}
class vechicle :public feature, service {
	int vid;
	int regno;
	float avgmileage;
	char* licensetype;
	bool status;
	char* fuel;
	float overallranking;
	date manufacturingdate;
	feature* list;
	//service** servicehistory;

public:
	vechicle()
	{
		/*servicehistory = new service * [10];*/
	}


	vechicle(int, int, float, char*, bool, char*, float, int, int, int, int, char*, float, char*, char*, float, int, int, int, int, int, int, bool, float, int, int, int);
	friend ostream& operator<<(ostream& out, const vechicle& p);
};
vechicle::vechicle(int a, int s, float b, char* c, bool d, char* e, float f, int g, int h, int i, int hh, char* ll, float mm, char* fa, char* si, float hi, int sa, int qi, int bi, int kp, int lo, int lp, bool ol, float on, int mn, int ny, int bg) :service(fa, si, hi, sa, qi, bi, kp, lo, lp, ol, on, mn, ny, bg)
{
	vid = a;
	regno = s;
	avgmileage = b;
	licensetype = new char[10];
	licensetype = c;
	status = d;
	fuel = new char[10];
	fuel = e;
	overallranking = f;
	manufacturingdate.setdata(g, h, i);
	feature::setdata(hh, ll, mm);

}
ostream& operator<<(ostream& out, const vechicle& p)
{
	out << p.vid << endl;
	out << p.regno << endl;
	out << p.avgmileage << endl;
	for (int i = 0; p.licensetype[i] != '\0'; i++)
		out << p.licensetype[i];
	cout << endl;
	out << p.status << endl;
	out << p.overallranking << endl;
	for (int i = 0; p.fuel[i] != '\0'; i++)
		out << p.fuel[i];
	cout << endl;
	out << p.manufacturingdate << endl;
	out << p.fid << endl;
	out << p.description << endl;
	out << p.cost << endl;
	return out;
}
class tms :public name, vechicle, date, service, customer
{
public:
	void go1()
	{
		char a, b;
		ofstream t1;
		t1.open("customer.csv", ios::app);

		int p, q, k, s, m, g;
		int y;
		customer* obj;
		obj = new customer[15];
		customer* pp = obj;
		for (int i = 0; i < 1; i++)
		{
			cout << "enter the first name:";
			cin >> a;
			cout << "enter the last name:";
			cin >> b;
			cout << "enter the day:";
			cin >> p;
			cout << "enter the month:";
			cin >> q;
			cout << "enter the year:";
			cin >> k;
			cout << "enter the age of person:";
			cin >> m;
			cout << "enter the id of the person:";
			cin >> s;
			cout << "enter the cid:";
			cin >> g;
			if (t1.is_open(), ios::app)
			{
				t1 << a << "," << b << "," << p << "," << q << "," << k << "," << m << "," << s << "," << g;
				t1 << endl;
			}
			else
				cout << "not";
			(*obj) = customer(s, a, b, p, q, k, m, g);
		}
		for (int i = 0; i < 1; i++)
		{
			/*cout << *pp;*/
			cout << *pp;
		}

	}
	void go2() {
		int  x, l, pl, oo;
		float io, o, gopg;
		driver* d1;
		d1 = new driver[15];
		int count;
		cout << "what u want to to PRESS 1 FOR ADD PRESS 0 FOR REMOVE:";
		cin >> count;
		if (count == 1)
		{
			bool flag = 0;
			char a, b, gog;
			int p, q, k, s, m, g;
			/*fstream f2*/
			/*f2.open("driver.csv", ios::in);
			int gg;
			while (!f2.eof())
			{
				getline(f2, gg, ',');
				oo = gg;
				if (f2.eof())
				{
					flag = 1;
					break;
				}
				getline(f2, gg, ',');
				a = gog;
				getline(f2, gg, ',');
				b = gog;
				getline(f2, gg, ',');
				p = gg;
				getline(f2, gg, ',');
				q = gg;
				getline(f2, gg, ',');
				k = gg;
				getline(f2, gg, ',');
				m = gg;
				getline(f2, gg, ',');
				pl = gg;
				getline(f2, gg, ',');
				io = gopg;
				getline(f2, gg, ',');
				o = gopg;
				getline(f2, gg, ',');
				x = gg;
				getline(f2, gg, ',');
				l = gg;
				(*d1) = driver(oo, pl, io, o, x, l, a, b, p, q, k, m, s);
				*d1++;*/
				//}
				//f2.close();
				//if (flag == 1)
				//{
			ofstream db;
			db.open("driver.csv", ios::app);
			for (int i = 0; i < 1; i++)
			{
				cout << "enter the driver id:";
				cin >> oo;
				cout << "enter the first name of driver:";
				cin >> a;
				cout << "enter the last name  of driver:";
				cin >> b;
				cout << "enter the day:";
				cin >> p;
				cout << "enter the month:";
				cin >> q;
				cout << "enter the year:";
				cin >> k;
				cout << "enter the age  of driver:";
				cin >> m;
				cout << "enter the nid of the person:";
				cin >> s;
				cout << "enter the number of licence:";
				cin >> pl;
				cout << "enter the overall ranking:";
				cin >> io;
				cout << "enter the salary:";
				cin >> o;
				cout << "enter the expensive:";
				cin >> x;
				cout << "enter the status:";
				cin >> l;
				db << oo << "," << a << "," << b << "," << io << "," << pl << "," << p << "," << q << "," << k << "," << s << "," << o << "," << x << "," << l << endl;
				(*d1) = driver(oo, pl, io, o, x, l, a, b, p, q, k, m, s);
			}
			//	}
			cout << *d1;
		}

	};
	void go3() {
		int count;
		cout << "what u want to to PRESS 1 FOR ADD PRESS 0 FOR REMOVE:";
		cin >> count;
		if (count == 1)
		{
			ofstream op;
			op.open("vechicle.csv", ios::app);
			int  x, l, pl, oo, hh, gg, ll, feat; bool s;
			float io, o, cost;
			vechicle* vec;
			vec = new vechicle[20];
			cout << "enter the vechicle id:";
			cin >> x;
			cout << "enter the registration no of vechicle:";
			cin >> l;
			cout << "enter the avg mileage:";
			cin >> io;
			char* p;
			p = new char[10];
			cout << "enter the licence type:";
			cin >> p;
			cout << "ener the status:";
			cin >> s;
			char* kl;
			char* upp;
			kl = new char[10];
			cout << "enter the fuel type:";
			cin >> kl;
			cout << "enter the overranking:";
			cin >> o;
			cout << "enter the day:";
			cin >> hh;
			cout << "enter the month:";
			cin >> gg;
			cout << "enter the year:";
			cin >> ll;
			cout << "enter feature id:";
			cin >> feat;
			upp = new char[10];
			cout << "enter description:";
			cin >> upp;
			cout << "enter the cost:";
			cin >> cost;
			char* source;
			float km, fuelra;
			bool sta;
			int day, mon, yea, hour, min, second, cid, vid, did;
			char* destination;
			destination = new char[10];
			source = new char[10];
			cout << "enter the service of this vechicle" << endl;
			cout << "enter the source:";
			cin >> source;
			cout << "enter the destination:";
			cin >> destination;
			cout << "enter the distance of travel in km:";
			cin >> km;
			cout << "enter the day of manufacturing:";
			cin >> day;
			cout << "enter the month of manufacturing:";
			cin >> mon;
			cout << "enter the year of manufacturing:";
			cin >> yea;
			cout << "enter the hour of bookng:";
			cin >> hour;
			cout << "enter the min of booking:";
			cin >> min;
			cout << "enter the second of booking:";
			cin >> second;
			cout << "enter the status:";
			cin >> sta;
			cout << "enter the fuel rate:";
			cin >> fuelra;
			cout << "enter CID:";
			cin >> cid;
			cout << "ENTER VID:";
			cin >> vid;
			cout << "enter DID:";
			cin >> did;

			char arrr[10] = { '\0' }, brrr[10] = { '\0' };
			char crrr[10] = { '\0' };
			for (int i = 0; i < 10; i++)
				arrr[i] = p[i];
			for (int i = 0; i < 10; i++)
				brrr[i] = kl[i];
			for (int i = 0; i < 10; i++)
				crrr[i] = upp[i];
			cout << crrr << endl << endl;

			op << x << "," << l << "," << io << "," << arrr << "," << s << "," << brrr << "," << o << "," << hh << "," << gg << "," << ll << "," << feat << "," << crrr << "," << cost << "," << source << "," << destination << "," << km << "," << day << "," << mon << "," << yea << "," << hour << "," << min << "," << second << "," << sta << "," << fuelra << "," << cid << "," << vid << "," << did << "," << endl;
			(*vec) = vechicle(x, l, io, p, s, kl, o, hh, gg, ll, feat, upp, cost, source, destination, km, day, mon, yea, hour, min, second, sta, fuelra, cid, vid, did);
			cout << *vec;
		}
		if (count == 0)
		{
			bool fun = 0;
			string arrr;

			int idd;
			string trash;
			fstream f1, f2;
			int e3;
			f1.open("vechicle.csv", ios::in);
			f2.open("vechiclenew.csv", ios::out);
			cout << "enter the vechicle id for which u want to remove record:";
			cin >> idd;
			while (!f1.eof())
			{

				f1 >> e3;
				if (f1.eof())
					break;

				if (idd == e3)
				{
					fun = 1;

					getline(f1, trash);
					continue;

				}
				else
				{
					f2 << e3;
					getline(f1, arrr);
					f2 << arrr << endl;
				}
			}
			if (fun == 0)
			{
				cout << "FILE NOT FOUND:";
			}
			f1.close();
			f2.close();
			remove("vechicle.csv");
			rename("vechiclenew.csv", "vechicle.csv");

		}



	}
	void go4()
	{
		string dd1, dd2;
		string d3;
		fstream f4;
		cout << "ALL CUSTOMER ARE:" << endl;
		f4.open("customer.csv", ios::in);
		while (!f4.eof())
		{
			getline(f4, dd1, ',');
			if (f4.eof())
			{
				break;
			}
			cout << "first name:" << dd1 << "   ";
			getline(f4, dd1, ',');
			cout << "last name:" << dd1 << "  ";
			getline(f4, d3);
			cout << endl;
		}

	}
	void go5() {

		string dd1, dd2;
		string d3;
		fstream f5;
		cout << "ALL CUSTOMER ARE:" << endl;
		f5.open("driver.csv", ios::in);
		while (!f5.eof())
		{
			getline(f5, dd1, ',');
			getline(f5, dd1, ',');
			if (f5.eof())
			{
				break;
			}
			cout << "first name:" << dd1 << "   ";
			getline(f5, dd1, ',');
			cout << "last name:" << dd1 << "  ";
			getline(f5, d3);
			cout << endl;
		}
	}
	void go6()
	{
		string h1;
		fstream g3;
		g3.open("vechicle.csv", ios::in);
		while (!g3.eof())
		{
			getline(g3, h1, ',');
			if (g3.eof())
				break;
			cout << "VID :" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "registeration no:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "average mileage:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "licence type:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "status:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "fuel type:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "overallranking:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "date of manufacturing:" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "fid:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "description:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "cost:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "source:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "destination:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "ditance:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "date of service:" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "time of service:" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "status:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "fuel rate:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "CID:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "VID:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "DID:" << h1 << "   ";
			cout << endl;
		}

	}
	void go7()
	{
		string vc;
		cout << "enter the vechicle id for which u want complete information:";
		cin >> vc;
		int i;
		fstream f1;
		string h1, trash;
		f1.open("vechicle.csv", ios::in);
		while (!f1.eof())
		{
			getline(f1, h1, ',');
			if (f1.eof())
				break;
			if (h1 == vc)
			{
				cout << endl;
				cout << "vechile id:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "registeration no:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "average mileage:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "licence type:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "status:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "fuel type:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "overallranking:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "date of manufacturing:" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "fid:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "description:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "cost:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "source:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "destination:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "ditance:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "date of service:" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "time of service:" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "status:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "fuel rate:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "CID:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "VID:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "DID:" << h1 << "   ";
				cout << endl;
			}
			getline(f1, trash);
		}
	}
	void go10() {
		ifstream k1;
		k1.open("driver.csv", ios::in);
		string s, s1, s2, s4;
		float s3;
		while (!k1.eof())
		{
			getline(k1, s, ',');
			if (k1.eof())
				break;
			getline(k1, s1, ',');
			getline(k1, s2, ',');
			k1 >> s3;
			if (s3 > 4.5)
			{
				cout << "driver id:" << s << "  " << "first name:" << s1 << "  " << "lastname:" << s2 << endl;

			}
			getline(k1, s4);

		}
	}
	void go11() {
		cout << "list of all driver are as follows:" << endl;
		string s1, s2, s3, s4;
		int s5;
		ifstream k2;
		k2.open("driver.csv", ios::in);
		while (!k2.eof())
		{
			getline(k2, s1, ',');
			if (k2.eof())
				break;
			getline(k2, s2, ',');
			getline(k2, s3, ',');
			getline(k2, s4, ',');
			k2 >> s5;
			if (s5 > 1)
			{
				cout << "ID:" << s1 << "  ";
				cout << "first name:" << s2 << "   ";
				cout << "last name:" << s3 << "  ";
				cout << endl;

			}
			getline(k2, s2);
		}
	}
	void go12()
	{
		ifstream k1;
		k1.open("driver.csv", ios::in);
		string s, s1, s2, s4, s5;
		float s3;
		while (!k1.eof())
		{
			getline(k1, s, ',');
			if (k1.eof())
				break;
			getline(k1, s1, ',');
			getline(k1, s2, ',');
			k1 >> s3;
			if (s3 > 4.5)
			{
				getline(k1, s5, ',');
				getline(k1, s5, ',');
				getline(k1, s5, ',');
				getline(k1, s5, ',');
				getline(k1, s5, ',');
				k1 >> s3;
				s3 = (s3 * 15) / 100;
				cout << "updated salary of ID:" << s << "=" << s3 << endl;
			}
			getline(k1, s4);
		}
	}

};

int main()
{
	tms t1;
	int foo;
	cout << "enter 1 to add customer:" << endl;
	cout << "enter 2 to add or remove  driver:" << endl;
	cout << "ENTER 3 TO ADD OR REMOVE A VECHICLE:" << endl;
	cout << "ENTER 4 TO PRINT LIST OF ALL CUSTOMERS:" << endl;
	cout << "ENTER 5 TO PRINT LIST OF ALL DRIVERS:" << endl;
	cout << "ENTER 6 TO PRINT COMPLETE LIST OF VECHICLE WITH DETAIL:" << endl;
	cout << "ENTER 7 Print complete details and service history of a particular vehicle:" << endl;
	cout << "ENTER 8 TO Print complete history of a particular customer:" << endl;
	cout << "ENTER 10 TO Print list of all drivers who have ranking above 4.5:" << endl;
	cout << "ENTER 11 TO PRINT of all drivers who have multiple licenses and their license information too" << endl;
	cout << "ENTER 12 TO Print updated salary of all drivers based on their updated ranking." << endl;
	cout << "ENTER 13 TO Add a Service request (ride or delivery) for a customer" << endl;
	cout << "enter 14. When the customer cancels a booking, he will be charged 5% of service fair cost \n";
	cout << "enter 15 Complete a service (Provide service ID). Update Customer, Driver’s, and vehicles\n";
	cout << " enter 16 Print details of all Customers, who used the same vehicle in a ride service on a different\n";
	cout << "enter 17 Print the List of all Drivers who completed delivery services on same days. \n";


	cin >> foo;
	if (foo == 1)
	{
		t1.go1();
		//char a, b;
		//ofstream t1;
		//t1.open("customer.csv", ios::app);

		//int p, q, k, s, m, g;
		//int y;
		//customer* obj;
		//obj = new customer[15];
		//customer* pp = obj;
		//for (int i = 0; i < 1; i++)
		//{
		//	cout << "enter the first name:";
		//	cin >> a;
		//	cout << "enter the last name:";
		//	cin >> b;
		//	cout << "enter the day:";
		//	cin >> p;
		//	cout << "enter the month:";
		//	cin >> q;
		//	cout << "enter the year:";
		//	cin >> k;
		//	cout << "enter the age of person:";
		//	cin >> m;
		//	cout << "enter the id of the person:";
		//	cin >> s;
		//	cout << "enter the cid:";
		//	cin >> g;
		//	if (t1.is_open(), ios::app)
		//	{
		//		t1 << a << "," << b << "," << p << "," << q << "," << k << "," << m << "," << s << "," << g;
		//		t1 << endl;
		//	}
		//	else
		//		cout << "not";
		//	(*obj) = customer(s, a, b, p, q, k, m, g);
		//}
		//for (int i = 0; i < 1; i++)
		//{
		//	/*cout << *pp;*/
		//	cout << *pp;
		//}
	}
	if (foo == 2)
	{
		t1.go2();
		//int  x, l, pl, oo;
		//float io, o, gopg;
		//driver* d1;
		//d1 = new driver[15];
		//int count;
		//cout << "what u want to to PRESS 1 FOR ADD PRESS 0 FOR REMOVE:";
		//cin >> count;
		//if (count == 1)
		//{
		//	bool flag = 0;
		//	char a, b, gog;
		//	int p, q, k, s, m, g;
		//	/*fstream f2*/
		//	/*f2.open("driver.csv", ios::in);
		//	int gg;
		//	while (!f2.eof())
		//	{
		//		getline(f2, gg, ',');
		//		oo = gg;
		//		if (f2.eof())
		//		{
		//			flag = 1;
		//			break;
		//		}
		//		getline(f2, gg, ',');
		//		a = gog;
		//		getline(f2, gg, ',');
		//		b = gog;
		//		getline(f2, gg, ',');
		//		p = gg;
		//		getline(f2, gg, ',');
		//		q = gg;
		//		getline(f2, gg, ',');
		//		k = gg;
		//		getline(f2, gg, ',');
		//		m = gg;
		//		getline(f2, gg, ',');
		//		pl = gg;
		//		getline(f2, gg, ',');
		//		io = gopg;
		//		getline(f2, gg, ',');
		//		o = gopg;
		//		getline(f2, gg, ',');
		//		x = gg;
		//		getline(f2, gg, ',');
		//		l = gg;
		//		(*d1) = driver(oo, pl, io, o, x, l, a, b, p, q, k, m, s);
		//		*d1++;*/
		//		//}
		//		//f2.close();
		//		//if (flag == 1)
		//		//{
		//	ofstream db;
		//	db.open("driver.csv", ios::app);
		//	for (int i = 0; i < 1; i++)
		//	{
		//		cout << "enter the driver id:";
		//		cin >> oo;
		//		cout << "enter the first name of driver:";
		//		cin >> a;
		//		cout << "enter the last name  of driver:";
		//		cin >> b;
		//		cout << "enter the day:";
		//		cin >> p;
		//		cout << "enter the month:";
		//		cin >> q;
		//		cout << "enter the year:";
		//		cin >> k;
		//		cout << "enter the age  of driver:";
		//		cin >> m;
		//		cout << "enter the nid of the person:";
		//		cin >> s;
		//		cout << "enter the number of licence:";
		//		cin >> pl;
		//		cout << "enter the overall ranking:";
		//		cin >> io;
		//		cout << "enter the salary:";
		//		cin >> o;
		//		cout << "enter the expensive:";
		//		cin >> x;
		//		cout << "enter the status:";
		//		cin >> l;
		//		db << oo << "," << a << "," << b << "," << io << "," << pl << "," << p << "," << q << "," << k << "," << s << "," << o << "," << x << "," << l << endl;
		//		(*d1) = driver(oo, pl, io, o, x, l, a, b, p, q, k, m, s);
		//	}
		//	//	}
		//	cout << *d1;
		//}
		//if (count == 0)
		//{
		//	string arrr;
		//	bool fun = 0;
		//	int idd;
		//	string trash;
		//	fstream f1, f2;
		//	int e3;
		//	f1.open("driver.csv", ios::in);
		//	f2.open("drivernew.csv", ios::out);
		//	cout << "enter the driver id for which u want to remove record:";
		//	cin >> idd;
		//	while (!f1.eof())
		//	{
		//		f1 >> e3;
		//		if (f1.eof())
		//			break;
		//		cout << e3 << endl;

		//		if (idd == e3)
		//		{
		//			fun = 1;
		//			getline(f1, trash);
		//			continue;

		//		}
		//		else
		//		{
		//			f2 << e3;
		//			getline(f1, arrr);
		//			f2 << arrr << endl;
		//		}
		//	}
		//	if (fun == 0)
		//	{
		//		cout << "FILE NOT FOUND:";
		//	}
		//	f1.close();
		//	f2.close();
		//	remove("driver.csv");
		//	rename("drivernew.csv", "driver.csv");
		//}
	}
	if (foo == 3)
	{
		t1.go3();
		/*int count;
		cout << "what u want to to PRESS 1 FOR ADD PRESS 0 FOR REMOVE:";
		cin >> count;
		if (count == 1)
		{
			ofstream op;
			op.open("vechicle.csv", ios::app);
			int  x, l, pl, oo, hh, gg, ll, feat; bool s;
			float io, o, cost;
			vechicle* vec;
			vec = new vechicle[20];
			cout << "enter the vechicle id:";
			cin >> x;
			cout << "enter the registration no of vechicle:";
			cin >> l;
			cout << "enter the avg mileage:";
			cin >> io;
			char* p;
			p = new char[10];
			cout << "enter the licence type:";
			cin >> p;
			cout << "ener the status:";
			cin >> s;
			char* kl;
			char* upp;
			kl = new char[10];
			cout << "enter the fuel type:";
			cin >> kl;
			cout << "enter the overranking:";
			cin >> o;
			cout << "enter the day:";
			cin >> hh;
			cout << "enter the month:";
			cin >> gg;
			cout << "enter the year:";
			cin >> ll;
			cout << "enter feature id:";
			cin >> feat;
			upp = new char[10];
			cout << "enter description:";
			cin >> upp;
			cout << "enter the cost:";
			cin >> cost;
			char* source;
			float km, fuelra;
			bool sta;
			int day, mon, yea, hour, min, second, cid, vid, did;
			char* destination;
			destination = new char[10];
			source = new char[10];
			cout << "enter the service of this vechicle" << endl;
			cout << "enter the source:";
			cin >> source;
			cout << "enter the destination:";
			cin >> destination;
			cout << "enter the distance of travel in km:";
			cin >> km;
			cout << "enter the day of manufacturing:";
			cin >> day;
			cout << "enter the month of manufacturing:";
			cin >> mon;
			cout << "enter the year of manufacturing:";
			cin >> yea;
			cout << "enter the hour of bookng:";
			cin >> hour;
			cout << "enter the min of booking:";
			cin >> min;
			cout << "enter the second of booking:";
			cin >> second;
			cout << "enter the status:";
			cin >> sta;
			cout << "enter the fuel rate:";
			cin >> fuelra;
			cout << "enter CID:";
			cin >> cid;
			cout << "ENTER VID:";
			cin >> vid;
			cout << "enter DID:";
			cin >> did;

			char arrr[10] = { '\0' }, brrr[10] = { '\0' };
			char crrr[10] = { '\0' };
			for (int i = 0; i < 10; i++)
				arrr[i] = p[i];
			for (int i = 0; i < 10; i++)
				brrr[i] = kl[i];
			for (int i = 0; i < 10; i++)
				crrr[i] = upp[i];
			cout << crrr << endl << endl;

			op << x << "," << l << "," << io << "," << arrr << "," << s << "," << brrr << "," << o << "," << hh << "," << gg << "," << ll << "," << feat << "," << crrr << "," << cost << "," << source << "," << destination << "," << km << "," << day << "," << mon << "," << yea << "," << hour << "," << min << "," << second << "," << sta << "," << fuelra << "," << cid << "," << vid << "," << did << "," << endl;
			(*vec) = vechicle(x, l, io, p, s, kl, o, hh, gg, ll, feat, upp, cost, source, destination, km, day, mon, yea, hour, min, second, sta, fuelra, cid, vid, did);
			cout << *vec;
		}
		if (count == 0)
		{
			bool fun = 0;
			string arrr;

			int idd;
			string trash;
			fstream f1, f2;
			int e3;
			f1.open("vechicle.csv", ios::in);
			f2.open("vechiclenew.csv", ios::out);
			cout << "enter the vechicle id for which u want to remove record:";
			cin >> idd;
			while (!f1.eof())
			{

				f1 >> e3;
				if (f1.eof())
					break;

				if (idd == e3)
				{
					fun = 1;

					getline(f1, trash);
					continue;

				}
				else
				{
					f2 << e3;
					getline(f1, arrr);
					f2 << arrr << endl;
				}
			}
			if (fun == 0)
			{
				cout << "FILE NOT FOUND:";
			}
			f1.close();
			f2.close();
			remove("vechicle.csv");
			rename("vechiclenew.csv", "vechicle.csv");

		}*/
	}
	if (foo == 4)
	{
		t1.go4();
		/*string dd1, dd2;
		string d3;
		fstream f4;
		cout << "ALL CUSTOMER ARE:" << endl;
		f4.open("customer.csv", ios::in);
		while (!f4.eof())
		{
			getline(f4, dd1, ',');
			if (f4.eof())
			{
				break;
			}
			cout << "first name:" << dd1 << "   ";
			getline(f4, dd1, ',');
			cout << "last name:" << dd1 << "  ";
			getline(f4, d3);
			cout << endl;
		}*/
	}
	if (foo == 5)
	{
		/*
		string dd1, dd2;
		string d3;
		fstream f5;
		cout << "ALL CUSTOMER ARE:" << endl;
		f5.open("driver.csv", ios::in);
		while (!f5.eof())
		{
			getline(f5, dd1, ',');
			getline(f5, dd1, ',');
			if (f5.eof())
			{
				break;
			}
			cout << "first name:" << dd1 << "   ";
			getline(f5, dd1, ',');
			cout << "last name:" << dd1 << "  ";
			getline(f5, d3);
			cout << endl;
		}*/
	}
	if (foo == 6)
	{
		t1.go6();
		/*string h1;
		fstream g3;
		g3.open("vechicle.csv", ios::in);
		while (!g3.eof())
		{
			getline(g3, h1, ',');
			if (g3.eof())
				break;
			cout << "VID :" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "registeration no:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "average mileage:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "licence type:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "status:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "fuel type:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "overallranking:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "date of manufacturing:" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "fid:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "description:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "cost:" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "source:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "destination:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "ditance:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "date of service:" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "time of service:" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1;
			getline(g3, h1, ',');
			cout << "/" << h1 << "  ";
			getline(g3, h1, ',');
			cout << "status:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "fuel rate:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "CID:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "VID:" << h1 << "   ";
			getline(g3, h1, ',');
			cout << "DID:" << h1 << "   ";
			cout << endl;
		}*/
	}
	if (foo == 7)
	{
		t1.go7();
		/*string vc;
		cout << "enter the vechicle id for which u want complete information:";
		cin >> vc;
		int i;
		fstream f1;
		string h1, trash;
		f1.open("vechicle.csv", ios::in);
		while (!f1.eof())
		{
			getline(f1, h1, ',');
			if (f1.eof())
				break;
			if (h1 == vc)
			{
				cout << endl;
				cout << "vechile id:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "registeration no:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "average mileage:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "licence type:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "status:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "fuel type:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "overallranking:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "date of manufacturing:" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "fid:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "description:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "cost:" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "source:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "destination:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "ditance:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "date of service:" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "time of service:" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1;
				getline(f1, h1, ',');
				cout << "/" << h1 << "  ";
				getline(f1, h1, ',');
				cout << "status:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "fuel rate:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "CID:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "VID:" << h1 << "   ";
				getline(f1, h1, ',');
				cout << "DID:" << h1 << "   ";
				cout << endl;
			}
			getline(f1, trash);
		}*/
	}

	if (foo == 10)
	{
		t1.go10();
		/*ifstream k1;
		k1.open("driver.csv", ios::in);
		string s, s1, s2, s4;
		float s3;
		while (!k1.eof())
		{
			getline(k1, s, ',');
			if (k1.eof())
				break;
			getline(k1, s1, ',');
			getline(k1, s2, ',');
			k1 >> s3;
			if (s3 > 4.5)
			{
				cout << "driver id:" << s << "  " << "first name:" << s1 << "  " << "lastname:" << s2 << endl;

			}
			getline(k1, s4);

		}*/
	}
	if (foo == 11)
	{
		t1.go11();
		/*cout << "list of all driver are as follows:" << endl;
		string s1, s2, s3, s4;
		int s5;
		ifstream k2;
		k2.open("driver.csv", ios::in);
		while (!k2.eof())
		{
			getline(k2, s1, ',');
			if (k2.eof())
				break;
			getline(k2, s2, ',');
			getline(k2, s3, ',');
			getline(k2, s4, ',');
			k2 >> s5;
			if (s5 > 1)
			{
				cout << "ID:" << s1 << "  ";
				cout << "first name:" << s2 << "   ";
				cout << "last name:" << s3 << "  ";
				cout << endl;

			}
			getline(k2, s2);
		}*/
	}

	if (foo == 12)
	{
		t1.go12();
		/*ifstream k1;
		k1.open("driver.csv", ios::in);
		string s, s1, s2, s4, s5;
		float s3;
		while (!k1.eof())
		{
			getline(k1, s, ',');
			if (k1.eof())
				break;
			getline(k1, s1, ',');
			getline(k1, s2, ',');
			k1 >> s3;
			if (s3 > 4.5)
			{
				getline(k1, s5, ',');
				getline(k1, s5, ',');
				getline(k1, s5, ',');
				getline(k1, s5, ',');
				getline(k1, s5, ',');
				k1 >> s3;
				s3 = (s3 * 15) / 100;
				cout << "updated salary of ID:" << s << "=" << s3 << endl;
			}
			getline(k1, s4);
		}*/
	}

	/*if (foo == 13)
	{


	}*/
	return 0;
}
