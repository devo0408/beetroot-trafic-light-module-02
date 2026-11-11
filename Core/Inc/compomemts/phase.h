//
// Created by Denys Vovk on 11.11.2026.
//

#ifndef BEETROOT_TRAFIC_LIGHT_MODULE_02_PHASE_H
#define BEETROOT_TRAFIC_LIGHT_MODULE_02_PHASE_H

#include <stdbool.h>
#include <stdint.h>

struct Phase {
    bool red;
    bool yellow;
    bool green;
    bool is_blinking;
    uint8_t seconds;
};

#define PHASE_COUNT 5

extern const struct Phase phases[PHASE_COUNT];

#endif //BEETROOT_TRAFIC_LIGHT_MODULE_02_PHASE_H
