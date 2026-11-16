//
// Created by Denys Vovk on 16.11.2026.
//

#include "main.h"
#include "components/health_check.h"

#define HEARTBEAT_PERIOD_MS 1000u
#define HEARTBEAT_FLASH_MS   100u

#define LED_ON  GPIO_PIN_RESET
#define LED_OFF GPIO_PIN_SET

static uint32_t heartbeat_start_ms;

void health_check_update(void)
{
  uint32_t elapsed = HAL_GetTick() - heartbeat_start_ms;

  HAL_GPIO_WritePin(LED_HEALTH_GPIO_Port, LED_HEALTH_Pin, elapsed < HEARTBEAT_FLASH_MS ? LED_ON : LED_OFF);

  if (elapsed >= HEARTBEAT_PERIOD_MS)
    heartbeat_start_ms += HEARTBEAT_PERIOD_MS;
}
