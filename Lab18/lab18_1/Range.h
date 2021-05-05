#pragma once
class Range {
	double r_left;
	double r_right;
public:
	void Init(double left, double right);
	void Read();
	void Show();

	bool rangecheck(double x);
};
