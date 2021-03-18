#pragma once
#include "particle.h"
#include <cstddef>
#include <cassert>

class pool
{
public:
    pool()
    {
        firstAvailable_ = &particles_[0];

        for (int i = 0; i < POOL_SIZE - 1; i++)
        {
            particles_[i].setNext(&particles_[i + 1]);
        }

        particles_[POOL_SIZE - 1].setNext(NULL);
    }

    void create(double x, double y, double xVel, double yVel, int lifetime) {
        assert(firstAvailable_ != NULL);

        particle* newParticle = firstAvailable_;
        firstAvailable_ = newParticle->getNext();

        newParticle->init(x, y, xVel, yVel, lifetime);
    };

    void animate()
    {
        for (int i = 0; i < POOL_SIZE; i++)
        {
            if (particles_[i].animate())
            {
                // Add this particle to the front of the list.
                particles_[i].setNext(firstAvailable_);
                firstAvailable_ = &particles_[i];
            }
        }
    }

private:
    static const int POOL_SIZE = 100;
    particle particles_[POOL_SIZE];
    particle* firstAvailable_;
};