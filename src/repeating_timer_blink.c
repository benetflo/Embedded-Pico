#include <pico/stdlib.h>
#include "hardware/gpio.h"

#define LED 16
#define DELAY = 300;

volatile bool led_on = false;
repeating_timer_t timer;

bool callback_func(repeating_timer_t *t){

	led_on = !led_on;
	return true;
}

void handle_led(bool led_on){

	led_on ? gpio_put(LED, 1) : gpio_put(LED, 0);
}

int main(){

	add_repeating_timer_ms(DELAY, &callback_func, NULL, &timer);
	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);

	while(1){

		handle_led(led_on);
		sleep_ms(50);
	}
	return 0;
}
