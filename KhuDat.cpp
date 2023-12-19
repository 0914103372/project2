#include "KhuDat.h"
istream& operator>> (istream& nh, Khudat& a) {
	cout << "Nhap dia diem Khu Dat: "; getline(cin, a.diadiem);
	cout << "Nhap gia ban Khu Dat: "; cin >> a.giaban;
	cout << "Nhap dien tich Khu Dat: "; cin >> a.dientich;
	return nh;
}
ostream& operator<< (ostream& nh, Khudat& a)
{
	cout << "dia diem la:" << a.diadiem;
	cout << "\ngia ban la:" << a.giaban << "viet nam dong";
	cout << "\ndien tich la:" << a.dientich << "met vuong";
	return nh;
}
Khudat::Khudat()
{
	id[0] = 'K';
	id[1] = 'D';
	
}
void Khudat::capid() {
	if (demmm == 2)
	{
		id[demmm] = kdat[0];
		id[demmm + 1] = NULL;
		kdat[0]++;
	}
	else if (demmm == 3)
	{
		id[demmm - 1] = kdat[0];
		id[demmm] = kdat[1];
		id[demmm + 1] = NULL;
		kdat[1]++;
	}
	if (kdat[0] == 58)
	{
		kdat[0] = 49;
		demmm++;
	}
	if (kdat[1] == 58)
	{
		kdat[0]++;
		kdat[1] = 48;
	}
}

