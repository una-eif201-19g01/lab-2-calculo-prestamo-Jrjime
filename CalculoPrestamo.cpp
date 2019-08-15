//
// Created by Rafael Jiménez  on 2019-08-15.
//

#include <iostream>
#include <string>
#include <sstream>
#include "CalculoPrestamo.h"

float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT)
{
	float num;
	std::string str = porcentajeTXT;

	std::size_t pos;
	std::string palab;

	pos = str.find("%");
	palab = str.substr(0, pos);
	num = std::stof(palab);


	return num / 100;

}

int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT)
{

	std::string str = tiempoTXT;
	std::string palab;
	int num;
	std::size_t buscarA;
	std::size_t buscarM;

	buscarA = str.find("A");
	buscarM = str.find("M");

	if (buscarA == true)
	{
		palab = str.substr(0, buscarA);
		num = stoi(palab);

		int mult;

		mult = num * 6 * 2;

		return mult;

	}
	else
		if (buscarM == true)
		{

			palab = str.substr(0, buscarM);
			num = stoi(palab);

			return num;

		}


}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual)
{
	float tasaMensual = tasaAnual / 12;
	float interes = tasaMensual * balance;


	return interes;


}

CalculoPrestamo::CalculoPrestamo()
{

}

CalculoPrestamo::CalculoPrestamo(int64_t mont)
{

	monto = mont;
}

std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT)
{
	std::string reporte = "";
	int meses = calcularTiempoEnMeses(tiempoTXT);
	float porcentaje = obtenerPorcentaje(porcentajeTXT);
	float balance = getMonto();
	float balanceNuevo = getMonto();

	for (int mes = 1; mes <= meses; mes++)
	{
		float interesMensual = calcularInteresMensual(balanceNuevo, porcentaje);
		balance = balanceNuevo;
		balanceNuevo = balance + interesMensual;

		reporte = reporte + "Tasa [" + porcentajeTXT + "], Mes [" + std::to_string(mes) + "], balance inicial [" + std::to_string(balance) + "], interes [" + std::to_string(interesMensual) + "], balance nuevo [" + std::to_string(balanceNuevo) + "] \n";



	}



	return reporte;


}

float CalculoPrestamo::getMonto()
{
	return monto;

}

void CalculoPrestamo::setMonto(float mont)
{
	monto = mont;

}
