#ifndef __BSP_H__
#define __BSP_H__

/* Board Support Package for the EK-TM4C123GXL board */

/* system clock setting [Hz] */
#define SYS_CLOCK_HZ 16000000U
#define TICKS_PER_SECOND 100U
/* on-board LEDs */
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

void BSP_delay(uint32_t);
void BSP_init(void);
int BSP_tickCtr (void);


void BSP_ledRedOn(void);
void BSP_ledRedOff(void);
void BSP_ledGreenOn(void);
void BSP_ledGreenOff(void);
void BSP_ledBlueOn(void);
void BSP_ledBlueOff(void);
void blinky_green(void);
void blinky_red(void);
#endif // __BSP_H__
