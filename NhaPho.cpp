#include "NhaPho.h"
void NhaPho::fixgiatri(string diadiem, long int giaban, double dientich, int a)
{
	this->diadiem = diadiem;
	this->giaban = giaban;
	this->dientich = dientich;
	this->sotang = sotang;
}
int NhaPho::takest()
{
	return sotang;
}
void NhaPho::ban()
{
	id[3] = NULL;
	diadiem.clear();
	giaban = NULL;
	dientich = NULL;
	sotang = NULL;
}
istream& operator>> (istream& nh, NhaPho& a)
{
	cout << "Nhap dia diem: "; getline(cin, a.diadiem);
	cout << "Nhap gia ban: "; cin >> a.giaban;
	cout << "Nhap dien tich xay dung : "; cin >> a.dientich;
	cout << "Nhap so tang: "; cin >> a.sotang;
	return nh;
}
ostream& operator<< (ostream& nh, NhaPho& a)
{
	cout << "dia diem la:" << a.diadiem;
	cout << "\ngia ban la:" << a.giaban << "viet nam dong";
	cout << "\ndien tich xay dung la:" << a.dientich << "met vuong";
	cout << "\n So tang la: " << a.sotang;
	return nh;
}
NhaPho::NhaPho()
{
	id[0] = 'N';
	id[1] = 'P';

}
void NhaPho::capid() {
	
	if (dem == 2)
	{
		id[dem] = npho[0];
		id[dem+1] = NULL;
		npho[0]++;
	}
	else if(dem == 3)
	{
		id[dem - 1] = npho[0];
		id[dem] = npho[1];
		id[dem + 1] = NULL;
		npho[1]++;
	}
	if (npho[0] == 58)
	{
		npho[0] = 49;
		dem++;
	}
	if (npho[1] == 58)
	{
		npho[0]++;
		npho[1] = 48;
	}
	
}
void NhaPho::fixsotang(int a)
{
	sotang = a;
}