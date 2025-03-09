// Copyright 2022 UNN-CS
#include <cstdint>
#include "tasks.h"
#include "circle.h"

double CalculateGroundRope() {
	const double EarthRadius = 6378.1 * 1000;
	Circle Earth;
	Earth.setFerence(EarthRadius + 1);
	double result = Earth.getRadius() - EarthRadius;
	return result;
}

double CalculatePoolCost() {
	const double pricePath = 1000;
	const double priceFence = 2000;
	const double radiusPool = 3;
	const double widthPath = 1;

	Circle Pool(radiusPool);
	Circle PoolWithPath(radiusPool + widthPath);

	double areaPath = PoolWithPath.getArea() - Pool.getArea();
	double totalPricePath = areaPath * pricePath;
	double totalPriceFence = PoolWithPath.getFerence() * priceFence;
	double result = totalPricePath + totalPriceFence;

	return result;
}