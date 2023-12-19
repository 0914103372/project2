#include "NhaSanVuon.h"
double NhaSanVuon::takedtsv()
{
	return dientichsanvuon;
}
istream& operator>>(istream& nh, NhaSanVuon& a)
{
	cout << "Nhap dia diem Nha San Vuon: "; getline(cin, a.diadiem);
	cout << "Nhap gia ban Nha San Vuon: "; cin >> a.giaban;
	cout << "Nhap dien tich xay dung: "; cin >> a.dientich;
	cout << "Nhap dien tich: "; cin >> a.dientichsanvuon;
	return nh;
}
void NhaSanVuon::fixgiatri(string diadiem, long int giaban, double dientich, double dientichsanvuon)
{
	this->diadiem = diadiem;
	this->giaban = giaban;
	this->dientich = dientich;
	this->dientichsanvuon = dientichsanvuon;

}
void NhaSanVuon::ban()
{
	id[3] = NULL;
	diadiem.clear();
	giaban = NULL;
	dientich = NULL;
	dientichsanvuon = NULL;
}
NhaSanVuon::NhaSanVuon()
{
	id[0] = 'N';
	id[1] = 'S';
	id[2] = 'V';
}
void NhaSanVuon::capid() {
	if (demm == 3)
	{
		id[demm] = nsvuon[0];
		id[demm + 1] = NULL;
		nsvuon[0]++;
	}
	else if (demm == 4)
	{
		id[demm - 1] = nsvuon[0];
		id[demm] = nsvuon[1];
		id[demm + 1] = NULL;
		nsvuon[1]++;
	}
	if (nsvuon[0] == 58)
	{
		nsvuon[0] = 49;
		demm++;
	}
	if (nsvuon[1] == 58)
	{
		nsvuon[0]++;
		nsvuon[1] = 48;
	}

}
void NhaSanVuon::fixdtsv(double dientichsanvuon)
{
	this->dientichsanvuon = dientichsanvuon;

}