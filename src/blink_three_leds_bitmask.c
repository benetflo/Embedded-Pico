#include <pico/stdlib.h>
#include "hardware/gpio.h"

#define LED_MASK 0b111

int main(){

	gpio_init_mask(LED_MASK);
	gpio_set_dir_masked(LED_MASK, LED_MASK);

	while(1){
		gpio_put_masked(LED_MASK, LED_MASK);
		sleep_ms(100);
		gpio_put_masked(LED_MASK, 0);
		sleep_ms(100);
	}

	return 0;
}
