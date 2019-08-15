//
// Created by Rafael Jiménez  on 2019-08-15.
//

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>

class CalculoPrestamo {
	float monto;
	int calcularTiempoEnMeses(std::string tiempoTXT);
	float calcularInteresMensual(float balance, float tasaAnual);
	float obtenerPorcentaje(std::string porcentajeTXT);

public:
	CalculoPrestamo();
	CalculoPrestamo(int64_t monto);
	std::string reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT);
	float getMonto();
	void setMonto(float monto);



};

#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H

