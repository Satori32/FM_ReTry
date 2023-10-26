#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>
#include <numbers>
#include <limits>
#include <random>

//not debug now

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
	return (2.0 - (T * 2)) - 1;
}
Float SawCi(Float T) {
	return (-2.0 + (T * 2)) + 1;
}
Float SquareA(Float T) {
	return 1;
}
Float SquareAi(Float T) {
	return -1;
}
Float SquareB(Float T) {
	return T>0? 1:-1;
}
Float TriangleA(Float T) {

	Float X = (2.0 * T);
	if (T >= 0.5) X = 2.0-(2.0 * T);

	return X;
}
Float TriangleAi(Float T) {

	Float X = (-2.0 * T);
	if (T >= 0.5) X = -2.0+(2.0 * T);

	return X;
}Float TriangleB(Float T) {

	Float X = -1.0+(4.0 * T);
	if (T > 0.5) X = 1.0-(4.0 * (T-0.5));

	return X;
}
Float TriangleBi(Float T) {

	Float X = 1.0-(4.0 * T);
	if (T > 0.5) X = -1.0+(4.0 * (T-0.5));

	return X;
}
Float TrapezoidA(Float T) {

	Float X = -1.0+T * 8;
	if (T >= 0.25) X = 1;
	if (T > 0.75) X = 1.0 - ( (T - 0.75) * 8);


	return X;
}
Float TrapezoidAi(Float T) {
	
	Float X = 1.0 - T * 8;
	if (T >= 0.25) X = -1;
	if (T > 0.75) X = -1.0 + ((T - 0.75) * 8);

	return X;

}
Float TrapezoidB(Float T) {
	
	Float X = (T * 4);
	if (T >= 0.25) X = 1;
	if (T > 0.75) X = 1 - ((T - 0.75)  * 4);

	return X;
}
Float TrapezoidBi(Float T) {
	
	Float X = -( T * 4);
	if (T >= 0.25) X = -1;
	if (T > 0.75) X = -1+((T - 0.75) * 4);

	return X;
}

Float FM_One(Float T,Float F1,Float F2, std::uint32_t Ch) {
	Float PI = std::numbers::pi_v<Float>;
	Float R = Sin(F1 * T + PI / 2 * Sin(F2 * T));

	return R;
}

std::vector<Float> Loop(Float(*Fp)(Float), std::uintmax_t N) {
	std::vector<Float> R;

	for (std::uintmax_t i = 0; i < N; i++) {
		R.push_back(Fp(1.0 / 360 * i));
	}

	return R;
}

int main() {

	auto A = Loop(SawA, 360);
	auto B = Loop(SawAi, 360);
	auto C = Loop(SawC, 360);
	auto D = Loop(SawCi, 360);
	auto E = Loop(TriangleA, 360);
	auto F = Loop(TriangleAi, 360);
	auto G = Loop(TriangleB, 360);
	auto H = Loop(TriangleBi, 360);
	auto I = Loop(TrapezoidA, 360);
	auto J = Loop(TrapezoidAi, 360);
	auto K = Loop(TrapezoidB, 360);
	auto L = Loop(TrapezoidBi, 360);
	return 0;
}