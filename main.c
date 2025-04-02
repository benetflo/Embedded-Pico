#include <pico/stdlib.h>
#include "hardware/gpio.h"
#include "pico/rand.h"

#define LED 19
#define LED2 20
#define LED3 21

void handle_leds(const uint TARGET, bool state){
	gpio_put(TARGET, state);
}

int main(){

	int leds[] = {LED, LED2, LED3};
	uint number_of_leds = sizeof(leds) / sizeof(leds[0]);

	for(int i = 0; i < number_of_leds; i++){
		gpio_init(leds[i]);
		gpio_set_dir(leds[i], GPIO_OUT);
	}

	while(1){
		uint32_t num = get_rand_32();

		sleep_ms(50);
		for(int i = 0; i < number_of_leds; i++){
			handle_leds(leds[i], false);
		}
	}
	return 0;
}
