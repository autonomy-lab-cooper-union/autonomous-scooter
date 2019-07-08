#include "encoder_odom/encoder.h"

    Encoder::Encoder()
    {
      //TODO: read the radius as param
      radius = 0.05;
    }

    void Encoder::update(double dt)
    {
      displacement = tick * radius;
      delta_displacement = displacement - last_displacement;
      speed = delta_displacement / dt;
      last_tick = tick;
      last_displacement = displacement;
    }