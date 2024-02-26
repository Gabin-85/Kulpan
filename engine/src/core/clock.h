#pragma once
#include "defines.h"

typedef struct clock {
    f64 start_time;
    f64 elapsed;
} clock;

//Clock updating
void clock_update(clock* clock);

//Start the provided clock
void clock_start(clock* clock);

//Stop the provided clock
void clock_stop(clock* clock);