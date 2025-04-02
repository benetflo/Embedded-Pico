#include <pico/stdlib.h>
#include "hardware/gpio.h"

#define LED 21
#define LED2 18
#define BUTTON 20
#define BUTTON2 19

volatile bool led_on = false;
volatile bool led2_on = false;

void callback_func(uint gpio, uint32_t events){
	if(gpio == BUTTON){
		led_on = !led_on;
	}else if (gpio == BUTTON2){
		led2_on = !led2_on;
	}
}

void handle_leds(bool led_on, bool led2_on){
	if(led_on){
		gpio_put(LED, 1);
	}else{
		gpio_put(LED, 0);
	}

	if(led2_on){
		gpio_put(LED2, 1);
	}else{
		gpio_put(LED2, 0);
	}
}

int main(){

	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);

	gpio_init(LED2);
	gpio_set_dir(LED2, GPIO_OUT);

	gpio_init(BUTTON2);
	gpio_set_dir(BUTTON2, GPIO_IN);
	gpio_pull_up(BUTTON2);

	gpio_init(BUTTON);
	gpio_set_dir(BUTTON, GPIO_IN);
	gpio_pull_up(BUTTON);

	gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_RISE, true, &callback_func);
	gpio_set_irq_enabled_with_callback(BUTTON2, GPIO_IRQ_EDGE_RISE, true, &callback_func);

	while(1){
		handle_leds(led_on, led2_on);
		sleep_ms(5);
	}

	return 0;
}
