#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>
#include <numbers>
#include <limits>
#include <random>

typedef double Float;

Float Sin(Float T) {
	return std::sin(2 * std::numbers::pi_v<Float>*T);
}

Float SawA(Float T) {
	return 1.0 - (T * 1);
}
Float SawAi(Float T) {
	return -1.0 + (T * 1);
}
Float SawB(Float T) {
	return 0.0 + (T * 1);
}
Float SawBi(Float T) {
	return 0.0 - (T * 1);
}
Float SawC(Float T) {
	return (2.0 - (T * 1))-1;
}
Float SawCi(Float T) {
	return (-2.0 + (T * 1))+1;
}
Float SquareA(Float T) {
	return 1*T;
}
Float SquareAi(Float T) {
	return -1*T;
}
Float SquareB(Float T) {
	return T>0? 1:-1;
}
Float Triangle(Float T) {

	Float X = (2.0 * T)-1;
	if (T >= 0.5) X = (-2.0 * T) + 1;

	return X;
}
Float TrapezoidA(Float T) {

	Float X = T*4;
	if (T >= 0.25) X = 1;
	if (T >= 0.75) X = 1 - ( (T - 0.5) * 4);

	return X;
}
Float TrapezoidAi(Float T) {
	
	Float X = -T*4;
	if (T >= 0.25) X = -1;
	if (T >= 0.75) X = -1 + ((T - 0.5) * 4);

	return X;

}
Float TrapezoidB(Float T) {
	
	Float X = (-1 + T * 8);
	if (T >= 0.25) X = 1;
	if (T >= 0.75) X = 1 - ((T - 0.5)  * 8);

	return X;
}
Float TrapezoidBi(Float T) {
	
	Float X = (1 - T * 8);
	if (T >= 0.25) X = -1;
	if (T >= 0.75) X = 1 - ((T - 0.5) * 8);

	return X;
}

Float FM_One(Float T,Float F1,Float F2, std::uint32_t Ch) {
	Float PI = std::numbers::pi_v<Float>;
	Float R = Sin(F1 * T + PI / 2 * Sin(F2 * T));

	return R;
}