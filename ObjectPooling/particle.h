#pragma once

class particle
{
public:
	particle()
		: framesLeft_(0)
	{}

	void init(double x, double y,
		double xVel, double yVel, int lifetime)
	{
		x_ = x;
		y_ = y;
		xVel_ = xVel;
		yVel_ = yVel;
		framesLeft_ = lifetime;
	}

	bool animate()
	{
		if (!inUse()) return false;

		framesLeft_--;
		x_ += xVel_;
		y_ += yVel_;

		return framesLeft_ == 0;
	}

	bool inUse() const { return framesLeft_ > 0; }

	particle* getNext() const { return state_.next; }
	void setNext(particle* next) { state_.next = next; }

private:
	int framesLeft_;
	double x_, y_;
	double xVel_, yVel_;

	union
	{
		// State when it's in use.
		struct
		{
			double x, y;
			double xVel, yVel;
		} live;

		// State when it's available.
		particle* next;
	} state_;
};