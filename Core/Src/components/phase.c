//
// Created by Denys Vovk on 11.11.2026.
//
#include "phase.h"

const struct Phase phases[PHASE_COUNT] = {
    // red    yellow green  blink  seconds
    { false, false, true,  false, 30 },  // Green (minimum)
    { false, false, true,  true,   3 },  // Green blinking
    { false, true,  false, false,  2 },  // Yellow
    { true,  false, false, false, 30 },  // Red (pedestrians: green)
    { true,  true,  false, false,  1 },  // Red + Yellow
};