//
// Created by Denys Vovk on 11.11.2026.
//
#include "components/phase.h"
#include "traffic_light_config.h"
#include <stdbool.h>

const struct Phase phases[PHASE_COUNT] = {
    // red    yellow green  blink  seconds
    { false, false, true,  false, GREEN_SECONDS },           // Green
    { false, false, true,  true,  GREEN_BLINKING_SECONDS },  // Green blinking
    { false, true,  false, false, YELLOW_SECONDS },          // Yellow
    { true,  false, false, false, RED_SECONDS },             // Red
    { true,  true,  false, false, RED_YELLOW_SECONDS },      // Red + Yellow
};
